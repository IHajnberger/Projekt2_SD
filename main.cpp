#include "tablica_dynamiczna.hpp"
#include "lista_wiazana.hpp"
#include "binary_heap.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// Funkcja do zapełniania struktury losowymi liczbami
template <typename Structure>
void fillStructure(Structure& structure, int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        structure.push(i, i); 
    }
}

// Funkcja do czyszczenia struktury
template <typename Structure>
void clearStructure(Structure& structure) {
    while (!structure.isEmpty()) {
        structure.pop();
    }
}

int main() {
    srand(time(0)); // Inicjalizacja generatora liczb losowych
    int rep = 50; // Liczba powtórzeń dla każdej operacji
    vector<int> tablice = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};

    // Otwieranie plików do zapisu wyników
    ofstream wyniki("wyniki.txt");
    if (!wyniki.is_open()) {
        cerr << "Nie można otworzyć pliku wyniki.txt!" << endl;
        return 1;
    }

    // Testowanie ListaWiazana
    ListaWiazana LW;
    wyniki << "Testowanie struktury: ListaWiazana" << endl;
    for (int dataSize : tablice) {
        wyniki << "Liczba elementów: " << dataSize << endl;

        // Wypełnienie struktury tylko raz
        fillStructure(LW, dataSize);

        // Testowanie operacji push
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            LW.push(rand() % dataSize, -1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            LW.pop(); // Usuwanie elementu po dodaniu
        }
        wyniki << "Średni czas operacji push: " << totalPushTime / rep << " ns" << endl;

        // Testowanie operacji pop
        long long totalPopTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            LW.pop();
            auto end = high_resolution_clock::now();
            totalPopTime += duration_cast<nanoseconds>(end - start).count();
            LW.push(rand() % dataSize, rand() % dataSize); // Dodawanie elementu po usunięciu
        }
        wyniki << "Średni czas operacji pop: " << totalPopTime / rep << " ns" << endl;

        // Testowanie operacji modifyPriority
        long long totalModifyTime = 0;
        for (int i = 0; i < rep; i++) {
            int oldPriority = rand() % dataSize;
            int newPriority = rand() % dataSize;
            auto start = high_resolution_clock::now();
            LW.modifyPriority(oldPriority, newPriority);
            auto end = high_resolution_clock::now();
            totalModifyTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji modifyPriority: " << totalModifyTime / rep << " ns" << endl;

        // Testowanie operacji peek
        long long totalPeekTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            LW.peek();
            auto end = high_resolution_clock::now();
            totalPeekTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji peek: " << totalPeekTime / rep << " ns" << endl;

        // Czyszczenie struktury po wszystkich testach dla danego rozmiaru
        clearStructure(LW);
    }

    // Analogiczne testy dla TablicaDynamiczna
    TablicaDynamiczna TD;
    wyniki << "Testowanie struktury: TablicaDynamiczna" << endl;
    for (int dataSize : tablice) {
        wyniki << "Liczba elementów: " << dataSize << endl;

        // Wypełnienie struktury tylko raz
        fillStructure(TD, dataSize);

        // Testowanie operacji push
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            TD.push(rand() % dataSize, -1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            TD.pop(); // Usuwanie elementu po dodaniu
        }
        wyniki << "Średni czas operacji push: " << totalPushTime / rep << " ns" << endl;

        // Testowanie operacji pop
        long long totalPopTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            TD.pop();
            auto end = high_resolution_clock::now();
            totalPopTime += duration_cast<nanoseconds>(end - start).count();
            TD.push(rand() % dataSize, rand() % dataSize); // Dodawanie elementu po usunięciu
        }
        wyniki << "Średni czas operacji pop: " << totalPopTime / rep << " ns" << endl;

        // Testowanie operacji modifyPriority
        long long totalModifyTime = 0;
        for (int i = 0; i < rep; i++) {
            int oldPriority = rand() % dataSize;
            int newPriority = rand() % dataSize;
            auto start = high_resolution_clock::now();
            TD.modifyPriority(oldPriority, newPriority);
            auto end = high_resolution_clock::now();
            totalModifyTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji modifyPriority: " << totalModifyTime / rep << " ns" << endl;

        // Testowanie operacji peek
        long long totalPeekTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            TD.peek();
            auto end = high_resolution_clock::now();
            totalPeekTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji peek: " << totalPeekTime / rep << " ns" << endl;

        // Czyszczenie struktury po wszystkich testach dla danego rozmiaru
        clearStructure(TD);
    }

    // Analogiczne testy dla BinaryHeap
    BinaryHeap BH;
    wyniki << "Testowanie struktury: BinaryHeap" << endl;
    for (int dataSize : tablice) {
        wyniki << "Liczba elementów: " << dataSize << endl;

        // Wypełnienie struktury tylko raz
        fillStructure(BH, dataSize);

        // Testowanie operacji push
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            BH.push(rand() % dataSize, -1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            BH.pop(); // Usuwanie elementu po dodaniu
        }
        wyniki << "Średni czas operacji push: " << totalPushTime / rep << " ns" << endl;

        // Testowanie operacji pop
        long long totalPopTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            BH.pop();
            auto end = high_resolution_clock::now();
            totalPopTime += duration_cast<nanoseconds>(end - start).count();
            BH.push(rand() % dataSize, rand() % dataSize); // Dodawanie elementu po usunięciu
        }
        wyniki << "Średni czas operacji pop: " << totalPopTime / rep << " ns" << endl;

        // Testowanie operacji modifyPriority
        long long totalModifyTime = 0;
        for (int i = 0; i < rep; i++) {
            int oldPriority = rand() % dataSize;
            int newPriority = rand() % dataSize;
            auto start = high_resolution_clock::now();
            BH.modifyPriority(oldPriority, newPriority);
            auto end = high_resolution_clock::now();
            totalModifyTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji modifyPriority: " << totalModifyTime / rep << " ns" << endl;

        // Testowanie operacji peek
        long long totalPeekTime = 0;
        for (int i = 0; i < rep; i++) {
            auto start = high_resolution_clock::now();
            BH.peek();
            auto end = high_resolution_clock::now();
            totalPeekTime += duration_cast<nanoseconds>(end - start).count();
        }
        wyniki << "Średni czas operacji peek: " << totalPeekTime / rep << " ns" << endl;

        // Czyszczenie struktury po wszystkich testach dla danego rozmiaru
        clearStructure(BH);
    }
    ofstream przypadki("przypadki.txt");
    if (!przypadki.is_open()) {
        cerr << "Nie można otworzyć pliku przypadki.txt!" << endl;
        return 1;
    }
    //============================================================
    // testy dla przypadku optymistycznego, średniego i pesymistycznego
    przypadki << "Testowanie struktury: ListaWiazana" << endl;
    for (int dataSize : tablice) 
    {
        fillStructure(LW, dataSize); // Przygotowanie struktury
        // ListaWiazana push
        przypadki<< "Liczba elementów: " << dataSize << endl;
        // Testowanie operacji push na początek listy
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.push(0, 1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            LW.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (optymistyczne): " << totalPushTime / rep << " ns" << endl;
        // Testowanie operacji push w środek listy
        long long totalPushTimeMiddle = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.push(dataSize / 2, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeMiddle += duration_cast<nanoseconds>(end - start).count();
            LW.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (średnie): " << totalPushTimeMiddle / rep << " ns" << endl;
        // Testowanie operacji push na koniec listy
        long long totalPushTimeEnd = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.push(dataSize - 1, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeEnd += duration_cast<nanoseconds>(end - start).count();
            LW.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (pesymistyczne): " << totalPushTimeEnd / rep << " ns" << endl;
        przypadki<<endl;

        // ListaWiazana pop - zawsze O(1) - nie potrzebne testy
        // ListaWiazana modifyPriority element na początku listy
        long long totalModifyTime = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.modifyPriority(0, 0);
            auto end = high_resolution_clock::now();
            totalModifyTime += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (optymistyczne): " << totalModifyTime / rep << " ns" << endl;
        // ListaWiazana modifyPriority element w środku listy
        long long totalModifyTimeMiddle = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.modifyPriority(dataSize / 2, 1);
            auto end = high_resolution_clock::now();
            totalModifyTimeMiddle += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (średnie): " << totalModifyTimeMiddle / rep << " ns" << endl;
        // ListaWiazana modifyPriority element na końcu listy
        long long totalModifyTimeEnd = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            LW.modifyPriority(dataSize - 1, 1);
            auto end = high_resolution_clock::now();
            totalModifyTimeEnd += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (pesymistyczne): " << totalModifyTimeEnd / rep << " ns" << endl;
        przypadki<<endl;
        clearStructure(LW); // Czyszczenie struktury po testach
        // ListaWiazana peek - zawsze O(1) - nie potrzebne testy
    }
    // Testowanie TablicaDynamiczna
    przypadki << "Testowanie struktury: TablicaDynamiczna" << endl;
    for(int dataSize : tablice) 
    {
        fillStructure(TD, dataSize-1); // Przygotowanie struktury
        // TablicaDynamiczna push
        przypadki<< "Liczba elementów: " << dataSize << endl;
        // Testowanie operacji push na początek tablicy
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.push(dataSize, 1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            TD.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (optymistyczne): " << totalPushTime / rep << " ns" << endl;
        // Testowanie operacji push w środek tablicy
        long long totalPushTimeMiddle = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.push(dataSize / 2, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeMiddle += duration_cast<nanoseconds>(end - start).count();
            TD.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (średnie): " << totalPushTimeMiddle / rep << " ns" << endl;
        // Testowanie operacji push na koniec tablicy
        long long totalPushTimeEnd = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.push(0, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeEnd += duration_cast<nanoseconds>(end - start).count();
            TD.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (pesymistyczne):" << totalPushTimeEnd / rep << " ns" << endl;
        przypadki<<endl;

        // TablicaDynamiczna pop - zawsze O(1) - nie potrzebne testy
        // TablicaDynamiczna modifyPriority element na początku tablicy
        //coś nie działa - będzie trzeba dodać wskaźnik lub coś
        long long totalModifyTime = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.modifyPriority(1, 0);
            auto end = high_resolution_clock::now();
            totalModifyTime += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (optymistyczne): " << totalModifyTime / rep << " ns" << endl;
        // TablicaDynamiczna modifyPriority element w środku tablicy
        long long totalModifyTimeMiddle = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.modifyPriority(dataSize / 2, 1);
            auto end = high_resolution_clock::now();
            totalModifyTimeMiddle += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (średnie): " << totalModifyTimeMiddle / rep << " ns" << endl;
        // TablicaDynamiczna modifyPriority element na końcu tablicy
        long long totalModifyTimeEnd = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            TD.modifyPriority(dataSize , 1);
            auto end = high_resolution_clock::now();
            totalModifyTimeEnd += duration_cast<nanoseconds>(end - start).count();
        }
        przypadki << "Średni czas operacji modifyPriority (pesymistyczne): " << totalModifyTimeEnd / rep << " ns" << endl;
        przypadki<<endl;
        clearStructure(TD); // Czyszczenie struktury po testach
    }
    // Testowanie BinaryHeap
    przypadki << "Testowanie struktury: BinaryHeap" << endl;
    for (int dataSize : tablice) 
    {
        fillStructure(BH, dataSize); // Przygotowanie struktury
        // BinaryHeap push
        przypadki<< "Liczba elementów: " << dataSize << endl;
        // Testowanie operacji push na początek tablicy
        long long totalPushTime = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            BH.push(dataSize-1, 1);
            auto end = high_resolution_clock::now();
            totalPushTime += duration_cast<nanoseconds>(end - start).count();
            BH.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (optymistyczne): " << totalPushTime / rep << " ns" << endl;
        // Testowanie operacji push w środek tablicy
        long long totalPushTimeMiddle = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            BH.push(dataSize / 2, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeMiddle += duration_cast<nanoseconds>(end - start).count();
            BH.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (średnie): " << totalPushTimeMiddle / rep << " ns" << endl;
        // Testowanie operacji push na koniec tablicy
        long long totalPushTimeEnd = 0;
        for (int i = 0; i < rep; i++) 
        {
            auto start = high_resolution_clock::now();
            BH.push(0, 1);
            auto end = high_resolution_clock::now();
            totalPushTimeEnd += duration_cast<nanoseconds>(end - start).count();
            BH.pop(); // Usuwanie elementu po dodaniu
        }
        przypadki << "Średni czas operacji push (pesymistyczne):" << totalPushTimeEnd / rep << " ns" << endl;
        przypadki<<endl;
        clearStructure(BH); // Czyszczenie struktury po testach
    }

    

    // Zamknięcie plików
    przypadki.close();
    wyniki.close();

    return 0;
}