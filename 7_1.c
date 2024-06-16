// 7.1 Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
// Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdbool.h>
#define N 5
int queue[N];
int front = -1, rear = -1;

void enqueue(int x)
{

    if (rear == N - 1)
    {
        printf("Queue is full. Can't insert %d.", x);
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("%d is insertred in the queue.", queue[rear]);
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("%d is insertred in the queue.", queue[rear]);
    }
}
void dequeue()
{

    if (rear == -1 && front == -1)
    {
        printf("Queue is Empty. Can't dequeue!");
    }
    else if (front == rear)
    {
        printf("%d is is being dequeued.", queue[front]);
        front = rear = -1;
        printf("\nQueue is totally empty! Now you can insert from start.");
    }
    else
    {
        printf("%d is is being dequeued.", queue[front]);
        queue[front] = '\0';
        front++;
    }
}

void display()
{

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Elements of queue are : ");
        for (int i = 0; i < rear + 1; i++)
        {

            printf("%d", queue[i]);
            if (i != rear)
            {
                printf(" -> ");
            }
        }
    }
}

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return rear == N - 1;
}

int main()
{
    int num;
    char c;

    while (1)
    {
        printf("\n *MENU* \n");
        printf("a.Enqueue\n");
        printf("b.Dequeue\n");
        printf("c.IsEmpty\n");
        printf("d.Display\n");
        printf("e.exit\n");
        printf("f.IsFull\n");
        printf("Enter choice : ");
        scanf("%s", &c);

        switch (c)
        {
        case 'a':
            printf("Enter the element to enqueue: ");
            scanf("%d", &num);
            enqueue(num);
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

        case 'f':
            if (isFull())
            {
                printf("Queue is full.\n");
            }
            else
            {
                printf("Queue is not full.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}