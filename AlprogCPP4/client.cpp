#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

#define SERVER "127.0.0.1"
#define PORT 8888

int main()
{
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    int recv_size;
    char messageRecv[100];
    string messageSend;

    // ====== Mulai Kerjakan disini ======

    cout << "Initialising Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed. Error Code: " << WSAGetLastError();
        return 1;
    }
    cout << "Winsock initialised." << endl;

    // Buat socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Could not create socket: " << WSAGetLastError();
        return 1;
    }
    cout << "Socket created." << endl;

    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect ke server
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        cout << "connect error";
        return 1;
    }
    cout << "Connected to server." << endl;

    // Input dari user
    string pesan, angka;
    cout << "Pesan yang ingin dikirim ke server: ";
    cin >> pesan >> angka;
    messageSend = pesan + " " + angka;

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);

    // Terima balasan
    if ((recv_size = recv(client_socket, messageRecv, sizeof(messageRecv), 0)) == SOCKET_ERROR)
    {
        cout << "recv failed" << endl;
    }
    messageRecv[recv_size] = '\0';
    cout << "Pesan dari server: " << messageRecv << endl;

    closesocket(client_socket);
    WSACleanup();

    // ====== Selesai Kerjakan ======
    return 0;
}
