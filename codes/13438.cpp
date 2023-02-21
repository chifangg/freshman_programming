#include<stdio.h>
#include<stdlib.h>
#include"function.h"




Node* createList(int n)
{

    head = (Node*)malloc(sizeof(Node));
    head -> prev = NULL;
//    head -> next = NULL;
    int cnt = 1;
    head -> number = cnt;
    Node* printhead = head;
    Node* cur = head;
//    cur -> next = head -> next;
    while(cnt < n)
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        cnt++;
        newnode -> number = cnt;
        newnode -> next = NULL;
        newnode -> prev = cur;
        cur -> next = newnode;
        cur = newnode;
    }

	return head;
}
void solve(int n, int m)
{
    Node* cur = head;
    //cur -> next = head -> next;
    
    //cur = cur -> next;
    n--;

    while(n > 0)
	{
        cur = cur -> next;
		n--;
	}
	Node* temp = cur;
	while(m-- && temp -> next != NULL)
    {
        temp = temp -> next;
    }
    
    if(cur == head)
    {
    	head = cur -> next;
	}
    if(cur -> next != NULL)
    {
	    cur -> next -> prev = cur -> prev;//////
	    if(cur -> prev != NULL)
	    {
	    	cur -> prev -> next = cur -> next;
		}
	    
	    //temp -> next -> prev = temp -> next;
	    cur -> next = temp -> next;
	    cur -> prev = temp;
	    temp -> next = cur;
	    if(cur -> next != NULL)
	    {	
	    	cur -> next -> prev = cur;///////
		}
	}
	Node* printhead = head;
	while(printhead -> next!= NULL)
    {
        printf("%d ", printhead -> number);
        printhead = printhead -> next;

    }
    printf("%d\n", printhead -> number);
    
    int from, to;
    while(scanf("%d%d", &from, &to) != EOF)
    {
        solve(from, to);
    }


}
