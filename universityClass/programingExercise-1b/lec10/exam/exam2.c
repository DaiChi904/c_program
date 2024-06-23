#include <stdio.h>

void bsort(int a[5]) { 
    for(int i=5; i>0; i--) {
        for(int j=1; j<i; j++) {
            if(a[j-1]>a[j]) {
                int tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
        }
    }
}

int main(void) {
    int h[5]={179, 175, 178, 173, 163};
    bsort(h);  for(int i=0; i<5; i++) printf("%d\n", h[i]);

    return 0; 
}
