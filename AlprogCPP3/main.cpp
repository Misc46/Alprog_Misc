#include <winsock2.h>
#include <iostream>

int main()
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }
    std::cout << "Winsock initialized.\n";
    WSACleanup();
    return 0;
}