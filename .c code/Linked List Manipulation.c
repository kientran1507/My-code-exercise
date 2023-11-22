#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc cho node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm để thêm một node mới vào cuối danh sách
Node* addlast(Node* head, int data) {
    // Tạo một node mới
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Nếu danh sách trống thì node mới trở thành đầu danh sách
    if (head == NULL) {
        return newNode;
    }

    // Duyệt qua danh sách để tìm node cuối cùng
    Node* current = head;
    while (current->next != NULL) {
        // Kiểm tra xem data đã có trong danh sách chưa
        if (current->data == data) {
           //  printf("%d is already in the linked list\n", data);
            free(newNode); // Nếu đã có thì giải phóng bộ nhớ của node mới
            return head;   // và trả lại đầu danh sách như cũ
        }
        current = current->next;
    }

    // Thêm node mới vào cuối danh sách
    current->next = newNode;
    return head;
}

// Hàm để thêm một node mới vào đầu danh sách
Node* addfirst(Node* head, int data) {
    // Tạo một node mới
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head; // Node mới trỏ về đầu danh sách

    // Kiểm tra xem data đã có trong danh sách chưa
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            // printf("%d is already in the linked list\n", data);
            free(newNode); // Nếu đã có thì giải phóng bộ nhớ của node mới
            return head;   // Và trả lại đầu danh sách như cũ
        }
        current = current->next;
    }

    // Cập nhật đầu danh sách là node mới
    return newNode;
}

// Hàm để thêm một node mới sau một node có giá trị là v
Node* addafter(Node* head, int u, int v) {
    // Tạo một node mới
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = NULL;

    // Nếu danh sách trống thì node mới trở thành đầu danh sách
    if (head == NULL) {
        return newNode;
    }

    // Duyệt qua danh sách để tìm node có giá trị bằng v
    Node* current = head;
    while (current != NULL) {
        if (current->data == v) {
            // Kiểm tra xem u đã có trong danh sách chưa
            Node* temp = head;
            while (temp != NULL) {
                if (temp->data == u) {
                    // printf("%d is already in the linked list\n", u);
                    free(newNode); // Nếu đã có thì giải phóng bộ nhớ của node mới
                    return head;   // Và trả lại đầu danh sách như cũ
                }
                temp = temp->next;
            }

            // Tạo node mới sau node v
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    // Nếu v không có trong danh sách, in ra thông báo và giải phóng bộ nhớ của node mới
    // printf("%d is not in the linked list\n", v);
    free(newNode);
    return head;
}

// Hàm để thêm một node mới trước một node có giá trị là v
Node* addbefore(Node* head, int u, int v) {
    // Tạo một node mới
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = NULL;

    // Nếu danh sách trống thì node mới trở thành đầu danh sách
    if (head == NULL) {
        return newNode;
    }

    // Kiểm tra xem node v có phải là đầu danh sách không
    if (head->data == v) {
        newNode->next = head;
        return newNode;
    }

    // Duyệt qua danh sách để tìm node có giá trị bằng v
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == v) {
            // Kiểm tra xem u đã có trong danh sách chưa
            Node* temp = head;
            while (temp != NULL) {
                if (temp->data == u) {
                    // printf("%d is already in the linked list\n", u);
                    free(newNode); // Nếu đã có thì giải phóng bộ nhớ của node mới
                    return head;   // Và trả lại đầu danh sách như cũ
                }
                temp = temp->next;
            }

            // Tạo node mới trước node v
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }

    // Nếu v không có trong danh sách, in ra thông báo và giải phóng bộ nhớ của node mới
    // printf("%d is not in the linked list\n", v);
    free(newNode);
    return head;
}

// Hàm để xóa node chứa giá trị k ra khỏi danh sách
Node* removeNode(Node* head, int k) {
    Node* temp = head;
    Node* prev = NULL;

    // Handle the case when the node to be removed is the head
    if (temp != NULL && temp->data == k) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the node with the specified data
    while (temp != NULL && temp->data != k) {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found, print a message and return the original head
    if (temp == NULL) {
        // printf("%d is not in the linked list\n", k);
        return head;
    }

    // Node with the specified data is found, remove it
    prev->next = temp->next;
    free(temp);
    return head;
}

// Hàm để đảo ngược thứ tự các nút trong danh sách
Node* reverse(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        // Lưu node tiếp theo
        next = current->next;

        // Đảo ngược liên kết
        current->next = prev;

        // Tiếp tục
        prev = current;
        current = next;
    }

    // 'prev' chỉ tới đầu của danh sách đảo ngược
    return prev;
}

// Hàm để in ra danh sách liên kết
void printList(const Node* head) {
    const Node* current = head; // Use a local variable for traversing the list
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm để giải phóng bộ nhớ của danh sách
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    int n, k, u, v;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        head = addlast(head, k);
    }

    while (1) {
        char cmd[256];
        scanf("%s", cmd);

        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "addlast") == 0) {
            scanf("%d", &k);
            head = addlast(head, k);
        }
        else if (strcmp(cmd, "addfirst") == 0) {
            scanf("%d", &k);
            head = addfirst(head, k);
        }
        else if (strcmp(cmd, "addafter") == 0) {
            scanf("%d", &u);
            scanf("%d", &v);
            head = addafter(head, u, v);
        }
        else if (strcmp(cmd, "addbefore") == 0) {
            scanf("%d", &u);
            scanf("%d", &v);
            head = addbefore(head, u, v);
        }
        else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &k);
            head = removeNode(head, k);
        }
        else if (strcmp(cmd, "reverse") == 0) {
            head = reverse(head);
        }
    }

    // Print the linked list
    printList(head);

    // Free the memory used by the linked list
    freeList(head);

    return 0;
}
