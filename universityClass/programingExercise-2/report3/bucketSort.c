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

double bucketSort(int array[], int bucket[], int dataAmount, int max) {
    double startTime = getTime();
    for (int i = 0; i < dataAmount; i++) {
        if (array[i] <= max) {
            bucket[array[i]] = bucket[array[i]] + 1;
        }
    }
    for (int i = 0; i < max; i++) {
        array[i] = bucket[i];
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
    int *bucket;
    int max;

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
    max = atoi(argv[3]);

    bucket = (int *)malloc(max * sizeof(int) + 1);
    for (int i = 0; i < max; i++){
        bucket[i] = 0;
    }

    data = (int *)malloc(dataAmount * sizeof(int)); // データ格納場所の確保
    fp = fopen(datafile, "r");
    for (int i = 0; i < dataAmount; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double timeOfBucketSort = bucketSort(data, bucket, dataAmount, max);
    fprintf(stderr, "バケットソートの実行時間 = %lf[秒]\n", timeOfBucketSort);

    free(data);

    return 0;
}
