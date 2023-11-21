#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void print_solution(double s, int m) {
    printf("%.0lf %d\n", s, m);
}

void find_solutions(int a, int b, int c, int d) {
    double x, x1, x2, x3;
    double discriminant = b * b - 3 * a * c;

    if (discriminant > 0) {
        double k = (9 * a * b * c - 2 * b * b * b- 27 * a * a * d) / (2 * sqrt(pow(fabs(discriminant), 3)));
        if (fabs(k) <= 1) {
            x1 = (2 * sqrt(discriminant) * cos(acos(k) / 3) - b) / (3 * a);
            x2 = (2 * sqrt(discriminant) * cos(acos(k) / 3 - 2 * M_PI / 3) - b) / (3 * a);
            x3 = (2 * sqrt(discriminant) * cos(acos(k) / 3 + 2 * M_PI / 3) - b) / (3 * a);
            if (x2==x3){
                print_solution(x2, 2);
                print_solution(x1, 1);
            } else {
                print_solution(x3, 1);
                print_solution(x2, 1);
                print_solution(x1, 1);
            }
        } else {
            x = ((sqrt(discriminant) * fabs(k)) / (3 * a * k)) * (cbrt(fabs(k) + sqrt(k * k - 1)) + cbrt(fabs(k) - sqrt(k * k - 1))) - b / (3 * a);
            printf("NO SOLUTION");
        }
    } else if (discriminant == 0) {
        if (b * b * b - 27 * a * a * d == 0) {
            x = -b / (3 * a);
            print_solution(x, 3);
        } else {
            x = (-b + cbrt(b * b * b - 27 * a * a * d)) / (3 * a);
            printf("NO SOLUTION");
        }
    } else {
        double k = (9 * a * b * c - 2 * b * b * b- 27 * a * a * d) / (2 * sqrt(pow(fabs(discriminant), 3)));
        x = (sqrt(fabs(discriminant)) / (3 * a)) * (cbrt(k + sqrt(k * k + 1)) + cbrt(k - sqrt(k * k + 1))) - b / (3 * a);
        printf("NO SOLUTION");
    }
}

int main() {
    int b, c, d;
    scanf("%d %d %d", &b, &c, &d);

    find_solutions(1, b, c, d);

    return 0;
}
