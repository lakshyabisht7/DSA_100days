/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

typedef struct Node {
    int to;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

Node* createNode(int to, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v, int w) {
    Node* n1 = createNode(v, w);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = createNode(u, w);
    n2->next = adj[v];
    adj[v] = n2;
}

int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int primMST(int n) {
    int key[MAX];
    int mstSet[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; // start from node 1
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        totalWeight += key[u];

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->to;
            int w = temp->weight;

            if (!mstSet[v] && w < key[v]) {
                key[v] = w;
            }

            temp = temp->next;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int result = primMST(n);
    printf("%d\n", result);

    return 0;
}