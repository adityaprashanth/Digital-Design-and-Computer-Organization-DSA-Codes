#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct StackNode 
{
    char data;
    struct StackNode* next;
};

struct StackNode* createStackNode(char data);
void push(struct StackNode** stack, char data);
char pop(struct StackNode** stack);
bool isOperator(char op);
int precedence(char operator);
void infixToPrefix(char infix[], char prefix[]);
int evaluatePrefixExpression(char prefix[]);

int main() {
    char infix[100];
    char prefix[100];

    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    
    int result = evaluatePrefixExpression(prefix);
    printf("%d", result);
    
    return 0;
}

struct StackNode* createStackNode(char data) 
{
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct StackNode** stack, char data) 
{
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

char pop(struct StackNode** stack) 
{
    if (*stack == NULL) 
    {
        return '\0';
    }
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

bool isOperator(char op)
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

int precedence(char operator) 
{
    switch (operator) 
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPrefix(char infix[], char prefix[]) 
{
    struct StackNode* operatorStack = NULL;
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLen - 1; i >= 0; i--) 
    {
        if (infix[i] == ' ') {
            continue;
        }

        if (!isOperator(infix[i])) 
        {
            prefix[prefixIndex++] = infix[i];
        } else 
        {
            while (operatorStack != NULL && precedence(operatorStack->data) > precedence(infix[i])) 
            {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    while (operatorStack != NULL) 
    {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    prefix[prefixIndex] = '\0';

    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int evaluatePrefixExpression(char prefix[]) 
{
    struct StackNode* operandStack = NULL;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            push(&operandStack, prefix[i] - '0');
        }
        else if (isOperator(prefix[i]))
        {
            int operand1 = pop(&operandStack);
            int operand2 = pop(&operandStack);

            switch (prefix[i]) 
            {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    push(&operandStack, operand1 / operand2);
                    break;
                case '^':
                    push(&operandStack, operand1 ^ operand2);
                    break;
            }
        }
    }
    return pop(&operandStack);
}
