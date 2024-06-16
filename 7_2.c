// 7.2 Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue, 
// IsEmpty, Traverse using single linked list.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = 0, *rear = 0;

bool isEmpty()
{
    return front == NULL || rear == NULL;
}

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (isEmpty())
    {
        front = rear = newnode;
        printf("%d is inserted in the queue\n .", rear->data);
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        printf("%d is inserted in the queue\n .", rear->data);
    }
}

void *dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty! Cant dequeue.\n");
    }
    else
    {
        struct node *temp;
        temp = front;
        printf("The date is being dequeued is %d.\n", front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct node *t;
        t = front;
        printf("Queue elements : ");
        int i = 0;
        while (t != NULL)
        {
            printf("%d", t->data);
            t = t->next;
            if (t != NULL)
            {
                printf(" -> ");
            }
            i++;
        }
    }
}

int main()
{
    int data;
    char c;

    while (1)
    {
        printf("\n *MENU* \n");
        printf("a.Enqueue\n");
        printf("b.Dequeue\n");
        printf("c.IsEmpty\n");
        printf("d.Display\n");
        printf("e.exit\n");
        printf("Enter choice : ");
        scanf("%s", &c);

        switch (c)
        {
        case 'a':
            printf("Enter the element to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 'b':
            dequeue();
            break;
        case 'c':
            if (isEmpty())
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
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