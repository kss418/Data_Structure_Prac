#include "../include/Circular_Queue.h"

void Circular_Queue::Create(int size){
    arr = new int[size];
    this->max_size = size;
    head = tail = this->size = 0;
}

bool Circular_Queue::Empty(){
    return size == 0;
}

bool Circular_Queue::Full(){
    return size == max_size;
}

void Circular_Queue::Push(int value){
    if(Full()) return;
    arr[head] = value; size++;
    head = (head + 1) % max_size;
}

int Circular_Queue::Pop(){
    if(Empty()) return 0;
    int ret = arr[tail]; size--;
    tail = (tail + 1) % max_size;
    return ret;
}

int Circular_Queue::Top(){
    if(Empty()) return 0;
    return arr[tail];
};