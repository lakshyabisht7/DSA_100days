/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i]) {  // if edge exists

            if(!visited[i]) {
                if(dfs(i, node, n))
                    return 1;
            }
            else if(i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int hasCycle(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, n))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // input edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    if(hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}