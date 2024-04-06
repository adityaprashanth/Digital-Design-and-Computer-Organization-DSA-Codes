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
