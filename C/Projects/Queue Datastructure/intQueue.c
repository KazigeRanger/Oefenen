#include <stdio.h>
#include <stdlib.h>

typedef struct Client {
    int value;
    struct Client *next;
} Client;

typedef struct Queue {
    Client *front;
    Client *back;
} Queue;

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->back = NULL;
}

void push(Queue *queue, int item) {
    // if (item == NULL) {
    //     fprintf(stderr, "Error: cannot push NULL to a queue.");
    //     return 1;
    // }
    Client *newClient = (Client *)malloc(sizeof(Client));
    newClient->value = item;
    queue->back = newClient;
    newClient->next = queue->back;
    if (newClient->next == NULL) {
        queue->front = newClient;
    }
}

int pop(Queue *queue) {
    if (queue->front == NULL || queue->back == NULL) {
        fprintf(stderr, "Error: content of queue can't be NULL.");
        return 1;
    }
    Client *temp = queue->front;
    int poppedValue = temp->value;
    queue->front = queue->front->next;
    queue->back = queue->back->next;
    free(temp);
    return poppedValue;
}

int main() {
    Queue queue;
    Queue *queueptr = &queue;
    initQueue(queueptr);

    push(queueptr, 10);
    push(queueptr, 5);
    push(queueptr, 20);

    printf("Front: %d\n", queueptr->front->value);
    printf("Back: %d\n", queueptr->back->value);

    // pop(queueptr);

    // printf("Front after pop: %d\n", queueptr->front->value);

    printf("%d\n", queueptr->front->next->value);
}