#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable: 4996)

SOCKET Connection;

void ClientHandler() {
    int msg_size;
    while (true) {
        recv(Connection, (char*)&msg_size, sizeof(int), NULL);
        char* msg = new char[msg_size + 1];
        msg[msg_size] = '\0';
        recv(Connection, msg, msg_size, NULL);
        cout << msg << endl;
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

    Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        std::cout << "Error: failed connect to server.\n";
        return 1;
    }

    cout << "(@server) Connected!\n";
    cout << "(@server) WELCOME! \n1. To enter the chatroom please enter your username beginning with @\n2. If you choose a username which already exists you will not be connected to the server\n3. If you want to send someone a private message please start it with _@(username)\n4.The names that already exist are listed below\n";
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
    bool firstCon = true;
    string user;
    if (firstCon) {
        getline(cin, user);
        while (user[0] != '@') {
            cout << "(@server) Wrong username input. Try again\n";
            getline(cin, user);
        }
        int userSize = user.size();
        send(Connection, (char*)&userSize, sizeof(int), NULL);
        send(Connection, user.c_str(), userSize, NULL);
        firstCon = false;
    }

    string msg1;
    bool st = true;
    while (st) {
        getline(cin, msg1);
        int msg1Size = msg1.size();
        send(Connection, (char*)&msg1Size, sizeof(int), NULL);
        send(Connection, msg1.c_str(), msg1Size, NULL);
        if(msg1=="EXIT"){
            st = false;
            exit(0);
            //closesocket(Connection);
            //Connection=INVALID_SOCKET;

        }
        Sleep(10);
    }

    system("pause");
    return 0;
}