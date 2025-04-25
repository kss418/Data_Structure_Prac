#pragma once

class Sorted_Linked_List{
public:
    class node{
    public:
        int value;
        node *prev, *next;
    };
    
    void Create();
    node* Search(int value);
    void Insert(int value);
    void Delete(int value);

private:
    node* head, *tail;
};
