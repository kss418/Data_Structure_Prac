#include "../include/Binary_Search_Tree.h"

void Binary_Search_Tree::Create(){
    root = nullptr;
}

void Binary_Search_Tree::Insert(int value){
    if(!root){
        root = new node;
        root->value = value;
        root->lchild = root->rchild = nullptr;
        return;
    }

    node* cur = root;
    while(cur != nullptr){
        if(cur->value == value) return;
        if(cur->value > value){
            if(cur->lchild == nullptr){
                node* nnode = new node;
                nnode->value = value;
                nnode->lchild = nnode->rchild = nullptr;
                cur->lchild = nnode;
                return;
            }
            else cur = cur->lchild;
        }
        else{
            if(cur->rchild == nullptr){
                node* nnode = new node;
                nnode->value = value;
                nnode->lchild = nnode->rchild = nullptr;
                cur->rchild = nnode;
                return;
            }
            else cur = cur->rchild;
        }
    }
}

void Binary_Search_Tree::Delete(int value){
    if(root == nullptr) return;
    if(root->Delete(value)){
        delete root;
        root = nullptr;
    }
}

int Binary_Search_Tree::node::Delete(int value){
    if(value == this->value){
        if(!this->lchild && !this->rchild) return 1;
        else if(!this->rchild){  
            node* dnode = this->lchild;
            this->value = dnode->value;
            this->rchild = dnode->rchild;
            this->lchild = dnode->lchild;
            delete dnode;
        }
        else if(!this->lchild){
            node* dnode = this->rchild;
            this->value = dnode->value;
            this->rchild = dnode->rchild;
            this->lchild = dnode->lchild;
            delete dnode;
        }
        else{
            this->value = this->lchild->Get_Max();
            if(this->lchild->Delete(this->value)){
                delete this->lchild;
                this->lchild = nullptr;
            }
        }
    }
    else if(value < this->value){
        if(!this->lchild) return 0;
        if(this->lchild->Delete(value)){
            delete this->lchild;
            this->lchild = nullptr;
        }
    }
    else{
        if(!this->rchild) return 0;
        if(this->rchild->Delete(value)){
            delete this->rchild;
            this->rchild = nullptr;
        }
    }

    return 0;
}

int Binary_Search_Tree::node::Get_Max(){
    if(!this->rchild) return this->value;
    return this->rchild->Get_Max();
}

Binary_Search_Tree::node* Binary_Search_Tree::Search(int value){
    node* cur = root;
    while(cur != nullptr){
        if(cur->value == value) return cur;
        if(cur->value > value) cur = cur->lchild;
        else cur = cur->rchild;
    }

    return nullptr;
}