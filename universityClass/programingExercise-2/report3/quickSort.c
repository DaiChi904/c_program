#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

double getTime()
{
    struct timeval tp;
    double ret;
    gettimeofday(&tp, NULL); // 1970/1/1 0:00 からの経過時刻を取得
    ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
    return ret;
}

void subSort(int array[], int lower, int upper)
{
    int i = lower;
    int j = upper;
    int base = array[(lower + upper) / 2]; // ピボット選択

    do
    {
        while (array[i] < base)
        {
            i++; // 左側から探索
        }
        while (array[j] > base)
        {
            j--; // 右側から探索
        }
        if (i <= j)
        {
            // 要素をスワップ
            int buffer = array[i];
            array[i] = array[j];
            array[j] = buffer;
            i++;
            j--;
        }
    } while (i <= j);

    // 再帰呼び出し
    if (lower < j)
    {
        subSort(array, lower, j);
    }
    if (i < upper)
    {
        subSort(array, i, upper);
    }
}

double quickSort(int array[], int dataAmount)
{
    double startTime = getTime();
    subSort(array, 0, dataAmount - 1);
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

    double timeOfQuickSort = quickSort(data, dataAmount);
    fprintf(stderr, "クイックソートの実行時間 = %lf[秒]\n", timeOfQuickSort);

    free(data);

    return 0;
}
