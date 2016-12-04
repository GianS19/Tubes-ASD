#include <iostream>
#include <cstdlib>
using namespace std;

#include "Menu&Initial.h"

int main()
{
    List_parent LP;
    List_child LC;

    createList(LP);
    createList(LC);

    inisialisasi(LP,LC);

    menuUtama(LP,LC);

    return 0;
}




