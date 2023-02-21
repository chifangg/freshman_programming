#include <iostream>
#include "function.h"
using namespace std;
Array_BST :: Array_BST():BST(){
    for(int i=0;i<1025;i++){
        array[i] = 0;
    }
}
void Array_BST :: insert(const int &num){
    int idx = 1, h = 1;
    while(array[idx]!=0){
        if(num<array[idx]){
            idx = idx * 2;
        }
        else if(num>array[idx]){
            idx = idx * 2 + 1;
        }
  else if(num == array[idx])  //WA1
            return;
        h++;
    }
    if(h>Height) //WA3
        Height = h; 
    array[idx] = num;
    return;
}
bool Array_BST :: search(const int &num) const{
    for(int i=0;i<1025;i++){
        if(array[i]==num)
            return true;
    }
    return false;
}

List_BST :: List_BST() : root(NULL),BST()
    {
    }
void List_BST :: insert(const int &num){
    if(root == NULL){
        root = createLeaf(num);
        return;
    }
    int h=1;
    ListNode* tmp = root;
    while(tmp!=NULL){
        if(num > tmp->key){
            h++;
            if(tmp->right == NULL){
                tmp->right = createLeaf(num);
                break;
            }
            tmp = tmp->right;
        }

        else if(num < tmp->key){
            h++;
            if(tmp->left == NULL){
                tmp->left = createLeaf(num);
                break;
            }
            tmp = tmp->left;
        }
  else if(num == tmp->key)  //WA1
            return;
  //h++; //WA2
    }
    if(h>Height) //WA3
        Height = h; 
    return;
}
bool List_BST :: search(const int &num) const{
    ListNode* tmp = root;
    while(tmp!=NULL){
        if(num < tmp->key)  
            tmp = tmp->left;
        else if(num > tmp->key)  
            tmp = tmp->right;
        else if(num == tmp->key)
            return true;    
    }
    return false;
}
ListNode* List_BST :: createLeaf(int key) const{
    ListNode* node = new ListNode(key);
    return node;
}
void List_BST :: deleteTree(ListNode *root){
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
