#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef struct elmlist_parent *address_parent;
typedef struct rak infotype_parent;

struct rak
{
    string namaRak, jenisBuku, lokasi;
    int ID, kapasitas, jumlahBaris;
};


struct elmlist_parent
{
    infotype_parent info;
    address_parent next;
};

struct List_parent
{
    address_parent first;
};

void createList(List_parent &L);                                            /*1301154407*/
void insertFirst(List_parent &L, address_parent P);                         /*1301154407*/
void insertAfter(address_parent Prec, address_parent P);                    /*1301154407*/
void insertLast(List_parent &L, address_parent P);                          /*1301154407*/
void deleteFirst(List_parent &L, address_parent &P);                        /*1301154407*/
void deleteLast(List_parent &L, address_parent &P);                         /*1301154407*/
void deleteAfter(address_parent Prec, address_parent &P);                   /*1301154407*/

address_parent alokasi(infotype_parent x);                                  /*1301154407*/
void dealokasi(address_parent &P);                                          /*1301154407*/
address_parent findElm(List_parent L, infotype_parent x);                   /*1301154407*/
void printInfo(List_parent L);                                              /*1301154407*/

void insertData(List_parent &L);                                            /*1301154407*/
void searchView(List_parent L);                                             /*1301154407*/
void searchDelete(List_parent &L,infotype_parent &x);                       /*1301154407*/

bool isFull(List_parent L);

///////////////////////////////

void searchEdit(List_parent &L);                                            //1301150057
void sortKapasitas(List_parent &L);                                         //1301150057
void TotalKapasitas(List_parent L);                                         //1301150057

void reportRak(List_parent L);                                              //1301150057
void jumlahRak(List_parent L);                                              //1301150057


#endif // LIST_PARENT_H_INCLUDED
