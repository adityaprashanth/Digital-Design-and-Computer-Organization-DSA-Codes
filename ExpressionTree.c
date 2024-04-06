#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {

	char data;
	struct node* left;
	struct node* right;
	struct node* next;
} NODE;

NODE* top = NULL;

NODE* createNode(char c)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = c;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->next = NULL;
	return newNode;
}

void push(NODE* node)
{
	if (top == NULL)
	{
		top = node;
	}
	else
	{
		node->next = top;
		top = node;
	}
}

NODE* pop()
{
	if (top == NULL)
	{
		return NULL;
	}
	else
	{
		NODE* poppedNode = top;
		top = top->next;
		return poppedNode;
	}
}

void inOrder(NODE* head)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		inOrder(head->left);
		printf("%c ", head->data);
		inOrder(head->right);
	}
}

int main()
{
	char inputString[] = "AB+C*D/";

	int length = strlen(inputString);

	for (int i = 0; i < length; i++)
	{
		char c = inputString[i];

		if (c == '+' || c == '*' || c == '/')
		{
			NODE* newNode = createNode(c);
			newNode->right = pop();
			newNode->left = pop();
			push(newNode);
		}
		else
		{
			NODE* newNode = createNode(c);
			push(newNode);
		}
	} // END OF FOR LOOP
	printf("The inorder traversal of expression tree is \n");
	inOrder(top);
}
