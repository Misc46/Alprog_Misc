# Case Study - Socket Programming
> Pembuat Soal: NS
```
Nama  : [Till]
NPM   : [0791348265]
```
---

#### Pengantar

Pada hari ini, anda ditugaskan untuk membuat sebuah sistem sederhana berbasis client-server. Server akan memproses permintaan dari client berdasarkan request yang dikirimkan oleh client ke server. Pada case study kali ini, kalian berusaha untuk mensimulasikan sebuah dns server sederhana dengan fitur tambahan untuk mematikan server.

#### Kriteria program
- Server
  - Server akan membuat sebuah directory dengan nama `system` dan membaca sejumlah file yang ada di dalam directory tersebut
  - Server akan membuka socket untuk menerima request dari client
  - Format request yang valid dari client adalah `NSLOOKUP [argument]`
  - Jika bentuk request valid, maka server akan mengirimkan teks dari sesuai permintaan yang dikirim.
  - Pada request `NSLOOKUP`, apabila domain dengan nama `[argument]` ditemukan, maka server akan mengirimkan ip address dari domain tersebut
  - Pada request `NSLOOKUP`, apabila ip address `[argument]` ditemukan, maka server akan mengirimkan nama domain dari host dengan ip address tersebut
  - Pada request `shutdown`, server akan menutup koneksi dan mengirimkan pesan konfirmasi bahwa request berhasil dijalankan
- Client
  - Client akan terhubung dengan server
  - Client meminta input ke user, lalu mengirimkannya request tersebut ke server
  - Client menampilkan hasil dari request yang dilakukan ke server dengan format :
    - Case `NSLOOKUP`:
      - Case `[argument]` ditemukan sebagai domain:
        ```
        Domain [argument] found!! Ip Address: [Ip adress dari domain tersebut]
        ```
      - Case `[argument]` ditemukan sebagai ip address:
        ```
        Host [argument] found!! Nameserver: [Nameserver dari host tersebut]
        ```
      - Case tidak ditemukan:
        ```
        [argument] is not found...
        ```
      **Note** : [ext] akan diganti sesuai extension yang diminta oleh client
    - Case `SHUTDOWN`:
        ```
        Server shutdowned...
        ```
#### Contoh run program

- video
    **KLIK GAMBARNYA**
    [![Thumbnail](https://cdn.digilabdte.com/u/PO0JIx.png)](https://youtu.be/NxAv3a_ILLU)

- Test case:
  - Case 1:
    Input client: `nslookup google.com`
    Output client:
    ```
    Domain [google.com] found!! Ip Address: 192.168.56.2
    ```
    Terminal:
    ![Case 1](http://cdn.digilabdte.com/u/TzzSsP.png)
  - Case 2:
    Input client: `nslookup 172.20.0.7`
    Output client:
    ```
    Host [172.20.0.7] found!! Nameserver: microsoft.com
    ```
    Terminal:
    ![Case 2](http://cdn.digilabdte.com/u/k2pDLK.png)
  - Case 3:
    Input client: `nslookup digilab.com`
    Output client:
    ```
    [digilab.com] is not found...
    ```
    Terminal:
    ![Case 3](http://cdn.digilabdte.com/u/to2WXR.png)
  - Case 3:
    Input client: `bind 192.168.10.9`
    Output client:
    ```
    Command is not recognized...
    ```
    Terminal:
    ![Case 4](http://cdn.digilabdte.com/u/ePR5y6.png)
  - Case 5:
    Input client: `SHUTDOWN`
    Output client:
    ```
    Server shutdowned...
    ```
    Terminal:
    ![Case 5](https://cdn.digilabdte.com/u/4DOeAM.png)


#### Note

Pada file server terdapat dua buah class, yaitu `Host` dan `DNSStorage`. Detail dari class tersebut :
- `Host` adalah class dari data yang ada di dalam `bind.txt`. Class `Host` akan menyimpan name server dan ip address.
- `DNSStorage` adalah class yang bertujuan untuk membaca isi dari  file `bind.txt` dan menyimpannya menjadi data dalam bentuk vector `Host`. 

Penggunaan class `DNSStorage` sudah diterapkan dalam program. Kalian hanya perlu memikirkan bagaimana data dengan class `Host` diolah pada file server. Class `DNSStorage` tidak ada implementasi tambahan selain yang sudah ada pada file.

Function `string processRequest(vector<Host>& storage, string request)` pada file server tidak harus diterapkan, anda diberi kebebasan bagaimana anda menyelesaikan CS ini. Akan tetapi, saya menyarankan untuk menerapkan function tersebut agar file lebih rapih dan modular. Function `processRequest` tersebut menerima dua argumen, yaitu keseluruhan list dari file dan request yang dikirimkan oleh client. Setelah memproses request client, function akan me-return sebuah string berupa message yang harus dikirimkan ke client.