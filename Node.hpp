#ifndef Nodepool
#define Nodepool
//Struktura pozwalająca na zarządzanie pamięcią dla węzłów listy
//zapobiegająca fragmentacji pamięci
struct Node
{
    int priority; //priorytet
    int value; //wartość
    Node* next; //wskaźnik do następnego elementu
    Node(int prio, int value); //konstruktor

};

class NodePool 
{
private:
    Node* head; // Wskaźnik do pierwszego elementu puli
    int poolSize; // Rozmiar puli

public:
    NodePool(int size = 100); // Konstruktor z domyślnym rozmiarem puli
    ~NodePool(); // Destruktor

    Node* getNode(int priority, int value); // Pobieranie elementu z puli
    void returnNode(Node* node); // Zwracanie elementu do puli
};

#endif 