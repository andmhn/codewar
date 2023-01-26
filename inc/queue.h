#include <stdbool.h>
#include <stdlib.h>

#pragma once

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front, *back;
} Queue;

void queue_enqueue(Queue *queue, int data);
int queue_dequeue(Queue *queue);
int queue_front(const Queue *queue);
bool queue_is_empty(const Queue *queue);
