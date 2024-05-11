// 身長と体重を実数で入力し、BMI (体重÷身長^2) を小数点以下2桁で出力

#include <stdio.h>

int main(void) {
    double height, weight;
    printf("Please input your height(cm) and weight(kg) in turn.");
    scanf("%lf %lf", &height, &weight);
    double BMI = weight / (height*height) * 10000;
    printf("Your BMI is %.2f", BMI);
    return 0;
}
