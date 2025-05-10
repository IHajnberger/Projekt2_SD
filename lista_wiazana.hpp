#ifndef lista_wiazana
#define lista_wiazana
#include <iostream>
#include "Node.hpp" // Wymagane dla struktury Node

class ListaWiazana
{
    private:
    Node* head;//wskaźnik do pierwszego elementu listy
    Node* tail; //wskaźnik do ostatniego elementu listy
    int size = 0; //rozmiar listy
    NodePool* nodePool; // Wskaźnik do puli węzłów
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