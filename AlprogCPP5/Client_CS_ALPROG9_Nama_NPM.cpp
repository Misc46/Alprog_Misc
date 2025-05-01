#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // Penting untuk link ke Winsock

using namespace std;

#define SERVER "127.0.0.1"
#define PORT 8888

int main()
{
    // 1. Inisialisasi Winsock
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed to initialize Winsock. Error Code: " << WSAGetLastError() << endl;
        return 1;
    }

    while (true)
    {
        cout << "Input: ";
        string input;
        getline(cin, input);

        // 2. Buat socket
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET)
        {
            cout << "Socket creation failed. Error: " << WSAGetLastError() << endl;
            WSACleanup();
            return 1;
        }

        // 3. Atur alamat server
        sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = inet_addr(SERVER); // Ganti dari inet_pton ke inet_addr

        // 4. Connect ke server
        if (connect(sock, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            cout << "Connection failed. Error: " << WSAGetLastError() << endl;
            closesocket(sock);
            continue;
        }

        // 5. Kirim pesan
        send(sock, input.c_str(), input.length(), 0);

        // 6. Terima respons
        char buffer[1024] = {0};
        int recv_size = recv(sock, buffer, sizeof(buffer), 0);
        if (recv_size > 0)
        {
            cout << "Server: " << string(buffer, recv_size) << endl;
        }
        else
        {
            cout << "No response or error." << endl;
        }

        closesocket(sock);

        if (input == "shutdown")
        {
            break;
        }
    }

    WSACleanup();
    return 0;
}
