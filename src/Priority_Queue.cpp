#include "../include/Priority_Queue.h"

void Priority_Queue::Create(int max_size){
    this->max_size = max_size;
    size = 0;
    arr = new int[max_size];
}

void Priority_Queue::Top_down_Heapify(int index){
    if(2 * index + 1 >= size) return;

    if(2 * index + 2 < size){
        if(arr[2 * index + 1] < arr[index] && arr[2 * index + 2] < arr[index]) return;
        if(arr[2 * index + 1] > arr[2 * index + 2]){
            int temp = arr[2 * index + 1];
            arr[2 * index + 1] = arr[index];
            arr[index] = temp;
            Top_down_Heapify(2 * index + 1);
        }
        else{
            int temp = arr[2 * index + 2];
            arr[2 * index + 2] = arr[index];
            arr[index] = temp;
            Top_down_Heapify(2 * index + 2);
        }
    }
    else if(arr[2 * index + 1] > arr[index]){
        int temp = arr[2 * index + 1];
        arr[2 * index + 1] = arr[index];
        arr[index] = temp;
    }
}

void Priority_Queue::Bottom_up_Heapify(int index){
    if(!index || arr[(index - 1) / 2] > arr[index]) return;
    int temp = arr[(index - 1) / 2];
    arr[(index - 1) / 2] = arr[index];
    arr[index] = temp;
    Bottom_up_Heapify((index - 1) / 2);
}

void Priority_Queue::Push(int value){
    arr[size++] = value;
    Bottom_up_Heapify(size - 1);
}

int Priority_Queue::Pop(){
    if(!size) return 0;
    int ret = arr[0]; size--;
    arr[0] = arr[size];
    Top_down_Heapify(0);

    return ret;
}

int Priority_Queue::Top(){
    if(!size) return 0;
    return arr[0];
}