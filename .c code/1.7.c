#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Số lượng các thành phần cần sinh ra
#define NUM_SENTENCES 10
#define NUM_ARTICLES 5
#define NUM_NOUNS 5
#define NUM_VERBS 5
#define NUM_PREPOSITIONS 5

// Mảng các mạo từ, danh từ, động từ, giới từ
const char* articles[NUM_ARTICLES] = {"the", "a", "one", "some", "any"};
const char* nouns[NUM_NOUNS] = {"boy", "girl", "dog", "town", "car"};
const char* verbs[NUM_VERBS] = {"drove", "jumped", "ran", "walked", "skipped"};
const char* prepositions[NUM_PREPOSITIONS] = {"to", "from", "over", "under", "on"};

// Hàm sinh số ngẫu nhiên từ min đến max
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main(void) {
    // Khởi tạo bộ sinh số ngẫu nhiên dựa trên thời gian
    srand(time(NULL));

    for (int i = 0; i < NUM_SENTENCES; i++) {
        // Lựa chọn ngẫu nhiên các thành phần của câu
        const char* article_1 = articles[random_int(0, NUM_ARTICLES - 1)];
        const char* article_2 = articles[random_int(0, NUM_ARTICLES - 1)];
        const char* noun_1 = nouns[random_int(0, NUM_NOUNS - 1)];
        const char* noun_2 = nouns[random_int(0, NUM_NOUNS - 1)];
        const char* verb = verbs[random_int(0, NUM_VERBS - 1)];
        const char* preposition = prepositions[random_int(0, NUM_PREPOSITIONS - 1)];

        // In câu tự động
        printf("%c%s %s %s %s %s %s.\n", toupper(article_1[0]), article_1 + 1, noun_1, verb, preposition, article_2, noun_2);
    }

    return 0;
}
