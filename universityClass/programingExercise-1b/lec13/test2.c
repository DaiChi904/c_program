#include <stdio.h>

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate topLeft;
    Coordinate topRight;
    Coordinate bottomLeft;
    Coordinate bottomRight;
} Rectangle;

Rectangle createRectangle(void) {
    Coordinate p1, p2;
    Rectangle r;
    puts("Input two coordinates.");
    puts("Coordinate 1");
    printf("x: ");
    scanf("%d", &p1.x);
    printf("y: ");
    scanf("%d", &p1.y);

    puts("Coordinate 2");
    printf("x: ");
    scanf("%d", &p2.x);
    printf("y: ");
    scanf("%d", &p2.y);

    if (p1.x <= p2.x && p1.y >= p2.y) {
        r.topLeft = p1;
        r.topRight = (Coordinate){p2.x, p1.y};
        r.bottomRight = p2;
        r.bottomLeft = (Coordinate){p1.x, p2.y};
    } else if (p1.x >= p2.x && p1.y <= p2.y) {
        r.topLeft = (Coordinate){p2.x, p1.y};
        r.topRight = p1;
        r.bottomRight = (Coordinate){p1.x, p2.y};
        r.bottomLeft = p2;
    } else if (p1.x <= p2.x && p1.y <= p2.y) {
        r.topLeft = (Coordinate){p1.x, p2.y};
        r.topRight = p2;
        r.bottomRight = (Coordinate){p2.x, p1.y};
        r.bottomLeft = p1;
    } else {
        r.topLeft = p2;
        r.topRight = (Coordinate){p1.x, p2.y};
        r.bottomRight = p1;
        r.bottomLeft = (Coordinate){p2.x, p1.y};
    }

    return r;
}

void printRectangle(Rectangle r) {
    printf("Top Left: (%d, %d)\n", r.topLeft.x, r.topLeft.y);
    printf("Top Right: (%d, %d)\n", r.topRight.x, r.topRight.y);
    printf("Bottom Left: (%d, %d)\n", r.bottomLeft.x, r.bottomLeft.y);
    printf("Bottom Right: (%d, %d)\n", r.bottomRight.x, r.bottomRight.y);
}

int main(void) {
    Rectangle r1, r2;

    puts("Input coordinates of two rectangles.");
    puts("Rectangle 1");
    r1 = createRectangle();
    puts("Rectangle 2");
    r2 = createRectangle();

    puts("Rectangle 1:");
    printRectangle(r1);

    puts("Rectangle 2:");
    printRectangle(r2);

    return 0;
}
