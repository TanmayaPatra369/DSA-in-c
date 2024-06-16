// 6.1 Write a menu driven program to create a stack using array and perform the following operation using
// function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push more elements.\n");
    }
    else
    {
        stack[++top] = item;
        printf("%d pushed onto the stack.\n", item);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        // return -1; // Return a sentinel value to indicate an empty stack
    }
    else
    {
        int item = stack[top--];
        printf("%d popped from the stack.\n", item);
        // return item;
    }
}

 isEmpty()
{
    return top == -1;
}

 isFull()
{
    return top == MAX_SIZE - 1;
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
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
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
        printf("e. Check if stack is full\n");
        printf("f. Exit\n");

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
            item = pop();
            // if (item != -1) {
            //     printf("Popped item: %d\n", item);
            // }
            break;
        case 'c':
            if (isFull())
            {
                printf("Stack is full.\n");
            }
            else
            {
                printf("Stack is not full.\n");
            }
            break;
        case 'd':
            display();
            break;
        case 'e':
            if (isEmpty())
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
            break;
        case 'f':
            printf("Exiting the program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}