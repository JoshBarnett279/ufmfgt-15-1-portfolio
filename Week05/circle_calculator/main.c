#include <stdio.h>

const double PI = 3.14159;

double calculate_circumference(double radius);
double calculate_area(double radius);

int main(void) {
    double radius;
    double circumference;
    double area;

    printf("Enter radius:\n\n");
    scanf("%lf", &radius);

    circumference = calculate_circumference(radius);
    area = calculate_area(radius);

    printf("Circumference = %.2lf\n\n", circumference);
    printf("Area = %.2lf\n\n", area);

    return 0;
}

double calculate_circumference(double radius) {
    return 2 * PI * radius;
}
double calculate_area(double radius) {
    return radius *radius * PI;
}
