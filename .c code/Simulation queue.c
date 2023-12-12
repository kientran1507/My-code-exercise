#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* myQueue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->next = NULL;

    if (myQueue->rear == NULL) {
        myQueue->front = myQueue->rear = newNode;
    } else {
        myQueue->rear->next = newNode;
        myQueue->rear = newNode;
    }
}

void dequeue(struct Queue* myQueue) {
    if (myQueue->front == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d\n", myQueue->front->value);

    struct Node* temp = myQueue->front;
    myQueue->front = myQueue->front->next;

    if (myQueue->front == NULL) {
        myQueue->rear = NULL;
    }

    free(temp);
}

void printQueue(struct Queue* myQueue) {
    struct Node* current = myQueue->front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue myQueue;
    myQueue.front = myQueue.rear = NULL;

    char cmd[5];

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "PUSH") == 0) {
            int value;
            scanf("%d", &value);
            enqueue(&myQueue, value);
        } else if (strcmp(cmd, "POP") == 0) {
            dequeue(&myQueue);
        } else if (strcmp(cmd, "#") == 0) {
            break;
        }
    }

    return 0;
}
