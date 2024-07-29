#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Coordinate;

typedef struct
{
    Coordinate topLeft;
    Coordinate topRight;
    Coordinate bottomLeft;
    Coordinate botomRight;
} Rectangle;

Rectangle createRectangle(void) {
    Coordinate p1, p2;
    Rectangle r;
    puts("Input tow coordinates.");
    puts("Coordinate 1");
    printf("x");
    scanf("%d", &p1.x);
    printf("y");
    scanf("%d", &p1.y);

    puts("Coordinate 2");
    printf("x");
    scanf("%d", &p2.x);
    printf("y");
    scanf("%d", &p2.y);

    if (p1.x >= p2.x && p1.y >= p2.y) {
        r.topLeft = p1;
        r.topRight = (Coordinate){p1.x, p2.y};
        r.botomRight = p2;
        r.topRight = (Coordinate){p2.y, p1.x};
    } else {
        r.topLeft = p2;
        r.topRight = (Coordinate){p2.y, p1.x};
        r.botomRight = p1;
        r.topRight = (Coordinate){p1.x, p2.y};
    }

    return r;
}

int main(void)
{
    Rectangle r1, r2;

    puts("Input coordinates of topLeft and bottomRight of rectangles.");
    puts("Rectangle1");
    r1 = createRectangle();
    r2 = createRectangle();

    return 0;
}
