#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define CAPACITY 200

typedef struct node
{
    int value;
    struct node * next;
} Queue;
unsigned int size = 0;

int push(Queue ** rear, Queue ** front, int data);
int pop(Queue ** front);
int getRear(Queue * rear);
int getFront(Queue * front);
int isEmpty();
int isFull();


int main()
{
    int op, data;
    Queue *rear, *front;

    rear  = NULL;
    front = NULL;
    while (1)
    {
        printf("  QUEUE LINKED operations: \n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("0. Exit\n");

        printf("Select what you want: ");

        scanf("%d", &op);
        switch (op)
        {
            case 1:
                printf("\nEnter data to push: ");
                scanf("%d", &data);

                if (push(&rear, &front, data))
                    printf("value added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = pop(&front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3:
                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Queue size => %d", size);

                break;

            case 4:
                data = getRear(rear);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Rear => %d", data);

                break;

            case 5:

                data = getFront(front);

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Front => %d", data);

                break;

            case 0:
                printf("Exit.\n");
                exit(0);

            default:
                printf("try again.");
                break;
        }

        printf("\n\n");
    }
}

int push(Queue ** rear, Queue ** front, int value)
{
    Queue * newNode = NULL;

    if (isFull())
    {
        return 0;
    }
    newNode = (Queue *) malloc (sizeof(Queue));
    newNode->value = value;
    newNode->next = NULL;


    if ( (*rear) )
    {
        (*rear)->next = newNode;
    }

    *rear = newNode;
    if ( !( *front) )
    {
        *front = *rear;
    }

    size++;

    return 1;
}

int pop(Queue ** front)
{
    Queue *toDequeue = NULL;
    int value = INT_MIN;

    if (isEmpty())
    {
        return INT_MIN;
    }

    toDequeue= *front;
    value= toDequeue->value;

    *front = (*front)->next;


    size--;

    free(toDequeue);

    return value;
}


int getRear(Queue * rear)
{
    return (isEmpty())
            ? INT_MIN
            : rear->value;
}

int getFront(Queue * front)
{
    return (isEmpty())
            ? INT_MIN
            : front->value;
}

int isEmpty()
{
    return (size <= 0);
}

int isFull()
{
    return (size > CAPACITY);
}
