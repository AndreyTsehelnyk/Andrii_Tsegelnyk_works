#pragma comment(lib, "ws2_32.lib") //отримання доступу до функцій роботи з сервером-клієнтом
#include <winsock2.h>
#include <iostream>
#include <string>
using namespace std;


#pragma warning(disable: 4996) //для того, щоб працював inet_addr


class bibLoadException : public exception {//виключення про помилку завантаження бібліотеки
public:
    const char* what() const throw() {
        return "Error loading library to work w server-client connection";//текст помилки
    }
};

class cientConnException : public exception {//виключення про помилку під'єднання клієнта до сервера
public:
    const char* what() const throw() {
        return "Error client couldn`t connect";//текст помилки
    }
};

typedef struct { // структура клієнт-індекс
    int index; //індекс
    string username; //юзернейм

}allUsers;

SOCKET Connections[100]; //список, що зберігає усіх клієнтів
int Counter = 0; //кількість підключень
allUsers usersLst[100]; //список структур

void ClientHandler(int index) { //обробка повідомлень
    int msgSize; //розмір повідомлення
    bool st = true; //змінна для роботи циклу
    while (st) {
        recv(Connections[index], (char*)&msgSize, sizeof(int), NULL); //отримання повідомлення від користувача з індексом index (обробка повідомлення описана в основній функції програми)
        char* msg = new char[msgSize + 1];
        msg[msgSize] = '\0';

        recv(Connections[index], msg, msgSize, NULL);
        string converter = msg; //конвертація  з char до string для обробки
        string converterWUN = usersLst[index].username + ": " + converter; //повідомлення у правильному форматі, що мають отримати користувачі

        if (converter == "EXIT") { //повідомлення, що сигналізує про бажання користувача від'єднатися від сервера
            closesocket(Connections[index]); //закриття сокету клієнта, що надіслав повідомлення
            Connections[index] = INVALID_SOCKET;
            st = false; //завершення циклу

            for (int i = 0; i < Counter; i++) { //для всіх користувачів
                if (i == index) { //окрім того, що надіслав повідомлення
                    continue;
                }
                string exit = "User has left the chat " + usersLst[index].username; //повідомлення про від\єднання користувача, що надіслав повідомлення та його надсилання
                usersLst[index].username = "0"; //заміна його юзернейму на "0"
                int convSize = exit.size();
                send(Connections[i], (char*)&convSize, sizeof(int), NULL);
                send(Connections[i], exit.c_str(), convSize, NULL);
            }
        }
        else {
            if (converter[0] == '_') { //індикатор про бажання відправити приватне повідомлення
                size_t s = converter.find_first_not_of("_"); //початок юзернейму того, кому хочуть надіслати це повідомлення
                size_t e = converter.find(" "); //початок повідомлення
                string name; //змінна, що зберігає юзернейм
                if (e != -1) name = converter.substr(s, e - 1); //обрізання юзернейму, якщо повідомлення містить інший текст
                else if (e == -1)name = converter.substr(s, converter.length()); //обрізання юзернейму, якщо повідомлення не містить інший текст
                cout << "Mention of " << name << " found in chat\n"; //повідомлення для серверу (була помічена спроба надіслати приватне повідомлення іншому користувачу)
                bool found = false; //індикатор 
                for (int j = 0; j < Counter; j++) { //пошук юзернейму серед інших юзернеймів в списку структур
                    if (usersLst[j].username == name) { //якщо знайдено
                        found = true; //зміна індикатора
                        cout << "found user with name " << name << "\n"; //повідомлення для серверу(клієнта з таким юзернеймом було знайдено зеред інших юзернеймів в списку структур)
                        int convSize = converterWUN.size();
                        send(Connections[usersLst[j].index], (char*)&convSize, sizeof(int), NULL);
                        send(Connections[usersLst[j].index], converterWUN.c_str(), convSize, NULL); //надсилання повідомлення потрібному користувачу
                    }
                }
                if (found == false) { //якщо не знайдено
                    cout << "didn`t find user with name " << name << "\n"; //повідомлення для серверу(клієнта з таким юзернеймом не було знайдено зеред інших юзернеймів в списку структур)
                    string error = "(@server) Looks like you were trying to write a presonal text. \nUnfortunately, we haven`t found a user with given username online. Please, try again"; //повідомлення для клієнту про те, шо такого користувача немає онлайн
                    int errSize = error.size();
                    send(Connections[index], (char*)&errSize, sizeof(int), NULL);
                    send(Connections[index], error.c_str(), errSize, NULL); //надсилання повідомлення
                }
            }
            else { //якщо це не повідомлення про вихід та не приватне повідомлення 
                for (int i = 0; i < Counter; i++) {
                    if (i == index) { //усім, окрім того, хто надіслав повідомлення
                        continue;
                    }
                    int convSize = converterWUN.size();
                    send(Connections[i], (char*)&convSize, sizeof(int), NULL);
                    send(Connections[i], converterWUN.c_str(), convSize, NULL); //надсилання повідомлення у потрібному форматі
                }
            }
        }
        delete[] msg; //видалення повідомлення, звільнення змінної
    }
}

