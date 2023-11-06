#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho node trong danh sách liên kết
struct Node {
    int data;
    struct Node* next;
};

// Hàm để tạo một node mới
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm để chèn một phần tử vào danh sách liên kết sao cho danh sách luôn được sắp xếp tăng dần
void insertSorted(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Hàm để in ra danh sách liên kết
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Tạo danh sách liên kết với 10 số nguyên ngẫu nhiên
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100; // Số nguyên ngẫu nhiên từ 0 đến 99
        insertSorted(&head, value);
    }

    printf("Danh sách liên kết sau khi chèn: ");
    printList(head);

    return 0;
}
