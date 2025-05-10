#include "lista_wiazana.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;
Node::Node(int p, int v) : priority(p), value(v), next(nullptr) {}


ListaWiazana::ListaWiazana() : head(nullptr), tail(nullptr), size(0) {
    nodePool = new NodePool(10000); // Tworzenie puli pamięci o rozmiarze 10000 węzłów
}

ListaWiazana::~ListaWiazana() {
    while (!isEmpty()) {
        pop();
    }
    delete nodePool; // Zwolnienie pamięci puli
}

bool ListaWiazana::isEmpty() {
    return head == nullptr;
}

void ListaWiazana::push(int priority, int value) {
    Node* newNode = nodePool->getNode(priority, value);
    size++;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        return;
    }
    if (head->priority > priority) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->priority <= priority) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (current->next == nullptr) {
        tail = newNode;
    }
}

int ListaWiazana::pop() {
    if (isEmpty()) {
        cout << "Lista jest pusta" << endl;
        return -1;
    }
    Node* temp = head;
    int val = head->value;
    head = head->next;
    nodePool->returnNode(temp); // Zwracanie węzła do puli
    size--;
    return val;
}

int ListaWiazana::getSize()
{
    return size;
}
int ListaWiazana::peek()
{
    if (isEmpty()) 
    {
        cout<<"Kolejka jest pusta"<<endl;
        return -1;
    }
    return head->value;
}
void ListaWiazana::modifyPriority(int oldPriority, int newPriority)
{
    if (isEmpty()) 
    {
        cout<<"Kolejka jest pusta"<<endl;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr && current->priority != oldPriority) 
    {
        prev = current;
        current = current->next;
    }
    if(current == nullptr) 
    {
        cout<<"Nie znaleziono elementu"<<endl;
        return;
    }
    if(prev == nullptr) 
    {
        head = current->next;
    } 
    else 
    {
        prev->next = current->next;
    }
    size--;
    push(newPriority, current->value);
    delete current;
}
void ListaWiazana::printQ()
{
    Node* current = head;
    if(isEmpty())
    {
        cout << "Kolejka jest pusta" << endl;
        return;
    }
    while (current) 
    {
        cout << "(" << current->priority << ", " << current->value << ") ";
        current = current->next;
    }
    cout << endl;
}