#pragma once

class Sorted_Linked_List{
public:
    void Create();
    int Search(int value);
    int Insert(int value);
    int Delete(int value);

private:
    class node{
        int value;
        node *prev, *next;
    };

    node* head;
};
