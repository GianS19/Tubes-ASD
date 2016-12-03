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

void connect(List_parent LP, List_child &LC)
{
    buku b1;
    rak r1;
    cout << "\nMASUKKAN BUKU KE RAK" << endl;
    cout << "===============================================" << endl;
    cout << "   Pilih Buku : ";
    cin >>b1.id;
    address_child C = findElm(LC,b1);
    if (C == NULL)
    {
        cout << "\n   Buku Tidak Ditemukan" << endl;
    }
    else
    {
        cout << "   Pilih Rak  : ";
        cin >> r1.ID;
        address_parent P = findElm(LP,r1);
        if (P == NULL)
        {
            cout << "\n   Rak Tidak Ditemukan" << endl;
        }
        else
        {
            parent(C) = P;
            cout << "\n   Buku Telah Dimasukkan ke dalam Rak" << endl;
        }
    }
    cout << "===============================================" << endl;
}

void disconnect(List_child &L)
{
    buku b1;
    cout << "   Pilih Buku : ";
    cin >>b1.id;
    address_child C = findElm(L,b1);
    parent(C) = NULL;
}

void menuRak(List_parent &LP, List_child &LC)
{
    string pilihan2;
    do
    {
        pilihan2 = "0";
        cout << "+=============================================+" << endl
             << "|                  MENU RAK                   |" << endl
             << "+=============================================+" << endl
             << "| 1.  Cari Rak                                |" << endl
             << "| 2.  Tambah Rak                              |" << endl
             << "| 3.  Ubah Detail Rak                         |" << endl
             << "| 4.  Hapus Rak                               |" << endl
             << "| 5.  Kosongkan Rak                           |" << endl
             << "| 6.  Jumlah Rak                              |" << endl
             << "| 7.  Total Kapasitas Rak                     |" << endl
             << "| 8.  Tampilkan Rak                           |" << endl
             << "| 9.  Tampilkan Seluruh Rak dan Buku          |" << endl
             << "| 10. Tampilkan Rak Berdasarkan Kapasitas     |" << endl
             << "| 11. Kembali                                 |" << endl
             << "+=============================================+" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan2;
        if (pilihan2 == "1")
        {
            searchView(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "2")
        {
            insertData(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "3")
        {
            searchEdit(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "4")
        {
            hapusParent(LP, LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "5")
        {
            kosongkanRak(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "6")
        {
            jumlahRak(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "7")
        {
            TotalKapasitas(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "8")
        {
            printInfo(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "9")
        {
            viewAll(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "10")
        {
            sortKapasitas(LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "11")
        {
            system("cls");
        }
        else
        {
            cout << "Input Salah" << endl << endl;
            system("pause");
            system("cls");
        }
    }
    while (pilihan2 != "11");
}

void menuBuku(List_parent &LP, List_child &LC)
{
    string pilihan2;
    do
    {
        pilihan2 = "0";
        cout << "+=============================================+" << endl
             << "|                  MENU BUKU                  |" << endl
             << "+=============================================+" << endl
             << "| 1.  Cari Buku                               |" << endl
             << "| 2.  Tambah Buku                             |" << endl
             << "| 3.  Ubah Detail Buku                        |" << endl
             << "| 4.  Hapus Buku                              |" << endl
             << "| 5.  Masukkan Buku ke Rak                    |" << endl
             << "| 6.  Tampung Buku ke Rak                     |" << endl
             << "| 7.  Jumlah Buku                             |" << endl
             << "| 8.  Jumlah Buku dalam Suatu Rak             |" << endl
             << "| 9.  Tampilkan Buku                          |" << endl
             << "| 10. Tampilkan Buku Berdasarkan Harga        |" << endl
             << "| 11. Tampilkan Seluruh Rak dan Buku          |" << endl
             << "| 12. Harga Buku Termahal                     |" << endl
             << "| 13. Harga Rata-rata Buku                    |" << endl
             << "| 14. Kembali                                 |" << endl
             << "+=============================================+" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan2;
        if (pilihan2 == "1")
        {
            searchView(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "2")
        {
            insertData(LC,LP);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "3")
        {
            searchEdit(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "4")
        {
            searchDelete(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "5")
        {
            connect(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "6")
        {
            tampungBuku(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "7")
        {
            jumlahBuku(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "8")
        {
            jumlahBukuDalamRak(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "9")
        {
            printInfo(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "10")
        {
            sortHarga(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "11")
        {
            viewAll(LP,LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "12")
        {
            maxHarga(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "13")
        {
            rataBuku(LC);
            system("pause");
            system("cls");
        }
        else if (pilihan2 == "14")
        {
            system("cls");
        }
        else
        {
            cout << "Input Salah" << endl << endl;
            system("pause");
            system("cls");
        }
    }
    while (pilihan2 != "14");
}

void menuUtama(List_parent &LP, List_child &LC)
{
    string pilihan = "0";
    while (pilihan != "3")
    {
        cout << "+=============================================+" << endl
             << "|                 MENU UTAMA                  |" << endl
             << "+=============================================+" << endl
             << "| 1.  Menu Rak                                |" << endl
             << "| 2.  Menu Buku                               |" << endl
             << "| 3.  Keluar                                  |" << endl
             << "+=============================================+" << endl;

        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        if (pilihan == "1")
        {
            system("cls");
            menuRak(LP,LC);
        }
        else if (pilihan == "2")
        {
            system("cls");
            menuBuku(LP,LC);
        }
        else if (pilihan == "3")
        {
            cout << "+=============================================+" << endl
                 << "|                TERIMA KASIH                 |" << endl
                 << "|                     BY                      |" << endl
                 << "|            SUGIANTO && RIDHWAN              |" << endl
                 << "|           101154407 && 1301150057           |" << endl
                 << "+=============================================+" << endl;
        }
        else
        {
            cout << "Input Salah" << endl << endl;
            system("pause");
            system("cls");
        }


    }
}

void inisialisasi(List_parent &LP, List_child &LC)
{
    address_child C;
    address_parent P;
    rak r1;
    buku b1;

    r1.ID = 4407;
    r1.jenisBuku = "Komputer";
    r1.jumlahBaris = 5;
    r1.kapasitas = 200;
    r1.lokasi = "Selatan";
    r1.namaRak = "GraKom";

    P = alokasi(r1);
    insertLast(LP, P);

    b1.id = 368;
    b1.judul= "Praktikum ASD";
    b1.pengarang = "Jeck";
    b1.penerbit = "Yudhistira";
    b1.tahun_terbit = 2015;
    b1.harga = 99000;

    C = alokasi(b1);
    parent(C) = P;
    insertLast(LC, C);

    r1.ID = 5057;
    r1.jenisBuku = "Religi";
    r1.jumlahBaris = 4;
    r1.kapasitas = 150;
    r1.lokasi = "Utara";
    r1.namaRak = "GraLigi";

    P = alokasi(r1);
    insertLast(LP, P);

    b1.id = 357;
    b1.judul= "Zikir Akhir Zaman";
    b1.pengarang = "M. Iqbal";
    b1.penerbit = "Erlangga";
    b1.tahun_terbit = 2017;
    b1.harga = 45000;

    C = alokasi(b1);
    parent(C) = P;
    insertFirst(LC, C);

    r1.ID = 6607;
    r1.jenisBuku = "Komik";
    r1.jumlahBaris = 6;
    r1.kapasitas = 300;
    r1.lokasi = "Timur";
    r1.namaRak = "GraMik";

    P = alokasi(r1);
    insertLast(LP, P);

    b1.id = 407;
    b1.judul= "Naruto ShippUdin Vol 57";
    b1.pengarang = "Masashi Kishimoto";
    b1.penerbit = "Shounen Jump";
    b1.tahun_terbit = 2016;
    b1.harga = 25000;

    C = alokasi(b1);
    parent(C)= P;
    insertLast(LC, C);

    r1.ID = 7077;
    r1.jenisBuku = "Sejarah";
    r1.jumlahBaris = 7;
    r1.kapasitas = 250;
    r1.lokasi = "Barat";
    r1.namaRak = "GraHis";

    P = alokasi(r1);
    insertLast(LP, P);

    b1.id = 458;
    b1.judul= "Ensiklopedia Dinosaururs";
    b1.pengarang = "M. Evan";
    b1.penerbit = "Zahis";
    b1.tahun_terbit = 2015;
    b1.harga = 85000;

    C = alokasi(b1);
    parent(C) = P;
    insertLast(LC, C);

    b1.id = 505;
    b1.judul= "WanPis Vol 77";
    b1.pengarang = "Eiichiro Oda";
    b1.penerbit = "Shounen Jump";
    b1.tahun_terbit = 2016;
    b1.harga = 25000;

    C = alokasi(b1);
    insertLast(LC, C);
}



