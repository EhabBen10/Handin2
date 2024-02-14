#include <iostream>
#include <stack>

class Queue
{

private:
    std::stack<int> StackOne;
    std::stack<int> StackTwo;

public:
    // tilføjer elementer til køen
    void queue(int value)
    {
        StackOne.push(value);
    }

    // flytter elementer fra StackOne
    int dequeue()
    {
        if (StackTwo.empty())
        {
            // flyt fra StackOne når StackTwo er empty
            while (!StackOne.empty())
            {
                StackTwo.push(StackOne.top());
                StackOne.pop();
            }
        }

        if (StackTwo.empty())
        {
            // Queue is empty
            std::cerr << "Error: Queue is empty" << std::endl;
            return false;
        }

        // MÅSKE IKKE SÅDAN???
        //  udtager
        int Value = StackTwo.top();
        StackTwo.pop();
        return Value;
    }

    // Tjek om køen er tom
    bool isEmpty()
    {
        return StackOne.empty() && StackTwo.empty();
    }
};
