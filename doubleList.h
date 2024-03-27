#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct data
{
    string nama;
    int tinggibadan;
};


typedef struct elemen *address;
struct elemen
{
    data info;
    address next;
    address prev;
};
struct list_integer
{
    address first;
    address last;
};

void createlist(list_integer &l);
address createelm(string nama, int isi);
void insertFirst(list_integer &l, address p);
void insertLast(list_integer &l, address p);
void insertAfter(list_integer &l, address p, string sebelum);
void deleteFirst(list_integer &l, address &p);
void deleteLast(list_integer &l, address &p);
void deleteAfter(list_integer &l, address &p, string cari);
void cetak_list(list_integer l);
void updateumur(list_integer &list, string namabaru, string nama, int tinggibadan);
int tbtertinggi(list_integer &l);
double ratarata(list_integer &l);

#endif // DOUBLELIST_H_INCLUDED