#include "list_parent.h"

void createList(List_parent &L)
{
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x)
{
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(address_parent &P)
{
    delete(P);
}

void insertFirst(List_parent &L, address_parent P)
{
    address_parent Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}


void printInfo(List_parent L)
{
    address_parent P = first(L);
    cout << "\nTAMPIL RAK" << endl;
    cout << "===============================================" << endl;
    if (P == NULL)
    {
        cout << "\n   Tidak Ada Rak" << endl;
    }
    else
    {
        do
        {
            cout<<"\n   ID           : " << info(P).ID<<endl;
            cout<<"   Kapasitas    : " << info(P).kapasitas<<endl;
            cout<<"   Jenis Buku   : " << info(P).jenisBuku<<endl;
            P = next(P);
        }
        while((P)!=first(L));
    }
    cout << "===============================================" << endl;

}

void searchView(List_parent L)
{
    rak r1;
    cout << "\nCARI RAK" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID : ";
    cin >> r1.ID;
    address_parent P = findElm(L,r1);
    if (P != NULL)
    {
        cout<<"\n   ID           : " << info(P).ID<<endl;
        cout<<"   Nama Rak     : " << info(P).namaRak<<endl;
        cout<<"   Jenis Buku   : " << info(P).jenisBuku<<endl;
        cout<<"   Jumlah Baris : " << info(P).jumlahBaris<<endl;
        cout<<"   Kapasitas    : " << info(P).kapasitas<<endl;
        cout<<"   Lokasi       : " << info(P).lokasi<<endl;
    }
    else
    {
        cout << "\n   Rak tidak ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

address_parent findElm(List_parent L, infotype_parent x)
{
    address_parent P = first(L);
    do
    {
        if(info(P).ID == x.ID)
        {
            return P;
        }
        P = next(P);
    }
    while(P != first(L));
    return NULL;
}

void insertAfter(address_parent Prec, address_parent P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLast(List_parent &L, address_parent P)
{
    address_parent Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirst(List_parent &L, address_parent &P)
{
    address_parent Q = first(L);
    P=first(L);
    if (first(L) != NULL)
    {
        if(next(P) == first(L))
        {
            next(P) = NULL;
            first(L) = NULL;
        }
        else
        {
            while (next(Q)!=first(L))
            {
                Q=next(Q);
            }
            first(L)=next(P);
            next(P)=NULL;
            next(Q) = first(L);
        }
    }
}

void deleteLast(List_parent &L, address_parent &P)
{
    address_parent Q = first(L);
    P = first(L);
    if (first(L) != NULL)
    {
        if(next(P) == first(L))
        {
            next(P) = NULL;
            first(L) = NULL;
        }
        else
        {
            while (next(next(Q))!=first(L))
            {
                Q=next(Q);
            }
            P =next(Q);
            next(Q) = first(L);
            next(P) = NULL;
        }
    }
}

void deleteAfter(address_parent Prec, address_parent &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void insertData(List_parent &L)
{
    rak r1;
    cout << "\nTAMBAH RAK" << endl
         << "===============================================" << endl;
    if(isFull(L))
    {
        cout << "   Ruangan tidak cukup" << endl;
    }
    else
    {
        cout << "   Masukkan ID            : ";
        cin >> r1.ID;

        address_parent R = findElm(L,r1);
        if (R == NULL)
        {
            cout << "   Masukkan Nama Rak      : ";
            cin >> r1.namaRak;
            cout << "   Masukkan Jenis Buku    : ";
            cin >> r1.jenisBuku;
            cout << "   Masukkan Jumlah Baris  : ";
            cin >> r1.jumlahBaris;
            cout << "   Masukkan Kapasitas     : ";
            cin >> r1.kapasitas;
            cout << "   Masukkan Lokasi        : ";
            cin >> r1.lokasi;

            address_parent P = alokasi(r1);
            address_parent Q = first(L);
            address_parent Prec = first(L);

            if ((first(L) == NULL) || (info(P).ID < info(Q).ID))
            {
                insertFirst(L,P);
            }
            else
            {
                Q = next(Q);
                while ((info(P).ID > info(Q).ID) && (Q != first(L)))
                {
                    Q = next(Q);
                    Prec = next(Prec);
                }
                insertAfter(Prec,P);
            }
            cout << "\n   Rak Telah Ditambahkan" << endl;
        }
        else
        {
            cout << "\n   ID sudah digunakan" << endl;
        }
    }
    cout << "===============================================" << endl;
}

void searchDelete(List_parent &L, infotype_parent &x)
{
    address_parent P = findElm(L,x);
    if (P != NULL)
    {
        if (P == first(L))
        {
            deleteFirst(L,P);
        }
        else
        {
            address_parent Prec = first(L);
            while (next(Prec) != P)
            {
                Prec = next(Prec);
            }
            deleteAfter(Prec,P);
        }
        dealokasi(P);
        cout << "\n   Rak Telah Dihapus" <<endl;
    }
    else
    {
        cout << "\n   Rak Tidak Ditemukan" << endl;
    }
}

void searchEdit(List_parent &L)
{
    rak r1;
    cout << "\nEDIT DETAIL RAK" << endl;
    cout << "===============================================" << endl;
    cout<<"   Masukkan ID Rak yang ingin dirubah : ";
    cin>>r1.ID;
    address_parent P = findElm(L,r1);
    if (P != NULL)
    {
        cout<<"\n   Masukkan Data Rak  : "<<endl;
        cout<<"   Jenis Buku   : ";
        cin>>info(P).jenisBuku;
        cout<<"   Jumlah Baris : ";
        cin>>info(P).jumlahBaris;
        cout <<"   Kapasitas    : ";
        cin >> info(P).kapasitas;
        cout <<"   Lokasi       : ";
        cin >> info(P).lokasi;
        cout<<"   Nama Rak     : ";
        cin>>info(P).namaRak;
        cout << "\n   Detail Rak Telah Dirubah" << endl;
    }
    else
    {
        cout << "\n   Rak Tidak Ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

void sortKapasitas(List_parent &L)
{
    List_parent LP;
    createList(LP);
    address_parent R = first(L);

    do
    {
        address_parent Q = first(LP);
        address_parent Prec = first(LP);

        rak r1;
        r1.ID = info(R).ID;
        r1.jenisBuku = info(R).jenisBuku;
        r1.jumlahBaris = info(R).jumlahBaris;
        r1.kapasitas = info(R).kapasitas;
        r1.lokasi = info(R).lokasi;
        r1.namaRak = info(R).namaRak;

        address_parent P = alokasi(r1);

        if ((first(LP) == NULL) || (info(P).kapasitas <= info(Q).kapasitas))
        {
            insertFirst(LP,P);
        }
        else
        {
            Q = next(Q);
            while ((Q != first(LP)) && (info(P).kapasitas >= info(Q).kapasitas))
            {
                Q = next(Q);
                Prec = next(Prec);
            }
            if (next(Prec) != first(LP))
            {
                insertAfter(Prec,P);
            }
            else
            {
                insertLast(LP,P);
            }
        }
        R = next(R);
    }
    while (R != first(L));
    printInfo(LP);
}


void jumlahRak(List_parent L)
{
    address_parent P = first(L);
    cout << "\nJUMLAH RAK" << endl;
    cout << "===============================================" << endl;
    int a = 1;
    cout<<"   Jumlah Semua Rak : ";
    do
    {
        a++;
        P = next(P);
    }
    while(next(P) != first(L));
    cout<<a<<endl;
    cout << "===============================================" << endl;
}

void TotalKapasitas(List_parent L)
{
    address_parent P = first(L);
    cout << "\nTOTAL KAPASITAS RAK" << endl;
    cout << "===============================================" << endl;
    int a = 0;
    cout<<"   Total Kapasitas Rak : ";
    do
    {
        a = a + info(P).kapasitas;
        P = next(P);
    }
    while(next(P) != first(L));
    cout<<a<<endl;
    cout << "===============================================" << endl;
}

bool isFull(List_parent L)
{
    int i = 0;
    address_parent P = first(L);
    do
    {
        i++;
        P = next(P);
    }
    while (P != first(L));

    if (i == 5)
    {
        return true;
    }
    return false;
}
