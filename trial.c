/*
//josephus problem using circular linked list

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node* nodeCreation(int data);
struct node* CircularLinkedList(int n);
int joseph(int n, int k);

int main() 
{
    int n;
    int k;
    scanf("%d %d", &n, &k);
    
    int remaining=joseph(n,k);
    printf("%d", remaining);

    return 0;
}


struct node* nodeCreation(int data) 
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* CircularLinkedList(int n) 
{
    if (n<=0) 
    {
        return NULL;
    }

    struct node* head=nodeCreation(1);
    struct node* current=head;

    for (int i=2;i<=n;i++) 
    {
        current->next=nodeCreation(i);
        current=current->next;
    }

    current->next=head;
    return head;
}

int joseph(int n, int k) 
{
    struct node* head=CircularLinkedList(n);
    struct node* current=head;
    struct node* prev=NULL;

    while (current->next!=current) 
    {

        for (int i=1;i<k;i++) 
        {
            prev=current;
            current=current->next;
        }

        prev->next=current->next;
        free(current);
        current=prev->next;
    }

    int remaining=current->data;
    free(current);
    return remaining;
}
*/


/*
// Palindrome number 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node 
{
    char data;
    struct Node* next;
    struct Node* prev;
};


void insertEnd(struct Node* head, char data) 
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
    } 
    else 
    {
        struct Node* current = head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) 
    {
        return 1; 
    }

    struct Node* front = head;
    struct Node* rear = head;

    while (rear->next != NULL) 
    {
        rear = rear->next;
    }

    while (front != rear) 
    {
        if (front->data != rear->data) 
        {
            return 0; 
        }
        front = front->next;
        rear = rear->prev;
    }

    return 1;
}

int main() 
{
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;


    for (int i = 0; i < n; i++) 
    {
        char data;
        scanf(" %c", &data); 
        insertEnd(head, data);
    }


    int result = isPalindrome(head);

    printf("%d\n", result);

    while (head != NULL) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
*/


/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the structure for a node in a stack
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct StackNode** stack, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** stack) {
    if (*stack == NULL) {
        return '\0';
    }
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}


bool isOperator(char operator)
{
    switch (operator) 
    {
        case '+':

        case '-':

        case '/':

        case '*':

        case '^':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

// Function to check the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // For parentheses
    }
}

// Function to convert infix to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct StackNode* operatorStack = NULL;
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLen - 1; i >= 0; i--) {
        if (infix[i] == ' ') {
            continue;
        }

        // If it's an operand, add it to the prefix expression
        if (!isOperator(infix[i])) {
            prefix[prefixIndex++] = infix[i];
        } else {
            while (operatorStack != NULL && precedence(operatorStack->data) > precedence(infix[i])) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (operatorStack != NULL) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }

    for(int i=0;i<len;i++)
    {
        int sum = prefix[i] + prefix[i+1];
    }
}

int main() {
    char infix[100];
    char prefix[100];

    printf("Enter the infix expression: ");
    scanf("%[^\n]s", infix);

    infixToPrefix(infix, prefix);
    printf("The prefix expression is: %s\n", prefix);

    return 0;
}
*/
//------------------------------------------------------------------------

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a node in a stack
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct StackNode** stack, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** stack) {
    if (*stack == NULL) {
        return '\0';
    }
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if a character is an operator
bool isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

// Function to check the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // For parentheses
    }
}

