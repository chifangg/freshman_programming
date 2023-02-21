#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node* left;
	struct _Node* right;
}Node;

typedef struct _saveNode
{
	Node* root;
	struct _saveNode* next;
}saveNode;


void Preorder(Node* root)
{
	if(root != NULL)
	{
		printf(" %d", root -> data);
		Preorder(root -> left);
		Preorder(root -> right);
	}
}

saveNode* check(int left, int right)
{
	saveNode* head = NULL;
	saveNode* tail = NULL;
	
	if(left > right)
	{
		head = (saveNode*)malloc(sizeof(saveNode));
        head -> root = NULL;
		head -> next = NULL;
        return head;
    }
    for(int i = left; i <= right; i++)
    {
    	saveNode *newleft = check(left, i-1);
    	saveNode* newright = check(i+1, right);
    	
    	while(newleft != NULL)
    	{
    		saveNode* moveto = newright;
    		while(moveto != NULL)
    		{
    			Node* newnode = (Node*)malloc(sizeof(Node));
    			newnode -> data = i;
    			newnode -> left = newleft -> root;
    			newnode -> right = moveto -> root;
    			
    			saveNode* add = (saveNode*)malloc(sizeof(saveNode));
    			add -> root = newnode;
    			add -> next = NULL;
    			if(head == NULL)
    			{
    				head = add;
    				tail = add;
				}
				else
				{
					tail -> next = add;
					tail = add;
				}
				moveto = moveto -> next;
			}
			newleft = newleft -> next;
		}
    	
	}
	return head;	
}

int main()
{
	int num;
	scanf("%d", &num);
	saveNode* listhead = check(1, num);
	while(listhead != NULL)
	{
		Node* root = listhead -> root;
		printf("%d", root -> data);
		Preorder(root -> left);
		Preorder(root -> right);
		printf("\n");
		listhead = listhead -> next;
	}
}
