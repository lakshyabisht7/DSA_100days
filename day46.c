/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n, int i)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Level Order Traversal (BFS)
void levelOrder(struct Node* root)
{
    if(root == NULL)
        return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);

        if(curr->left)
            queue[rear++] = curr->left;

        if(curr->right)
            queue[rear++] = curr->right;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    levelOrder(root);

    return 0;
}