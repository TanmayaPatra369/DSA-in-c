// 6.2 Write a menu driven program to create a stack using linked list and perform the following operation
// using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL, *newnode;

void push(int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
    printf("%d is pushed into the stack\n", x);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stak is already empty!\n");
    }
    else
    {
        struct node *temp;
        temp = top;
        printf("Poped element is %d.\n", temp->data);
        top = top->link;
        free(temp);
    }
}

bool isEmpty()
{
    return top == NULL;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        struct node *temp = top;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            if (temp->link != NULL)
            {
                printf(" <- ");
            }
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    char choice;
    int item;

    while (1)
    {
        printf("\nStack Menu:\n");
        printf("a. Push\n");
        printf("b. Pop\n");
        printf("c. Check if stack is empty\n");
        printf("d. Display stack elements\n");
        printf("e. Exit\n");

        printf("Enter your choice: ");
        scanf("%s", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter the element to push: ");
            scanf("%d", &item);
            push(item);
            break;
        case 'b':
            pop();
            break;
        case 'c':
            if (isEmpty())
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        case 'd':
            display();
            break;
        case 'e':
            printf("Exiting the program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}