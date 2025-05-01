#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 8888

class Host {
    public:
        string nameserver;
        string ip_address;
};

class DNSStorage {
    private:
        string FILENAME = "bind.txt";

    public:
        static vector<Host> GetData() {
            DNSStorage storage;
            ifstream file_data;
            vector<Host> data = {};

            file_data.open(storage.FILENAME);
            
            if(file_data.fail()){
                cout << "Failed to open file." << endl ;

                return {};
            }

            string line;
            while (!file_data.eof()) {
                getline(file_data, line);
                
                stringstream ss(line);
                string temp;
                Host tempData;

                getline(ss, temp, '@');
                tempData.nameserver = temp;
                
                getline(ss, temp);
                tempData.ip_address = temp;

                data.push_back(tempData);
            }
            file_data.close();

            return data;
        }
};

/*
string processRequest(vector<Host>& storage, string request){
    
}
*/

int main() {
    vector<Host> storage = DNSStorage::GetData();

    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer[1024];
    string request, response;

    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Buat socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Konfigurasi alamat server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    bind(server_socket, (struct sockaddr *)&server, sizeof(server));

    // Listen
    listen(server_socket, 3);
    cout << "Server is running and waiting for client..." << endl;

    c = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &c);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
        if (recv_size == SOCKET_ERROR)
            break;

        request = string(buffer);
        transform(request.begin(), request.end(), request.begin(), ::tolower);

        if (request.find("nslookup") == 0)
        {
            string argument = request.substr(9); // setelah 'nslookup '
            bool found = false;
            for (Host &h : storage)
            {
                if (h.nameserver == argument)
                {
                    response = "Domain [" + argument + "] found!! Ip Address: " + h.ip_address;
                    found = true;
                    break;
                }
                else if (h.ip_address == argument)
                {
                    response = "Host [" + argument + "] found!! Nameserver: " + h.nameserver;
                    found = true;
                    break;
                }
            }
            if (!found)
                response = "[" + argument + "] is not found...";
        }
        else if (request == "shutdown")
        {
            response = "Server shutdowned...";
            send(client_socket, response.c_str(), response.size(), 0);
            break;
        }
        else
        {
            response = "Command is not recognized...";
        }

        send(client_socket, response.c_str(), response.size(), 0);
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}
