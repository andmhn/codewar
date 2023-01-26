#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#pragma once

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *root;
} Stack;

Stack *new_stack();
void stack_push(Stack *stack, int data);
int stack_pop(Stack *stack);
int stack_peek(const Stack *stack);
bool stack_is_empty(const Stack *stack);
void delete_stack(Stack *stack);
