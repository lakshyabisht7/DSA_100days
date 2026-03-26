/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct Node* curr = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int level[2000];

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            int index;
            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = node->data;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}