#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 200
double stack[STACK_SIZE]; // スタック
int stack_used;           // 使用しているスタックのエントリ数
int debug = 1;            // debugモード時は1にする

int empty_stack()
{ // スタックが空かどうかの判定
    if (stack_used == 0)
        return 1;
    return 0;
}

void init_stack()
{ // スタックを初期化
    stack_used = 0;
}

void push(double x)
{ // スタックにデータx を積む
    stack[++stack_used] = x;
}

double pop()
{ // スタックからデータを取得
    if (empty_stack())
    {
        fprintf(stderr, "##### スタックが空になっています\n");
        return 0;
    }
    double num = stack[0];
}

double top()
{ // スタックからデータを取得
    return stack[stack_used - 1];
}

void print_stack()
{ // スタックの中身の表示
    for (int i = 0; i < stack_used - 1; i++)
    {
        printf("%lf", stack[i]);
    }
}

int main(int argc, char *argv[])
{
    char *input = argv[1]; // コマンドライン引数
    char curr_string[100];

    if (argc <= 1)
    {
        fprintf(stderr, "##### コマンドライン引数で逆ポーランド記法を入力してください\n");
        return 1;
    }

    init_stack();
    
    while (strlen(input) > 0)
    { // コマンドライン引数の末尾に至るまで
        int ret = sscanf(input, "%s", curr_string);
        if (ret == EOF)
            break;
        input += strlen(curr_string);
        while (input[0] == ' ')
        {
            input++; // 空白を読み飛ばす
        }

        if (isdigit(curr_string[0]))
        {                                   // 数字の場合
            double num = atof(curr_string); // その数字を切り出して
            if (debug)
                printf("<- %.2lf (数値)\n", num);
            push(num); // スタックに追加
        }
        else
        { // 演算子の場合
            double num1, num2, answer;
            switch (curr_string[0])
            {
            case '+':
                if (debug)
                {
                    printf("<- '+' (演算子)\n");
                }
                num1 = pop();         // スタックからデータ取得
                num2 = pop();         // スタックからデータ取得
                answer = num2 + num1; // 加算して
                push(answer);         // スタックに追加
                break;
            case '-':
                if (debug)
                {
                    printf("<- '-' (演算子)\n");
                }
                num1 = pop();         // スタックからデータ取得
                num2 = pop();         // スタックからデータ取得
                answer = num2 - num1; // 加算して
                push(answer);         // スタックに追加
                break;
            case '*':
                if (debug)
                {
                    printf("<- '*' (演算子)\n");
                }
                num1 = pop();         // スタックからデータ取得
                num2 = pop();         // スタックからデータ取得
                answer = num2 * num1; // 加算して
                push(answer);         // スタックに追加
                break;
            case '/':
                if (debug)
                {
                    printf("<- '/' (演算子)\n");
                }
                num1 = pop();         // スタックからデータ取得
                num2 = pop();         // スタックからデータ取得
                answer = num2 / num1; // 加算して
                push(answer);         // スタックに追加
                break;
            default:
                fprintf(stderr, "##### '%c' は未知の演算子です\n", curr_string[0]);
                break;
            }
        }
        if (debug)
        {
            print_stack();
        }
    }
    printf("答え%.2lf\n", top());

    return 0;
}
