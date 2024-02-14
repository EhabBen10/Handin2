#include <iostream>
#include "StackArray.h"

StackArray::StackArray(int size)
{
    Capacity = size;
    arrPtr_ = new int[Capacity];
    top_ = -1;
}
StackArray::~StackArray()
{
    delete[] arrPtr_;
}

void StackArray::push(int x)
{
    if (top_ < Capacity)
    {
        arrPtr_[top_++] = x;
    }
    else
    {
        std::cout << "Stack is full" << std::endl;
        int *temp = new int[Capacity * 2];
        std::cout << "A new array is located with double the size" << std::endl;
        for (int i = 0; i < Capacity; i++)
        {
            temp[i] = arrPtr_[i];
        }
        std::cout << "The old values are located the new array" << std::endl;
        for (size_t i = Capacity; i < Capacity * 2; i++)
        {
            temp[i] = 0;
        }
        std::cout << "The rest of the values are null" << std::endl;
        delete[] arrPtr_;
        arrPtr_ = temp;
        arrPtr_[top_] = x;
        top_++;
        Capacity *= 2;
    }
}

int StackArray::pop()
{
    top_--;
    return arrPtr_[top_];
}

void StackArray::print() const
{
    std::cout << "The size" << std::endl;
    for (int i = 0; i < top_; i++)
    {
        std::cout << arrPtr_[i] << " ";
    }
    std::cout << std::endl;
}