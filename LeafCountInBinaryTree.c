#include <stdio.h>
#include <stdlib.h>


struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


int countLeafNodes(struct TreeNode* root) 
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // The node is a leaf node
        return 1;
    } 
    else 
    {
        // Recursively count leaf nodes in the left and right subtrees
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int main() 
{
    int n;
    scanf("%d", &n); // Input size of level order traversal
    int* levelOrder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &levelOrder[i]); // Input level order traversal
    }

    
    struct TreeNode* root = NULL;
    struct TreeNode* queue[n];
    int front = 0, rear = 0;
    root = createNode(levelOrder[0]);
    queue[rear++] = root;

    for (int i = 1; i < n; i++) 
    {
        struct TreeNode* currentNode = queue[front];
        front++;

       
        if (levelOrder[i] != -1) 
        {
            currentNode->left = createNode(levelOrder[i]);
            queue[rear++] = currentNode->left;
        }

        i++;
        if (i < n && levelOrder[i] != -1) 
        {
            
            currentNode->right = createNode(levelOrder[i]);
            queue[rear++] = currentNode->right;
        }
    }

    
    int leafCount = countLeafNodes(root);

    printf("%d\n", leafCount); 
    return 0;
}