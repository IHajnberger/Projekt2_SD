#include "lista_wiazana.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;
Node::Node(int p, int v) : priority(p), value(v), next(nullptr) {}


ListaWiazana::ListaWiazana() : head(nullptr), tail(nullptr), size(0) 
{
    nodePool = new NodePool(10000); // Tworzenie puli pamięci o rozmiarze 10000 węzłów
}

ListaWiazana::~ListaWiazana() 
{
    while (!isEmpty()) {
        pop();
    }
    delete nodePool; // Zwolnienie pamięci puli
}

bool ListaWiazana::isEmpty() 
{
    return head == nullptr;
}

void ListaWiazana::push(int priority, int value) 
{
    Node* newNode = nodePool->getNode(priority, value);
    size++;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        return;
    }
    if (head->priority > priority) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->priority <= priority) 
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail) 
    {
        tail = newNode;
    }
}

int ListaWiazana::pop() 
{
    if (isEmpty()) 
    {
        cout << "Lista jest pusta" << endl;
        return -1;
    }
    Node* temp = head;
    int val = head->value;
    head = head->next;
    nodePool->returnNode(temp); 
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
        cout << "Kolejka jest pusta" << endl;
        return;
    }

    if (head->priority == oldPriority) 
    {
        head->priority = newPriority;

        // Jeśli nowy priorytet wymaga zmiany pozycji węzła
        if (head->next != nullptr && head->next->priority < newPriority) 
        {
            Node* current = head;
            head = head->next; // Usuń węzeł z początku
            current->next = nullptr;

            // Wstaw węzeł w odpowiednie miejsce
            Node* temp = head;
            Node* prev = nullptr;
            while (temp != nullptr && temp->priority <= newPriority) 
            {
                prev = temp;
                temp = temp->next;
            }

            if (prev == nullptr) 
            {
                current->next = head;
                head = current;
            } 
            else
            {
                // Wstaw w środek lub na koniec
                current->next = temp;
                prev->next = current;
                if (current->next == nullptr) 
                {
                    tail = current; 
                }
            }
        }
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->priority != oldPriority) 
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) 
    {
        cout << "Nie znaleziono elementu o podanym priorytecie" << endl;
        return;
    }

    // Usuń węzeł z bieżącej pozycji
    if (prev != nullptr) 
    {
        prev->next = current->next;
    }

    if (current == tail) 
    {
        tail = prev;
    }

    // Zmień priorytet węzła
    current->priority = newPriority;

    // Wstaw węzeł w odpowiednie miejsce
    if (head == nullptr || head->priority > newPriority) 
    {
        current->next = head;
        head = current;
        if (tail == nullptr) 
        {
            tail = current; 
        }
    } else {
        // Znajdź odpowiednie miejsce w liście
        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority <= newPriority) 
        {
            temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
        if (current->next == nullptr) 
        {
            tail = current; 
        }
    }
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