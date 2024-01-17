#include <stdio.h>
#include <string.h>

#define BASE 256

long computeHashCode(const char *s, int m) {
    int length = strlen(s);
    long hash = 0;
    long power = 1;

    for (int i = length - 1; i >= 0; --i) {
        hash = (hash + s[i] * power) % m;
        power = (power * BASE) % m;
    }

    return hash;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char strings[n][201];

    for (int i = 0; i < n; ++i) {
        scanf("%s", strings[i]);
    }

    for (int i = 0; i < n; ++i) {
        long hashCode = computeHashCode(strings[i], m);
        printf("%ld\n", hashCode);
    }

    return 0;
}
