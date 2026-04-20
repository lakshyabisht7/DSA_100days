/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100005

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

Node* newNode(int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

void addEdge(int u, int v, int w) {
    Node* n1 = newNode(v, w);
    n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = newNode(u, w); // undirected
    n2->next = adj[v];
    adj[v] = n2;
}

/* -------- Min Heap -------- */

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(int i, int j) {
    HeapNode t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

void push(int node, int dist) {
    heap[++size] = (HeapNode){node, dist};
    int i = size;

    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i+1, smallest = i;

        if (l <= size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r <= size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }
    return top;
}

/* -------- Dijkstra -------- */

void dijkstra(int n, int src) {
    int dist[MAX];
    int vis[MAX] = {0};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int u = cur.node;

        if (vis[u]) continue;
        vis[u] = 1;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!vis[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

/* -------- Main -------- */

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

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}