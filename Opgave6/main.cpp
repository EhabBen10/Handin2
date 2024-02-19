#include <iostream>
#include "Sets.cpp"

using namespace std;

int main() {
    Set mySet;
    
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(2);

    mySet.print();
    mySet.erase(2);
    mySet.print();

    std::cout << "Is 1 in the set? " << (mySet.contains(1) ? "Yes" : "No") << endl;

    return 1;
}
