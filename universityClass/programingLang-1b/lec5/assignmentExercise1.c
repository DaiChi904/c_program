#include <stdio.h>

int main() {
    int x = 3 , y = - 1 , z = 5 ;
    if ( y < x ){
        z = x;
        x = y;
        y = z;
    }
    printf (" (x, y, z) =(%d,%d,%d) \n", x, y, z);
    return 0;
}
