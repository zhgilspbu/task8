#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<iostream>
#include<iomanip>
#include "list.h"

using namespace std;

typedef struct bin_tree{

int id;
int key;
int path;
bin_tree* left;
bin_tree* right;

} tree;

void add(tree *&root, int num,int key,int cur_path, list *&head){

if (!root){
    root=new tree;
    root->id=num;
    root->key=key;
    root->path=cur_path;
    root->left=NULL;
    root->right=NULL;
    push(head,root->id,root->key);
}
else{
    if (!root->right && !root->left){
        rem(head,root->id);
    }
    if (num>root->id){
        add(root->right,num,key,cur_path+root->key,head);
    }else{
    add(root->left,num,key,cur_path+root->key,head);
    }
}
}


tree* minimum(tree* root){
if (!root->left)
    return root;
return minimum(root->left);
}

tree* pop (tree *&root, int num){


if (num<root->id){
    root->left=pop(root->left,num);
}
else if (num>root->id) {
    root->right=pop(root->right,num);
}
else if (root->left && root->right){
    root->id=minimum(root->right)->id;
    root->right=pop(root->right,root->id);
}
else{
    if (root->left){
            tree* ptr=root;
        root=root->left;
        delete(ptr);
    }
    else if (root->right){
        tree* ptr= root;
        root=root->right;
        delete(ptr);
    }

    else{
        tree* ptr=root;
        delete ptr;
        root=NULL;
    }
}
return root;
}

void show(tree *t, int n) {
  if (t != NULL) {
    show(t->left, n + 1);
    cout << setw(n * 6)<< t->id<<"("<<t->key<<")" << endl;
    show(t->right, n + 1);
  }
}

void print_path(tree *head, int num){
cout<<head->id<<" ";
if (num>head->id){
    print_path(head->right,num);
}
else if(num<head->id){
    print_path(head->left,num);
}
else{
    return;
}
}



#endif // TREE_H_INCLUDED
