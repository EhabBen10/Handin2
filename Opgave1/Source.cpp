#include "StackArray.cpp"
#include <iostream>
#include "StackArray.h"

using namespace std;

int main()
{
    StackArray sa;

    sa.print();

    sa.push(2);
    sa.print();

    for (size_t i = 0; i < 100; i++)
    {
        sa.push(i);
    }
    sa.print();

    cout << "Pop: " << sa.pop() << endl;
    cout << "Pop: " << sa.pop() << endl;
    cout << "Pop: " << sa.pop() << endl;
    cout << "Pop: " << sa.pop() << endl;
    sa.print();
    return 0;
}