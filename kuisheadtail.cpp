#include <bits/stdc++.h>
using namespace std;

struct akunBank {
    long long nomorAkun;
    long long saldo;
    akunBank* next;
};

akunBank *kepala, *ekor, *NB, *bantu, *hapus;

void buatlist();
bool listkosong();
void sisipAkun(long long nomorAkun, long long saldo);
void hapusAkun(long long nomorAkun);
void tampilkanAkun();
void cariAkun(long long nomorAkun);

int main() {
    int pilihan;
    long long nomorAkun, saldo;
    
    buatlist();
    
    do {
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
                cout << "Output" << endl;
                cout << "======" << endl;
                tampilkanAkun();
                break;
            case 3:
                cout << "Cari" << endl;
                cout << "====" << endl;
                cout << "Cari Nomor Rekening : ";
                cin >> nomorAkun;
                cariAkun(nomorAkun);
                break;
            case 4:
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
    ekor = new akunBank();
    kepala->nomorAkun = 0;
    kepala->saldo = 0;
    kepala->next = ekor;
    ekor->nomorAkun = 9999999999;
    ekor->saldo = 0;
    ekor->next = NULL;
}

bool listkosong() {
    return kepala->next == ekor;
}

void sisipAkun(long long nomorAkun, long long saldo) {
    NB = new akunBank();
    NB->nomorAkun = nomorAkun;
    NB->saldo = saldo;
    bantu = kepala;
    
    while(nomorAkun > bantu->next->nomorAkun)
        bantu = bantu->next;
    
    NB->next = bantu->next;
    bantu->next = NB;
}

void tampilkanAkun() {
    if(listkosong()) {
        cout << "Tidak ada data akun." << endl;
    } else {
        bantu = kepala->next;
        while(bantu != ekor) {
            cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
            cout << "Tabungan       : " << bantu->saldo << endl;
            cout << "===============================" << endl;
            bantu = bantu->next;
        }
    }
}

void cariAkun(long long nomorAkun) {
    bantu = kepala->next;
    while(bantu != ekor && bantu->nomorAkun != nomorAkun)
        bantu = bantu->next;
    
    if(bantu != ekor) {
        cout << "Nomor Rekening : " << bantu->nomorAkun << endl;
        cout << "Isi Tabungan   : " << bantu->saldo << endl;
    } else {
        cout << "Akun tidak ditemukan." << endl;
    }
}

void hapusAkun(long long nomorAkun) {
    if(listkosong()) {
        cout << "Tidak ada data akun untuk dihapus." << endl;
    } else {
        bantu = kepala;
        while(bantu->next != ekor && nomorAkun != bantu->next->nomorAkun)
            bantu = bantu->next;
        
        if(nomorAkun == bantu->next->nomorAkun) {
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
            cout << "Rekening " << nomorAkun << " Dihapus" << endl;
        } else {
            cout << "Akun " << nomorAkun << " tidak ditemukan." << endl;
        }
    }
}
