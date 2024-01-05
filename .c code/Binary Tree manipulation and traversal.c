#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* findNode(Node* root, int id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    Node* left = findNode(root->left, id);
    if (left) return left;
    return findNode(root->right, id);
}

void addLeft(Node* root, int childID, int parentID) {
    Node* parent = findNode(root, parentID);
    if (parent && !parent->left) {
        parent->left = createNode(childID);
    }
}

void addRight(Node* root, int childID, int parentID) {
    Node* parent = findNode(root, parentID);
    if (parent && !parent->right) {
        parent->right = createNode(childID);
    }
}

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->id);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->id);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->id);
    }
}

int main() {
    char command[20];
    Node* root = NULL;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "MakeRoot") == 0) {
            int id;
            scanf("%d", &id);
            root = createNode(id);
        } else if (strcmp(command, "AddLeft") == 0) {
            int parentID, childID;
            scanf("%d %d", &childID, &parentID);
            addLeft(root, childID, parentID);
        } else if (strcmp(command, "AddRight") == 0) {
            int parentID, childID;
            scanf("%d %d", &childID, &parentID);
            addRight(root, childID, parentID);
        } else if (strcmp(command, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(command, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        } else if (strcmp(command, "*") == 0) {
            break;
        }
    }

    return 0;
}
