/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* build(int preorder[], int preStart, int preEnd,
                   int inorder[], int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct Node* root = createNode(rootVal);

    // find root in inorder
    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, k - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, k + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = build(preorder, 0, n - 1,
                              inorder, 0, n - 1);

    postorder(root);

    return 0;
}