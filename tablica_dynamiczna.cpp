#include "tablica_dynamiczna.hpp"
#include <iostream>

using namespace std;

TablicaDynamiczna::TablicaDynamiczna():capacity(10), size(0)
{
    data = new Element[capacity];
}
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] data;
}
bool TablicaDynamiczna::isEmpty()
{
    return size == 0;
}
void TablicaDynamiczna::push(int priority, int value)
{
    if (size == capacity)
    {
        // Zwiększenie pojemności i realokacja pamięci
        int new_capacity = capacity * 2;
        Element* new_data = new Element[new_capacity];
        std::copy(data, data + size, new_data); // Kopiowanie elementów
        delete[] data; // Zwolnienie starej pamięci
        data = new_data; // Przypisanie nowej pamięci
        capacity = new_capacity; // Zmiana pojemności
    }

    // Wstawianie elementu w odpowiednie miejsce (zachowanie porządku według priorytetu)
    int i = size - 1;
    while (i >= 0 && data[i].priority > priority)
    {
        data[i + 1] = data[i]; // Przesunięcie elementów w prawo
        i--;
    }
    data[i + 1].priority = priority;
    data[i + 1].value = value;
    size++;
}
int TablicaDynamiczna::pop()
{
    if (isEmpty())
    {
        cout<<"Kolejka jest pusta"<<endl;
        return -1;
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (data[i].priority < data[minIndex].priority)
        {
            minIndex = i;
        }
    }
    int val = data[minIndex].value;
    for (int i = minIndex; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    return val;
}
int TablicaDynamiczna::getSize()
{
    return size;
}
int TablicaDynamiczna::peek()
{
    if (isEmpty())
    {
        cout<<"Kolejka jest pusta"<<endl;
        return -1;
    }
    return data[0].value;
}
void TablicaDynamiczna::modifyPriority(int oldPriority, int newPriority)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (data[i].priority == oldPriority)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout<<"Nie znaleziono elementu"<<endl;
        return;
    }
    int value = data[index].value;
    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
    push(newPriority, value);
}
void TablicaDynamiczna::printQ()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Priorytet: " << data[i].priority << ", Wartosc: " << data[i].value << endl;
    }
}
