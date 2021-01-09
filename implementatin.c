#include <stdio.h>
#include <conio.h>
typedef struct Node
{
    int item;
    struct Node *ptr;
} Node;

Node* createNode(int data)
{
    Node* temp=(Node *)malloc(sizeof(Node));
    temp->item=data;
    temp->ptr=NULL;
    return temp;
}

void printLinkedList(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->item);
        temp = temp->ptr;
    }
    printf("NULL\n");
}

int lengthLinkedList(Node* Head)
{
    int length=0;
    Node* cur=Head;
    while(cur!=NULL)
    {
        cur=cur->ptr;
        length++;
    }
    return length;
}

Node* addAtIndex(Node* Head, Node* temp, int idx)
{
    int length=lengthLinkedList(Head);
    if(idx>length)
    {
        printf("Index Invalid\n");
        return Head;
    }
    if(idx==0)
    {
        Head=addAtStart(Head,temp);
        return Head;
    }
    if(idx==length)
    {
        Head=addAtEnd(Head,temp);
        return Head;
    }
    Node* cur=Head;
    Node* next;
    for(int i=0;i<idx-1;i++)
    {
        cur=cur->ptr;
    }
    next=cur->ptr;
    cur->ptr=temp;
    temp->ptr=next;
    return Head;
}

