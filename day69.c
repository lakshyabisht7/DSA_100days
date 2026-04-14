/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

typedef struct {
    int node, dist;
} Pair;

Pair heap[MAX];
int size = 0;

// swap
void swap(int i, int j) {
    Pair temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// push into min heap
void push(int node, int dist) {
    heap[++size].node = node;
    heap[size].dist = dist;

    int i = size;
    while(i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

// pop min
Pair pop() {
    Pair top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while(2*i <= size) {
        int j = 2*i;
        if(j+1 <= size && heap[j+1].dist < heap[j].dist)
            j++;

        if(heap[i].dist <= heap[j].dist) break;

        swap(i, j);
        i = j;
    }

    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];

    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    push(src, 0);

    while(size > 0) {
        Pair p = pop();
        int u = p.node;
        int d = p.dist;

        // ignore outdated entry
        if(d > dist[u]) continue;

        for(int v = 0; v < n; v++) {
            if(adj[u][v] != 0) {
                if(dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    push(v, dist[v]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}