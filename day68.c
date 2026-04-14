/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // input edges (directed)
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    // queue
    int queue[MAX];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for(int v = 0; v < n; v++) {
            if(adj[u][v]) {
                indegree[v]--;

                if(indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    // cycle detection
    if(count != n) {
        printf("\nCycle detected\n");
    }

    return 0;
}