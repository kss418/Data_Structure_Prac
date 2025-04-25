#pragma once

class Stack{
public:
    void Create(int size);
    bool Empty();
    bool Full();
    void Push(int value);
    int Pop();
    int Top();

private:
    int size, max_size;
    int* arr;
};