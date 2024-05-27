#include <stdio.h>
int main () {
    int c1 = 'A', c2 = 'B', c3 = 'C';
    switch (c1) {
        case 'A': c2 = c1; c1 = 'a';
        case 'B': break;
        case 'a': c3 = 'c';
    }
    printf("(c1,c2,c3) = (%c,%c,%c)\n", c1, c2, c3);
    return 0;
}
