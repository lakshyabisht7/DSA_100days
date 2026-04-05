/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    // push start
    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(int i = 0; i < size[node]; i++) {
            int next = adj[node][i];

            if(!visited[next]) {
                visited[next] = 1;   // mark HERE
                queue[rear++] = next;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    int u, v;

    // input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // undirected graph
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int s;
    scanf("%d", &s);

    bfs(s);

    return 0;
}