//  Hashing and Chaining

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE 
{
    int info;
    struct NODE* link;
    
}NODE;

NODE* createNode(int info)
{
    NODE* MyNode=(NODE*) malloc(sizeof(NODE));
    MyNode->info=info;
    MyNode->link=NULL;
    return MyNode;
}

NODE* insertNode(NODE* head, int info)
{
    if (head==NULL) 
    {
        NODE* myNode=createNode(info);
        return myNode;
    } 
    else 
    {
        NODE* myNode=createNode(info);
        NODE* currentLast=head;
        while (currentLast->link!=NULL) 
        {
            currentLast=currentLast->link;
        }
        currentLast->link=myNode; 
    }
    
    return head;
}

int locationInsertor(int value, int size)
{
    return value%size;
}

void displayNode(NODE* head)
{
    NODE* current=head;
    if (head==NULL) 
    {
        return;
    } 
    else 
    {
        while (current!=NULL) 
        {
            printf("%d\t", current->info);
            current = current->link;
        }
    }
}

int main(void)
{
    NODE* myHashArray[7]={NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    for (int i=0; i<7; i++) 
    {
        int currentValue;
        printf("Enter your %dth Value", i);
        scanf("%d", &currentValue);
        int location=locationInsertor(currentValue, 7);
        myHashArray[location]=insertNode(myHashArray[location], currentValue);  
    }
    for (int i=0; i<7; i++) 
    {
        displayNode(myHashArray[i]);
        printf("\t");
    }
}