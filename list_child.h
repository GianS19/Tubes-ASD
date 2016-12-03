#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED


#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define parent(P) P->parent

#include "list_parent.h"

typedef struct buku infotype_child;
typedef struct elmlist_child *address_child;
struct buku
{
    int id,harga,tahun_terbit;
    string judul,pengarang,penerbit;
};


struct elmlist_child
{
    infotype_child info;
    address_child next;
    address_child prev;

    address_parent parent;

};

struct List_child
{
    address_child first;
    address_child last;
};

void createList(List_child &L);                                         //1301150057
void insertFirst(List_child &L, address_child P);                       //1301150057
void insertLast(List_child &L, address_child P);                        //1301150057
void insertAfter(address_child Prec, address_child P);                  //1301150057
void deleteFirst(List_child &L, address_child &P);                      //1301150057
void deleteLast(List_child &L, address_child &P);                       //1301150057
void deleteAfter(address_child Prec, address_child &P);                 //1301150057

address_child alokasi(infotype_child x);                                //1301150057
void dealokasi(address_child &P);                                       //1301150057
address_child findElm(List_child L, infotype_child x);                  //1301150057
void printInfo(List_child L);                                           //1301150057

void jumlahBuku(List_child L);                                          //1301150057
void rataBuku(List_child L);                                            //1301150057
void maxHarga(List_child L);                                            //1301150057
void searchEdit(List_child &L);                                         //1301150057
void sortHarga(List_child &L);                                          //1301150057

void jumlahBukuDalamRak(List_parent LP,List_child L);                   //1301150057

////////////////////////////////////////

void insertData(List_child &L, List_parent LP);                         /*1301154407*/
void searchView(List_child L);                                          /*1301154407*/
void searchDelete(List_child &L);                                       /*1301154407*/
void hapusParent(List_parent &LP, List_child L);                        /*1301154407*/
void viewAll (List_parent LP,List_child LC);                            /*1301154407*/

void kosongkanRak(List_parent &LP, List_child &LC);                     /*1301154407*/
void tampungBuku(List_parent &LP, List_child &LC);                      /*1301154407*/

#endif // LIST_CHILD_H_INCLUDED
