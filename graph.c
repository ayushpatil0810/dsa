#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int visited[MAX];
int graph[MAX][MAX];
int n; // number of cities

// Depth First Search (DFS)
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// Function to check if graph is connected
void checkConnectivity() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0); // start DFS from city 0

    // After DFS, check if all nodes are visited
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("\n✅ The graph is CONNECTED — All cities are reachable from each other.\n");
    else
        printf("\n❌ The graph is NOT CONNECTED — Some cities are not reachable.\n");
}

int main() {
    int edges, src, dest;
    char cities[MAX][30];

    printf("=== Flight Path Graph Representation ===\n");

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input city names
    printf("\nEnter the names of cities:\n");
    for (int i = 0; i < n; i++) {
        printf("City %d: ", i);
        scanf("%s", cities[i]);
    }

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Input edges
    printf("\nEnter the number of flight paths: ");
    scanf("%d", &edges);

    printf("\nEnter the flight connections (source destination) as indices (0 to %d):\n", n - 1);
    for (int i = 0; i < edges; i++) {
        printf("Connection %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= n || dest >= n || src < 0 || dest < 0) {
            printf("Invalid city index!\n");
            i--;
            continue;
        }
        graph[src][dest] = 1;
        graph[dest][src] = 1; // assuming undirected graph (two-way flights)
    }

    // Display adjacency matrix
    printf("\nAdjacency Matrix Representation:\n");
    printf("     ");
    for (int i = 0; i < n; i++)
        printf("%-8s", cities[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%-8s", cities[i]);
        for (int j = 0; j < n; j++)
            printf("%-8d", graph[i][j]);
        printf("\n");
    }

    // Check connectivity
    checkConnectivity();

    return 0;
}
