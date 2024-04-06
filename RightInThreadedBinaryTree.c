#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    int info;
    struct node* left;
    struct node* right;
    int rthread;
}NODE;

NODE* createNode(int e)
{
    NODE* temp = malloc(sizeof(NODE));
    temp->info=e;
    temp->right=NULL;
    temp->left=NULL;
    temp->rthread=1;
    return temp;
}

void inOrder(NODE* root)
{
    NODE* p = root;
    NODE* q;
    do
    {
        q = NULL;
        while(p!=NULL)
        {
            q = p;
            p = p->left;
        }
        if(q!=NULL)
        {
            printf("%d",q->info);
            p = q->right;
            while(q->rthread && p!=NULL)
            {
                printf("%d",p->info);
                q = p;
                p = p->right;
            }
        }

    }while(q!=NULL);
}

NODE* insert(NODE* head,int data)
{
    if(head == NULL)
    {
        return createNode(data);
    }
    else if(data < head->data)
    {
        if(head->left == NULL)
        {
            setLeft(head,data);
        }
        head->left = insert(head->left, data);
    }
    else if(data > head->data)
    {
        if(head->rthread)
        {
            setRight(head,data);
        }
        head->right = insert(head->right, data);
    }
    return head;
}

void main()
{
    int num = 0;
    printf("enter number of nodes");
    
}