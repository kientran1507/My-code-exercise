#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Sử dụng: <Giá trị lũy thừa> [<Sai số cho phép>]\n");
        return 1;
    }

    double x = atof(argv[2]);
    double result = exp(x);

    if (argc == 4) {
        double tolerance = atof(argv[3]);
        double term = 1.0;
        double sum = 1.0;
        int n = 1;

        while (fabs(term) >= tolerance) {
            term *= x / n;
            sum += term;
            n++;
        }

        printf("e^%.2f = %.6f (tich luy theo chuoi)\n", x, sum);
    }

    printf("e^%.2f = %.6f\n", x, result);

    return 0;
}
