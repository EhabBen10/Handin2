#include <iostream>
#include "Opgave4.cpp"
int main()
{
    Queue q;

    // Test isEmpty on an empty queue
    std::cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    // Add elements to the queue
    q.queue(1);
    q.queue(2);
    q.queue(3);

    // Test isEmpty on a non-empty queue
    std::cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    // Dequeue and print elements
    while (!q.isEmpty())
    {
        std::cout << "Dequeued: " << q.dequeue() << std::endl;
    }

    // Test isEmpty after all elements have been dequeued
    std::cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    // Try to dequeue from an empty queue
    q.dequeue();

    return 0;
}