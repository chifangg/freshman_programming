#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	char letter;
	struct _Node* next;
	struct _Node* prev;
}Node;

void delete_node(Node** rightnow);
void keyin(Node** now, char letter);
void printlist(Node* head);

int main()
{
	int num;
	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		Node* head = (Node*) malloc(sizeof(Node));
		head -> next = NULL;
		head -> prev = NULL;
		Node* cur = head;
		int count;
		scanf("%d", &count);
		//printf("%d\n", count);
		getchar();
		for(int j = 0; j < count; j++)
		{
			//printf("j: %d\n", j);
			char letter;
			letter = getchar();
			//printf("now is %c\n", letter);
			if(letter == 'B')
			{
				//printf("backspace\n");
				delete_node(&cur);//&&&&&&&&&&&&&!
			}
			else if(letter == 'R')
			{
				//printf("go right\n");
				if(cur -> next != NULL) 
				cur = cur -> next;
			}
			else if(letter == 'L')
			{
				//printf("go left\n");
				if(cur -> prev != NULL) 
				cur = cur -> prev;	
			}
			else 
			{
				keyin(&cur, letter);
			}
			
		}
		printlist(head);
		
	}	
	
	return 0;
	
}
void delete_node(Node** rightnow)
{
	Node* cur;////no malloc!!!
	cur = *rightnow;
	if(cur -> prev == NULL) return;
	if(cur -> next == NULL)//last
	{
		*rightnow = cur -> prev;
		(*rightnow) -> next = NULL;//()must!!
		free(cur);
	}
	else //middle
	{
		cur -> next -> prev = cur-> prev;
		cur -> prev -> next = cur -> next;
		(*rightnow) = cur -> prev;
		free(cur); 	
	}
	
	
}

void keyin(Node** now, char letter)
{
	Node* cur = *now; 
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode -> letter = letter;
	newnode -> next = cur -> next;//////now
	newnode -> prev = cur;///////////now
	
	if(cur -> next != NULL)
	{
		cur -> next -> prev = newnode;
	}
	cur -> next = newnode;
	(*now) = newnode;////dummy node disappear
	
}

void printlist(Node* head)
{
	Node* cur;
	cur = head -> next;
	while(cur != NULL)
	{
		printf("%c", cur -> letter);
		Node* tmp;// = (Node*)malloc(sizeof(Node))
		tmp = cur;
		cur = cur -> next;
		free(tmp);
	}
	free(head);
	printf("\n");
}






