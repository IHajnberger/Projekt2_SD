#include "Node.hpp"
#include <iostream>

using namespace std;

NodePool::NodePool(int size) : head(nullptr), poolSize(size) 
{
    for (int i = 0; i < poolSize; ++i) 
    {
        Node* newNode = new Node(0, 0); // Tworzenie pustego węzła
        newNode->next = head;
        head = newNode;
    }
}

NodePool::~NodePool()
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp; 
    }
}

// Pobieranie elementu z puli
Node* NodePool::getNode(int priority, int value) 
{
    if (head == nullptr) 
    {
        return new Node(priority, value);
    }
    Node* node = head;
    head = head->next;
    node->priority = priority;
    node->value = value;
    node->next = nullptr;
    return node;
}

// Zwracanie elementu do puli
void NodePool::returnNode(Node* node) 
{
    node->next = head;
    head = node;
}