#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int new_data)
{                                                  // function returns a Node
    Node *new_node = (Node *)malloc(sizeof(Node)); // Inisialisasi node baru dengan ukuran node
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// queue type
typedef struct Queue
{
    Node *front, *rear;
} Queue;

// create queue

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int data)
{
    Node *createdNode = newNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = createdNode;
        return;
    }
    q->rear->next = createdNode;
    q->rear = createdNode;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

void printQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue (dari first): Empty\n");
        return;
    }
    Node *temp = q->front;
    printf("Queue (dari first): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, inst, value;
    Queue *q = createQueue();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inst);
        if (inst == 1)
        {
            printf("Masukan: ");
            scanf("%d", &value);
            enqueue(q, value);
        }
        else
        {
            dequeue(q);
        }
    }

    printQueue(q);
}