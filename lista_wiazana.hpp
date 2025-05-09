#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
struct Node
{
    int priority; //priorytet
    int value; //wartość
    Node* next; //wskaźnik do następnego elementu
    Node(int prio, int value); //konstruktor
};
class ListaWiazana
{
    private:
    Node* head;//wskaźnik do pierwszego elementu listy
    Node* tail; //wskaźnik do ostatniego elementu listy
    int size = 0; //rozmiar listy
    public:
    ListaWiazana(); //konstruktor
    ~ListaWiazana(); //destruktor
    bool isEmpty(); //sprawdzenie czy lista jest pusta
    void push(int priority, int value); //dodawanie elementu
    int pop(); //usuwanie elementu   
    int getSize(); //zwracanie rozmiaru listy
    int peek(); //podejrzenie następnego elementu do usunięcia
    void modifyPriority(int oldPriority, int newPriority); //zmiana priorytetu
    void printQ(); //wyświetlanie listy/debugowanie 
};

#endif