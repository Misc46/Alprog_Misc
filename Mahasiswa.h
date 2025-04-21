#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
#include "Jurusan.h"
#include "Kelas.h"
using namespace std;

class Mahasiswa
{
private:
    string nama;
    int id;
    Kelas alprog, sisben, matdis, fislis;
    Jurusan jurusan;

public:
    Mahasiswa(string nama, int id, Kelas alprog, Kelas sisben, Kelas matdis, Kelas fislis, Jurusan jurusan);
    float getIPK();
    void showDetail();
};

#endif
