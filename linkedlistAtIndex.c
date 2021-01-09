#include<stdio.h>
#include<conio.h>
typedef struct Node
{
    int data;
     struct Node* ptr;
}Node;
struct node* Head;

void insertAtRandom();
void display();

void main()
{
    insertatRandom();
    display();
}

void insertatRandom()
{
int i,loc,value;
struct Node *temp,*cur;
temp=(struct Node*)malloc(sizeof(struct Node*));
if(temp==NULL)
{
    printf("\n Overflow");
    return;
}
else
{
    printf("Enter the value which you want to add in the node");
    scanf("%d",&value);
    temp->data=value;
    printf("Enter the location of the node after which you want to insert");
    scanf("%d",&loc);
    cur=Head;
    for(i=0;i<loc;i++)
    {
      cur=cur->ptr;
    if(cur==NULL)
    {
        printf("\n Can't insert node");
        return;
    }
    }
    temp->ptr=cur->ptr;
    cur->ptr=temp;
    printf("Node inserted\n");
}
}
void display()
{
     Node* cur;
     cur=Head;
     if(cur==NULL)
     {
         printf("Nothing is print");
     }
     else
     {
         printf("\n printing value is....");
     while(cur!=NULL)
        {
            printf("%d",cur->data);
            cur=cur->ptr;
        }
     }
}
