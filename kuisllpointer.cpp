#include <bits/stdc++.h>
using namespace std;

struct akunBank {
    string nomorAkun;
    long long saldo;
    akunBank* next;
};

akunBank *awal, *akhir, *nodebaru;

void sisipAkun(string nomorAkun, long long saldo);
void hapusAkun(string nomorAkun);
void tampilkanAkun();
void cariAkun(string nomorAkun);
bool listkosong();

int main() {
    awal = akhir = nullptr;
    int pilihan;
    string nomorAkun;
    long long saldo;
    
    do {
        system("cls");
        cout << "ADMIN BANK" << endl;
        cout << "==========" << endl;
        cout << "1. Input" << endl;
        cout << "2. Output" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "==========" << endl;
        cout << "Pilih (1-5) : ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                system("cls");
                cout << "Input" << endl;
                cout << "=====" << endl;
                cout << "Jumlah Input : ";
                int jumlahInput;
                cin >> jumlahInput;
                for(int i = 0; i < jumlahInput; i++) {
                    cout << "Nomor Rekening : ";
                    cin >> nomorAkun;
                    cout << "Tabungan       : ";
                    cin >> saldo;
                    sisipAkun(nomorAkun, saldo);
                }
                break;
            case 2:
                system("cls");
                cout << "Output" << endl;
                cout << "======" << endl;
                tampilkanAkun();
                break;
            case 3:
                system("cls");
                cout << "Cari" << endl;
                cout << "====" << endl;
                cout << "Cari Nomor Rekening : ";
                cin >> nomorAkun;
                cariAkun(nomorAkun);
                break;
            case 4:
                system("cls");
                cout << "Hapus" << endl;
                cout << "=====" << endl;
                cout << "Hapus Nomor Rekening : ";
                cin >> nomorAkun;
                hapusAkun(nomorAkun);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan layanan Admin Bank." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        
        if(pilihan != 5) {
            char kembali;
            cout << "Kembali ke Menu Awal (y/n) : ";
            cin >> kembali;
            if(kembali != 'y' && kembali != 'Y') pilihan = 5;
        }
    } while(pilihan != 5);
    
    // Clean up memory
    while (awal != nullptr) {
        akunBank* temp = awal;
        awal = awal->next;
        delete temp;
    }
    
    return 0;
}

bool listkosong() {
    return awal == nullptr;
}

void sisipAkun(string nomorAkun, long long saldo) {
    nodebaru = new akunBank();
    nodebaru->nomorAkun = nomorAkun;
    nodebaru->saldo = saldo;
    nodebaru->next = nullptr;
    
    if(listkosong()) {
        awal = akhir = nodebaru;
    } else if(nomorAkun < awal->nomorAkun) {
        nodebaru->next = awal;
        awal = nodebaru;
    } else {
        akunBank* bantu = awal;
        while(bantu->next != nullptr && nomorAkun > bantu->next->nomorAkun)
            bantu = bantu->next;
        nodebaru->next = bantu->next;
        bantu->next = nodebaru;
        if(bantu == akhir) {
            akhir = nodebaru;
        }
    }
}

void tampilkanAkun() {
    if(listkosong()) {
        cout << "Tidak ada data akun." << endl;
    } else {
        akunBank* bantu = awal;
        while(bantu != nullptr) {
            cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
            cout << "Tabungan       : " << bantu->saldo << endl;
            cout << "===============================" << endl;
            bantu = bantu->next;
        }
    }
}

void cariAkun(string nomorAkun) {
    if(listkosong()) {
        cout << "Tidak ada data akun." << endl;
        return;
    }
    
    akunBank* bantu = awal;
    while(bantu != nullptr) {
        if(bantu->nomorAkun == nomorAkun) {
            cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
            cout << "Isi Tabungan   : " << bantu->saldo << endl;
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "Akun tidak ditemukan." << endl;
}

void hapusAkun(string nomorAkun) {
    if(listkosong()) {
        cout << "Tidak ada data akun untuk dihapus." << endl;
        return;
    }
    
    if(awal->nomorAkun == nomorAkun) {
        akunBank* hapus = awal;
        awal = awal->next;
        delete hapus;
        if(awal == nullptr) {
            akhir = nullptr;
        }
        cout << "Rekening " << nomorAkun << " Dihapus" << endl;
        return;
    }
    
    akunBank* bantu = awal;
    while(bantu->next != nullptr && bantu->next->nomorAkun != nomorAkun) {
        bantu = bantu->next;
    }
    
    if(bantu->next != nullptr) {
        akunBank* hapus = bantu->next;
        bantu->next = hapus->next;
        if(hapus == akhir) {
            akhir = bantu;
        }
        delete hapus;
        cout << "Rekening " << nomorAkun << " Dihapus" << endl;
    } else {
        cout << "Akun " << nomorAkun << " tidak ditemukan." << endl;
    }
}