#include<stdio.h>
#include<stdlib.h>
#include"function.h"

void constructTree(Node** head)
{	
	char c;
	if((*head) == NULL && idx < strlen(s2))
	{
		(*head) = (Node*)malloc(sizeof(Node));
		c = s2[idx];
		(*head) -> data = c;
		idx++;
		(*head) -> left = NULL;
		(*head) -> right = NULL;
		if((*head)->right == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->right);
        if((*head)->left == NULL && ((*head)->data=='&' || (*head)->data=='|'))
            constructTree( &(*head)->left);
	}
}
