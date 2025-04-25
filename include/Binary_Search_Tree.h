#pragma once

class Binary_Search_Tree{
public:
    class node{
    public:
        int value;
        node* lchild, *rchild;
        int Delete(int value);
        int Get_Max();
    };

    void Create();
    void Insert(int value);
    void Delete(int value);
    node* Search(int value);
private:
    node* root;
};