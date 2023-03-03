#include <iostream>

class Node
{
public:
    Node *prev;
    Node *next;
    int data;
    Node(): data(0), prev(nullptr), next(nullptr) {}
    Node(int data): data(data), prev(nullptr), next(nullptr) {}

};

class DoubleLinkedList
{
public: 
    Node *head;
    Node *tail;
    DoubleLinkedList(): head(nullptr), tail(nullptr) {}
    bool empty() {
        if (head == nullptr || tail == nullptr) return true;
        return false;
    }
    void push(int value) {
        Node * newNode = new Node(value);
        newNode->next = head;
        if (empty()) tail = newNode;
        head = newNode;
        if (newNode->next == nullptr) return;
        newNode->next->prev = newNode;
    }
    void append(int value) {
        Node * newNode = new Node(value);
        newNode->prev = tail;
        if (empty())
    }

};

int main()
{
    using namespace std;
    DoubleLinkedList list;
    list.push(1);
    cout << "Head: " << list.head << " - " << list.head->data << endl;
    cout << "Tail: " << list.tail << " - " << list.tail->data << endl;
    list.push(2);
    cout << "Head: " << list.head << " - " << list.head->data << endl;
    cout << "Tail: " << list.tail << " - " << list.tail->data << endl;



    return 0;
}