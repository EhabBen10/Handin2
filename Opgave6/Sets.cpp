#include <iostream>
#include <list>

using namespace std;

class Set {
private:
    list<int> elements;

public:
    void insert(int i) {
         if(!contains(i)||elements.size()==0){
            elements.push_back(i);
         }else{
            cout<<i<<" is already in the set"<<endl;
        }
    }

    void erase(int i) {
        if(find(elements.begin(),elements.end(),i)!=elements.end()){
            elements.remove(i);
        }
    }

    bool contains(int i) {
        bool contains = false;
        for (int j : elements){
            if(j==i){
                contains = true;
            }
        }
        return contains;
    }

    void print() const {
        for (int element : elements) {
            cout << element << " ";
        }
        cout<<endl;
    }
};