#include<stdio.h>
#include<stdlib.h>
#include"function.h"

Node* ReadOneList()
{
	Node* now = (Node*)malloc(sizeof(Node));
	scanf("%d: ", &(now->size));
	now -> data = (int*)malloc((now->size) * sizeof(int));
	for(int i = 0; i < (now->size); i++)
	{
		int num;
		scanf("%d ", &num);
		//getchar();
		now -> data[i] = num; /////////////////////check if * needed
	}
	now -> next = NULL;
	return now;	
}
void PrintList(Node* now)
{
	now = now -> next;
	while(now != NULL)
	{
		printf("%d", *(now -> data));
		for(int i = 1; i < (now -> size); i++)
		{
			printf(" %d", *((now -> data)+i));
		}
		printf("\n");
		//////////continue/////////////
		Node* tmp = now;
		now = now -> next;		
	}
		
}
void Merge(Node* now, int a, int b)
{
	///////find the place and the place before
	Node* before1 = now;
	Node* point1 = before1 -> next;
	Node* before2 = now;
	Node* point2 = before2 -> next;
	a--;//////////num-1
	///find the 'a'
	while(a > 0)
	{
		before1 = before1 -> next;
		point1 = point1 -> next;
//		if(point1 == NULL) return;
		a--;
	}
	b--;
	//find the 'b'
	while(b > 0)
	{
		before2 = before2 -> next;
		point2 = point2 -> next;
	//	if(point2 == NULL) return;
		b--;
	}
	/////////node size different ////
	//create new one
	//printf("%d %d\n", point1 -> size, point2 -> size);
	Node* newhead = (Node*)malloc(sizeof(Node));
	newhead -> size = (point1 -> size) + (point2 -> size);
	newhead -> data = (int*)malloc((newhead -> size)*sizeof(int));
	
	int rem = 0;//to remember 'i'
	for(int i = 0; i < point2 -> size; i++)
	{
		//movethe data into the newnode
		*((newhead -> data)+i) = *((point2 -> data)+i);//move
		rem = i;
	}
	//printf("%d\n", rem);
	for(int j = 0; j < point1 -> size; j++)
	{
		*((newhead -> data)+rem+j+1) = *((point1 -> data)+j);
	}
	
	//--------------------------------------
	//repoint!
	//if a is next to b -> special case to address
	if(point2 == before1)
	{
		before2 -> next = newhead;
		newhead -> next = point1 -> next;
	}
	else if(point1 == before2)
	{
		before1 -> next = newhead;
		newhead -> next = point2 -> next;
	}
	else
	{
		before2 -> next = newhead;
		newhead -> next = point2 -> next;
		before1 -> next = point1 -> next;
	}
	
	free(point1);
	//free(point1 -> data);
	free(point2);
	//free(point2 -> data);
	//----------------------------	
	
}
void Cut(Node* now, int a, int b)
{
	Node* before = now;
	Node* nownode = now -> next;
	a--;
	
	//find the 'a'
	while(a > 0)
	{
		before = before -> next;
		nownode = nownode -> next;
		a--;
	}
	//if(nownode -> size < 2) return;//only 1 can't cut
	int cut1 = b;
	int cut2 = nownode -> size - b;
	//printf("%d %d\n", cut1, cut2);
	Node* newhead1 = (Node*)malloc(sizeof(Node));
	Node* newhead2 = (Node*)malloc(sizeof(Node));
	newhead1 -> size = cut1;
	newhead2 -> size = cut2;
	newhead1 -> data = (int*)malloc(newhead1 -> size * sizeof(int));
	newhead2 -> data = (int*)malloc(newhead2 -> size * sizeof(int));
	int rem = 0;
	for(int i = 0; i < newhead1 -> size; i++)
	{
		*(newhead1 -> data+i) = *(nownode -> data+i);
		rem = i;
	}	
	for(int i = 0; i < newhead2 -> size; i++)
	{
		*(newhead2 -> data+i) = *((nownode -> data)+rem+i+1);
	}
	before -> next = newhead1;
	newhead1 -> next = newhead2;
	newhead2 -> next = nownode -> next;
	free(nownode -> data);
	free(nownode);
	
}
