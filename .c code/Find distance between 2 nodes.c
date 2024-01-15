#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* del(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = del(root->left, value);
    else if (value > root->data)
        root->right = del(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

// Function to find the distance from root to a given node
int findDistance(struct Node* root, int key) {
    if (root == NULL) return -1;

    int distance = 0;
    while (root != NULL) {
        if (key < root->data) {
            root = root->left;
        } else if (key > root->data) {
            root = root->right;
        } else {
            return distance;
        }
        distance++;
    }

    return -1; // Node not found
}

// Function to find the distance between two nodes
int findNodeDistance(struct Node* root, int n1, int n2) {
    if (root == NULL) return -1;

    while (root != NULL) {
        if (n1 < root->data && n2 < root->data) {
            root = root->left;
        } else if (n1 > root->data && n2 > root->data) {
            root = root->right;
        } else {
            // Found the lowest common ancestor
            int distance1 = findDistance(root, n1);
            int distance2 = findDistance(root, n2);
            if (distance1 != -1 && distance2 != -1) {
                return distance1 + distance2;
            } else {
                return -1; // One of the nodes not found
            }
        }
    }

    return -1; // LCA not found
}

int main() {
    struct Node* root = NULL;
    int value;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) {
            break;
        } else if (strcmp(cmd, "insert") == 0) {
            scanf(" %d", &value);
            root = insert(root, value);
        } else if (strcmp(cmd, "del") == 0) {
            scanf(" %d", &value);
            root = del(root, value);
        } else if (strcmp(cmd, "dis") == 0) {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            int distance = findNodeDistance(root, n1, n2);
            if (distance != -1) {
                printf("%d\n", distance);
            } else {
                printf("Nodes not present in the tree\n");
            }
        }
    }

    return 0;
}
