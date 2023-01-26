#include "queue.h"

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
