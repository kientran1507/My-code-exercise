#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc thông tin sinh viên
struct Student {
    char name[100];
    char email[100];
    struct Student* next;
    struct Student* prev;
};

// Khởi tạo danh sách liên kết đôi
struct Student* head = NULL;
struct Student* tail = NULL;

// Hàm để đọc danh sách sinh viên từ tệp văn bản
void loadStudentList() {
    FILE* file = fopen("student_list.txt", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    char line[256];
    char name[100];
    char email[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "Name: ") != NULL) {
            sscanf(line, "Name: %99[^\n]", name);
        } else if (strstr(line, "Email: ") != NULL) {
            sscanf(line, "Email: %99[^\n]", email);
            addStudent(name, email);
        }
    }

    fclose(file);
    printf("Student list loaded from student_list.txt\n");
}

// Hàm để in ra danh sách sinh viên
void printStudentList() {
    struct Student* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("\n");
        current = current->next;
    }
}

// Hàm để thêm một hồ sơ sinh viên vào danh sách
void addStudent(char name[], char email[]) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    strcpy(newStudent->email, email);
    newStudent->next = NULL;
    newStudent->prev = tail;

    if (head == NULL) {
        head = newStudent;
        tail = newStudent;
    } else {
        tail->next = newStudent;
        tail = newStudent;
    }

    printf("Student added successfully.\n");
}

// Hàm để xóa một hồ sơ sinh viên dựa trên tên
void deleteStudent(char name[]) {
    struct Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev == NULL) {
                head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current->next == NULL) {
                tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Student with name %s deleted.\n", name);
            return;
        }
        current = current->next;
    }
    printf("Student with name %s not found.\n", name);
}

// Hàm để lưu danh sách sinh viên vào một file văn bản
void saveStudentList() {
    FILE* file = fopen("student_list.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    struct Student* current = head;
    while (current != NULL) {
        fprintf(file, "Name: %s\n", current->name);
        fprintf(file, "Email: %s\n\n", current->email);
        current = current->next;
    }

    fclose(file);
    printf("Student list saved to student_list.txt\n");
}

int main() {
    int choice;
    char name[100];
    char email[100];

    while (1) {
        printf("Student Profile Management\n");
        printf("1. Load Student List\n");
        printf("2. Print Student List\n");
        printf("3. Add Student\n");
        printf("4. Delete Student\n");
        printf("5. Save Student List\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loadStudentList();
                break;
            case 2:
                printf("Student List:\n");
                printStudentList();
                break;
            case 3:
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student email: ");
                scanf("%s", email);
                addStudent(name, email);
                break;
            case 4:
                printf("Enter student name to delete: ");
                scanf("%s", name);
                deleteStudent(name);
                break;
            case 5:
                saveStudentList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
