/*
Name: Toki Al Hasan
ID: C223001
Sec:3EM
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int x = 0;  // Initializing x to 0
struct Queue
{
    int front;
    int rear;
    int size;
    int *Q;
} q;

void create(struct Queue *q)
{
    printf("\nEnter the number of waiting slots to avoid inconvenience to the customers: ");
    scanf("%d", &q->size);
    q->front = -1;
    q->rear = -1;
    q->Q = (int*)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q)
{
    if((q->front == 0 && q->rear == q->size - 1) || (q->rear == (q->front - 1) % (q->size - 1)))
    {
        x--;
        printf("\nWaiting list is very large.\nWe recommend you not to wait.\nSorry for the inconvenience.\nDo visit us again.");
    }
    else if(q->front == -1)
    {
        q->front = q->rear = 0;
        printf("\nYour token number is %d", x);
        q->Q[q->rear] = x;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        printf("\nYour token number is %d", x);
        q->Q[q->rear] = x;
    }
}

void dequeue(struct Queue *q)
{
    int temp;
    if(q->front == -1 && q->rear == -1)
        printf("\nNo waiting yet!");
    else if(q->rear == q->front)
    {
        temp = q->Q[q->front];
        q->rear = q->front = -1;
        printf("\nYour wait is over. Token no. %d \nPlease make yourself comfortable here.", temp);
    }
    else
    {
        temp = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
        printf("\nYour wait is over. Token no. %d \nPlease make yourself comfortable here.", temp);
    }
}

void display(struct Queue *q)
{
    int i = 0;
    printf("\nThe waiting tokens are: ");

    if(q->front == -1 && q->rear == -1)
    {
        printf("\nNo more waiting customers!");
    }
    else if(q->front > q->rear)
    {
        for(i = q->front; i < q->size; i++)
        {
            printf("\n%d", q->Q[i]);
        }
        for(i = 0; i <= q->rear; i++)
        {
            printf("\n%d", q->Q[i]);
        }
    }
    else
    {
        for(i = q->front; i <= q->rear; i++)
        {
            printf("\n%d", q->Q[i]);
        }
    }
}

int main()
{
    int i;
    char Customer_name[20];
    int n, o = 1;
    printf(" \n\n                                       WELCOME TO IIUC CENTRAL RESTAURANT.\n\n");
    create(&q);
    while(o == 1)
    {
        printf("\nWaiting status:\n1. Book a table\n2. Whose waiting is over?\n3. Display the waiting list\n");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                printf("Enter the name of the customer in waiting: ");
                scanf("%s", Customer_name);
                x++;
                enqueue(&q);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;
            default:
                printf("Invalid choice!!");
        }
        printf("\nPress 1 to perform more operations: ");
        scanf("%d", &o);
    }
    return 0;
}
