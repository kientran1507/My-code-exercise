#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define MAX_STRING_LENGTH 201

struct ListNode {
    char key[MAX_STRING_LENGTH];
    struct ListNode *next;
};

struct HashTable {
    struct ListNode *buckets[TABLE_SIZE];
};

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    int length = strlen(key);

    for (int i = 0; i < length; i++) {
        hash = (hash * 256 + key[i]) % TABLE_SIZE;
    }

    return hash;
}

int insertKey(struct HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);

    struct ListNode *current = hashTable->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 0;  // Key already exists
        }
        current = current->next;
    }

    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->key, key);
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;

    return 1;  // Insertion successful
}

// Function to find a key in the hash table
int findKey(struct HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);

    // Search for the key in the list
    struct ListNode *current = hashTable->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;  // Key found
        }
        current = current->next;
    }

    return 0;  // Key not found
}

void freeHashTable(struct HashTable *hashTable) {
    for (unsigned int i = 0; i < TABLE_SIZE; i++) {
        struct ListNode *current = hashTable->buckets[i];
        while (current != NULL) {
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    struct HashTable hashTable;

    // Initialize the hash table buckets to NULL
    for (unsigned int i = 0; i < TABLE_SIZE; i++) {
        hashTable.buckets[i] = NULL;
    }

    // Read keys from the first block until encountering "*"
    char key[MAX_STRING_LENGTH];
    while (1) {
        scanf("%s", key);
        if (strcmp(key, "*") == 0) break;
        insertKey(&hashTable, key);
    }

    // Process actions from the second block
    char cmd[10];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0)
            break;
        if (strcmp(cmd, "find") == 0) {
            scanf("%s", key);
            printf("%d\n", findKey(&hashTable, key));
        } else if (strcmp(cmd, "insert") == 0) {
            scanf("%s", key);
            printf("%d\n", insertKey(&hashTable, key));
        }
    }

    // Free allocated memory
    freeHashTable(&hashTable);

    return 0;
}
