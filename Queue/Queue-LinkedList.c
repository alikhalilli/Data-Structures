#include <stdlib.h>
#include <stdio.h>

struct qNode {
    int data;
    struct qNode *next;
};

struct Queue {
    struct qNode *front;
    struct qNode *rear;
};

struct Queue *createQueue() {
    struct Queue *queue = (struct Stack *) malloc(sizeof(queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int item) {
    struct qNode *temp = (struct qNode *) malloc(sizeof(struct qNode));
    queue->front = temp;

    temp->data = item;
    temp->next = NULL;
    queue->rear->next = temp;
    queue->rear = temp;
}

int dequeue(struct Queue *queue) {
    struct qNode *temp = queue->front;
    int item = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return item;
}

int main() {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue = createQueue();
    return 0;
}
