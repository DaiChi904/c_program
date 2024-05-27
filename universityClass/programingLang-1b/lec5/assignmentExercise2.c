#include <stdio.h>

int main() {
    char x = 'A';
    char y1 = 'B', y2 = 'C', y3 = 'D';

    if (x == 'B') {
        y1 = x;
    }
    if (y2 == 'C') {
        y2 = 'D';
    }
    if (y1 == 'B') {
        y3 = y2;
    }
    printf("(y1, y2, y3) = (%c, %c, %c)\n", y1, y2, y3);

    if (x == 'A' && y1 == 'B') {
        y1 = 'E';
    }
    if (y2 == 'C') {
        y2 = 'F';
    }
    if (y3 == 'D') {
        y3 = 'G';
    }
    printf("(y1, y2, y3) = (%c, %c, %c)\n", y1, y2, y3);
    
    return 0;
}
