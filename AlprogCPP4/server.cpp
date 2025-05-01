#include <iostream>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888
#define PASSWORD "tmxa" // Password hardcoded

string decrypt(string text, int n)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        result += char((int(text[i] - 97 + n) % 26) + 97);
    }
    return result;
}

void parseMessage(const string &messageRecv, string &pass, int &key)
{
    stringstream ss(messageRecv);
    string temp;

    getline(ss, temp, ' ');
    pass = "";
    for (int x = 0; x < temp.length(); x++)
    {
        pass += char(tolower(temp[x]));
    }

    getline(ss, temp, ' ');
    key = atoi(temp.c_str());
}

int main()
{
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;

    string pass;
    int key;

    // ====== Mulai Kerjakan disini ======

    cout << "Initialising Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed. Error Code: " << WSAGetLastError();
        return 1;
    }
    cout << "Winsock initialised." << endl;

    // Buat socket
    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Could not create socket: " << WSAGetLastError();
        return 1;
    }
    cout << "Socket created." << endl;

    // Siapkan struktur server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(listen_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cout << "Bind failed with error code: " << WSAGetLastError();
        return 1;
    }
    cout << "Bind done." << endl;

    // Listen
    listen(listen_socket, 3);

    // Accept koneksi masuk
    cout << "Waiting for incoming connections..." << endl;
    c = sizeof(struct sockaddr_in);
    client_socket = accept(listen_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET)
    {
        cout << "accept failed with error code: " << WSAGetLastError();
        return 1;
    }
    cout << "Connection accepted." << endl;

    // Terima pesan
    if ((recv_size = recv(client_socket, messageRecv, sizeof(messageRecv), 0)) == SOCKET_ERROR)
    {
        cout << "recv failed" << endl;
    }

    messageRecv[recv_size] = '\0'; // null-terminate
    parseMessage(string(messageRecv), pass, key);

    cout << "Pesan dari client: " << pass << " " << key << endl;

    // Caesar cipher
    string hasilCipher = decrypt(pass, key);
    cout << "Hasil cipher : " << hasilCipher << " (key = " << key << ")" << endl;

    // Bandingkan hasil dengan PASSWORD
    if (hasilCipher == PASSWORD)
    {
        messageSend = "Success";
    }
    else
    {
        messageSend = "Failed";
    }

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);

    closesocket(listen_socket);
    WSACleanup();

    // ====== Selesai Kerjakan ======
    return 0;
}
