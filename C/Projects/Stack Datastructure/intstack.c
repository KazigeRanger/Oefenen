#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack overflow\n");
        return; // Memory allocation failed
    }
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return INT_MIN; // Indicate underflow
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return INT_MIN; // Indicate empty stack
    }
    return stack->top->data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int main() {
    Stack stack;
    Stack* stackptr = &stack;
    initStack(stackptr);

    push(stackptr, 8);
}