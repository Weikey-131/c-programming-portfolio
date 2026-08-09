#include "adt.h"
void stackInit(Stack *s) { s->top = -1; }
int stackIsEmpty(const Stack *s) { return s->top < 0; }
int stackIsFull(const Stack *s) { return s->top == CAPACITY - 1; }
int stackPush(Stack *s, int value) {
    /* TODO: reject a full stack, then add value at the top. */
    if (stackIsFull(s))  // Check if the stack is already full
    {
        return 0;
    }
    s->top++; // Move top 
    s->data[s->top] = value;// Store the new value
    return 1;//process successfully
}
int stackPop(Stack *s, int *value) {
    /* TODO: reject an empty stack, then remove the top value. */
    if (stackIsEmpty(s))// Check if the stack is empty
    {
        return 0;
    }
    *value = s->data[s->top];// save the top value
    s->top--; // Remove the top element
    return 1;//process successfully
}
void queueInit(Queue *q) { q->front = 0; q->rear = -1; q->count = 0; }
int queueIsEmpty(const Queue *q) { return q->count == 0; }
int queueIsFull(const Queue *q) { return q->count == CAPACITY; }
int enqueue(Queue *q, int value) {
    /* TODO: wrap rear with % CAPACITY, store value, update count. */
    // Check if queue is full
    if (queueIsFull(q))
    {
        return 0;
    }
    q->rear = (q->rear + 1) % CAPACITY;// Move rear to the next position
    q->data[q->rear] = value; // Store the new value
    q->count++;
    return 1;//process successfully
}
int dequeue(Queue *q, int *value) {
    /* TODO: read front, wrap front with % CAPACITY, update count. */
    // Check if queue is empty
    if (queueIsEmpty(q))
    {
        return 0;
    }
    *value = q->data[q->front];    // Read the value at the front
    q->front = (q->front + 1) % CAPACITY; // Move front to the next position
    q->count--;
    return 1;//process successfully
}
