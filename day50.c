/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    while (root != NULL) {
        if (root->val == key)
            return root;

        if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;
    int x;

    // Build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int key;
    scanf("%d", &key);

    struct Node* result = search(root, key);

    if (result)
        printf("%d", result->val);
    else
        printf("-1");

    return 0;
}