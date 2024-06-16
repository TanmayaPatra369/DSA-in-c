// 8.1 Write a menu driven program to implement Deques (both Inputrestricted and output-restricted) and
// performed operations such as Enqueue, Dequeue, Peek, IsEmpty, IsFull using static array.

// INPUT RESTRICTED

#include <stdio.h>
#include <stdbool.h>
#define N 5
int queue[N];
int front = -1, rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return front == (rear + 1) % N;
}

void enqueue(int x)
{

    if (isFull())
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
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("%d is insertred in the queue.", queue[rear]);
    }
}
void deleteFromLeft()
{

    if (isEmpty())
    {
        printf("Queue is Empty. Can't dequeue!");
    }
    else if (front == rear)
    {
        printf("%d is is being dequeued.", queue[front]);
        front = rear = -1;
        printf("\nQueue is totally empty.");
    }
    else
    {
        printf("%d is is being dequeued.", queue[front]);
        queue[front] = '\0';
        front = (front + 1) % N;
    }
}
void deleteFromRight()
{

    if (isEmpty())
    {
        printf("Queue is Empty. Can't dequeue!");
    }
    else if (front == rear)
    {
        printf("%d is is being dequeued.", queue[rear]);
        front = rear = -1;
        printf("\nQueue is totally empty.");
    }
    else
    {
        printf("%d is is being dequeued.", queue[rear]);
        queue[rear] = '\0';
        rear = (rear - 1 ) % N;
    }
}

void display()
{

    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements of queue are : ");
        for (int i = front;; i = (i + 1) % N)
        {

            printf("%d", queue[i]);
            if (i != rear)
            {
                printf(" -> ");
            }
            if (i == rear)
                break;
        }
        printf("\n");
    }
}

int main()
{
    int num;
    char c;

    while (1)
    {
        printf("\n *MENU* \n");
        printf("a.Enqueue\n");
        printf("b.Delete from left \n");
        printf("c.Delete from right \n");
        printf("d.Display\n");
        printf("e.exit\n");
        printf("f.IsFull\n");
        printf("h.IsEmpty\n");
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
            deleteFromLeft();
            break;
        case 'c':
            deleteFromRight();
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
            if (isEmpty())
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Queue is not empty.\n");
            }
            break;
        case 'h':

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}