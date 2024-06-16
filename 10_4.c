//10.4 WAP to create a directed graph using Adjacency Matrix Method and display the degree of each
//vertex.

#include <stdio.h>

#define MAX_VERTICES 10

// Function to initialize the adjacency matrix
void initializeGraph(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = 0; // Initialize all elements to 0
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int vertex1, int vertex2) {
    // For a directed graph
    adjacencyMatrix[vertex1][vertex2] = 1;
}

// Function to display the adjacency matrix
void displayGraph(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate and display the in-degree, out-degree, and total degree of each vertex
void displayDegree(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Sample Output:\n");
    printf("Vertex In_Degree Out_Degree Total_Degree\n");
    for (int i = 0; i < numVertices; i++) {
        int inDegree = 0, outDegree = 0;

        // Calculate in-degree
        for (int j = 0; j < numVertices; j++) {
            inDegree += adjacencyMatrix[j][i];
        }

        // Calculate out-degree
        for (int j = 0; j < numVertices; j++) {
            outDegree += adjacencyMatrix[i][j];
        }

        int totalDegree = inDegree + outDegree;

        printf("%d\t%d\t%d\t%d\n", i + 1, inDegree, outDegree, totalDegree);
    }
}

int main() {
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    initializeGraph(adjacencyMatrix, numVertices);

    // Input adjacency information
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            char isAdjacent;
            if (i != j) {
                printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
                scanf(" %c", &isAdjacent);  // Note the space before %c to consume the newline character
                if (isAdjacent == 'Y' || isAdjacent == 'y') {
                    addEdge(adjacencyMatrix, numVertices, i, j);
                }
            }
        }
    }

    displayGraph(adjacencyMatrix, numVertices);
    displayDegree(adjacencyMatrix, numVertices);

    return 0;
}
