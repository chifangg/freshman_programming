#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000000001
#define MINVAL -1000000001
int pindex;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
 
    return node;
}
 
// Recursive function to perform inorder traversal on a given binary tree
void inorder(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    inorder(root->left);
    printf("%d", root->key);
    inorder(root->right);
}
 
// Recursive function to perform inorder traversal on a given binary tree
void Preorder(struct Node* root)
{
    if (root != NULL) 
 {
        printf(" %d",root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}
 
// Recursive function to build a binary search tree from
// its postorder sequence
struct Node* constructBST(int postorder[], int start_min, int end_max)
{
    // base case
    if (pindex < 0) {
        return NULL;
    }

    int curr= postorder[pindex];

    if (curr < start_min || curr > end_max) {
        return NULL;
    }
    
    struct Node* node = newNode(curr);
     
    pindex--;
    node->right = constructBST(postorder, curr+1, end_max);

    node->left = constructBST(postorder, start_min, curr-1);

    return node;
}
 
int main(void)
{
    int inval,count=0;
    int postorder[200000];
 
    while(scanf("%d",&inval)!= EOF)
    {
     postorder[count]=inval;
     count++;
 }
 
    pindex=count-1;
    // construct the BST
    struct Node* root = constructBST(postorder, MINVAL, MAXVAL);
 
    // preorder on the BST always returns a sorted sequence
    printf("%d", root -> key);
    Preorder(root -> left);
    Preorder(root -> right);
    printf("\n");
 
    return 0;
}
