#include <stdio.h>

#define abs(n) ((n) >= 0 ? (n) : -(n)) // 絶対値

//--- 座標を表す構造体 ---//
typedef struct
{
    int x; // X座標
    int y; // Y座標
} Point;

//--- 矩形（長方形）を表す構造体 ---//
typedef struct
{
    Point p1; // 左上限（または右下限）
    Point p2; // 右下限（または左上限）
} Rectangle;

//--- 座標を読み込む ---//
Point scan_point(void)
{
    Point point;

    printf("X座標：");
    scanf("%d", &point.x);
    printf("Y座標：");
    scanf("%d", &point.y);

    return point;
}

//--- 矩形の面積を計算する ---//
int area_of(Rectangle r)
{
    return abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
}

//--- 矩形の全辺の長さの合計を計算する ---//
int circumference_of(const Rectangle r)
{
    return 2 * (abs(r.p1.x - r.p2.x) + abs(r.p1.y - r.p2.y));
}

int main(void)
{
    Rectangle r; // 矩形

    puts("左上限と右下限の座標を入力してください");
    
    puts("短形１");
    puts("座標１");
    r.p1 = scan_point();
    puts("座標２");
    r.p2 = scan_point();

    puts("短形２");

    printf("面積は%dです。\n", area_of(r));
    printf("周囲の長さは%dです。\n", circumference_of(r));

    return 0;
}