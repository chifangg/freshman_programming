#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"


#define MAXEXPR 256
#define NUMSYM 6


BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);

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
            newNode -> data = ID_A;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        case 'B':
            newNode -> data = ID_B;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case 'C':
            newNode -> data = ID_C;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case 'D':
            newNode -> data = ID_D;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;


        case '&':
            newNode -> data = OP_AND;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        case '|':
            newNode -> data = OP_OR;
            newNode -> right = NULL;
            newNode -> left = NULL;
            break;

        return newNode;



    }
    return newNode;
}
