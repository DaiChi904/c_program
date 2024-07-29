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

//--- 2つの矩形の共有する領域の左上限の座標と右下限の座標を求める ---//
Rectangle shared_area_point(Rectangle r1, Rectangle r2)
{
    Point p1, p2, p_shared;
    int temp1, temp2;
    Rectangle r;

    r.p1.x = abs(r1.p1.x - r2.p1.x);
    r.p1.y = abs(r1.p1.y - r2.p1.y);

    r.p2.x = abs(r1.p2.x - r2.p2.x);
    r.p2.y = abs(r1.p2.y - r2.p2.y);

    r.p1 = p1;
    r.p2 = p2;

    return r;
}

int main(void)
{
    Rectangle r1, r2, r_shared; // 矩形

    puts("左上限と右下限の座標を入力してください");

    puts("短形１");
    puts("座標１");
    r1.p1 = scan_point();
    puts("座標２");
    r1.p2 = scan_point();
    puts("短形２");
    puts("座標１");
    r2.p1 = scan_point();
    puts("座標２");
    r2.p2 = scan_point();

    r_shared = shared_area_point(r1, r2);
    printf("面積は%dです。\n", area_of(r_shared));

    return 0;
}
