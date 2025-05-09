#ifndef binary_heap
#define binary_heap
#include <iostream>
#include <vector>

struct Value
    {
        int priority; //priorytet
        int value; //wartość
    };
class BinaryHeap
{
private:
    std::vector<Value> heap; //tablica dynamiczna
    void heapifyUp(int index); //przesunięcie elementu w górę
    void heapifyDown(int index); //przesunięcie elementu w dół
public:
    bool isEmpty(); //sprawdzenie czy tablica jest pusta
    void push(int priority, int value); //dodawanie elementu
    int pop(); //usuwanie elementu
    int peek(); //podejrzenie następnego elementu do usunięcia
    void modifyPriority(int oldPriority, int newPriority); //zmiana priorytetu
    void printQ(); //wyświetlanie tablicy/debugowanie
};

#endif