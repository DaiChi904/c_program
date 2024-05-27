 #include <stdio.h>

int main(void)  {
    int a=1234, b;
    double c=9.8765, d;

    printf("Input integer : ");
    scanf("%d", &b); // bにint型整数を入力
    printf("Input real number : ");
    scanf("%lf", &d); // dにdouble型実数を入力
    if((a >= b)) {
        puts("a≧b");
        b*=a;
        a++;
    } // a≧bなら{ }内の処理を実行

    printf("a'=%d, b'=%d\n", a, b);
    int cnt=0;
    while(c>d) {
        d+=0.03; cnt++;
    }
    printf("cnt=%d\n", cnt);
    return 0;  
}
