#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

/**
 * 1970/1/1 0:00 からの経過時刻を double 型で返す関数
 */
double getTime()
{
    struct timeval tp;
    double ret;
    gettimeofday(&tp, NULL); // 1970/1/1 0:00 からの経過時刻を取得
    ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
    return ret;
}

double bubbleSort(int *a, int n)
{
    double startTime = getTime();

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }
    }

    double endTime = getTime();

    return endTime - startTime;
}

int main(int argc, char *argv[])
{
    char *datafile; // 入力データのファイル名
    FILE *fp;       // 入力データのファイルポインタ
    int dataAmount; // 入力データのデータ数
    int *data;      // 入力データ格納場所

    if (argc <= 1)
    {
        fprintf(stderr, "##### ファイルを指定してください\n");
        return 1;
    }
    datafile = argv[1];

    if (argc <= 2)
    {
        fprintf(stderr, "##### データ数を指定してください\n");
        return 1;
    }
    dataAmount = atoi(argv[2]);

    data = (int *)malloc(dataAmount * sizeof(int)); // データ格納場所の確保
    fp = fopen(datafile, "r");
    for (int i = 0; i < dataAmount; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double timeOfBubble = bubbleSort(data, dataAmount);
    fprintf(stderr, "バブルソートの実行時間 = %lf[秒]\n", timeOfBubble);
    free(data);

    return 0;
}
