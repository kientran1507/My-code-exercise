#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho node trong danh sách liên kết
struct Node {
    int data;
    struct Node* next;
};

// Hàm để thêm một node mới vào danh sách
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Hàm để tìm giá trị lớn nhất trong danh sách
int findMax(struct Node* head) {
    int max = head->data;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// Hàm để tìm giá trị nhỏ nhất trong danh sách
int findMin(struct Node* head) {
    int min = head->data;
    while (head != NULL) {
        if (head->data < min) {
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

// Hàm để xóa node chứa giá trị x ra khỏi danh sách
void deleteNode(struct Node** head, int x) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == x) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return; // Không tìm thấy giá trị x trong danh sách
    }

    prev->next = temp->next;
    free(temp);
}

// Hàm để in ra danh sách liên kết
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Hàm để xóa toàn bộ danh sách
void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Nhập số lượng số nguyên: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhập số nguyên thứ %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    printf("Danh sách ban đầu: ");
    printList(head);

    int max = findMax(head);
    int min = findMin(head);

    deleteNode(&head, max);
    deleteNode(&head, min);

    printf("Danh sách sau khi xóa số lớn nhất và số nhỏ nhất: ");
    printList(head);

    deleteList(&head);

    printf("Danh sách sau khi xóa toàn bộ: ");
    printList(head);

    return 0;
}
