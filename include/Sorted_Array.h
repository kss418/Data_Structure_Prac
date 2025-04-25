#pragma once

class Sorted_Array{
public:
    void Create(int size);
    void Insert(int value);
    void Delete(int value);
    int* Search(int value);
    int* Search(int value, int l, int r);
    int* Access(int index);
private:
    int size;
    int* arr;
};
