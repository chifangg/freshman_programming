#include <stdio.h>
#include <stdlib.h>
#include"function.h"
Node* ages[6000];

Node* createList(int N)
{
	
	head = (Node*) malloc(sizeof(Node));
	head -> prev = NULL;
	head -> next = NULL;
	int num;
	scanf("%d", &num);
	head -> age = num;
	Node* cur = head;		
	int cnt = 0;
	ages[cnt] = head;
	//printf("%d\n", head -> age);
	cnt++;
	for(int i = 1; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode -> age = n;
		newnode -> prev = cur;
		newnode -> next = NULL;
		ages[cnt] = newnode; 
		cnt++;
		cur -> next = newnode;
		cur = newnode;		
//		printf("%d\n", cur -> age);
	}
	cur -> next = head;
	head -> prev = cur;
	return head;	
}

Node* solve(int N, int M)
{		
	Node* cur;
		
	for(int i = 0; i < M; i++)
	{
		
		cur = head;
		int person, move;
		scanf("%d%d", &person, &move);
		move = move%(N-1);
		if(move == 0)
			continue;
		//person--;
		cur = ages[person-1];
		//printf("%d\n", cur -> age);
			//	printf("cur: %d\n", cur -> age);
		Node* temp = cur;
		while(move--)
		{
			temp = temp -> next;
		}
//		printf("temp: %d\n", temp -> age);
		cur -> next -> prev = cur -> prev;
		cur -> prev -> next = cur -> next;
		cur -> next = temp -> next;
		cur -> prev = temp;
		temp -> next -> prev = cur;
		temp -> next = cur;

		
	}
	return head;
}



