#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "function.h"
using namespace std;
List_stack::List_stack()
{
	this -> head = this -> tail = NULL;
}

List_stack::~List_stack()
{
	
}
void List_stack::push(const int &n)
{
	ListNode *newnode;
	newnode =  new ListNode(n);//////new?
	newnode -> prevPtr = this -> tail;
	this -> tail = newnode;
}

void List_stack::pop()
{
	if(this -> tail == NULL)return;
	ListNode *temp;
	temp = this -> tail;
	this -> tail = this -> tail -> prevPtr;
	free(temp);
}
void List_stack::print()
{
	ListNode *now = this -> tail;
	while(now != NULL)
	{
		if(now -> prevPtr != NULL) cout << now -> data << " ";
		else 
		{
			cout << now -> data;
			break;
		}
		now = now -> prevPtr;
	}
	
}
