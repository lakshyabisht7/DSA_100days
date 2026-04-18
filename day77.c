/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* size) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, visited, adj, size);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* size = (int*)calloc(n + 1, sizeof(int));

    // temporary storage for edges
    int u, v;
    int edges[m][2];

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        size[u]++;
        size[v]++;
    }

    // allocate exact memory
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0;
    }

    // fill adjacency list
    for (int i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    dfs(1, visited, adj, size);

    // check if all visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}