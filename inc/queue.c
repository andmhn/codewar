#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front, *back;
} Queue;

// Modify the code below to implement the key operations for queues
void queue_enqueue(Queue *queue, int data) {
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = queue->back;
    queue->back = tmp;
}

int queue_dequeue(Queue *queue) {
    Node *back = queue->back;
    int data = back->data;

    queue->back = back->next;
    free(back);
    return data;
}

int queue_front(const Queue *queue) { return queue->front->data; }

bool queue_is_empty(const Queue *queue) {
    if (queue->front == NULL && queue->back == NULL)
        return true;
    return false;
}
