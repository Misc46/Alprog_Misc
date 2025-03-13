#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue penuh!\n");
        return;
    }
    q->data[++q->rear] = val;
}

int findMax(Queue *q)
{
    int max = q->data[q->front];
    for (int i = q->front; i <= q->rear; i++)
        if (q->data[i] > max)
            max = q->data[i];
    return max;
}

int findMin(Queue *q)
{
    int min = q->data[q->front];
    for (int i = q->front; i <= q->rear; i++)
        if (q->data[i] < min)
            min = q->data[i];
    return min;
}

int main()
{
    Queue q = {.front = 0, .rear = -1};
    int n, num;

    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

    printf("Masukkan angka-angka:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        enqueue(&q, num);
    }

    int result = (findMax(&q) + findMin(&q)) / 2;
    printf("Hasil: %d\n", result);
    return 0;
}