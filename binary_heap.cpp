#include "binary_heap.hpp"
#include <iostream>
#include <vector>

using namespace std;

bool BinaryHeap::isEmpty()
{
    return heap.empty();
}

void BinaryHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (heap[index].priority >= heap[parentIndex].priority)
            break;

        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

void BinaryHeap::heapifyDown(int index)
{
    int size = heap.size();
    while (index < size)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallestIndex = index;

        if (left < size && heap[left].priority < heap[smallestIndex].priority)
            smallestIndex = left;

        if (right < size && heap[right].priority < heap[smallestIndex].priority)
            smallestIndex = right;

        if (smallestIndex == index)
            break;

        swap(heap[index], heap[smallestIndex]);
        index = smallestIndex;
    }
}

void BinaryHeap::push(int priority, int value)
{
    Value newValue;
    newValue.priority = priority;
    newValue.value = value;
    heap.push_back(newValue);
    heapifyUp(heap.size() - 1);
}

int BinaryHeap::pop()
{
    if (isEmpty())
    {
        cout << "Kolejka jest pusta" << endl;
        return -1;
    }
    int val = heap[0].value;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return val;
}

int BinaryHeap::peek()
{
    if (isEmpty())
    {
        cout << "Kolejka jest pusta" << endl;
        return -1;
    }
    return heap[0].value;
}

void BinaryHeap::modifyPriority(int oldPriority, int newPriority)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i].priority == oldPriority)
        {
            heap[i].priority = newPriority;
            heapifyUp(i);
            heapifyDown(i);
            break;
        }
    }
}
void BinaryHeap::printQ()
{
    if(isEmpty())
    {
        cout << "Kolejka jest pusta" << endl;
        return;
    }
    cout << "Kolejka: ";
    for (int i = 0; i < heap.size(); i++)
    {
        cout << "(" << heap[i].priority << ", " << heap[i].value << ") ";
    }
    cout << endl;
}
