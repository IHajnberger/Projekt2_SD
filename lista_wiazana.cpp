#include "lista_wiazana.hpp"

using namespace std;
Node::Node(int p, int v) : priority(p), value(v), next(nullptr) {}
ListaWiazana::ListaWiazana() : head(nullptr), size(0) {}
ListaWiazana::~ListaWiazana() 
{
    Node* current = head; 
    Node* nextNode;     
    while (current != nullptr) 
    {
        nextNode = current->next; 
        delete current; 
        current = nextNode; 
    }
    head = nullptr; 
    tail = nullptr; 
}
bool ListaWiazana::isEmpty()
{
    return head == nullptr;
}
void ListaWiazana::push(int priority, int value)
{
   Node* newNode = new Node(priority, value);
   size++;
   if(isEmpty())
   {
       head = newNode;
       tail = newNode;
       return;
   }
   if(head->priority > priority)
   {
       newNode->next = head;
       head = newNode;
       return;
   }
    Node* current = head;
    while(current->next != nullptr && current->next->priority <= priority)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if(current->next == nullptr)
    {
        tail = newNode;
    }

}
int ListaWiazana::pop()
{
   if(isEmpty())
   {
        cout<<"Kolejka jest pusta"<<endl;
        return -1;
   }
    Node* temp = head;
    int val = head->value;
    head = head->next;
    delete temp;
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