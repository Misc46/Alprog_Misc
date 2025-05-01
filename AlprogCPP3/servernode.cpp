#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

#define PORT 8888

int main()
{
    WSADATA wsa;
    SOCKET listen_socket, client_socket;
    struct sockaddr_in server, client;
    int c, recv_size;
    char messageRecv[100];
    string messageSend;

    cout << "Initialising Winsock...\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cerr << "WSAStartup failed. Error code: " << WSAGetLastError() << "\n";
        return 1;
    }
    cout << "Winsock initialised.\n";

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == INVALID_SOCKET)
    {
        cerr << "Could not create socket. Error code: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }
    cout << "Socket created.\n";

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cerr << "Bind failed. Error code: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Bind done.\n";

    listen(listen_socket, 3);
    cout << "Waiting for incoming connections...\n";

    c = sizeof(struct sockaddr_in);
    client_socket = accept(listen_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET)
    {
        cerr << "Accept failed. Error code: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    cout << "Connection accepted.\n\n";

    cout << "Pesan yang ingin dikirim ke client: ";
    cin >> messageSend;

    send(client_socket, messageSend.c_str(), messageSend.length(), 0);

    recv_size = recv(client_socket, messageRecv, sizeof(messageRecv) - 1, 0);
    if (recv_size == SOCKET_ERROR)
    {
        cout << "recv failed with error code" << WSAGetLastError();
    }
    else
    {
        messageRecv[recv_size] = '\0';
    }
    cout << "Pesan dari client: " << messageRecv << "\n";

    closesocket(client_socket);
    closesocket(listen_socket);
    WSACleanup();

    return 0;
}