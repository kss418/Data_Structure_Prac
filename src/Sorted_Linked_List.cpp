#include "../include/Sorted_Linked_List.h"

void Sorted_Linked_List::Create(){
    head = new node;
    tail = new node;

    head->next = tail;
    tail->prev = head;

    tail->next = nullptr;
    head->prev = nullptr;
}

void Sorted_Linked_List::Insert(int value){
    node* cur = head;
    while(cur->next != tail){
        if(cur->next->value >= value) break;
        cur = cur->next;
    }

    node* nnode = new node;
    nnode->value = value;

    cur->next->prev = nnode;
    nnode->next = cur->next;
    nnode->prev = cur;
    cur->next = nnode;
}

void Sorted_Linked_List::Delete(int value){
    node* cur = head;
    while(cur->next != tail){
        if(cur->next->value != value){
            cur = cur->next; continue;
        }
        
        node* dnode = cur->next;
        cur->next = dnode->next;
        cur->next->prev = cur;
        delete(dnode); return;
    }
}

Sorted_Linked_List::node* Sorted_Linked_List::Search(int value){
    node* cur = head->next;
    while(cur != tail){
        if(cur->value == value) return cur;
        cur = cur->next;
    }

    return nullptr;
}