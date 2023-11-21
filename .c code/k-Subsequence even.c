#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int sequence[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }

    int cumulativeSum[n + 1];
    cumulativeSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cumulativeSum[i] = cumulativeSum[i - 1] + sequence[i - 1];
    }

    int evenCount = 0;

    for (int i = 0; i <= n - k; i++) {
        int subsequenceSum = cumulativeSum[i + k] - cumulativeSum[i];
        if (subsequenceSum % 2 == 0) {
            evenCount++;
        }
    }

    printf("%d\n", evenCount);

    return 0;
}
