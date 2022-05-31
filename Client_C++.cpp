#pragma comment(lib, "ws2_32.lib") //отримання доступу до функцій роботи з сервером-клієнтом
#include <winsock2.h>
#include <iostream>
#include <string>
using namespace std;

#pragma warning(disable: 4996) //для того, щоб працював inet_addr

class bibLoadException : public exception { //виключення про помилку завантаження бібліотеки
public:
    const char* what() const throw() {
        return "Error loading library to work w server-client connection"; //текст помилки
    }
};

class cientConnException : public exception {//виключення про помилку під'єднання клієнта до сервера
public:
    const char* what() const throw() {
        return "Error client couldn`t connect";//текст помилки
    }
};

SOCKET Connection; //сокет для клієнта

void ClientHandler() { //функція отримання повідомлень та виведення їх в термінал
    int msg_size; //розмір повідомлення
    while (true) { //цикл отримання повідомлень
        recv(Connection, (char*)&msg_size, sizeof(int), NULL); //отримання розміру нового повідомлення
        char* msg = new char[msg_size + 1]; //ствоення змінної, що зберігатиме повідомлення
        msg[msg_size] = '\0'; //індикатор кінця повідомлення
        recv(Connection, msg, msg_size, NULL);//отримання повідомлення
        cout << msg << endl; //виведення повідомлення на екран
        delete[] msg; //звільнення змінної
    }
}

int main(int argc, char* argv[]) {
    //WSAStartup
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1); //версія winsock2.h
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        throw bibLoadException();
        exit(1);
    }

    SOCKADDR_IN addr; //змінна для збереження адреси інтернет-сокета 
    int sizeofaddr = sizeof(addr); //розмір адреси
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адреса серверу (localhost)
    addr.sin_port = htons(1111);//порт підключення
    addr.sin_family = AF_INET;//сім'я протоколів

    Connection = socket(AF_INET, SOCK_STREAM, NULL); //доєднання до серверу
    if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) { //обробка помилки підключення
        throw cientConnException();
        return 1;
    }

    cout << "(@server) Connected!\n"; //інакше якщо підключився + повідомлення нижче з правилами
    cout << "(@server) WELCOME! \n1. To enter the chatroom please enter your username beginning with @\n2. If you choose a username which already exists you will not be connected to the server\n3. If you want to send someone a private message please start it with _@(username)\n4.The names that already exist are listed below\n5. To exit the chat type EXIT\n";
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
    bool firstCon = true; //індикатор першого підключення
    string user; //змінна, що зберігає юзернейм
    if (firstCon) {
        getline(cin, user); //отримання введення юзернейму з консолі
        while (user[0] != '@') {//перевірка на правильність введення
            cout << "(@server) Wrong username input. Try again\n";
            getline(cin, user);
        }
        int userSize = user.size();//розмір юзернейму
        send(Connection, (char*)&userSize, sizeof(int), NULL); //надсилання розміру юзернейму
        send(Connection, user.c_str(), userSize, NULL); //надсилання самого юзернейму
        firstCon = false; //зміна індикатора першого підключення
    }

    string msg1; //повідомлення
    bool st = true; //індикатор підключення
    while (st) {
        getline(cin, msg1); //отримання тексту повідомлення з консолі
        int msg1Size = msg1.size(); //розмір повідомлення
        send(Connection, (char*)&msg1Size, sizeof(int), NULL); //надсилання розміру
        send(Connection, msg1.c_str(), msg1Size, NULL); //надсилання повідомлення
        if (msg1 == "EXIT") { //якщо це повідомлення про вихід 
            st = false; //зміна індикатора підключення
            exit(0); //завершення роботи програми
            //closesocket(Connection); 
            //Connection=INVALID_SOCKET;

        }
        Sleep(10);
    }

    system("pause");
    return 0;
}
