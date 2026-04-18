/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

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

    int edges[m][2];
    int* size = (int*)calloc(n + 1, sizeof(int));

    // Read edges and count degrees
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        size[edges[i][0]]++;
        size[edges[i][1]]++;
    }

    // Allocate adjacency list
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(size[i] * sizeof(int));
        size[i] = 0; // reset for filling
    }

    // Fill adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, size);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}