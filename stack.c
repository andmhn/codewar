#include <criterion/criterion.h>
#include <criterion/internal/ordered-set.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *root;
} Stack;

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

Test(Stack, should_work_for_fixed_tests) {
    Stack *stack = new_stack();
    cr_assert(stack_is_empty(stack), "The stack is initially empty");
    stack_push(stack, 1);
    cr_assert_eq(
        stack_peek(stack), 1,
        "A 1 was pushed to the stack so the top item in the stack should be 1");
    cr_assert(
        !stack_is_empty(stack),
        "The stack should have exactly 1 item and is therefore not empty");
    stack_push(stack, 2);
    cr_assert_eq(
        stack_peek(stack), 2,
        "The most recent number 2 pushed to the stack should be at the "
        "top of the stack");
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 3);
    cr_assert_eq(stack_peek(stack), 3);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 3,
                 "The pop operation should return the popped item");
    cr_assert_eq(stack_peek(stack), 2,
                 "The pop operation should remove the top item of the stack");
    cr_assert(
        !stack_is_empty(stack),
        "The stack should have 2 items remaining and is therefore not empty");
    stack_push(stack, 4);
    cr_assert_eq(stack_peek(stack), 4);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 5);
    cr_assert_eq(stack_peek(stack), 5);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 6);
    cr_assert_eq(stack_peek(stack), 6);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 6);
    cr_assert_eq(stack_peek(stack), 5);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 5);
    cr_assert_eq(stack_peek(stack), 4);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 7);
    cr_assert_eq(stack_peek(stack), 7);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 8);
    cr_assert_eq(stack_peek(stack), 8);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 9);
    cr_assert_eq(stack_peek(stack), 9);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 10);
    cr_assert_eq(stack_peek(stack), 10);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 10);
    cr_assert_eq(stack_peek(stack), 9);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 9);
    cr_assert_eq(stack_peek(stack), 8);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 8);
    cr_assert_eq(stack_peek(stack), 7);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 7);
    cr_assert_eq(stack_peek(stack), 4);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 4);
    cr_assert_eq(stack_peek(stack), 2);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 2);
    cr_assert_eq(stack_peek(stack), 1);
    cr_assert(!stack_is_empty(stack));
    cr_assert_eq(stack_pop(stack), 1);
    cr_assert(stack_is_empty(stack));
    stack_push(stack, 11);
    cr_assert_eq(stack_peek(stack), 11);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 12);
    cr_assert_eq(stack_peek(stack), 12);
    cr_assert(!stack_is_empty(stack));
    stack_push(stack, 13);
    cr_assert_eq(stack_peek(stack), 13);
    cr_assert(!stack_is_empty(stack));
    delete_stack(stack);
}
