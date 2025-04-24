# Dokumentasi Program File System Manager

## Pendahuluan

Program ini adalah implementasi sederhana dari sistem manajemen file berbasis teks. Program ini memungkinkan pengguna untuk membuat file, menambahkan konten ke file, membaca konten file, dan melihat daftar file dalam sebuah direktori. Program ini ditulis dalam **C++**, sehingga cocok untuk Anda yang sedang transisi dari **C ke C++**.

## Struktur Program

Program ini terdiri dari beberapa file utama:

1. **File.hpp** dan **File.cpp**: Mengelola representasi file, termasuk nama dan kontennya.
2. **Directory.hpp** dan **Directory.cpp**: Mengelola direktori yang berisi kumpulan file.
3. **FileSystemManager.hpp** dan **FileSystemManager.cpp**: Mengelola logika utama program, termasuk perintah seperti `touch`, `echo`, `cat`, dan `ls`.
4. **Main.cpp**: Titik masuk utama program.

### Diagram Kelas

Berikut adalah hubungan antar kelas dalam program:

`Main.cpp -> FileSystemManager -> Directory -> File`

## Fitur Program
Program ini mendukung beberapa perintah:
1. **touch `<nama_file>`**: Membuat file baru dengan nama tertentu.
2. **echo `<konten>` `>` `<nama_file>`**: Menulis konten baru ke file (mengganti konten lama).
3. **echo `<konten>` `>>` `<nama_file>`**: Menambahkan konten baru ke file (tanpa menghapus konten lama).
4. **cat `<nama_file>`**: Menampilkan konten file.
5. **ls**: Menampilkan daftar file dalam direktori.
6. **exit**: Keluar dari program.

## Penjelasan Teknis
### Perbedaan C dan C++ yang Digunakan
1. **Kelas dan Objek**: Program ini menggunakan **kelas** untuk merepresentasikan file dan direktori. Ini adalah fitur utama C++ yang tidak ada di C.
   - Contoh: `class File` digunakan untuk menyimpan nama dan konten file.
2. **STL (Standard Template Library)**: Program ini menggunakan **std::vector** untuk menyimpan daftar file dalam direktori. Ini menggantikan array statis di C.
   - Contoh: `vector<File> files` di kelas `Directory`.
3. **Fungsi Anggota**: Fungsi seperti `getName()` dan `setContent()` adalah fungsi anggota yang terkait langsung dengan objek.
4. **Namespace**: Program menggunakan `std` namespace untuk menghindari penulisan `std::` berulang kali.

### Penjelasan Kelas
#### 1. Kelas `File`
- **Tugas**: Merepresentasikan sebuah file.
- **Atribut**:
  - `name`: Nama file.
  - `content`: Konten file.
- **Fungsi**:
  - `getName()`: Mengembalikan nama file.
  - `getContent()`: Mengembalikan konten file.
  - `setContent(newContent)`: Mengganti konten file.
  - `appendContent(extraContent)`: Menambahkan konten baru ke file.

#### 2. Kelas `Directory`
- **Tugas**: Merepresentasikan direktori yang berisi kumpulan file.
- **Atribut**:
  - `name`: Nama direktori.
  - `files`: Daftar file dalam direktori.
- **Fungsi**:
  - `addFile(fileName)`: Menambahkan file baru ke direktori.
  - `getFiles()`: Mengembalikan referensi ke daftar file.
  - `getName()`: Mengembalikan nama direktori.

#### 3. Kelas `FileSystemManager`
- **Tugas**: Mengelola logika utama program.
- **Atribut**:
  - `directory`: Direktori yang sedang dikelola.
- **Fungsi**:
  - `touch(name)`: Membuat file baru.
  - `echo(content, name, mode)`: Menulis atau menambahkan konten ke file.
  - `cat(name)`: Menampilkan konten file.
  - `ls()`: Menampilkan daftar file.
  - `run()`: Menjalankan loop utama untuk menerima perintah dari pengguna.

### Alur Program
1. Program dimulai dari `Main.cpp`.
2. Sebuah direktori bernama "root" dibuat.
3. Objek `FileSystemManager` dibuat untuk mengelola direktori tersebut.
4. Fungsi `run()` dipanggil untuk menerima input dari pengguna.
5. Pengguna dapat memasukkan perintah seperti `touch`, `echo`, `cat`, `ls`, atau `exit`.

## Cara Menggunakan Program
1. **Kompilasi Program**:
   Gunakan perintah berikut untuk mengompilasi program:
   ```bash
   g++ -std=c++17 -Wall -Wextra -Wpedantic -o program Main.cpp FileSystemManager.cpp Directory.cpp File.cpp
