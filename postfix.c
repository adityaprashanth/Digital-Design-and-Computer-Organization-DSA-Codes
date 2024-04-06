#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    char op;
    struct node* next;
};

struct node* push(struct node* top, char op)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->op = op;
    temp-> next =NULL;
    if(top==NULL)
    {
        return temp;
    }
    top = top->next;
    temp->next = top;
    return temp;
}

struct node* pop(struct node* top, char* op)
{
    if(top == NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp =top;
        top = top->next;
        *op = temp->op;
        free(temp);
        return top;
    }
}

void isoperator(char op)
{
    switch(op)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')': return true;
        default: return false;
        
    }
}

int getPrecedence(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '(':
        case ')': return 0;
        default: return -1;
    }
}

char* infixToPostfix(struct node* top,char op)
{
    int length = strlen(infix)+1;
    char* postfix = (char*)malloc(sizeof(char)*length+1);

    for(int i=0;i<length;i++)
    {
        if(isoperator(infix))
        {
            postfix[j++]=infix[i];
        }
        else
        {
            if(top==NULL || getPrecedence(infix[i])>getPrecedence(top->op))
            {
                top=push(top,infix[i]);
            }
            else if( getPrecedence(infix[i])<getPrecedence(stackTop->op))
            {
                if(infix[i]=='(')
                {
                    stackTop=push(stackTop,infix[i]);
                }
                else if(infix[i]==')')
                {
                    while(stackTop->op!='(')
                    {
                        stackTop=pop(stackTop,&postfix[j++]);
                    }
                }
                
                char discard;
                stackTop=pop(stackTop,&discard);
                else
                {
                    while(getPrecedence(infix[i]<getPrecedence(stackTop->op)))
                    {
                        stackTop = pop(stackTop,&postfix[j++]);
                    }
                }
            }
        }
    }
    while(stackTop != NULL)
    {
        stackTop = pop(stackTop,&postfix[j++]);
    }
}

int main()
{
    char infix[] = "(A+B-C)*(D/E-F)";
    struct node* stackTop = NULL;

    char* postfix;
    postfix = infixToPostfix(stackTop, infix);
    printf("postfix is=%s",postfix);

    return 0;
}



