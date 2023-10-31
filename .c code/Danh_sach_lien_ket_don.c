#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho danh sách liên kết đơn
struct Node {
    int data;
    struct Node* next;
};

// Hàm để thêm một phần tử vào danh sách liên kết
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Hàm để in ra danh sách liên kết
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Thêm các phần tử vào danh sách
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 40);
    head = append(head, 50);

    // In ra danh sách liên kết
    printf("Danh sách liên kết: ");
    printList(head);

    // Giải phóng bộ nhớ khi đã sử dụng xong
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
