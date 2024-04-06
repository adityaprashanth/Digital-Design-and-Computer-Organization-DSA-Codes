#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Queue
struct Queue {
    int front, rear, size;
    int *array;
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to check if the queue is full
int isFull(struct Queue* queue, int capacity) {
    return (queue->size == capacity);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item, int capacity) {
    if (isFull(queue, capacity)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % capacity;
    }

    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue, int capacity) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % capacity;
    }

    queue->size--;
    return item;
}

// Function to get the front element of the queue without dequeuing
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }

    return queue->array[queue->front];
}

int main() {
    int capacity;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &capacity);

    struct Queue* queue = createQueue(capacity);

    int numElements, element;
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &numElements);

    printf("Enter %d elements to enqueue:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        enqueue(queue, element, capacity);
    }

    printf("Front element: %d\n", front(queue));
    printf("Dequeued element: %d\n", dequeue(queue, capacity));
    printf("Dequeued element: %d\n", dequeue(queue, capacity));
    printf("Dequeued element: %d\n", dequeue(queue, capacity));

    free(queue->array);
    free(queue);

    return 0;
}
