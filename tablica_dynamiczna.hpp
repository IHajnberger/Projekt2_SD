#ifndef tablica_dynamiczna  
#define tablica_dynamiczna
#include <iostream>
struct Element
{
    int priority; //priorytet
    int value; //wartość
};
class TablicaDynamiczna
{
private:
Element* data;
int size;
int capacity;
public:
TablicaDynamiczna(); //konstruktor
~TablicaDynamiczna(); //destruktor
bool isEmpty(); //sprawdzenie czy tablica jest pusta
void push(int priority, int value); //dodawanie elementu
int pop(); //usuwanie elementu
int getSize(); //zwracanie rozmiaru tablicy
int peek(); //podejrzenie następnego elementu do usunięcia
void modifyPriority(int oldPriority, int newPriority); //zmiana priorytetu
void printQ(); //wyświetlanie tablicy/debugowanie
};
#endif


