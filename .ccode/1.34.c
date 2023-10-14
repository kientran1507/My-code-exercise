#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point_t;

typedef struct circle {
    point_t center;
    double radius;
} circle_t;

int is_in_circle(point_t p, circle_t c) {
    double distance = sqrt((p.x - c.center.x) * (p.x - c.center.x) + (p.y - c.center.y) * (p.y - c.center.y));
    
    if (distance <= c.radius) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    circle_t c;
    point_t p;
    printf("Enter point coordinates\n");
    scanf("%lf%lf", &p.x, &p.y);
    printf("Enter circle center coordinates\n");
    scanf("%lf%lf", &c.center.x, &c.center.y);
    printf("Enter circle's radius\n");
    scanf("%lf", &c.radius);

    printf("Point p is%s inside the circle.\n", is_in_circle(p, c) ? "" : " not");
    return 0;
}