int main(int argc, char* argv[]) {
    //WSAStartup 
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1); //версія winsock2.h
    if (WSAStartup(DLLVersion, &wsaData) != 0) { //завантаження бібліотеки
        throw bibLoadException(); //обробка помилок, помилка завантаження бібліотеки
        exit(1);
    }

    SOCKADDR_IN addr; //змінна для збереження адреси інтернет-сокета 
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адреса серверу (localhost)
    addr.sin_port = htons(1111); //порт підключення
    addr.sin_family = AF_INET; //сім'я протоколів

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); //установлення з'єднання
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); //прив'язання адреси сокету
    listen(sListen, SOMAXCONN); //очікування з'єднання клієнта


    SOCKET newConnection; //новий сокет клієнта
    for (int i = 0; i < 100; i++) { //до 100 клієнтів
        newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); //доєднання клієнта

        if (newConnection == 0) { //обробка помилок, якщо клієнт не доєднався
            throw cientConnException();
        }
        else {
            std::cout << "Client Connected!\n"; //якщо клієнт доєднався

            int msg_size; //розмір повідомлення
            if (Counter != 0) { //перевірка кількості підключень
                string online = "(@server) ALL USERS ONLINE These name(s) you shouldn't use:"; //повідомлення про кількість підключених клієнтів
                int onlineSize = online.size(); //розмір повідомлення про кількість підключених клієнтів
                send(newConnection, (char*)&onlineSize, sizeof(int), NULL); //відправка розміру повідомлення
                send(newConnection, online.c_str(), onlineSize, NULL); //відправка повідомлення
                for (int j = 0; j < Counter; j++) { //цикл по кількості підключень
                    int nameSize = usersLst[j].username.size(); //змінна, що зберігає розмір юзернейму клієнта
                    send(newConnection, (char*)&nameSize, sizeof(int), NULL); //надсилання розміру повідомлення
                    send(newConnection, usersLst[j].username.c_str(), nameSize, NULL); //надсилання юзернейму
                }
            }
            recv(newConnection, (char*)&msg_size, sizeof(int), NULL); //отримання розміру нового юзернейму
            char* msg = new char[msg_size + 1]; //ствоення змінної, що зберігатиме повідомлення
            msg[msg_size] = '\0'; //індикатор кінця повідомлення
            recv(newConnection, msg, msg_size, NULL); //отримання повідомлення
            string converter = msg; //конвертація повідомлення з char до string для обробки

            delete[] msg; //звільнення змінної
            int k = 0; //інтикатор підключення
            if (Counter != 0) { //перевірка кількості підключень

                bool f = false; //булева змінна (знайшли\не знайшли користувача з надісланим іменем)
                for (int j = 0; j < Counter; j++) {
                    if (usersLst[j].username == converter) { //якщо знайшли
                        f = true; //зміна індикатору
                        string lockedname = "This name was chosen before!"; //повідомлення, що має надійти клієнту, далі його надсилання
                        int messageSize = lockedname.size();
                        send(newConnection, (char*)&messageSize, sizeof(int), NULL);
                        send(newConnection, lockedname.c_str(), messageSize, NULL);
                        k = 1;
                    }
                }
                if (f == false) { //якщо не знайшли

                    for (int j = 0; j < Counter; j++) { //для всіх користувачів
                        string others = "(@server) User " + converter + " has entered the chat"; //повідомлення про те, що новий користувач доєднався до чату та надсилання повідомлення
                        int othersSize = others.size();
                        send(Connections[j], (char*)&othersSize, sizeof(int), NULL);
                        send(Connections[j], others.c_str(), othersSize, NULL);
                    }
                }
            }

            if (k == 0) { //якщо у користувача унікальний юзернейм
                Connections[i] = newConnection; //додавання користувача до списку доєднаних клієнтів
                usersLst[i] = { i, converter }; //додавання юзернейму клієнта на його порядкорого ноемру до списку структур
                Counter++; //збільшення змінної, що зберігає інформайію про к-ть підключень
                CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL); //реалізація багатопотокового сервера, додавання індексу клієнта 
            }
        }
    }


    system("pause"); //продовження програми
    return 0; //перевірка на роботу
}
