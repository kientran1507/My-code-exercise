#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sde(double a, double b, double c) {
    double delta = b * b - 4 * a *c ;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("x1 = %lf\n", x1);
        printf("x2 = %lf\n", x2);
    } else if (delta == 0) {
        double x = -b / (2 * a);
        printf("x1 = x2 = %lf\n", x);
    } else if (delta < 0) {
        printf("Phuong trinh vo nghiem\n");
    }
}
int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Su dung: <a> <b> <c>\n");
        return 1;
    }

    double a,b,c;
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

    sde(a,b,c);
    
    return 0;
}