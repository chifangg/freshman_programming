#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR]; 
int pos;             

//typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    char data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void printInfix(BTNode *root);
void freeTree(BTNode *root);

BTNode* EXPR()
{
    BTNode* right_expr = FACTOR();
    if(pos == -1 || expr[pos] == '(') return right_expr;
    BTNode* head = makeNode(expr[pos--]);
    head -> right = right_expr;
    head -> left = EXPR();
    return head;

}

BTNode* FACTOR()
{
    char input = expr[pos--];
    BTNode* factorized;
    switch(input)
    {
        case ')': {
        factorized = EXPR();
        pos--;
        return factorized;
        }
        default:
            return makeNode(input);
    }
}

BTNode* makeNode(char c)
{
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));

    switch(c)
    {
        case 'A':
            newNode -> data = 'A';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        case 'B':
            newNode -> data = 'B';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case 'C':
            newNode -> data = 'C';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case 'D':
            newNode -> data = 'D';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case '&':
            newNode -> data = '&';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        case '|':
            newNode -> data = '|';
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        return newNode;



    }
    return newNode;
}

void freeTree(BTNode *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void printInfix(BTNode *root)
{
	if (root->left != NULL) printInfix(root->left);
	printf("%c", root->data);
	if (root->right != NULL)
	{
//		printf("here");
		if (root->right->data == '&' || root->right->data == '|')
		{
			printf("(");
		}
	      
	    printInfix(root->right);
	    if (root->right->data == '&' || root->right->data == '|')
	      printf(")");
	}  
}

int main(void)
{
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printInfix(root);
//        printf("\n");
        freeTree(root);
    }

    return 0;
    
}

