#include <iostream>
#include <vector>

using namespace std;

class HashTableLinearProbing {
private:
    vector<int> table;  
    int size;  // Størrelsen af hash-tabellen
    int keys;  // Antallet af nøgler i tabellen

public:
    HashTableLinearProbing(int tableSize) : size(tableSize), keys(0) {
        table.resize(size, -1);  // Initialiserer størrelsen af vektoren til at være lig med tabellens størrelse og fylder med -1 (markerer tomme positioner)
    }

    void insert(int key) {
        int index = key % size;  // Beregner hash-index ved at tage modulus af nøglen
        int originalIndex = index;

        while (table[index] != -1) { //kør indtil ledig position
            index = (index + 1) % size;  //øges med 1 og tager modulus 
            if (index == originalIndex) {
                cout << "Fejl: Hash-tabellen er fuld." << endl;
                return;
            }
        }

        table[index] = key;  // Indsæt key på den første ledige position
        keys++; //opdatere key
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
    HashTableLinearProbing tableLinearProbing(7);

    // Indsæt keys
    tableLinearProbing.insert(5);
    tableLinearProbing.insert(28);
    tableLinearProbing.insert(19);
    tableLinearProbing.insert(15);
    tableLinearProbing.insert(20);
    tableLinearProbing.insert(33);
    tableLinearProbing.insert(12);
    tableLinearProbing.insert(17);
    tableLinearProbing.insert(33);
    tableLinearProbing.insert(10);

    // Vis hash-tabellen for lineær probing
    cout << "Lineær Probing Hash Tabel:" << endl;
    tableLinearProbing.display();


    cout << "Load Factor: " << tableLinearProbing.loadFactor() << endl;
    return 0;
}
