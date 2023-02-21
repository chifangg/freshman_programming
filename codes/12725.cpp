#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000000001


typedef struct _Node{
	char data;
	int treevalue;
	struct _Node *left;
	struct _Node *right;
}Node;

void constructTree(Node** head);
int rightspin(Node **root);
int leftspin(Node **root);
int CallInfix(Node *root);
void freeTree(Node *root);

//int values[300000];

void constructTree(Node** head)
{
    char c;

    if((*head)==NULL) 
    {
        (*head) = (Node*)malloc(sizeof(Node));
         c = getchar();

         (*head)->data = c;
         (*head)->treevalue = MAX;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left == NULL && ((*head)->data=='+' || (*head)->data=='-' || (*head)->data=='*'))
            constructTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data=='+' || (*head)->data=='-' || (*head)->data=='*'))
            constructTree( &(*head)->right);
    }
    
}


int rightspin(Node **root)
{
	Node* tmp;
	if((*root) -> left -> data != '+' && (*root) -> left -> data != '*' && (*root) -> left -> data != '-')
	return 0;
	else
	{
		(*root) -> treevalue = MAX;//////////++
		tmp = (*root) -> left;
		(*root) -> left = tmp -> right;
		tmp -> right = *root;//connect to head
		tmp -> treevalue = MAX;/////++
		*root = tmp;//refresh head
		return 1;
		
	}
}

int leftspin(Node **root)
{
	Node *tmp;
	if((*root) -> right -> data != '+' && (*root) -> right -> data != '-' && (*root) -> right -> data != '*')
	return 0;
	else
	{
		tmp = (*root) -> right;
		(*root) -> right = tmp -> left;
		tmp -> left = *root;
		*root = tmp;
		return 1;
	}
	
}

int CallInfix(Node *root)
{		
	int total = 0;
	if(root -> left != NULL && root -> right != NULL)
	{
		if(root -> data == '+')
		{
			if(root -> left -> treevalue != MAX && root -> right -> treevalue != MAX)
			total = root -> left -> treevalue + root -> right -> treevalue;
			if(root -> left -> treevalue != MAX && root -> right -> treevalue == MAX)
			total = root -> left -> treevalue + CallInfix(root -> right);
			if(root -> left -> treevalue == MAX && root -> right -> treevalue != MAX)
			total = CallInfix(root -> left) + root -> right -> treevalue;
			if(root -> left -> treevalue == MAX && root -> right -> treevalue == MAX)
			total = CallInfix(root -> left) + CallInfix(root -> right);
			
			root -> treevalue = total;
			return total;
		 }
		if(root -> data == '*') 
		{
			if(root -> left -> treevalue != MAX && root -> right -> treevalue != MAX)
			total = root -> left -> treevalue * root -> right -> treevalue;
			if(root -> left -> treevalue != MAX && root -> right -> treevalue == MAX)
			total = root -> left -> treevalue * CallInfix(root -> right);
			if(root -> left -> treevalue == MAX && root -> right -> treevalue != MAX)
			total = CallInfix(root -> left) * root -> right -> treevalue;
			if(root -> left -> treevalue == MAX && root -> right -> treevalue == MAX)
			total = CallInfix(root -> left) * CallInfix(root -> right);
			
			root -> treevalue = total;
			return total;
		}
		if(root -> data == '-')
		{
			if(root -> left -> treevalue != MAX && root -> right -> treevalue != MAX)
			total = root -> left -> treevalue - root -> right -> treevalue;
			if(root -> left -> treevalue != MAX && root -> right -> treevalue == MAX)
			total = root -> left -> treevalue - CallInfix(root -> right);
			if(root -> left -> treevalue == MAX && root -> right -> treevalue != MAX)
			total = CallInfix(root -> left) - root -> right -> treevalue;
			if(root -> left -> treevalue == MAX && root -> right -> treevalue == MAX)
			total = CallInfix(root -> left) - CallInfix(root -> right);
			
			root -> treevalue = total;
			return total;
		}
	}
	else
	{
		total = (int)(root -> data - '0');
		root -> treevalue = total;
		return total;
	}
 } 

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


int main()
{
	int num;
	scanf("%d", &num);
	Node* root = NULL;
	getchar();
	constructTree(&root);
	int min = MAX;
	int now;
	//printf("first: %d\n", min);
	while(leftspin(&root))
	{
		//now = CallInfix(root);
		//if(now < min) min = now;	
	}
	now = CallInfix(root);
	if(now < min) min = now;
	while(rightspin(&root))
	{
		now = CallInfix(root);
		//printf("%d\n", now);
		if(now < min) min = now;	
	}
	
	printf("%d\n", min);
	freeTree(root);
	return 0;
	
}
