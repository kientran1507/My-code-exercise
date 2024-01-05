#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *next;  // Linked list to store children
    struct Node *child; // Points to the first child
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

Node* findNode(Node* root, int id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;

    Node* temp = root->child;
    while (temp) {
        Node* result = findNode(temp, id);
        if (result) return result;
        temp = temp->next;
    }
    return NULL;
}

void insertNode(Node* root, int id, int parent) {
    Node* newNode = createNode(id);
    Node* parentNode = findNode(root, parent);
    if (parentNode) {
        if (parentNode->child == NULL) {
            parentNode->child = newNode;
        } else {
            Node* temp = parentNode->child;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->id);
        Node* temp = root->child;
        while (temp) {
            preOrder(temp);
            temp = temp->next;
        }
    }
}

void inOrder(Node* root) {
    if (root) {
        Node* child = root->child;
        if (child) {
            inOrder(child);
        }
        printf("%d ", root->id);
        while (child) {
            child = child->next;
            if (child) {
                inOrder(child);
            }
        }
    }
}

void postOrder(Node* root) {
    if (root) {
        Node* temp = root->child;
        while (temp) {
            postOrder(temp);
            temp = temp->next;
        }
        printf("%d ", root->id);
    }
}

int main() {
    char action[10];
    int u, v;
    Node* root = NULL;

    while (1) {
        scanf("%s", action);
        if (action[0] == '*') break;
        if (strcmp(action, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = createNode(u);
        } else if (strcmp(action, "Insert") == 0) {
            scanf("%d %d", &u, &v);
            insertNode(root, u, v);
        } else if (strcmp(action, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(action, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(action, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    return 0;
}
