/*In addition to 4.1, perform following operations using function on the single linked list:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list*/

#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to search for an element in the linked list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current; // Element found
        }
        current = current->next;
    }

    return NULL; // Element not found
}

// Function to sort the linked list in ascending order
void sort(struct Node** head) {
    struct Node *current, *next;
    int temp;

    current = *head;

    while (current != NULL) {
        next = current->next;

        while (next != NULL) {
            if (current->data > next->data) {
                // Swap data
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }

            next = next->next;
        }

        current = current->next;
    }
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node *prev, *current, *next;
    prev = NULL;
    current = *head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Driver program to test the functions
int main() {
    struct Node* head = NULL;

    // Insert some elements into the linked list
    push(&head, 3);
    push(&head, 1);
    push(&head, 4);
    push(&head, 2);

    printf("Original Linked List: ");
    printList(head);

    // Search for an element
    int key = 4;
    struct Node* result = search(head, key);
    if (result != NULL) {
        printf("Element %d found in the list.\n", key);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    // Sort the linked list
    sort(&head);
    printf("Sorted Linked List: ");
    printList(head);

    // Reverse the linked list
    reverse(&head);
    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
