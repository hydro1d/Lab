#include<stdio.h>

int adjacencyMatrix[20][20]; // Matrix to represent the graph
int visited[20];            // Array to track visited nodes
int numVertices;            // Number of vertices in the graph

// Depth-First Search (DFS) function
void dfs(int currentVertex) {
    visited[currentVertex] = 1; // Mark the current vertex as visited
    for (int i = 1; i <= numVertices; i++) {
        // If there's an edge and the vertex isn't visited yet
        if (adjacencyMatrix[currentVertex][i] == 1 && visited[i] == 0) {
            printf("\n %d -> %d", currentVertex, i);
            dfs(i); // Recursively visit the connected vertex
        }
    }
}

int main() {
    int i, j, connectedCount = 0;

    // Input: number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize the adjacency matrix and visited array
    printf("\nEnter the adjacency matrix (use 0/1 to represent edges):\n");
    for (i = 1; i <= numVertices; i++) {
        visited[i] = 0; // Mark all vertices as not visited
        for (j = 1; j <= numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Perform DFS starting from vertex 1
    printf("\nDepth-First Search traversal:");
    dfs(1);

    // Check if all vertices are visited
    for (i = 1; i <= numVertices; i++) {
        if (visited[i] == 1) {
            connectedCount++;
        }
    }

    // Output: Check connectivity of the graph
    if (connectedCount == numVertices) {
        printf("\n\nThe graph is connected.");
    } else {
        printf("\n\nThe graph is not connected.");
    }

    return 0;
}
