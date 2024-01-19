#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the head of the linked list
Node* insertHead(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

// Function to insert a new node at the tail of the linked list
Node* insertTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data == data) {
            free(newNode);
            return head;
        }
        current = current->next;
    }

    if (current->data == data) {
        free(newNode);
        return head;
    }

    current->next = newNode;
    return head;
}

// Function to print all elements of the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to print even elements of the linked list followed by odd elements
void printEvenOdd(Node* head) {
    Node* current = head;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }

    current = head;  // Reset the pointer to the head for odd numbers

    while (current != NULL) {
        if (current->data % 2 != 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }

    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Process the input
    char command[20];
    int data;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "InsertHead") == 0) {
            scanf("%d", &data);
            if (data > 0) head = insertHead(head, data);
        } else if (strcmp(command, "InsertTail") == 0) {
            scanf("%d", &data);
            if (data > 0) head = insertTail(head, data);
        } else if (strcmp(command, "Print") == 0) {
            scanf("%d", &data);
            if (data == 0) {
                printList(head);
            } else if (data == 1) {
                printEvenOdd(head);
            }
        }
    }

    // Free allocated memory
    freeList(head);

    return 0;
}
