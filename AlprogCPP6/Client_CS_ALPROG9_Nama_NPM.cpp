#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

#define SERVER "127.0.0.1"
#define PORT 8888

int main() {

    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char buffer[1024];
    string message, server_reply;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Buat socket
    s = socket(AF_INET, SOCK_STREAM, 0);

    // Konfigurasi server
    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Koneksi ke server
    connect(s, (struct sockaddr *)&server, sizeof(server));

    while (1)
    {
        cout << "Enter command: ";
        getline(cin, message);

        send(s, message.c_str(), message.length(), 0);

        memset(buffer, 0, sizeof(buffer));
        int recv_size = recv(s, buffer, sizeof(buffer), 0);
        if (recv_size == SOCKET_ERROR)
            break;

        cout << string(buffer) << endl;

        if (message == "shutdown")
            break;
    }

    closesocket(s);
    WSACleanup();

    return 0;
}