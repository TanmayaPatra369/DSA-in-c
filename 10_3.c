//10.3 In addition to 10.1, display BFS traversal sequence of the undirected graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Function to perform Breadth First Search (BFS) traversal
void BFS(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int numVertices, int startVertex) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Enqueue the start vertex and mark it as visited
    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    printf("Breadth First Search: ");

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                // Enqueue adjacent vertices that have not been visited
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices for BFS

    BFS(adjacencyMatrix, visited, numVertices, startVertex);

    return 0;
}

