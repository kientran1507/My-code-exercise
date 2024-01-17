#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define HASH_TABLE_SIZE 10007

// Node structure for a linked list in the hash table
struct ListNode {
    char word[MAX_WORD_LENGTH + 1];
    int count;
    struct ListNode *next;
};

// Hash table structure
struct HashTable {
    struct ListNode *buckets[HASH_TABLE_SIZE];
};

// WordCount structure to store words and their counts
struct WordCount {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

// Function to calculate the hash value for a given word
unsigned int hash(char *word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + *word++;
    }
    return hashValue % HASH_TABLE_SIZE;
}

// Function to insert or update a word in the hash table
void insertOrUpdate(struct HashTable *hashTable, char *word) {
    unsigned int index = hash(word);
    struct ListNode *current = hashTable->buckets[index];

    // Check if the word is already in the list
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // Word not found, create a new node and insert it at the beginning of the list
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->word[MAX_WORD_LENGTH] = '\0';
    newNode->count = 1;
    newNode->next = hashTable->buckets[index];
    hashTable->buckets[index] = newNode;
}

// Function to create an array of WordCount from the hash table
struct WordCount* createWordArray(struct HashTable *hashTable, int *wordCount) {
    *wordCount = 0;

    // Count the total number of words
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct ListNode *current = hashTable->buckets[i];
        while (current != NULL) {
            (*wordCount)++;
            current = current->next;
        }
    }

    // Allocate memory for the array
    struct WordCount *wordArray = (struct WordCount *)malloc((*wordCount) * sizeof(struct WordCount));

    // Fill the array with words and counts
    int index = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct ListNode *current = hashTable->buckets[i];
        while (current != NULL) {
            strncpy(wordArray[index].word, current->word, MAX_WORD_LENGTH);
            wordArray[index].word[MAX_WORD_LENGTH] = '\0';
            wordArray[index].count = current->count;
            index++;
            current = current->next;
        }
    }

    return wordArray;
}

// Function to compare strings for qsort
int compareWords(const void *a, const void *b) {
    return strcmp(((struct WordCount *)a)->word, ((struct WordCount *)b)->word);
}

int main() {
    char text[10000];
    struct HashTable hashTable;

    // Initialize the hash table buckets to NULL
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable.buckets[i] = NULL;
    }

    // Read input until an empty line
    while (fgets(text, sizeof(text), stdin) && text[0] != '\n') {
        char *token = strtok(text, " \t\n"); // Tokenize based on space, tab, and newline

        while (token != NULL) {
            // Insert or update the word in the hash table
            insertOrUpdate(&hashTable, token);

            // Move to the next word
            token = strtok(NULL, " \t\n");
        }
    }

    // Create an array of WordCount from the hash table
    int wordCount;
    struct WordCount *wordArray = createWordArray(&hashTable, &wordCount);

    // Sort the array lexicographically
    qsort(wordArray, wordCount, sizeof(struct WordCount), compareWords);

    // Print the words and their occurrences
    for (int i = 0; i < wordCount; i++) {
        printf("%s %d\n", wordArray[i].word, wordArray[i].count);
    }

    // Free allocated memory
    free(wordArray);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct ListNode *current = hashTable.buckets[i];
        while (current != NULL) {
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
