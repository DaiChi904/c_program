#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

int debug = 0; // debug モード時は 1 にする

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

void makeHeap(int array[], int level, int remaingData)
{
    int parentIndex = level;
    int leftChildIndex = 2 * level + 1;
    int rightChildIndex = 2 * level + 2;

    // 左の子ノードと比較
    if (leftChildIndex < remaingData && array[leftChildIndex] > array[parentIndex])
    {
        parentIndex = leftChildIndex;
    }

    // 右の子ノードと比較
    if (rightChildIndex < remaingData && array[rightChildIndex] > array[parentIndex])
    {
        parentIndex = rightChildIndex;
    }

    // 最大値が親でない場合は交換し、再帰的に修正
    if (level != parentIndex)
    {
        int temp = array[level];
        array[level] = array[parentIndex];
        array[parentIndex] = temp;

        makeHeap(array, parentIndex, remaingData);
    }
}

double heapSort(int array[], int dataAmount)
{
    int *sortedArray;
    double startTime = getTime();
    sortedArray = (int *)malloc(dataAmount * sizeof(int));

    // 全ての部分木をヒープ化する
    for (int i = dataAmount / 2 - 1; i >= 0; i--)
    {
        makeHeap(array, i, dataAmount);
    }

    for (int i = dataAmount - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        sortedArray[i] = temp;

        makeHeap(array, 0, i);
    }
    
    for (int i = 0; i < dataAmount; i++)
    {
        array[i] = sortedArray[i];
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

    double timeOfHeapSort = heapSort(data, dataAmount);
    fprintf(stderr, "ヒープソートの実行時間 = %lf[秒]\n", timeOfHeapSort);
    free(data);

    return 0;
}
