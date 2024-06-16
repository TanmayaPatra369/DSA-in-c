#include <stdio.h>

void readMatrix(int matrix[][100], int n) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


int countNonZeroElements(int matrix[][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}


void displayUpperTriangular(int matrix[][100], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


void displayDiagonalElements(int matrix[][100], int n) {
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j - 1 || i == j + 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[100][100];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    readMatrix(matrix, n);

    int nonZeroCount = countNonZeroElements(matrix, n);
    printf("Number of nonzero elements: %d\n", nonZeroCount);

    displayUpperTriangular(matrix, n);
    displayDiagonalElements(matrix, n);

    return 0;
}