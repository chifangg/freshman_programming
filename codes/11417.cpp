#include<iostream>
#include"function.h"

using namespace std;

Str::Str(char* c) // construct a new Str by linked list of Char
{
	int num = 0;
	if(c[num] != '\0')
	{
		Char* firstnode = new Char(c[num]);
		head = firstnode;
		tail = firstnode;
		num++;
		while(c[num] != '\0')
		{
			Char* newnode = new Char(c[num]);
			tail -> next = newnode;
			tail = newnode;
			num++;
		}
	}
}

		
Str::Str(const Str &str)// copy constructor
{
	head = new Char(str.head -> text);
	tail = head;
	Char* nextnode = str.head -> next;
	while(nextnode != NULL)
	{
		Char* newnode = new Char(nextnode -> text);
		tail -> next = newnode;
		tail = newnode;
		nextnode = nextnode -> next;
	}
}

Str&Str::strInsert(const Str &str)
{
	Str* temp = new Str(str);
	this -> tail -> next = temp -> head;
	this -> tail = temp -> tail;////////just stick it together directly
	return *this;
}
