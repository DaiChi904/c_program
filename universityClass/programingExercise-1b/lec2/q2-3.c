// イチローの2004年シーズン最多262安打(704打数)のときの打率は?

#include <stdio.h>

int main(void) {
    double tryCnt = 704, hitCnt=262;
    double batAve = hitCnt / tryCnt;
    printf("Batting average is %f", batAve);
    return 0;
}
