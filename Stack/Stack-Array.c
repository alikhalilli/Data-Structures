#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Last In First Out - Array Implementation

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

// a structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

// function to create a stack of given capacity.
// It initializes size of stack as 0
struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to add item to stack. It increases top by 1
void push(struct Stack *stack, int item) {
    if (isFull())
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from tack. It decreases top by 1
int pop(struct Stack *stack) {
    if (isEmpty())return INT_MIN;
    return stack->array[stack->top--];
}

int main() {
    struct Stack *stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    return 0;
}
