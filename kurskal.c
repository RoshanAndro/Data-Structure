#include <stdio.h>

int parent[9], n, cost[9][9], mincost = 0, ne = 1; // ne: edge counter

// Function to find the set of a node using path compression
int find(int u) {
    while (parent[u]) {
        u = parent[u];
    }
    return u;
}

// Function to perform union of two sets
void uni(int ru, int rv) {
    parent[rv] = ru;
}

void main() {
    int i, j, u, v, ru, rv, min;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 for no edge ) :\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Set no edge as a large value
            }
        }
    }

    printf("\nThe edges of the minimum cost spanning tree are:\n");

    // Kruskal's algorithm to find the MST
    while (ne < n) {
        min = 999;  // Use 999 as the placeholder for infinity
        
        // Find the minimum cost edge that is not yet processed
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ru = find(u); // Find the root of u
        rv = find(v); // Find the root of v

        // If the nodes are not in the same set, include the edge in the MST
        if (ru != rv) {
            uni(ru, rv); // Union the sets
            printf("Edge %d: (%d, %d) = %d\n", ne++, u, v, min);
            mincost += min;
        }

        // Set the edge as processed (remove it from the graph)
        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

