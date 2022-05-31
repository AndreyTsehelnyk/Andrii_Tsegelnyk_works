#include <iostream>
#include <stack>
using namespace std;


template<class T>
struct Node {
    Node<T>* next;
    T item;
};


template<class T>
class MyStack {

private:

    int _size;
    Node<T>* head;

public:

    MyStack() : _size(0), head(nullptr) {}

    ~MyStack() {
        while (!empty())
            pop();
    }

    bool empty() { return head == nullptr; }
    int size() { return _size; }

    T top() {
        if (empty())
            throw logic_error("Stack is empty");
        return head->item;
    }

    void pop() {
        if (empty())
            throw logic_error("Stack is empty");
        Node<T>* node = head;
        head = node->next;
        delete node;
        _size--;
    }

    void push(T item) {
        Node<T>* node = new Node<T>();
        node->item = item;
        node->next = head;
        head = node;
        _size++;
    }

};


int main() {
    stack<int> stl_stack;
    MyStack<int> my_stack;

    for (int i = 0; i < 10; i++) {
        stl_stack.push(i);
        cout << stl_stack.top() << ends;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        my_stack.push(i);
        cout << my_stack.top() << ends;
    }
    cout << endl << endl;

    while (!stl_stack.empty()) {
        cout << stl_stack.top() << ends;
        stl_stack.pop();
    }
    cout << endl;
    while (!my_stack.empty()) {
        cout << my_stack.top() << ends;
        my_stack.pop();
    }

    return 0;
}