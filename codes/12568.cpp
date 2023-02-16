#include"function.h"
void Push(Node** ptr_head, int x)
{
    Node* ptr;
    ptr = (Node*)malloc(sizeof(Node));
    ptr -> data = x;
    ptr -> next = *ptr_head;
    *ptr_head = ptr;
}

void Pop(Node** ptr_head)
{
    Node* ptr;
    ptr = *ptr_head;
    if(ptr == NULL)
    return;
    *ptr_head = (*ptr_head) -> next;
    free(ptr);
}

void Reverse_List(Node** ptr_head)
{
    Node* newhead, *find, *temp;
    newhead = NULL;
    while(*ptr_head != NULL)
    {
        find = *ptr_head;
        temp = (Node*)malloc(sizeof(Node));
        temp -> data = find -> data;
        temp -> next = newhead;
        newhead = temp;
        *ptr_head = (*ptr_head) -> next;
        free(find);
    }
    *ptr_head = newhead;

}
