#include <iostream>
#include <iomanip>
#include <string>
#include "Dosen.h"
#include "Kelas.h"
#include "Mahasiswa.h"
#include "Jurusan.h"

using namespace std;

// Implementation of Dosen class
Dosen::Dosen(string name, int id)
{
    this->name = name;
    this->id = id;
}

string Dosen::getName()
{
    return name;
}

void Dosen::setName(string name)
{
    this->name = name;
}

void Dosen::setId(int id)
{
    this->id = id;
}

// Implementation of Kelas class
Kelas::Kelas(string namaKelas, float nilai, int sks, Dosen dosen)
    : dosen(dosen)
{
    this->namaKelas = namaKelas;
    this->nilai = nilai;
    this->sks = sks;
}

void Kelas::showDetail()
{
    cout << "Kelas: " << namaKelas
         << ", Nilai: " << nilai
         << ", SKS: " << sks
         << ", Dosen: " << dosen.getName() << endl;
}

float Kelas::getNilai()
{
    return nilai;
}

int Kelas::getSKS()
{
    return sks;
}

void Kelas::setNilai(float nilai)
{
    this->nilai = nilai;
}

void Kelas::setSKS(int sks)
{
    this->sks = sks;
}

void Kelas::setNamaKelas(string namaKelas)
{
    this->namaKelas = namaKelas;
}

// Implementation of Mahasiswa class
Mahasiswa::Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan)
    : alprog(alprog), sisben(sisben), matdis(matdis), fislis(fislis)
{
    this->nama = nama;
    this->id = id;
    this->jurusan = jurusan;
}

float Mahasiswa::getIPK()
{
    float totalNilai =
        alprog.getNilai() * alprog.getSKS() +
        sisben.getNilai() * sisben.getSKS() +
        matdis.getNilai() * matdis.getSKS() +
        fislis.getNilai() * fislis.getSKS();
    int totalSKS =
        alprog.getSKS() + sisben.getSKS() + matdis.getSKS() + fislis.getSKS();
    return totalNilai / totalSKS;
}

void Mahasiswa::showDetail()
{
    cout << "Nama: " << nama << ", ID: " << id << ", Jurusan: ";
    switch (jurusan)
    {
    case ELEKTRO:
        cout << "Teknik Elektro";
        break;
    case BIOMEDIK:
        cout << "Teknik Biomedik";
        break;
    case KOMPUTER:
        cout << "Teknik Komputer";
        break;
    }
    cout << endl;

    alprog.showDetail();
    sisben.showDetail();
    matdis.showDetail();
    fislis.showDetail();

    cout << fixed << setprecision(2);
    cout << "IPK: " << getIPK() << endl;
}

// Main function
int main()
{
    Dosen dosenAlpro("Mr. Budi", 10);
    Dosen dosenSisben("Mr. Thomas", 11);
    Dosen dosenMatdis("Ms. Puff", 12);
    Dosen dosenFislis("Ms. Sandy", 13);

    Kelas alprog("Alpro", 3.8, 3, dosenAlpro);
    Kelas sisben("Sisben", 3.5, 3, dosenSisben);
    Kelas matdis("Matdis", 4.0, 3, dosenMatdis);
    Kelas fislis("Fislis", 3.6, 2, dosenFislis);

    Mahasiswa mhs("Burhan", 12345, alprog, sisben, matdis, fislis, ELEKTRO);

    mhs.showDetail();

    return 0;
}