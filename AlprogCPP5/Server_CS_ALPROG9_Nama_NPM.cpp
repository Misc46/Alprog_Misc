#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string>
#include <winsock2.h>
#include <bits/stdc++.h>
#include <WS2tcpip.h>

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


string processRequest(vector<Host>& storage, string request){
    string req = request;
    transform(req.begin(), req.end(), req.begin(), ::tolower);
    if(req.find("nslookup") == 0) {
        string arg = request.substr(9);
        arg.erase(0, arg.find_first_not_of(""));
        for (auto& h : storage){
            if(h.nameserver == arg) {
                return "Domain [" + arg + "] found!! Ip Address: " + h.ip_address;
            }
            if (h.ip_address == arg) {
                return "Host [" + arg + "] found!! Nameserver: " + h.nameserver;
            }
        }
        return "[" + arg + "] is not found...";
    }   else if (req == "shutdown") {
        return "Server shutdowned...";
    }   else {
        return "Command is not recognized...";
    }
}


int main() {
    vector<Host> storage = DNSStorage::GetData();
    
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // gw bingung jujur
    // RLC lah anjir
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    bool running = true;
    while (running) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, 1024);
        string request(buffer);
        string response = processRequest(storage, request);
        send(new_socket, response.c_str(), response.size(), 0);
        if (response == "Server shutdowned...") {
            running = false;
        }
        close(new_socket);
    }
    close(server_fd);
    return 0;
}
