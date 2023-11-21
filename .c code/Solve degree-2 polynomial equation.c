#include <stdio.h>
#include <math.h>

void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b - sqrt(discriminant)) / (2 * a);
        double root2 = (-b + sqrt(discriminant)) / (2 * a);
        printf("%.2lf %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("%.2lf\n", root);
    } else {
        printf("NO SOLUTION");
    }
}

int main() {
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    solveQuadratic(a, b, c);

    return 0;
}
