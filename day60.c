/*roblem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if(n == 0) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n) {
        struct Node* curr = queue[front++];

        if(i < n) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        if(i < n) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Check CBT
int isCBT(struct Node* root) {
    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int flag = 0;

    while(front < rear) {
        struct Node* curr = queue[front++];

        if(curr == NULL) {
            flag = 1;
        } else {
            if(flag) return 0;

            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }

    return 1;
}

// Check heap property
int isHeap(struct Node* root) {
    if(root == NULL) return 1;

    if(root->left && root->data > root->left->data)
        return 0;

    if(root->right && root->data > root->right->data)
        return 0;

    return isHeap(root->left) && isHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if(isCBT(root) && isHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}