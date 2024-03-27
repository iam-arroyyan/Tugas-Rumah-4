#include <iostream>
#include <stdlib.h>
#include "doubleList.h"
#include "doubleList.cpp"
#include <string>
using namespace std;

int main()
{
    list_integer l;
    createlist(l);
    int tinggibadan, pilihan;
    string nama;
    address p;
    bool stop = false;
    while (!stop)
    {
        system("cls");
        cout << "==Program Pendataan Tinggi Badan==" << endl;
        cetak_list(l);
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete First" << endl;
        cout << "5. Delete Last" << endl;
        cout << "6. Delete After" << endl;
        cout << "7. Update Data" << endl;
        cout << "8. Data Tertinggi" << endl;
        cout << "9. Tinggi Rata-rata" << endl;
        cout << "10. Keluar" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan Tinggi Badan : ";
            cin >> tinggibadan;
            p = createelm(nama, tinggibadan);
            insertFirst(l, p);
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan Tinggi Badan : ";
            cin >> tinggibadan;
            p = createelm(nama, tinggibadan);
            insertLast(l, p);
        }
        else if (pilihan == 3)
        {
            cout << "Masukkan Nama : ";
            cin >> nama;
            cout << "Masukkan Tinggi Badan : ";
            cin >> tinggibadan;
            cout << "Masukkan pilihan Nama sebelumnya : ";
            string sebelum;
            cin >> sebelum;
            p = createelm(nama, tinggibadan);
            insertAfter(l, p, sebelum);
        }
        else if (pilihan == 4)
        {
            deleteFirst(l, p);
            cout << p->info.nama << ". Tinggi Badan " << p->info.tinggibadan << " akan dihapus" << endl;
            system("pause");
        }
        else if (pilihan == 5)
        {
            deleteLast(l, p);
            cout << p->info.nama << ". Tinggi Badan " << p->info.tinggibadan << " akan dihapus" << endl;
            system("pause");
        }
        else if (pilihan == 6)
        {
            cout << "Masukkan pilihan Nama yang akan dihapus : ";
            string cari;
            cin >> cari;
            deleteAfter(l, p, cari);
            if (p->info.nama != cari)
            {
                cout << "Data yang dicari tidak ada" << endl;
            }
            else
            {
                cout << p->info.nama << ". Tinggi Badan " << p->info.tinggibadan << " akan dihapus" << endl;
            }
            system("pause");
        }
        else if (pilihan == 7)
        {
            string updatenama, namabaru;
            int tinggibadanbaru;
            cout << "Masukkan nama yang ingin di cari untuk di-Update : ";
            cin >> updatenama;
            cout << "Masukan nama baru : ";
            cin >> namabaru;
            cout << "Masukan nama baru : ";
            cin >> tinggibadanbaru;
            updateumur(l, updatenama, namabaru, tinggibadanbaru);
        }
        else if (pilihan == 8)
        {
            cout << "Tinggi badan tertinggi dalam data adalah " << tbtertinggi(l) << endl;
            system("pause");
        }
        else if (pilihan == 9)
        {
            cout << "Rata-rata dari data tinggi badan adalah " << ratarata(l) << endl;
            system("pause");
        }
        else if (pilihan == 10)
        {
            stop = true;
        }
    }
    return 0;
}