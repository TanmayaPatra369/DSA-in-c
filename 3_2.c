// WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

// Function to add two sparse matrices
void addSparseMatrices(struct Element matrix1[], int size1, struct Element matrix2[], int size2, struct Element result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (matrix1[i].row < matrix2[j].row) {
            result[k++] = matrix1[i++];
        } else if (matrix1[i].row > matrix2[j].row) {
            result[k++] = matrix2[j++];
        } else {
            if (matrix1[i].col < matrix2[j].col) {
                result[k++] = matrix1[i++];
            } else if (matrix1[i].col > matrix2[j].col) {
                result[k++] = matrix2[j++];
            } else {
                // Sum the values for the same position
                result[k].row = matrix1[i].row;
                result[k].col = matrix1[i].col;
                result[k].value = matrix1[i].value + matrix2[j].value;
                k++;
                i++;
                j++;
            }
        }
    }

    // Copy the remaining elements from both matrices
    while (i < size1) {
        result[k++] = matrix1[i++];
    }

    while (j < size2) {
        result[k++] = matrix2[j++];
    }

    *sizeResult = k;
}

// Function to print a sparse matrix
void printSparseMatrix(struct Element matrix[], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d, %d) ", matrix[i].row, matrix[i].col, matrix[i].value);
    }
    printf("\n");
}

int main() {
    // Example sparse matrices
    struct Element matrix1[] = {
        {0, 0, 3},
        {0, 2, 5},
        {1, 1, 8},
        {2, 0, 2}
    };

    struct Element matrix2[] = {
        {0, 1, 6},
        {1, 1, 7},
        {2, 0, 1},
        {2, 2, 4}
    };

    int size1 = sizeof(matrix1) / sizeof(matrix1[0]);
    int size2 = sizeof(matrix2) / sizeof(matrix2[0]);

    printf("Sparse Matrix 1: ");
    printSparseMatrix(matrix1, size1);

    printf("Sparse Matrix 2: ");
    printSparseMatrix(matrix2, size2);

    // Allocate space for the result matrix
    struct Element result[100]; // Assuming a maximum of 100 non-zero elements in the result
    int sizeResult;

    // Perform addition of two sparse matrices
    addSparseMatrices(matrix1, size1, matrix2, size2, result, &sizeResult);

    printf("Sum of Sparse Matrices: ");
    printSparseMatrix(result, sizeResult);

    return 0;
}


