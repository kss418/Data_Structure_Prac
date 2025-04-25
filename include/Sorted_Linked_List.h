#pragma once

struct Sorted_Linked_List{
    void Create();
    void Insert(int value);
    int Delete(int value);
    int Search(int value);

    struct node{
        int value;
        node* next;
    };
};
