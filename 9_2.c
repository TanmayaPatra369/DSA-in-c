/*perform the following menu driven operations on BST.
i. insert an element to the BST
ii. display the largest element
iii. display the smallest element
iv. height of a node
v. count number of leaf nodes*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int value);
void displayLargest(struct Node *root);
void displaySmallest(struct Node *root);
int height(struct Node *root);
int countLeafNodes(struct Node *root);

int main() {
    struct Node *root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert an element\n");
        printf("2. Display the largest element\n");
        printf("3. Display the smallest element\n");
        printf("4. Height of a node\n");
        printf("5. Count number of leaf nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                displayLargest(root);
                break;
            case 3:
                displaySmallest(root);
                break;
            case 4:
                printf("Enter the element to find its height: ");
                scanf("%d", &value);
                printf("Height of %d is: %d\n", value, height(root));
                break;
            case 5:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 0:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void displayLargest(struct Node *root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    printf("Largest element: %d\n", root->data);
}

void displaySmallest(struct Node *root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    printf("Smallest element: %d\n", root->data);
}

int height(struct Node *root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeafNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
