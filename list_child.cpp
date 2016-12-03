#include "list_child.h"

void createList(List_child &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x)
{
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    parent(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P)
{

    if(first(L) == NULL)
    {
        last(L)  = P;
        first(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void printInfo(List_child L)
{
    address_child P = first(L);
    cout << "\nTAMPIL BUKU" << endl;
    cout << "===============================================" << endl;
    if (first(L) != NULL)
    {
        while(P != NULL)
        {
            cout<<"\n   ID     : "<<info(P).id<<endl;
            cout<<"   Judul  : "<<info(P).judul<<endl;
            cout<<"   Harga  : "<<info(P).harga<<endl;
            if(parent(P) != NULL)
            {
                cout<<"   Di Rak : "<<info(parent(P)).ID<<endl;
            }
            else if (parent(P) == NULL)
            {
                cout<<"   ! Belum Punya Rak !"<<endl;
            }
            P = next(P);
        }
        cout << "===============================================" << endl;
    }
    else
    {
        cout << "Tidak Ada Buku yag Tersedia" << endl;
    }
}

void dealokasi(address_child &P)
{
    delete P;
}

void jumlahBuku(List_child L)
{
    address_child P = first(L);
    int a = 0;
    cout << "\nJUMLAH BUKU" << endl;
    cout << "===============================================" << endl;
    cout<<"   Jumlah Semua Buku : ";
    while(P != NULL)
    {
        a++;
        P = next(P);
    }
    cout<<a<<endl;
    cout << "===============================================" << endl;
}

void rataBuku(List_child L)
{
    address_child P = first(L);
    double harga = 0;
    int c = 0;
    cout << "\nHARGA RATA-RATA" << endl;
    cout << "===============================================" << endl;
    while (P != NULL)
    {
        harga = harga + info(P).harga;
        c++;
        P = next(P);
    }
    cout<<"   Rata-rata Harga :";
    cout<<(harga/c)<<endl;
    cout << "===============================================" << endl;
}

void maxHarga(List_child L)
{
    address_child P = first(L);
    address_child Q = next(first(L));
    cout << "\nBUKU TERMAHAL" << endl;
    cout << "===============================================" << endl;
    int hMax = 0;
    do
    {
        if (info(P).harga > info(Q).harga)
        {
            if (info(P).harga > hMax)
            {
                hMax = info(P).harga;
            }
        }
        else
        {

            if (info(Q).harga > hMax)
            {
                hMax = info(Q).harga;
            }
        }
        P = next(P);
        Q = next(Q);
    }
    while (Q != NULL);
    cout<<"   Harga Maksimum : "<<hMax<<endl;
    cout << "===============================================" << endl;
}

void jumlahBukuDalamRak(List_parent LP, List_child L)
{
    rak r1;
    int count = 0;
    cout << "\nJUMLAH BUKU DALAM RAK" << endl;
    cout << "===============================================" << endl;
    cout<<"   Pilih Rak(ID) : ";
    cin>>r1.ID;
    address_parent P = findElm(LP, r1);
    if (P == NULL)
    {
        cout<<"\n   Rak "<<r1.ID<<" Tidak Ada"<<endl;
    }
    else
    {
        address_child C = first(L);
        if(C == NULL)
        {
            cout<<"\n   Tidak Ada Buku"<<endl;
        }
        else
        {
            while(C != NULL)
            {
                if (parent(C) != NULL)
                {
                    if (info(parent(C)).ID == r1.ID)
                    {
                        count++;
                    }
                }
                C = next(C);
            }
            cout<<"\n   Jumlah Buku : "<<count<<endl;
        }
    }
    cout << "===============================================" << endl;
}

void searchEdit(List_child &L)
{
    buku b1;
    cout << "\nEDIT DETAIL BUKU" << endl;
    cout << "===============================================" << endl;
    cout<<"   Masukkan ID Buku yang ingin dirubah : ";
    cin >> b1.id;
    address_child P = findElm(L,b1);
    if (P != NULL)
    {
        cout<<"\n   Masukkan Data Buku : "<<endl;
        cout << "   Judul        : ";
        cin>>info(P).judul;
        cout << "   Pengarang    : ";
        cin>>info(P).pengarang;
        cout << "   Penerbit     : ";
        cin >> info(P).penerbit;
        cout << "   Tahun Terbit : ";
        cin >> info(P).tahun_terbit;
        cout << "   Harga        : ";
        cin>>info(P).harga;
        cout << "\n   Detail Buku Telah Dirubah" <<endl;
    }
    else
    {
        cout << "\n   Buku Tidak Ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

void sortHarga(List_child &L)
{
    List_child LC;
    createList(LC);
    address_child R = first(L);

    while (R != NULL)
    {
        address_child Q = first(LC);
        address_child Prec = first(LC);

        buku b1;
        b1.harga = info(R).harga;
        b1.id = info(R).id;
        b1.judul = info(R).judul;
        b1.penerbit = info(R).penerbit;
        b1.pengarang = info(R).pengarang;
        b1.tahun_terbit = info(R).tahun_terbit;

        address_child P = alokasi(b1);
        parent(P) = parent(R);

        if ((first(LC) == NULL) || (info(P).harga <= info(Q).harga))
        {
            insertFirst(LC,P);
        }
        else
        {
            Q = next(Q);
            while ((Q != NULL) && (info(P).harga >= info(Q).harga))
            {
                Q = next(Q);
                Prec = next(Prec);
            }
            if (next(Prec) != NULL)
            {
                insertAfter(Prec,P);
            }
            else
            {
                insertLast(LC,P);
            }
        }
        R = next(R);
    }
    printInfo(LC);
}

address_child findElm(List_child L, infotype_child x)
{
    address_child P = first(L);
    while(P != NULL)
    {
        if(info(P).id == x.id)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}



void insertData(List_child &L, List_parent LP)
{
    buku b1;
    rak r1;
    cout << "\nTAMBAH BUKU" << endl;
    cout << "===============================================" << endl;
    cout << "   ID             : ";
    cin >> b1.id;

    address_child R = findElm(L,b1);
    if (R == NULL)
    {
        cout << "   Judul          : ";
        cin >> b1.judul;
        cout << "   Nama Pengarang : ";
        cin >> b1.pengarang;
        cout << "   Nama Penerbit  : ";
        cin >> b1.penerbit;
        cout << "   Harga Buku     : ";
        cin >> b1.harga;
        cout << "   Tahun Terbit   : ";
        cin >> b1.tahun_terbit;
        cout << "   Pilih Rak      : ";
        cin >> r1.ID;

        address_child P = alokasi(b1);
        address_child Q = first(L);
        address_child Prec = first(L);
        address_parent T = findElm(LP,r1);
        if (T != NULL)
        {
            parent(P) = T;
        }
        else
        {
            cout << "   Rak tidak ditemukan" << endl;
        }

        if ((first(L) == NULL) || (info(P).id < info(Q).id))
        {
            insertFirst(L,P);
        }
        else
        {
            Q = next(Q);
            while (Q != NULL)
            {
                if (info(P).id > info(Q).id)
                {
                    Prec = next(Prec);
                }
                Q = next(Q);
            }
            if (next(Prec) != NULL)
            {
                insertAfter(Prec,P);
            }
            else
            {
                insertLast(L,P);
            }
        }
        cout << "\n   Buku Telah Ditambahkan" << endl;
    }
    else
    {
        cout << "\n   ID Sudah Digunakan" << endl;
    }
    cout << "===============================================" << endl;
}

void searchView(List_child L)
{
    buku b1;
    cout << "\nCARI BUKU" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID : ";
    cin >> b1.id;
    address_child P = findElm(L,b1);
    if (P != NULL)
    {
        cout<<"\n   ID           : " << info(P).id<<endl;
        cout<<"   Judul Buku   : " << info(P).judul<<endl;
        cout<<"   Pengarang    : " << info(P).pengarang<<endl;
        cout<<"   Penerbit     : " << info(P).penerbit<<endl;
        cout<<"   Harga Buku   : " << info(P).harga<<endl;
        cout<<"   Tahun Terbit : " << info(P).tahun_terbit<<endl;
        if (parent(P) != NULL)
        {
            cout<<"\n   Posisi Rak   : " << info(parent(P)).ID<<endl;
        }
    }
    else
    {
        cout << "\n   Buku tidak ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

void searchDelete(List_child &L)
{
    buku b1;
    cout << "\nHAPUS BUKU" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID : ";
    cin >> b1.id;
    address_child P = findElm(L,b1);
    if (P != NULL)
    {
        if (P == first(L))
        {
            deleteFirst(L,P);
        }
        else if (P == last(L))
        {
            deleteLast(L,P);
        }
        else
        {
            address_child Prec = first(L);
            while (next(Prec) != P)
            {
                Prec = next(Prec);
            }
            deleteAfter(Prec,P);
        }
        dealokasi(P);
        cout << "\n   Buku Telah Dihapus" << endl;

    }
    else
    {
        cout << "\n   Buku tidak ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

void deleteAfter(address_child Prec, address_child &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void hapusParent(List_parent &LP, List_child LC)
{
    rak r1;
    cout <<"\nHAPUS RAK" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID : ";
    cin >> r1.ID;

    bool hapus = true;
    address_child S = first(LC);
    while(S !=NULL)
    {
        if (parent(S) != NULL)
        {
            if(info(parent(S)).ID == r1.ID)
            {
                hapus = false;
            }
        }
        S = next(S);
    }


    if(hapus)
    {
        searchDelete(LP,r1);
    }
    else
    {
        cout << "\n   Rak Tersebut Masih Memiliki Buku" << endl;
        cout << "   Gagal Menghapus Rak" << endl;
    }
    cout << "===============================================" << endl;


}

void viewAll (List_parent LP,List_child LC)
{
    address_parent P = first(LP);
    cout << "\nTAMPIL SEMUA" << endl;
    cout << "===============================================" << endl;
    if (P != NULL)
    {
        do
        {
            int i = 1;
            cout<<"\n   ID           : " << info(P).ID<<endl;
            cout<<"   Jenis Buku   : " << info(P).jenisBuku<< endl;
            address_child Q = first(LC);
            while (Q != NULL)
            {
                if (parent(Q) != NULL)
                {
                    if (info(parent(Q)).ID == info(P).ID)
                    {

                        cout << "   - - - - - - - - - - - - - - - - - - -" << endl;
                        cout << "      Buku " << i << " : " << endl;
                        cout << "      ID     : " << info(Q).id << endl;
                        cout << "      Judul  : " << info(Q).judul << endl;
                        i++;
                    }

                }
                Q = next(Q);
            }
            P = next(P);
            cout << "   +++++++++++++++++++++++++++++++++++++" << endl;
        }
        while((P)!= first(LP));
    }
    cout << "===============================================" << endl;
}

void deleteFirst(List_child &L, address_child &P)
{
    P = first(L);
    if (first(L) != last(L))
    {
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
    else
    {
        first(L) = NULL;
        last(L) = NULL;
    }
}

void insertAfter(address_child Prec, address_child P)
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void deleteLast(List_child &L, address_child &P)
{
    P = last(L);
    if (first(L) != last(L))
    {
        last(L) = prev(P);
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
    else
    {
        first(L) = NULL;
        last(L) = NULL;
    }
}

void kosongkanRak(List_parent &LP, List_child &LC)
{
    rak r1;
    cout << "\nKOSONGKAN RAK" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID : ";
    cin >> r1.ID;
    address_parent P = findElm(LP,r1);
    if (P != NULL)
    {
        address_child C = first(LC);
        while (C != NULL)
        {
            if (parent(C) != NULL)
            {
                if (info(parent(C)).ID == info(P).ID)
                {
                    parent(C) = NULL;
                }
            }
            C = next(C);
        }
        cout << "\n   Rak telah dikosongkan" << endl;
    }
    else
    {
        cout << "\n   Rak tidak ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}

void tampungBuku(List_parent &LP, List_child &LC)
{
    rak r1;
    cout << "\nTAMPUNG BUKU" << endl;
    cout << "===============================================" << endl;
    cout << "   Masukkan ID Rak : ";
    cin >> r1.ID;
    address_parent P = findElm(LP,r1);
    if (P != NULL)
    {
        address_child C = first(LC);
        while (C != NULL)
        {
            if (parent(C) == NULL)
            {
                parent(C) = P;
            }
            C = next(C);
        }
        cout << "\n   Seluruh Buku telah ditampung" << endl;
    }
    else
    {
        cout << "\n   Rak tidak ditemukan" << endl;
    }
    cout << "===============================================" << endl;
}
