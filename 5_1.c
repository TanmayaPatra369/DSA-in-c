/*5.1 Write a program to create a double linked list and perform the following menu based operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    int count = 1;

    if (position == 1) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
    } else {
        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            printf("Position out of range\n");
            return;
        }

        if (current->prev != NULL) {
            current->prev->next = current->next;
        }

        if (current->next != NULL) {
            current->next->prev = current->prev;
        }

        free(current);
    }
}

void traverse(struct Node* head) {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, n, value; // Declare n and value variables

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtPosition(&head, value, i + 1);
    }

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert element at a specific position\n");
        printf("2. Delete element from a specific position\n");
        printf("3. Traverse the list\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}