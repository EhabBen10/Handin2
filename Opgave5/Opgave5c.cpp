#include <iostream>
#include <vector>

using namespace std;

class HashTableQuadraticProbing {
private:
    vector<int> table;
    int size;// Størrelsen af hash-tabellen
    int keys;  // Antallet af nøgler i tabellen

public:
    HashTableQuadraticProbing(int tableSize) : size(tableSize),keys(0) {
        table.assign(size, -1);  // Initialiserer hash-tabellen med -1 -> en tom position
    }

    // Indsæt en nøgle i hash-tabellen ved hjælp af kvadratisk probing
    void insert(int key) {
        int index = key % size;
        int originalIndex = index;

        // Indsætte key ved at anvende kvadratisk probing
        int i = 1;
        while (table[index] != -1) {
            index = (originalIndex + i * i) % size;   // Opdater indeks ved hjælp af kvadratisk probing
            i++;

            if (index == originalIndex) {
                cout << "Fejl: Hash-tabellen er fuld." << endl;
                return;
            }
        }
        // Indsæt key på den fundne position i hash-tabellen
        table[index] = key;
        keys++; 
    }

    double loadFactor() const {
        return static_cast<double>(keys) / size;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTableQuadraticProbing tableQuadraticProbing(7);

    // Indsæt keys 
    tableQuadraticProbing.insert(5);
    tableQuadraticProbing.insert(28);
    tableQuadraticProbing.insert(19);
    tableQuadraticProbing.insert(15);
    tableQuadraticProbing.insert(20);
    tableQuadraticProbing.insert(33);
    tableQuadraticProbing.insert(12);
    tableQuadraticProbing.insert(17);
    tableQuadraticProbing.insert(33);
    tableQuadraticProbing.insert(10);

    // Vis hash-tabellen
    cout << "Kvadratisk Probing Hash Tabel:" << endl;
    tableQuadraticProbing.display();

    cout << "Load Factor: " << tableQuadraticProbing.loadFactor() << endl;

    return 0;
}
