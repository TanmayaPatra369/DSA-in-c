//10.1 WAP to create an un-directed graph using Adjacency Matrix Method and display the degree of each
//vertex.


#include <stdio.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 10

// Function to calculate and display the degree of each vertex
void displayDegree(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Sample Output:\n");
    printf("Vertex Degree\n");
    for (int i = 0; i < numVertices; i++) {
        int degree = 0;
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                degree++;
            }
        }
        printf("%d %d\n", i + 1, degree);
    }
}

int main() {
    int numVertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    // Initialize the adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Input adjacency information
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            char isAdjacent;
            if (i != j) {
                printf("Vertices %d & %d are Adjacent? (Y/N): ", i + 1, j + 1);
                scanf(" %c", &isAdjacent);  // Note the space before %c to consume the newline character
                if (isAdjacent == 'Y' || isAdjacent == 'y') {
                    adjacencyMatrix[i][j] = 1;
                }
            }
        }
    }

    // Display the degree of each vertex
    displayDegree(adjacencyMatrix, numVertices);

    return 0;
}

