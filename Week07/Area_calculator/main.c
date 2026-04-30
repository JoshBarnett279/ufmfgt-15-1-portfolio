#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point upperLeft;
    Point lowerRight;
} Rectangle;

float area(Rectangle r) {

    float width  = r.lowerRight.x - r.upperLeft.x;
    float height = r.upperLeft.y - r.lowerRight.y;

    if (width < 0)  width  = -width;
    if (height < 0) height = -height;

    return width * height;
}

Point centre(Rectangle r) {

    Point c;

    c.x = (r.upperLeft.x + r.lowerRight.x) / 2;
    c.y = (r.upperLeft.y + r.lowerRight.y) / 2;

    return c;
}

void moveRectangle(Rectangle *r, float x, float y) {

    r->upperLeft.x  += x;
    r->upperLeft.y  += y;

    r->lowerRight.x += x;
    r->lowerRight.y += y;
}

int main() {

    Rectangle r;

    r.upperLeft.x = 0;
    r.upperLeft.y = 10;

    r.lowerRight.x = 5;
    r.lowerRight.y = 0;

    printf("Area: %.2f\n", area(r));

    Point c = centre(r);
    printf("Centre: (%.2f, %.2f)\n", c.x, c.y);

    moveRectangle(&r, 2, 3);

    printf("After moving:\n");
    printf("Upper Left: (%.2f, %.2f)\n", r.upperLeft.x, r.upperLeft.y);
    printf("Lower Right: (%.2f, %.2f)\n", r.lowerRight.x, r.lowerRight.y);

    return 0;
}