// Function to convert infix to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct StackNode* operatorStack = NULL;
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLen - 1; i >= 0; i--) {
        if (infix[i] == ' ') {
            continue;
        }

        // If it's an operand, add it to the prefix expression
        if (!isOperator(infix[i])) {
            prefix[prefixIndex++] = infix[i];
        } else {
            while (operatorStack != NULL && precedence(operatorStack->data) > precedence(infix[i])) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (operatorStack != NULL) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefixExpression(char prefix[]) {
    struct StackNode* operandStack = NULL;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(&operandStack, prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            int operand1 = pop(&operandStack);
            int operand2 = pop(&operandStack);

            switch (prefix[i]) {
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

int main() {
    char infix[100];
    char prefix[100];

    //printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    //printf("The prefix expression is: %s\n", prefix);

    int result = evaluatePrefixExpression(prefix);
    printf("%d", result);

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack definition
struct Stack
{
    char items[50];
    int top;
};

// Push function
void push(struct Stack *stack, char item)
{
    if (stack->top == 49)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// Pop function
char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

// Check whether the symbol is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

// If it is an operator, implement according to precedence
int getPrecedence(char operator)
{
    if (operator== '+' || operator== '-' || operator== '$')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    return 0;
}

// Convert infix -> postfix
void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    stack.top = -1;
    int infixLength = strlen(infix);
    int postfixIndex = 0;
    for (int i = 0; i < infixLength; i++)
    {
        char currentChar = infix[i];
        if ((currentChar >= '0' && currentChar <= '9') || (currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z'))
        {
            postfix[postfixIndex++] = currentChar;
        }
        else if (currentChar == '(')
        {
            push(&stack, currentChar);
        }
        else if (currentChar == ')')
        {
            while (stack.top != -1 && stack.items[stack.top] != '(')
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from stack
        }
        else if (isOperator(currentChar))
        {
            while (stack.top != -1 && getPrecedence(stack.items[stack.top]) >= getPrecedence(currentChar))
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, currentChar);
        }
    }
    while (stack.top != -1)
    {
        postfix[postfixIndex++] = pop(&stack);
    }
    postfix[postfixIndex] = '\0';
}

int main()
{
    char infix[50];
    char postfix[50];

    //printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a node in a stack
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a character onto the stack
void push(struct StackNode** stack, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** stack) {
    if (*stack == NULL) {
        return '\0';
    }
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if a character is an operator
bool isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

// Function to check the precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // For parentheses
    }
}

// Function to convert infix to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct StackNode* operatorStack = NULL;
    int infixLen = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLen - 1; i >= 0; i--) {
        if (infix[i] == ' ') {
            continue;
        }

        // If it's an operand, add it to the prefix expression
        if (!isOperator(infix[i])) {
            prefix[prefixIndex++] = infix[i];
        } else {
            while (operatorStack != NULL && precedence(operatorStack->data) > precedence(infix[i])) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (operatorStack != NULL) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefixExpression(char prefix[]) {
    struct StackNode* operandStack = NULL;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(&operandStack, prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            int operand1 = pop(&operandStack);
            int operand2 = pop(&operandStack);

            switch (prefix[i]) {
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

int main() {
    char infix[100];
    char prefix[100];

    //printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    //printf("The prefix expression is: %s\n", prefix);

    int result = evaluatePrefixExpression(prefix);
    printf("%d", result);

    return 0;
}
*/
// ----------------------------
/*
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int info;
    struct node* next;
};

struct node* insertFront(struct node* head, int ele);
struct node* insertAt(struct node* head, int ele, int index);
struct node* insertLast(struct node* head, int ele);
struct node* deleteFront(struct node* head);
struct node* deleteLast(struct node* head);
struct node* deleteDuplicate(struct node* head);
void display(struct node* head);
struct node* freeList(struct node* head);

void main(){
    struct node* head = NULL;
    int choice;
    int info;
    int element;
    do{
        printf("<1> Insert Front <2> Insert End <3> Insert At <4> Delete Front <5> Delete End <6> Delete Duplicate <7> Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the value: ");
					scanf("%d", &info);
					head = insertFront(head, info);
					break;
			case 2: printf("Enter the value: ");
					scanf("%d", &info);
					head = insertLast(head, info);
					break;
			case 3: printf("Enter the value and index: ");
					scanf("%d %d", &info, &element);
					head = insertAt(head, info, element);
					break;
			case 4: head = deleteFront(head);
					break;
			case 5: head = deleteLast(head);
					break;
			case 6: head = deleteDuplicate(head);
					break;
			case 7: display(head);
					break;
        }
    }while(choice>0 && choice<8);
	head=freeList(head);
}

struct node* insertFront(struct node* head, int ele){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->info = ele;
    temp->next=head;
    if(head==NULL){
        return temp;
    }
    head->prev=temp;
    return temp;
}

struct node* insertLast(struct node* head, int ele){
    struct node* temp = malloc(sizeof(struct node));
    struct node* parser = head;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        temp->info=ele;
        return temp;
    }
    while(parser->next!=NULL){
        parser=parser->next;
    }
    parser->next=temp;
    temp->prev=parser;
    temp->next=NULL;
    temp->info=ele;
    return head;
}

struct node* insertAt(struct node* head, int ele, int index){
    struct node* temp = malloc(sizeof(struct node));
    struct node* parser = head;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        temp->info=ele;
        return temp;
    }
    if(index==0){
        return insertFront(head, ele);
    }
    for(int i=0; i<index; i++){
        if(parser->next==NULL){
            parser->next=temp;
            temp->prev=parser;
            temp->info=ele;
            temp->next=NULL;
            return head;
        }
        parser=parser->next;
    }
    parser = parser->prev;
    struct node* current = parser->next;
    temp->info = ele;
    temp->next = current;
    temp->prev = parser;
    parser->next = temp;
    current->prev = temp;
    return head;
}

struct node* deleteFront(struct node* head){
    struct node* temp = head;
    if(head->next==NULL){
        head=head->next;
        return head;
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

struct node* deleteLast(struct node* head){
    struct node* parser = head;
    if(head->next==NULL){
        head=head->next;
        return head;
    }
    while(parser->next!=NULL){
        parser=parser->next;
    }
    struct node* temp = parser->prev;
    temp->next = NULL;
    free(parser);
    return head;
}

struct node* deleteDuplicate(struct node* head){
    struct node* parser = head;
    int val=0;
    while(parser->next){
        val=parser->info;
        struct node* post = parser->next;
        while(post){
            if(post->info==val){
                if(post->next==NULL){
                    struct node* lp = post->prev;
                    lp->next=NULL;
                    free(post);
                    post=NULL;
                    break;
                }
                struct node* lp = post->prev;
                struct node* rp = post->next;
                lp->next = rp;
                rp->prev = lp;
                free(post);
                post = lp;
            }
            post=post->next;
        }
        if(parser->next){
            parser=parser->next;
        }
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp){
        printf("%d, ", temp->info);
        temp=temp->next;
    }
    printf("\b\b  \n");
}

struct node* freeList(struct node* head){
    struct node* temp = head;
    while(head!=NULL){
        head=head->next;
        free(temp);
        temp=head;
    }
    return head;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Queue
struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Structure to represent a stack using two queues
struct Stack {
    struct Queue* queue1;
    struct Queue* queue2;
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->queue1 = createQueue(capacity);
    stack->queue2 = createQueue(capacity);
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    // Enqueue the new element to queue1
    enqueue(stack->queue1, item);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack->queue1))
        return -1;

    // Move all elements from queue1 to queue2, except the last one
    while (stack->queue1->size > 1) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }

    // Pop and return the last element in queue1
    int poppedValue = dequeue(stack->queue1);

    // Swap queue1 and queue2 for the next operations
    struct Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;

    return poppedValue;
}

int main() {
    int numOperations;
    scanf("%d", &numOperations);

    struct Stack* stack = createStack(100);

    while (numOperations--) {
        int operation, value;
        scanf("%d %d", &operation, &value);

        if (operation == 1) {
            // Push operation
            push(stack, value);
        } else if (operation == 2) {
            // Pop operation
            int poppedValue = pop(stack);
            if (poppedValue != -1) {
                printf("%d", poppedValue);
            }
        }
    }

    return 0;
}

*/

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *next;
}node;

node* insertFront(node* head,int ele);
node* insertLast(node* head,int ele);
void display(node *head);
void sortdisplay(node *head);
int ListLength(node *head);
node* deleteFront(node* head,int *pele);
node* deleteLast(node* head,int *pele);
node* freeList(node* head);

int main(){
	node *head=NULL;
	int choice;
	int ele;

	do{
		printf(">> 1.InsertFront 2.InserLast 3.Display 4.SortDisplay 5.DeleteFront 6.DeleteLast 7.ListLength\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertFront(head,ele);
					break;
			case 2:printf("Enter an integer\n");
					scanf("%d",&ele);
					head=insertLast(head,ele);
					break;
			case 3:display(head);
					break;
			case 4:sortdisplay(head);
					break;
			case 5: if(head!=NULL){
						head=deleteFront(head,&ele);
						printf("Deleted element is %d\n",ele);
					}
					else
						printf("List is already empty\n");
					break;
			case 6: if(head!=NULL){
						head=deleteLast(head,&ele);
						printf("Deleted element is %d\n",ele);
					}
					else
						printf("List is already empty\n");
					break;
			case 7: printf("The length of the List is: %d\n", ListLength(head));
		}
	}while(choice<8 && choice>0);

	head=freeList(head);
}

node *createnode(int ele){
	node* newnode=malloc(sizeof(struct node));
	newnode->info=ele;
	newnode->next=NULL;
	return newnode;
}

node* insertFront(node* head,int ele){
	node* newnode=createnode(ele);
	newnode->next=head;
	head=newnode;
	return head;
}

node* insertLast(node* head,int ele){
	node* newnode=createnode(ele);
	if(head==NULL){
		head=newnode;
	}
	else{
		node* p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=newnode;
	}
	return head;
}

void display(node *head){
	if(head==NULL)
		printf("Empty List\n");
	else{
		node *p=head;
		while(p!=NULL){
			printf("%d ",p->info);
			p=p->next;
		}
	}
}

void sortdisplay(node *head){
	int x = ListLength(head);
	int arr[x];
	int i=0;
	if(head==NULL)
		printf("Empty List\n");
	else{
		node *p=head;
		while(p!=NULL){
			arr[i]=p->info;
			i++;
			p=p->next;
		}
	}
	for(int j=0; j<i; j++){
		for(int k=0; k<i; k++){
			if(arr[j]<arr[k]){
				int temp = arr[j];
				arr[j]=arr[k];
				arr[k] = temp;
			}
		}
	}
	for(int j=0; j<i; j++){
		printf("%d ",arr[j]);
	}
}

node* deleteFront(node* head,int *pele){
	node *p=head;
	*pele=head->info;
	head=head->next;
	free(p);
	return head;
}

node* deleteLast(node* head,int *pele){
	if(head->next==NULL){
		*pele=head->info;
		free(head);
		head=NULL;
	}
	else{
		node* p=head;
		node *q=NULL;
		while(p->next!=NULL){
			q=p;
			p=p->next;
		}
		*pele=p->info;
		q->next=NULL;
		free(p);
	}
	return head;
}

node* freeList(node* head){
	node *p=head;
	while(head!=NULL){
		head=head->next;
		// printf("Freeing %d\n",p->data);
		free(p);
		p=head;
	}
	return head;
}

int ListLength(node *head){
	if(head==NULL)
		return 0;
	return 1+ListLength(head->next);
}
*/

/*  stack testing using copiolot
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 // define the maximum size of the stack

// declare a structure for the stack
struct stack {
    int items[MAXSIZE]; // an array to store the elements
    int top; // an index to keep track of the top element
};

// initialize the stack with an empty state
void init_stack(struct stack *s) {
    s->top = -1; // set the top index to -1
}

// check if the stack is empty
int is_empty(struct stack *s) {
    return s->top == -1; // return true if the top index is -1
}

// check if the stack is full
int is_full(struct stack *s) {
    return s->top == MAXSIZE - 1; // return true if the top index is MAXSIZE - 1
}

// push an element into the stack
void push(struct stack *s, int x) {
    if (is_full(s)) { // check if the stack is full
        printf("Stack overflow\n"); // print an error message
        exit(1); // terminate the program
    }
    s->top++; // increment the top index
    s->items[s->top] = x; // store the element at the top position
}

// pop an element from the stack
int pop(struct stack *s) {
    if (is_empty(s)) { // check if the stack is empty
        printf("Stack underflow\n"); // print an error message
        exit(1); // terminate the program
    }
    int x = s->items[s->top]; // get the element at the top position
    s->top--; // decrement the top index
    return x; // return the popped element
}

// print the elements of the stack
void print_stack(struct stack *s) {
    if (is_empty(s)) { // check if the stack is empty
        printf("Stack is empty\n"); // print a message
        return; // exit the function
    }
    printf("Stack: "); // print a label
    for (int i = 0; i <= s->top; i++) { // loop through the elements from bottom to top
        printf("%d ", s->items[i]); // print each element with a space
    }
    printf("\n"); // print a newline
}

// main function to test the code
int main() {
    struct stack s; // declare a stack variable
    init_stack(&s); // initialize the stack

    push(&s, 10); // push 10 into the stack
    push(&s, 20); // push 20 into the stack
    push(&s, 30); // push 30 into the stack

    print_stack(&s); // print the stack

    int x = pop(&s); // pop an element from the stack and store it in x

    printf("Popped %d from the stack\n", x); // print the popped element

    print_stack(&s); // print the stack again

    return 0; // end the program
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the AVL tree
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Function to create a new node with the given data
struct AVLNode* newNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1; // New node is initially added at the leaf level
    return node;
}

// Function to get the height of a node
int height(struct AVLNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform a right rotation
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get the balance factor of a node
int getBalance(struct AVLNode* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into the AVL tree
struct AVLNode* insert(struct AVLNode* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        // Duplicate data is not allowed
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor and perform necessary rotations
    int balance = getBalance(root);

    // Left Heavy
    if (balance > 1) {
        if (data < root->left->data) {
            // Left Left Case
            return rightRotate(root);
        } else {
            // Left Right Case
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (data > root->right->data) {
            // Right Right Case
            return leftRotate(root);
        } else {
            // Right Left Case
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(struct AVLNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Main function
int main() {
    struct AVLNode* root = NULL;

    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 350);

    printf("In-order traversal of AVL tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) 
    {
        return createNode(value);
    }
    if (value < root->data) 
    {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = insert(root->right, value);
    }
    return root;
}

int search(struct Node* root, int value) 
{
    if (root == NULL) 
    {
        return 0;
    }
    if (value == root->data) 
    {
        return 1;
    }
    else if (value < root->data) 
    {
        return search(root->left, value);
    } 
    else 
    {
        return search(root->right, value);
    }
}

struct Node* findMin(struct Node* node) 
{
    while (node->left != NULL) 
    {
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int value) 
{
    if (root == NULL) 
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    } 
    else 
    {
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printSearchResult(struct Node* root, int value) 
{
    if (search(root, value)) 
    {
        printf("YES\n");
    } 
    else 
    {
        printf("NO\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* levelOrder = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &levelOrder[i]);
    }
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) 
    {
        if (levelOrder[i] != -1) 
        {
            root = insert(root, levelOrder[i]);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) 
    {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 0) 
        {
            printSearchResult(root, x);
        } 
        else if (op == 1) 
        {
            root = deleteNode(root, x);
        }
    }
    free(levelOrder);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTreeFromLevelOrder(int level_order[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct TreeNode* root = createNode(level_order[0]);
    struct TreeNode* queue[n];
    int i = 1, front = 0, rear = 0;
    queue[rear++] = root;

    while (i < n) {
        struct TreeNode* current = queue[front++];
        int left_value = level_order[i++];
        if (left_value != -1) {
            current->left = createNode(left_value);
            queue[rear++] = current->left;
        }

        if (i < n) {
            int right_value = level_order[i++];
            if (right_value != -1) {
                current->right = createNode(right_value);
                queue[rear++] = current->right;
            }
        }
    }

    return root;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void diameterOfBinaryTreeHelper(struct TreeNode* root, int* diameter, int* height) {
    if (root == NULL) {
        *height = 0;
        return;
    }

    int left_height, right_height;
    diameterOfBinaryTreeHelper(root->left, diameter, &left_height);
    diameterOfBinaryTreeHelper(root->right, diameter, &right_height);

    *diameter = max(*diameter, left_height + right_height);
    *height = 1 + max(left_height, right_height);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    int height = 0;
    diameterOfBinaryTreeHelper(root, &diameter, &height);
    return diameter;
}

int main() {
    int n;
    //printf("Enter the number of elements in the level order traversal: ");
    scanf("%d", &n);

    int level_order[n];
    //printf("Enter the level order traversal values (separated by spaces): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &level_order[i]);
    }

    struct TreeNode* root = buildTreeFromLevelOrder(level_order, n);

    int diameter = diameterOfBinaryTree(root);

    printf("%d\n", diameter);

    return 0;
}
*/

//  ---------------------------- 2nd ass ---------------------------------

/*
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTreeFromLevelOrder(int level_order[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct TreeNode* root = createNode(level_order[0]);
    struct TreeNode* queue[n];
    int i = 1, front = 0, rear = 0;
    queue[rear++] = root;

    while (i < n) {
        struct TreeNode* current = queue[front++];
        int left_value = level_order[i];
        i++;
        if (left_value != -1) {
            current->left = createNode(left_value);
            queue[rear++] = current->left;
        }

        if (i < n) {
            int right_value = level_order[i];
            i++;
            if (right_value != -1) {
                current->right = createNode(right_value);
                queue[rear++] = current->right;
            }
        }
    }

    return root;
}

struct TreeNode* findLowestCommonAncestor(struct TreeNode* root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value == p || root->value == q) {
        return root;
    }

    struct TreeNode* left = findLowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = findLowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    if (left != NULL) {
        return left;
    }

    return right;
}

int main() {
    int n;
    //printf("Enter the number of elements in the level order traversal: ");
    scanf("%d", &n);

    int level_order[n];
    //printf("Enter the level order traversal values (separated by spaces): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &level_order[i]);
    }

    struct TreeNode* root = buildTreeFromLevelOrder(level_order, n);

    int thief1, thief2;
    //printf("Enter the values of the two thieves: ");
    scanf("%d %d", &thief1, &thief2);

    struct TreeNode* lca = findLowestCommonAncestor(root, thief1, thief2);

    if (lca != NULL) {
        printf("%d\n", lca->value);
    } 

    return 0;
}
*/

// ---------------------------  1st ass  --------------------------------------
/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* newNode (int data){
  struct node* Node = malloc(sizeof(struct node));
  Node->val = data;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
};

int judge(int i, int height){
    for(int j=2; j<height; j++){
        i = i/2;
    }
    return i%2;
}

int height(struct node* node){
    if (node == NULL){
        return 0;
    }
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight){
            return (lheight + 1);
        }
        else{
            return (rheight + 1);
        }
    }
}

struct node* insert(struct node* head, int temp, int i){
    if(head==NULL){
        if(temp == -1){
            return NULL;
        }
        return newNode(temp);
    }else if(judge(i, height(head))==0){
        head->left = insert(head->left, temp, i);
    }else if(judge(i, height(head))==1){
        head->right = insert(head->right, temp, i);
    }
    return head;
}

// void display(struct node* head){
//     if(head==NULL){
//         return;
//     }
//     display(head->left);
//     printf("(%d,%d) ", head->val, height(head));
//     display(head->right);
// }

int main() {
    int nodenum = 0;
    int temp = 0;
    struct node* head = NULL;
    scanf("%d", &nodenum);
    for(int i=0; i<nodenum; i++){
        scanf("%d", &temp);
        head = insert(head, temp, i+1);
    }
    // display(head);
    printf("%d", height(head->left)+height(head->right)+1);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Data structure to represent a graph
struct Graph {
    int vertices;
    int edges;
    int adjacency[MAX_NODES][MAX_NODES];
};

// Function to perform DFS and check if destination is reachable from source
int isReachable(struct Graph *graph, int src, int dest, int visited[]) {
    if (src == dest) {
        return 1;
    }

    visited[src] = 1;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacency[src][i] && !visited[i]) {
            if (isReachable(graph, i, dest, visited)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    struct Graph graph;
    int q, src, dest;

    // Read the number of nodes and edges
    scanf("%d %d", &graph.vertices, &graph.edges);

    // Initialize the adjacency matrix
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph.adjacency[i][j] = 0;
        }
    }

    // Read the edges and build the graph
    for (int i = 0; i < graph.edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph.adjacency[u][v] = 1;
    }

    // Read the number of queries
    scanf("%d", &q);

    // Process the queries
    for (int i = 0; i < q; i++) {
        int visited[MAX_NODES] = {0};
        scanf("%d %d", &src, &dest);
        if (isReachable(&graph, src, dest, visited)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
--------------------------

#include <stdio.h>
#include <stdlib.h>

// Data structure for a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Data structure for an adjacency list
struct AdjList {
    struct Node* head;
};

// Data structure for the graph
struct Graph {
    int vertices;
    struct AdjList* array;
};

// Create a new node
struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

// Create a graph with 'vertices' nodes
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}

// Depth-First Search to check connectedness
int isConnected(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    
    struct Node* node = graph->array[v].head;
    while (node != NULL) {
        int neighbor = node->dest;
        if (!visited[neighbor] && isConnected(graph, neighbor, visited)) {
            return 1;
        }
        node = node->next;
    }
    
    return 0;
}

// Check if the graph is a tree
int isTree(struct Graph* graph) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }
    
    if (!isConnected(graph, 0, visited)) {
        return 0; // Not connected
    }
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            return 0; // Not all nodes are visited
        }
    }
    
    return 1; // Meets both conditions, so it's a tree
}

int main() {
    int n, e, src, dest;
    
    // Read the number of nodes and edges
    scanf("%d %d", &n, &e);
    
    // Create the graph
    struct Graph* graph = createGraph(n);
    
    // Read and add edges to the graph
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    
    // Check if the graph is a tree
    int result = isTree(graph);
    
    // Print the result
    printf(result ? "true\n" : "false\n");
    
    return 0;
}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char* ECO;
	char* name;
	char* move;
	int childnum;
	struct node** child;
};

struct node* head = NULL;

struct node* createNode(char* ECO, char* name, char* move){
    struct node* temp = malloc(sizeof(struct node));
    temp->ECO = malloc(sizeof(char)*strlen(ECO));
    strcpy(temp->ECO, ECO);
    temp->name = malloc(sizeof(char)*strlen(name));
    strcpy(temp->name, name);
    temp->move = malloc(sizeof(char)*strlen(move));
    strcpy(temp->move, move);
    temp->childnum = 0;
}

void display(){
    printf("\ndisplay:\n");
    printf("ECO: %s\n", head->ECO);
    printf("name:%s\n", head->name);
    printf("move: %s\n", head->move);
    printf("childnum:%d\n", head->childnum);
}

void push(char* ECO, char* name, char* move){
    if(head == NULL){
        head = createNode(ECO, name, strtok(move, "\r"));
        return;
    }
}

void main()
{
	FILE* fp = fopen("openings1.txt", "r");
	
	if (fp==NULL){
		printf("Can't open file\n");
	}
	else{
		char buffer[1024];
        char* token1;
        char* token2;
        char* token3;
		for(int i=0; i<10; i++){
            fgets(buffer, 1024, fp);
            token1 = strtok(buffer, ";");
            printf("%s\n",  token1);
            token2 = strtok(NULL, ";");
            printf("%s\n",  token2);
            token3 = strtok(NULL, ";");
            printf("%s",  token3);
            push(token1, token2, token3);
		}
		fclose(fp);
	}
    display();
}