#pragma once
class StackArray
{
public:
    StackArray(int size = 100);
    ~StackArray();
    void push(int x);
    int pop();
    void print() const;

private:
    int *arrPtr_;
    int top_;
    int size_;
};
