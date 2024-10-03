#include <bits/stdc++.h>
using namespace std;

struct akunBank {
    string nomorAkun;
    long long saldo;
    akunBank* next;
};

akunBank *kepala, *NB, *bantu, *hapus;

void buatlist();
bool listkosong();
void sisipAkun(string nomorAkun, long long saldo);
void hapusAkun(string nomorAkun);
void tampilkanAkun();
void cariAkun(string nomorAkun);

int main() {
    int pilihan;
    string nomorAkun;  // Tambahkan deklarasi ini
    long long saldo;   // Tambahkan deklarasi ini
    buatlist();
    
    do {
        system("cls");  // Tambahkan ini untuk membersihkan layar
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
    
    return 0;
}

void buatlist() {
    kepala = new akunBank();
    kepala->nomorAkun = "0";
    kepala->saldo = 0;
    kepala->next = kepala;
}

bool listkosong() {
    return kepala->next == kepala;
}

void sisipAkun(string nomorAkun, long long saldo) {
    NB = new akunBank();
    NB->nomorAkun = nomorAkun;
    NB->saldo = saldo;
    
    if(listkosong() || nomorAkun < kepala->next->nomorAkun) {
        NB->next = kepala->next;
        kepala->next = NB;
    } else {
        bantu = kepala->next;
        while(bantu->next != kepala && nomorAkun > bantu->next->nomorAkun)
            bantu = bantu->next;
        NB->next = bantu->next;
        bantu->next = NB;
    }
}

void tampilkanAkun() {
    if(listkosong()) {
        cout << "Tidak ada data akun." << endl;
    } else {
        bantu = kepala->next;
        do {
            cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
            cout << "Tabungan       : " << bantu->saldo << endl;
            cout << "===============================" << endl;
            bantu = bantu->next;
        } while(bantu != kepala);
    }
}

void cariAkun(string nomorAkun) {
    if(listkosong()) {
        cout << "Tidak ada data akun." << endl;
        return;
    }
    
    bantu = kepala->next;
    do {
        if(bantu->nomorAkun == nomorAkun) {
            cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
            cout << "Isi Tabungan   : " << bantu->saldo << endl;
            return;
        }
        bantu = bantu->next;
    } while(bantu != kepala);
    
    cout << "Akun tidak ditemukan." << endl;
}

void hapusAkun(string nomorAkun) {
    if(listkosong()) {
        cout << "Tidak ada data akun untuk dihapus." << endl;
        return;
    }
    
    bantu = kepala;
    do {
        if(bantu->next->nomorAkun == nomorAkun) {
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
            cout << "Rekening " << nomorAkun << " Dihapus" << endl;
            return;
        }
        bantu = bantu->next;
    } while(bantu != kepala);
    
    cout << "Akun " << nomorAkun << " tidak ditemukan." << endl;
}
