#ifndef KELAS_H
#define KELAS_H

#include <string>
#include "Dosen.h"
using namespace std;

class Kelas
{
private:
    string namaKelas;
    float nilai;
    int sks;
    Dosen dosen;

public:
    Kelas(string namaKelas, float nilai, int sks, Dosen dosen);
    void showDetail();
    float getNilai();
    int getSKS();
    void setNilai(float nilai);
    void setSKS(int sks);
    void setNamaKelas(string namaKelas);
};

#endif
