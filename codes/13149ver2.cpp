#include<stdio.h>
#include<stdlib.h>
typedef struct _Node{
	int data;
	struct _Node* left;
	struct _Node* right;
}Node;

char bolstr[3005];
void constructTree(Node** head);
int callInfix(Node* root);
void freeTree(Node* root);

void constructTree(Node** head)
{
	int num;
	scanf("%d", &num);
	(*head) = (Node*)malloc(sizeof(Node));
	(*head) -> data = num;
	(*head) -> right = NULL;
	(*head) -> left = NULL;
	char c;
	c = getchar();
	if((*head) -> left == NULL && c == '?') constructTree(&(*head) -> left);
	if((*head) -> right == NULL && c == '?') constructTree(&(*head) -> right);
}


int callInfix(Node* root)
{
	if(root -> left == NULL && root -> right == NULL)
	{
		return(bolstr[root -> data-1] == '1');
	}
	if(bolstr[root -> data-1] == '1')
	{
		return callInfix(root -> left);
	}
	else return callInfix(root ->right);
}

void freeTree(Node* root)
{
	if(root != NULL)
	{
		freeTree(root -> left);
		freeTree(root -> right);
		free(root);	
	}
}


int main()
{
	Node* root = NULL;
	constructTree(&root);
	int num;
	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		scanf("%s", bolstr);
		int ans = 0;
		ans = callInfix(root);
		printf("%d\n", ans);
	}
	freeTree(root);
}


