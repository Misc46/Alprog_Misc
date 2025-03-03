#include <stdio.h>
#include <string.h>
#define MAX_MAHASISWA 100

// Struct AkademikInfo
typedef struct
{
    int semester;
    float ipk;
    char jurusan[50];
} AkademikInfo;

// Struct PersonalInfo
typedef struct
{
    char nama[50];
    char npm[20];
    char alamat[100];
} PersonalInfo;

// Struct Mahasiswa (Nested Structs)
typedef struct
{
    PersonalInfo personal;
    AkademikInfo akademik;
    char kesibukan[100];
} Mahasiswa;

Mahasiswa database[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void addMahasiswa()
{
    if (jumlahMahasiswa >= MAX_MAHASISWA)
    {
        printf("Database penuh! Tidak dapat menambahkan mahasiswa baru.\n");
        return;
    }

    printf("\nAdd Mahasiswa\n---------------\nData Personal:\n");
    Mahasiswa *m = &database[jumlahMahasiswa];
    printf("Nama : ");
    fgets(m->personal.nama, 50, stdin);
    m->personal.nama[strcspn(m->personal.nama, "\n")] = 0;
    printf("NPM : ");
    fgets(m->personal.npm, 20, stdin);
    m->personal.npm[strcspn(m->personal.npm, "\n")] = 0;
    printf("Alamat : ");
    fgets(m->personal.alamat, 100, stdin);
    m->personal.alamat[strcspn(m->personal.alamat, "\n")] = 0;
    printf("Jurusan : ");
    fgets(m->akademik.jurusan, 50, stdin);
    m->akademik.jurusan[strcspn(m->akademik.jurusan, "\n")] = 0;
    printf("Semester : ");
    scanf("%d", &m->akademik.semester);
    printf("IPK : ");
    scanf("%f", &m->akademik.ipk);
    getchar();
    printf("Kesibukan : ");
    fgets(m->kesibukan, 100, stdin);
    m->kesibukan[strcspn(m->kesibukan, "\n")] = 0;

    jumlahMahasiswa++;
    printf("Mahasiswa ditambahkan!\n\n");
}

void showMahasiswa()
{
    printf("\nList Mahasiswa\n---------------\n");
    if (jumlahMahasiswa == 0)
    {
        printf("\n");
        return;
    }
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        printf("%d. %s - %s\n", i + 1, database[i].personal.nama, database[i].personal.npm);
        printf("Alamat: %s\nJurusan: %s\nSemester %d\nIPK %.2f\nKesibukan: %s\n\n",
               database[i].personal.alamat,
               database[i].akademik.jurusan,
               database[i].akademik.semester,
               database[i].akademik.ipk,
               database[i].kesibukan);
    }
}

void showMenu()
{
    printf("Database Kuliah\n---------------\n");
    printf("1. Show Mahasiswa\n2. Mahasiswa Baru\n3. Exit\n\n");
}

int main()
{
    int pilihan;
    while (1)
    {
        showMenu();
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 1)
        {
            showMahasiswa();
        }
        else if (pilihan == 2)
        {
            addMahasiswa();
        }
        else if (pilihan == 3)
        {
            printf("Program selesai!\n");
            break;
        }
    }
    return 0;
}