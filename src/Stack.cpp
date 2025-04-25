#include "../include/Stack.h"

void Stack::Create(int size){
    arr = new int[size];
    this->max_size = size;
    this->size = 0;
}

bool Stack::Empty(){
    return size == 0;
}

bool Stack::Full(){
    return size == max_size;
}

void Stack::Push(int value){
    if(Full()) return;
    arr[size++] = value;
}

int Stack::Pop(){
    if(Empty()) return 0;
    return arr[--size];
}

int Stack::Top(){
    if(Empty()) return 0;
    return arr[size - 1];
}
