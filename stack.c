#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;   
};

struct node* Push(struct node* head, int data);
struct node* Pop(struct node* head, int *data);

int main()
{
    int inputvar=0;
    struct node* head =NULL;
    int data=0;
    for(;;)
    {
        printf("enter your choice ");
        scanf("%d",&inputvar);
        switch(inputvar)
        {
            case 1:
                printf("enter stack elements ");
                scanf("%d", &data);
                head = Push(head, data);
                break;
            case 2:
                head = Pop(head , &data);
                printf("deleated element is %d\n ", data);
                break;
            default:
                return 1;
        }
    }

    return 0;
}

struct node* Push(struct node*head, int data)
{
    struct node* temp = malloc(sizeof(struct node));
    
    temp->data=data;
    temp->link = head;

    head =temp;

    return temp;
}

struct node* Pop(struct node* head, int *data)
{
    *data=head->data;
    head=head->link;
    return head;
}

