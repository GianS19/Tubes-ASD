#ifndef MENU&INITIAL_H_INCLUDED
#define MENU&INITIAL_H_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

#include "list_child.h"

void connect(List_parent LP, List_child &LC);
void disconnect(List_child &L);
void menuBuku(List_parent &LP, List_child &LC);
void menuRak(List_parent &LP, List_child &LC);
void menuUtama(List_parent &LP, List_child &LC);
void inisialisasi(List_parent &LP, List_child &LC);

#endif // MENU&INITIAL_H_INCLUDED
