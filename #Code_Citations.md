# Code Citations

## License: GPL_3_0
https://github.com/bashlogs/DSA/tree/8d5890bc5df3dd35bfeef85fa051a7e2c6870eae/dsa/Linked%20list/LL%20remove%20function.c

```
;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to
```


## License: unknown
https://github.com/adityaapraveen/DSA-College/tree/027019e2657736548115fab04ce5fa6d95ddcc9a/LinearQueueUsingLinkedList.c

```
* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function
```


## License: unknown
https://github.com/jayapriya-a-n/DSA_codes/tree/cf13f179ccac01b91759ae1217e719c8df3899a9/supermarket_checkout.c

```
Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

//
```

