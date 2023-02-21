#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node{
	char data;
	struct _Node *left;
	struct _Node *right;
}Node;

int ABCD[16][4] = 
{
  0,0,0,0,
  0,0,0,1,
  0,0,1,0,
  0,0,1,1,
  0,1,0,0,
  0,1,0,1,
  0,1,1,0,
  0,1,1,1,
  1,0,0,0,
  1,0,0,1,
  1,0,1,0,
  1,0,1,1,
  1,1,0,0,
  1,1,0,1,
  1,1,1,0,
  1,1,1,1
}; 

void constructTree(Node** head);
void printInfix(Node* root);
void freeTree(Node* root);

void constructTree(Node** head)
{
	char c;
	if((*head) == NULL)
	{
		(*head) = (Node*)malloc(sizeof(Node));
		c = getchar();
		(*head)->data = c;

        (*head)->left = (*head)->right = NULL;

        if((*head)->left == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
        if((*head)->right == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
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

void printInfix(Node *root)
{
 
	if (root->left != NULL) printInfix(root->left);
	printf("%c",root->data);
 	if (root->right !=NULL)
	{
	   if (root->right->data == '&' || root->right->data == '|')
	      printf("(");
	   printInfix(root->right);
	   if (root->right->data == '&' || root->right->data == '|')
	      printf(")");
    }  
    
}

int call(Node* root, int now)
{
	if(root -> left != NULL && root -> right != NULL)
	{
		if(root -> data == '&')
		return call(root -> left, now) & call(root -> right, now);
		if(root -> data == '|')
		return call(root -> left, now) | call(root -> right, now);
	}
	if(root -> left == NULL && root -> right == NULL)
		return ABCD[now][root -> data -'A'];
}

int main(void)
{

        Node *root=NULL;
        constructTree(&root);// construct syntax tree
        //printInfix(root);
        //printf("\n");
        
        for (int i=0;i<16;i++)
        {
         for (int j=0;j<4;j++)
           printf("%d ",ABCD[i][j]);
         printf("%d\n", call(root,i));
  }
        freeTree(root);
        
    return 0;
}
