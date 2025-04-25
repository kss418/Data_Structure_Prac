#pragma once

class Circular_Queue{
public:
    void Create(int size);
    bool Empty();
    bool Full();
    void Push(int value);
    int Pop();
    int Top();
private:
    int max_size;
    int head, tail, size;
    int* arr;
};