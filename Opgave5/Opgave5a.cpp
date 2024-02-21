#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTableChaining {
private:
    vector<list<int>> table;
    int size; // Størrelsen af hash-tabellen
    int keys;

public:
    HashTableChaining(int tableSize) : size(tableSize),keys(0) {
        table.resize(size); // Initialiserer størrelsen af vektoren til at være lig med tabellens størrelse
    }

    void insert(int key) {
        int index = key % size; // Beregner hash-index ved at tage modulus af key
        table[index].push_back(key); // Indsætter key i linked listen ved den beregnede index
        keys++;
    
    }

    double loadFactor() const {
        return static_cast<double>(keys) / size;
    }


    //Udskriver 
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            for (const auto &value : table[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTableChaining tableChaining(7);
    // Indsætter keys
    tableChaining.insert(5);
    tableChaining.insert(28);
    tableChaining.insert(19);
    tableChaining.insert(15);
    tableChaining.insert(20);
    tableChaining.insert(33);
    tableChaining.insert(12);
    tableChaining.insert(17);
    tableChaining.insert(33);
    tableChaining.insert(10);

    // Display the hash table
    cout << "Chaining Hash Table:" << endl;
    tableChaining.display();

    cout << "Load Factor: " << tableChaining.loadFactor() << endl;

    return 0;
}
