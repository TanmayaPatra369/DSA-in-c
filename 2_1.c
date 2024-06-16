#include <stdio.h>

void createArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    printf("Array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int position, int element) {
    if (position < 0 || position > *n) {
        printf("Invalid position. Insertion failed.\n");
        return;
    }

    for (int i = *n - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*n)++;
    printf("Element inserted.\n");
}

void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position. Deletion failed.\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted.\n");
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    createArray(array, n);

    while (1) {
        printf("\nMenu:\n");
        printf("a. Insert element\n");
        printf("b. Delete element\n");
        printf("c. Linear search\n");
        printf("d. Display array\n");
        printf("e. Exit\n");

        char choice;
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        int position, element, index;
        switch (choice) {
            case 'a':
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(array, &n, position, element);
                break;
            case 'b':
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(array, &n, position);
                break;
            case 'c':
                printf("Enter the element to search: ");
                scanf("%d", &element);
                index = linearSearch(array, n, element);
                if (index != -1) {
                    printf("Element found at position: %d\n", index);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;
            case 'd':
                displayArray(array, n);
                break;
            case 'e':
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}