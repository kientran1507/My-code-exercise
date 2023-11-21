#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char date[MAX_LEN];
    int count;
} DailyStats;

// So sánh hai DailyStats để sắp xếp theo thứ tự tăng dần của ngày
int compareDates(const void *a, const void *b) {
    return strcmp(((DailyStats *)a)->date, ((DailyStats *)b)->date);
}

void processInput() {
    DailyStats *stats = NULL;
    int statsSize = 0;
    char input[MAX_LEN];

    while (1) {
        fgets(input, MAX_LEN, stdin);

        if (input[0] == '*') {
            break;
        }

        // Parse input
        char date[MAX_LEN];
        sscanf(input, "%s", date);

        // Check if date already exists in stats
        int found = 0;
        for (int i = 0; i < statsSize; i++) {
            if (strcmp(stats[i].date, date) == 0) {
                stats[i].count++;
                found = 1;
                break;
            }
        }

        // If date doesn't exist, add it to stats
        if (!found) {
            statsSize++;
            stats = realloc(stats, statsSize * sizeof(DailyStats));
            strcpy(stats[statsSize - 1].date, date);
            stats[statsSize - 1].count = 1;
        }
    }

    // Sort stats by date in ascending order
    qsort(stats, statsSize, sizeof(DailyStats), compareDates);

    // Print results for days with counts
    for (int i = 0; i < statsSize; i++) {
        printf("%s %d\n", stats[i].date, stats[i].count);
    }

    // Clean up
    free(stats);
}

int main() {
    processInput();
    return 0;
}
