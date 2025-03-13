#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an element
void enqueue(Queue *queue, int data)
{
    Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element
void dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        return;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
}

// Function to print the queue
void printQueue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue (dari first): Empty\n");
        return;
    }
    Node *temp = queue->front;
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
    int n, instruction, value;
    Queue *queue = createQueue();

    // Read the number of instructions
    scanf("%d", &n);

    // Process each instruction
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &instruction);
        if (instruction == 1)
        {
            // Enqueue operation
            scanf("%d", &value);
            enqueue(queue, value);
        }
        else if (instruction == 2)
        {
            // Dequeue operation
            dequeue(queue);
        }
    }

    // Print the final state of the queue
    printQueue(queue);

    // Free the queue
    while (queue->front != NULL)
    {
        dequeue(queue);
    }
    free(queue);

    return 0;
}