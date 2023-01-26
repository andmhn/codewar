#include"stack.h"

Node *new_node() {
    Node *node = malloc(sizeof(Node));
    return node;
}

Stack *new_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->root = NULL;
    return stack;
}

void stack_push(Stack *stack, int data) {
    Node *node = new_node();
    node->data = data;
    node->next = stack->root;

    stack->root = node;
}

int stack_pop(Stack *stack) {
    Node *nd = stack->root;
    int data = nd->data;
    stack->root = nd->next;
    free(nd);
    return data;
}

int stack_peek(const Stack *stack) { return stack->root->data; }

bool stack_is_empty(const Stack *stack) {
    if (stack->root == NULL)
        return true;
    return false;
}

// Test

void delete_stack(Stack *stack) {
    Node *nd = stack->root;
    while (nd) {
        Node *tmp = nd->next;
        free(nd);
        nd = tmp;
    }
    free(stack);
}
