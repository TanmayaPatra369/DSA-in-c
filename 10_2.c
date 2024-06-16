//10.2 In addition to 10.1, display DFS traversal sequence of the undirected graph.


#include <stdio.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 5

// Function to perform Depth First Search
void DFS(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int currentVertex) {
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
            DFS(adjacencyMatrix, visited, i);
        }
    }
}

int main() {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    int startVertex;
    printf("Enter start vertex: ");
    scanf("%d", &startVertex);

    printf("Sample Output:\n");
    printf("Depth First Search: ");
    DFS(adjacencyMatrix, visited, startVertex);

    return 0;
}
