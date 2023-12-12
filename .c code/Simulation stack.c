#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* myStack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->next = myStack->top;
    myStack->top = newNode;
}

void pop(struct Stack* myStack) {
    if (myStack->top == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d\n", myStack->top->value);

    struct Node* temp = myStack->top;
    myStack->top = myStack->top->next;

    free(temp);
}

int main() {
    struct Stack myStack;
    myStack.top = NULL;

    char cmd[5];

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "PUSH") == 0) {
            int value;
            scanf("%d", &value);
            push(&myStack, value);
        } else if (strcmp(cmd, "POP") == 0) {
            pop(&myStack);
        } else if (strcmp(cmd, "#") == 0) break;
    }

    return 0;
}
