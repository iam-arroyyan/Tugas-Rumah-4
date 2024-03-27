#include "doubleList.h"
#include <iostream>
#include <string>
using namespace std;

void createlist(list_integer &l)
{
    l.first = NULL;
    l.last = NULL;
}

address createelm(string nama, int isi)
{
    address P = new elemen;
    P->info.nama = nama;
    P->info.tinggibadan = isi;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst(list_integer &l, address p)
{
    if ((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(list_integer &l, address p)
{
    if ((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void insertAfter(list_integer &l, address p, string sebelum)
{
    if ((l.first == NULL) && (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        address q = l.first;
        while ((q->next != NULL) && (q->info.nama != sebelum))
        {
            q = q->next;
        }
        if (q->info.nama == sebelum)
        {
            p->next = q->next;
            p->prev = q;
            q->next->prev = p;
            q->next = p;
        }
    }
}

void deleteFirst(list_integer &l, address &p)
{
    p = l.first;
    if ((l.first != NULL) && (l.last != NULL))
    {
        if (l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.first = p->next;
            p->next = NULL;
            l.first->prev = NULL;
        }
    }
}

void deleteLast(list_integer &l, address &p)
{
    p = l.last;
    if ((l.first != NULL) && (l.last != NULL))
    {
        if (l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.last = l.last->prev;
            p->prev = NULL;
            l.last->next = NULL;
        }
    }
}

void deleteAfter(list_integer &l, address &p, string cari)
{
    p = l.first;
    if ((l.first != NULL) && (l.last != NULL))
    {
        if ((l.first == l.last) && (l.first->info.nama == cari))
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            address q;
            while ((p->next != NULL) && (p->info.nama != cari))
            {
                q = p;
                p = p->next;
            }
            if (p->info.nama == cari)
            {
                if (p == l.first)
                {
                    deleteFirst(l, p);
                }
                else if (p == l.last)
                {
                    deleteLast(l, p);
                }
                else
                {
                    q->next = p->next;
                    p->next->prev = q;
                    p->next = NULL;
                    p->prev = NULL;
                }
            }
        }
    }
}

void cetak_list(list_integer l)
{
    cout << "Isi list : ";
    if ((l.first == NULL) && (l.last == NULL))
    {
        cout << "[ ]";
    }
    else
    {
        address current = l.first;
        while (current->next != NULL)
        {
            cout << "[" << current->info.nama << "(" << current->info.tinggibadan << ")"
                 << "] ";
            current = current->next;
        }
        cout << "[" << current->info.nama << "(" << current->info.tinggibadan << ")"
             << "] ";
    }
    cout << endl;
}

void updateumur(list_integer &list, string namabaru, string nama, int tinggibadan)
{
    address temp = list.first;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->info.nama == namabaru)
        {
            temp->info.nama = nama;
            temp->info.tinggibadan = tinggibadan;
            found = true;
            cout << "Data berhasil diperbarui untuk nama " << namabaru << " dengan tinggi badan baru" << tinggibadan << endl;
            break;
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "Data tidak ditemukan untuk nama " << namabaru << ". Tidak ada pembaruan yang dilakukan." << endl;
    }
}

int tbtertinggi(list_integer &l)
{
    if ((l.first == NULL) && (l.last == NULL))
    {
        cout << "data kosong" << endl;
        return 0;
    }

    int tbtertinggi = l.first->info.tinggibadan;
    address current = l.first->next;

    while (current != NULL)
    {
        if (current->info.tinggibadan > tbtertinggi)
        {
            tbtertinggi = current->info.tinggibadan;
        }
        current = current->next;
    }

    return tbtertinggi;
}

double ratarata(list_integer &l) 
{
    int count = 0;
    int sum = 0;
    address temp = l.first; 
    while (temp != NULL) {
        sum += temp->info.tinggibadan;
        count++;
        temp = temp->next;
    }

    if (count != 0)
        return (double)sum / count;
    else
        return 0.0;
}
