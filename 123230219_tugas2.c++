#include <iostream>
#include <string>

using namespace std;

struct Kos {
    string nama;
    int harga;
    Kos* next;
};

Kos *kepala = NULL, *listbaru, *bantu, *hapus;
int jmlnode = 0;

bool listkosong();
void sisipNode(string nama, int harga);
void hapusNode(string nama);
void lihatData();
void bacamaju();
void bacamundur();
bool kembaliKeMenu();

int main() {
    kepala = new Kos();
    kepala->next = kepala;
    kepala->harga = 0; 

    int pilihan;

    while (true) {
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Input Kosan" << endl;
        cout << "2. Lihat Data Kosan (baca maju)" << endl;
        cout << "3. Lihat Data Kosan (baca mundur)" << endl;
        cout << "4. Lihat Data Kosan" << endl;
        cout << "5. Hapus Data Kosan" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                system("cls");
                string nama;
                int harga;

                cout << "Input Data :" << endl;
                cout << "Nama kosan\t: ";
                cin.ignore();
                getline(cin, nama);

                cout << "Harga/Bulan\t: ";
                cin >> harga;
                cout << endl;
                sisipNode(nama, harga);
                cout << "Kosan berhasil ditambahkan." << endl;
                if (!kembaliKeMenu()) return 0;
                break;
            }

            case 2: {
                system("cls");
                cout << "Data Kosan (baca maju):" << endl;
                bacamaju();
                if (!kembaliKeMenu()) return 0;
                break;
            }

            case 3: {
                system("cls");
                cout << "Data Kosan (baca mundur):" << endl;
                bacamundur();
                lihatData();
                bacamundur(); //mengmbalikkan arrow list
                if (!kembaliKeMenu()) return 0;
                break;
            }
            case 4: {
                system("cls");
                cout << "Data Kosan:" << endl;
                lihatData();
                if (!kembaliKeMenu()) return 0;
                break;
            }
            case 5: {
                system("cls");
                cout << "Hapus Data Kosan" << endl;
                string nama;
                cout << "Kosan apa yang ingin di hapus: ";
                cin.ignore();
                getline(cin, nama);
                hapusNode(nama);
                cout << "Kosan berhasil di hapus." << endl;
                if (!kembaliKeMenu()) return 0;
                break;
            }
            case 6:
                cout << "Terima kasih ya aja oh aja." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi dengan menginputkan angka yang tertera di menu ya bos." << endl;
                break;
        }
    }

    return 0;
}

bool listkosong(){ 
    if(kepala->next == kepala)
        return(true);
    else
        return(false); 
}

void sisipNode(string nama, int harga) {
    listbaru = new Kos();
    listbaru->nama = nama;
    listbaru->harga = harga;

    if(listkosong()){
        listbaru->next = kepala;
        kepala->next = listbaru;
    } else { 
        bantu = kepala;
        while(bantu->next->harga < harga && bantu->next != kepala)
            bantu = bantu->next;

        if(bantu->next != kepala){ 
            listbaru->next = bantu->next;
            bantu->next = listbaru;
        } else { 
            listbaru->next = kepala;
            bantu->next = listbaru; 
        }
    }
    jmlnode++;
    kepala->harga = jmlnode;
}

void hapusNode(string nama) {
    if(listkosong()){
        cout << "List Masih Kosong" << endl;
        return;
    }
    bantu = kepala;
    while(bantu->next != kepala && bantu->next->nama != nama)
        bantu = bantu->next;

    if(bantu->next == kepala){
        cout << "Kosan tidak ditemukan." << endl;
        return;
    }

    if(bantu->next != kepala){ 
        hapus = bantu->next;
        bantu->next = hapus->next;
        free(hapus);
    } else { 
        hapus = bantu->next;
        bantu->next = kepala;
        free(hapus);
        }
    jmlnode--;
    kepala->harga = jmlnode;
}

void lihatData() {
    if (listkosong()) {
        cout << "Data kosan tidak ditemukan." << endl;
        return;
    }

    Kos* current = kepala->next;

    do {
        cout << "Nama Kos\t: " << current->nama << endl; 
        cout << "Harga/Bulan\t: Rp" << current->harga << endl;
        cout << endl;
        current = current->next;
    } while (current != kepala);
}

bool kembaliKeMenu() {
    char kembali;
    cout << "Kembali ke menu awal? (y/n): ";
    cin >> kembali;
    return (kembali == 'y' || kembali == 'Y');
}

void bacamaju(){
    if(listkosong()){
        cout << "List Kosong" << endl;
        return;
    }
    
    bantu = kepala->next;
    do {
        cout << "Nama Kos\t: " << bantu->nama << endl; 
        cout << "Harga/Bulan\t: Rp" << bantu->harga << endl;
        cout << endl;
        bantu = bantu->next;
    } while(bantu != kepala);
}

void bacamundur() {
    if (listkosong() || kepala->next->next == kepala) {
        cout << "Tidak perlu dibalik." << endl;
        return;
    }

    Kos* prev = kepala;
    Kos* current = kepala->next;
    Kos* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != kepala);

    kepala->next = prev;
}