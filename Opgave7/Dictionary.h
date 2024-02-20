#pragma once
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Dictionary
{
private:
    vector<pair<int, string>> d;

public:
    bool insert(pair<int, string>);
    void remove(pair<int, string>);
    bool contains(pair<int, string>);
};
