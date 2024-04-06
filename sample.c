#include <stdio.h>
#include<stdlib.h>
//
struct node
{
    int data;
    struct node* link;   
};

//defn of insert fxn
//parameters: node* head and int info
//return type : struct node* ->return the head of the list
struct node* insertNode(struct node*head, int info)
{
    struct node* current = head;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = info;
    newNode->link = NULL;

    if(head == NULL)
    {
        return newNode;
    }
    else
    {
        while(current->link != NULL)
        {
            current=current->link;
        }
        current->link = newNode;
    }

    return head;
}

struct node* deleteNode(struct node* head,int info)
{
    if(head==NULL)
    {
        printf("list doesn't exist");
        return head;
    }
    else
    {
        struct node* current = head;
        struct node* previous = NULL; //because we need to assign the prev node to the next node

        while(current->data != info || current->link != NULL)
        {
            previous = current;
            current = current->link;
        }
        if(current->data == info)
        {
            previous->link = current->link;
            printf("node with value = %d was deleated",info);
            free(current);
        }
        else
        {
            printf("specific node is not found");

        }

    }
     
    return head;
}

int searchNode(struct node* head,int info)
{
    struct node* current = head;
    int index = 1; //to get the index of the searched element

    while(current->link != NULL || current->data != info)
    {
        current = current->link;
        index +=1;
    }
    if(current->data == info)
    {
        return index;
    }
    else
    {
        return -1;
    }
      
}


//performs;
//1. insertion of node into list
//2. deletion
//3. search for a node 
//4. exit from the program
int main()
{
    //head points to the first memory location of the list
    //initiallly points to NULL
    struct node* head = NULL;
    int info;  //info taken from user
    int choice; 
    int pos; //posistion of node 
    printf("enter choice: ");
    scanf("%d",&choice);
    for(;;)
    {
        switch(choice)
        {
            case 1: //insertion
                printf("enter data to be inserted ");
                scanf("%d",&info);
                head = insertNode(head,info);  //because we need to return the head i.e the first memory location to acces it
                break;
        
            case 2: //deletion
                printf("enter data to be deleated ");
                scanf("%d",&info);
                head =deleteNode(head,info); //we have info also because we'll have too search for the node before deleting it
                break;
        
            case 3: //search
                printf("enter data to be searched ");
                scanf("%d",&info);
                pos = searchNode(head,info);
                if(pos==-1)
                {
                    printf("list doesn't exist");
                }
                else
                {
                    printf("data was found at %d posistion",pos);
                }
                break;
        
            default: return 1;  //exit from program

        }
    }
    
    return 0;
}
