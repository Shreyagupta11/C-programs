#include <stdio.h>
#include <conio.h>

typedef struct Node
{
    int item;
    struct Node *ptr;
} Node;

Node *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->item = data;
    temp->ptr = NULL;
    return temp;
}

Node *addAtStart(Node *Head, Node *temp)
{
    if (Head == NULL)
    {
        Head = temp;
        return Head;
    }
    Node *tHead = Head;                                  // variable tHead is declaring//
    Head = temp;
    Head->ptr = tHead;

    return Head;
}

Node *addAtEnd(Node *Head, Node *temp)
{
    if (Head == NULL)
    {
        Head = temp;
        return Head;
    }
    Node *cur = Head;
    while (cur->ptr != NULL)
    {
        cur = cur->ptr;
    }
    cur->ptr = temp;
    return Head;
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

int lengthLinkedList(Node *Head)
{
    int length = 0;
    Node *cur = Head;
    while (cur != NULL)
    {
        cur = cur->ptr;
        length++;
    }
    return length;
}

Node *addAtIndex(Node *Head, Node *temp, int idx)
{
    int length = lengthLinkedList(Head);
    if (idx > length)
    {
        printf("Index Invalid\n");
        return Head;
    }
    if (idx == 0)
    {
        Head = addAtStart(Head, temp);
        return Head;
    }
    if (idx == length)
    {
        Head = addAtEnd(Head, temp);
        return Head;
    }
    Node *cur = Head;
    Node *next;
    for (int i = 0; i < idx - 1; i++)
    {
        cur = cur->ptr;
    }
    next = cur->ptr;
    cur->ptr = temp;
    temp->ptr = next;
    return Head;
}

Node* deleteAtStart(Node* Head)
{
    if(Head==NULL)
    {
        return Head;
    }
    Node* temp=Head;
    Head=Head->ptr;
    free(temp);
    return Head;
}

Node* deleteAtEnd(Node* Head)
{
    if(Head==NULL)
    {
        return Head;
    }
    Node* temp=Head;
    Node* cur;
    {
    while(temp->ptr!=NULL)
    {
        cur=temp;
        temp=temp->ptr;
    }
        cur->ptr=NULL;
        free(temp);
        return Head;
    }
}

Node* deleAtIndex(Node* Head,Node* idx)
{
    if(Head==NULL)
    {
        return Head;
    }
    Node* temp=Head;
    Node* tHead;
    {
        while(temp)
    }
}

int main()
{
    printf("INSTRUCTIONS\n");
    printf("1: To Add an element at start, use mode B [INPUT NUMBER]\n");
    printf("2: To Add an element at End, use mode E [INPUT NUMBER]\n");
    printf("3: To Add an element at Index, use mode I [INPUT NUMBER, INDEX]\n");
    printf("4: To Print the Linked List, use mode P\n");
    printf("5: To delete the first element, use mode X\n");
    printf("6: to delete element from last,use mode Y\n");
    printf("TO QUIT THE PROGRAM, use mode Q\n");

    Node *Head = NULL;

    while (1)
    {
        char mode;
        printf("\nENTER MODE: ");
        scanf(" %c", &mode);
        if (mode == 'Q')
        {
            break;
        }
        else if (mode == 'B')
        {
            int N;
            printf("Enter the Number: ");
            scanf("%d", &N);
            Head = addAtStart(Head, createNode(N));
        }
        else if (mode == 'E')
        {
            int N;
            printf("Enter the Number: ");
            scanf("%d", &N);
            Head = addAtEnd(Head, createNode(N));
        }
        else if (mode == 'I')
        {
            int N;
            int idx;
            printf("Enter the Number: ");
            scanf("%d", &N);
            printf("Enter the Index: ");
            scanf("%d", &idx);
            Head = addAtIndex(Head, createNode(N), idx);
        }
        else if (mode == 'P')
        {
            printLinkedList(Head);
        }
        else if(mode=='X')
        {
            Head= deleteAtStart(Head);
        }
        else if(mode=='Y')
        {
            Head= deleteAtEnd(Head);
        }
        else
        {
            printf("ENTER A VALID MODE\n");
        }
    }

    return 0;
}
