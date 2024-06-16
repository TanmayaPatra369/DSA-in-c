/*5.3 Write a program to represent the given sparse matrix using header single linked list and
display it.*/

//5.3//
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node representing a non-zero element
struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

// Define a structure for a header node representing a row
struct HeaderNode {
    int row;
    struct Node* next;
    struct HeaderNode* down;
};

// Function to create a new node for a non-zero element
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for createNode\n");
        exit(1); // Exit the program on memory allocation failure
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new header node for a row
struct HeaderNode* createHeaderNode(int row) {
    struct HeaderNode* newHeaderNode = (struct HeaderNode*)malloc(sizeof(struct HeaderNode));
    if (newHeaderNode == NULL) {
        fprintf(stderr, "Memory allocation failed for createHeaderNode\n");
        exit(1); // Exit the program on memory allocation failure
    }
    newHeaderNode->row = row;
    newHeaderNode->next = NULL;
    newHeaderNode->down = NULL;
    return newHeaderNode;
}

// Function to insert a node into a row's linked list
void insertNode(struct HeaderNode* header, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (header->next == NULL) {
        header->next = newNode;
    } else {
        struct Node* current = header->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the sparse matrix in 3-tuple format
void displayMatrix(struct HeaderNode* header) {
    struct HeaderNode* currentRow = header;
    while (currentRow != NULL) {
        struct Node* current = currentRow->next;
        while (current != NULL) {
            printf("(%d, %d, %d) ", current->row, current->col, current->value);
            current = current->next;
        }
        currentRow = currentRow->down;
    }
    printf("\n");
}

int main() {
    int numRows, numCols;
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &numRows, &numCols);

    // Create an array of header nodes to represent rows
    struct HeaderNode* headerArray[numRows];

    for (int i = 0; i < numRows; i++) {
        headerArray[i] = createHeaderNode(i);
    }

    // Input the matrix and build the sparse matrix representation
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int value;
            printf("Enter the value at (%d, %d): ", i, j);
            scanf("%d", &value);
            if (value != 0) {
                insertNode(headerArray[i], i, j, value);
            }
        }
    }

    // Display the sparse matrix in 3-tuple format
    printf("Sparse Matrix Representation (3-Tuple Format):\n");
    displayMatrix(headerArray[0]);
    displayMatrix(headerArray[1]);
    displayMatrix(headerArray[2]);
    displayMatrix(headerArray[3]);
    displayMatrix(headerArray[4]);
    return 0;
}