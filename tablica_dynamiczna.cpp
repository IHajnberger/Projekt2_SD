#include "tablica_dynamiczna.hpp"
#include <iostream>

using namespace std;

TablicaDynamiczna::TablicaDynamiczna()
{
    data = new Element[capacity];
    size = 0;
    capacity = 10;
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
        capacity *= 2;
        Element* newData = new Element[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    int i = size - 1;
    while (i >= 0 && data[i].priority > priority)
    {
        data[i + 1] = data[i]; // Przesunięcie elementów w prawo
        i--;
    }
    data[i+1].priority = priority;
    data[i+1].value = value;
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
        throw runtime_error("Kolejka jest pusta");
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
