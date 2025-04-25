#pragma once

class Priority_Queue{
public:
    void Create(int max_size);
    void Top_down_Heapify(int index);
    void Bottom_up_Heapify(int index);
    void Push(int value);
    int Pop();
    int Top();
private:
    int size, max_size;
    int *arr;
};