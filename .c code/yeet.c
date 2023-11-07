#include <stdio.h>
#include <string.h>

#define MAX_ATHLETES 100

struct athlete {
    char Name[50];
    char Nation[50];
    int Register[3];
    short Pass[3];
    int Total;
};

typedef struct athlete Athlete;

void printHeader() {
    printf("%-20s%-20s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Name", "Nation", "R1", "R2", "R3", "P1", "P2", "P3");
}

void printAthleteInfo(Athlete *a) {
    printf("%-20s%-20s%-10d%-10d%-10d%-10d%-10d%-10d\n", a->Name, a->Nation, a->Register[0], a->Register[1], a->Register[2], a->Pass[0], a->Pass[1], a->Pass[2]);
}

void calculateTotal(Athlete *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i].Total = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i].Pass[j] == 1) {
                a[i].Total += a[i].Register[j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of athletes (1-100): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ATHLETES) {
        printf("Invalid number of athletes. Please enter a number between 1 and 100.\n");
        return 1;
    }

    Athlete athletes[MAX_ATHLETES];

    for (int i = 0; i < n; i++) {
        printf("Enter information for athlete %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", athletes[i].Name);  // Read the name with spaces.
        printf("Nation: ");
        scanf("%s", athletes[i].Nation);
        for (int j = 0; j < 3; j++) {
            printf("Enter R%d for athlete %d: ", j + 1, i + 1);
            scanf("%d", &athletes[i].Register[j]);
            printf("Enter P%d for athlete %d: ", j + 1, i + 1);
            scanf("%hd", &athletes[i].Pass[j]);
        }
    }

    printf("\nAthlete Information:\n");
    printHeader();
    for (int i = 0; i < n; i++) {
        printAthleteInfo(&athletes[i]);
    }

    calculateTotal(athletes, n);

    printf("\nAthlete Information with Totals:\n");
    printHeader();
    for (int i = 0; i < n; i++) {
        printAthleteInfo(&athletes[i]);
        printf("%-10d\n", athletes[i].Total);
    }

    return 0;
}
