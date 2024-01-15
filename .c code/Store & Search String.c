#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100000
#define KEY_SIZE 51

typedef struct Node {
    char key[KEY_SIZE];
    struct Node* next;
} Node;

typedef struct {
    Node* table[MAX_KEYS];
} HashTable;

unsigned int hash(const char* key) {
    unsigned int hashVal = 0;
    while (*key) {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % MAX_KEYS;
}

Node* createNode(const char* key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strcpy(newNode->key, key);
        newNode->next = NULL;
    }
    return newNode;
}

void insert(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key);
    Node* newNode = createNode(key);

    if (!hashTable->table[index]) {
        hashTable->table[index] = newNode;
    } else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

int find(HashTable* hashTable, const char* key) {
    unsigned int index = hash(key);
    Node* current = hashTable->table[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1; // Key found
        }
        current = current->next;
    }

    return 0; // Key not found
}

int main() {
    HashTable hashTable = {0};

    // Read the first block of keys
    char key[KEY_SIZE];
    while (scanf("%s", key) == 1 && strcmp(key, "*") != 0) {
        insert(&hashTable, key);
    }

    // Read the second block of actions
    char cmd[10], actionKey[KEY_SIZE];
    while (scanf("%s", cmd) == 1 && strcmp(cmd, "***") != 0) {
        scanf("%s", actionKey);
        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", find(&hashTable, actionKey));
        } else if (strcmp(cmd, "insert") == 0) {
            int result = find(&hashTable, actionKey);
            if (!result) {
                insert(&hashTable, actionKey);
            }
            printf("%d\n", !result);
        }
    }

    // Clean up the allocated memory
    for (int i = 0; i < MAX_KEYS; i++) {
        Node* current = hashTable.table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
