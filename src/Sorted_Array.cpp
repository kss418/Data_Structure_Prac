#include "../include/Sorted_Array.h"

void Sorted_Array::Create(int size){
    arr = new int[size];
    this->size = 0;
}

void Sorted_Array::Insert(int value){
    int index = 0;
    while(index < size){
        if(*Access(index) > value) break;
        index++;
    }

    size++;
    for(int i = size - 1;i > index;i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

int* Sorted_Array::Access(int index){
    if(index < 0 || index >= size) return nullptr;
    return &arr[index];
}

int* Sorted_Array::Search(int value){
    return Search(value, 0, size - 1);
}

int* Sorted_Array::Search(int value, int l, int r){
    if(l > r) return nullptr;
    int mid = (l + r) / 2;
    if(*Access(mid) > value) return Search(value, l, mid - 1);
    else if(*Access(mid) < value) return Search(value, mid + 1, r);

    return Access(mid);
}

void Sorted_Array::Delete(int value){
    int index = 0;
    while(index < size){
        if(*Access(index) == value) break;
        index++;
    }

    if(index == size) return; size--;
    for(int i = index; i < size;i++){
        arr[i] = arr[i + 1];
    }
}