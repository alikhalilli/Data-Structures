#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int rear;
    int front;
    int size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->rear = capacity - 1;
    queue->front = queue->size = 0;
    queue->array = (int *) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue *queue) {
    return queue->size == 0;
}

int isFull(struct Queue *queue) {
    return queue->size == queue->capacity;
}

void enqueue(struct Queue *queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) return 0;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct Queue *queue) {
    if (isEmpty(queue))return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue *queue) {
    if (isEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->rear];
    return item;
}

int main() {
    struct Queue *queue = createQueue(10);
    enqueue(queue, 10);
    int item = dequeue(queue);
    return 0;
}
