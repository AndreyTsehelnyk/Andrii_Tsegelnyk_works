#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable: 4996)

typedef struct {
    int index;
    string username;

}allUsers;

SOCKET Connections[100];
int Counter = 0;
allUsers usersLst[100];

void ClientHandler(int index) {
    int msgSize;
    bool st = true;
    while (st) {
        recv(Connections[index], (char*)&msgSize, sizeof(int), NULL);
        char* msg = new char[msgSize + 1];
        msg[msgSize] = '\0';

        recv(Connections[index], msg, msgSize, NULL);
        string converter = msg;
        string converterWUN = usersLst[index].username + ": " + converter;

        if (converter == "EXIT") {
            closesocket(Connections[index]);
            Connections[index] = INVALID_SOCKET;
            st = false;
            
            for (int i = 0; i < Counter; i++) {
                if (i == index) {
                    continue;
                }
                string exit = "User has left the chat "+ usersLst[index].username;
                usersLst[index].username = "0";
                int convSize = exit.size();
                send(Connections[i], (char*)&convSize, sizeof(int), NULL);
                send(Connections[i], exit.c_str(), convSize, NULL);
            }
        }
        else {
            if (converter[0] == '_') {
                size_t s = converter.find_first_not_of("_");
                size_t e = converter.find(" ");
                string name;
                if (e != -1) name = converter.substr(s, e - 1);
                else if (e == -1)name = converter.substr(s, converter.length());
                cout << "Mention of " << name << " found in chat\n";
                bool found = false;
                for (int j = 0; j < Counter; j++) {
                    if (usersLst[j].username == name) {
                        found = true;
                        cout << "found user with name " << name << "\n";
                        int convSize = converterWUN.size();
                        send(Connections[usersLst[j].index], (char*)&convSize, sizeof(int), NULL);
                        send(Connections[usersLst[j].index], converterWUN.c_str(), convSize, NULL);
                    }
                }
                if (found == false) {
                    cout << "didn`t find user with name " << name << "\n";
                    string error = "(@server) Looks like you were trying to write a presonal text. \nUnfortunately, we haven`t found a user with given username online. Please, try again";
                    int errSize = error.size();
                    send(Connections[index], (char*)&errSize, sizeof(int), NULL);
                    send(Connections[index], error.c_str(), errSize, NULL);
                }
            }
            else {
                for (int i = 0; i < Counter; i++) {
                    if (i == index) {
                        continue;
                    }
                    int convSize = converterWUN.size();
                    send(Connections[i], (char*)&convSize, sizeof(int), NULL);
                    send(Connections[i], converterWUN.c_str(), convSize, NULL);
                }
            }
        }
        delete[] msg;
    }
}

int main(int argc, char* argv[]) {
    //WSAStartup
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);


    SOCKET newConnection;
    for (int i = 0; i < 100; i++) {
        newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

        if (newConnection == 0) {
            std::cout << "Error client couldnt connect\n";
        }
        else {
            std::cout << "Client Connected!\n";

            int msg_size;
            if (Counter != 0) {
                string online = "(@server) ALL USERS ONLINE These name(s) you shouldn't use:";
                int onlineSize = online.size();
                send(newConnection, (char*)&onlineSize, sizeof(int), NULL);
                send(newConnection, online.c_str(), onlineSize, NULL);
                for (int j = 0; j < Counter; j++) {
                    int nameSize = usersLst[j].username.size();
                    send(newConnection, (char*)&nameSize, sizeof(int), NULL);
                    send(newConnection, usersLst[j].username.c_str(), nameSize, NULL);

                }
            }
            recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
            char* msg = new char[msg_size + 1];
            msg[msg_size] = '\0';
            recv(newConnection, msg, msg_size, NULL);
            string converter = msg;
            //maybe throw exception is username exists
            delete[] msg;
            int k = 0;
            if (Counter != 0) {
                
                bool f = false;
                for (int j = 0; j < 100; j++) {
                    if (usersLst[j].username == converter) {
                        f = true;
                        string lockedname = "This name was chosen before!";
                        int messageSize = lockedname.size();
                        send(newConnection, (char*)&messageSize, sizeof(int), NULL);
                        send(newConnection, lockedname.c_str(), messageSize, NULL);
                        k = 1;
                    }
                }
                if (f == false) {

                    for (int j = 0; j < Counter; j++) {
                        string others = "(@server) User " + usersLst[j].username + " has entered the chat";
                        int othersSize = others.size();
                        send(Connections[j], (char*)&othersSize, sizeof(int), NULL);
                        send(Connections[j], others.c_str(), othersSize, NULL);
                    }
                }
            }

            if (k == 0) {
                Connections[i] = newConnection;
                usersLst[i] = { i, converter };
                Counter++;
                CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
            }
        }
    }


    system("pause");
    return 0;
}