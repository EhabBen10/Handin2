#include <iostream>
#include <vector>

using namespace std;

class HashTableQuadraticProbing {
private:
    vector<int> table;
    int size;  // Størrelsen af hash-tabellen
    int keys;  // Antallet af keys

public:
    HashTableQuadraticProbing(int tableSize) : size(tableSize), keys(0) {
        table.assign(size, -1);  // Initialiserer hash-tabellen med -1 -> en tom position
    }

    // Hash-funktion
    int hashFunction(int key) const {
        return key % size;
    }

    // Indsæt en key i hash-tabellen ved hjælp af kvadratisk probing
    void insert(int key) {
        int index = hashFunction(key);
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
        keys++;  // Opdater antallet af nøgler
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTableQuadraticProbing hashTable(11);

    // Indsæt de givne værdier
    hashTable.insert(22);
    hashTable.insert(5);
    hashTable.insert(16);
    hashTable.insert(27);

    // hash-tabellen
    cout << "Hashtabellen efter indsatte værdier:" << endl;
    hashTable.display();
    
    // Nye værdier (1, 12, alder, studienummer)
    hashTable.insert(1);
    hashTable.insert(12);

    int dinAlder = 23;
    int ditStudienummer = 123456;

    hashTable.insert(dinAlder);
    hashTable.insert(ditStudienummer);

    // Vis hash-tabellen efter nye indsatte værdier
    cout << "\nHashtabellen efter yderligere indsatte værdier:" << endl;
    hashTable.display();

    return 0;
}
