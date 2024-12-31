#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

int *gamma; // γ: 一時的なデータ置き場(教科書 p.71 13 行目「余分の記憶容量」のこと)

// 教科書 p.70 alpha[0, 1, ..., n−1], beta[0, 1, ..., m−1] をマージ
int *merge(int *alpha, int n, int *beta, int m)
{
    int gammaInUse = 0;
    int i, j;

    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (alpha[i] <= beta[j])
        {
            gamma[gammaInUse] = alpha[i];
            gammaInUse++;
            i++;
        }
        else
        {
            gamma[gammaInUse] = beta[j];
            gammaInUse++;
            j++;
        }
    }
    if (i < n && j >= m)
    {
        while (i < n)
        {
            gamma[gammaInUse] = alpha[i];
            gammaInUse++;
            i++;
        }
    }
    if (i >= n && j < m)
    {
        while (j < m)
        {
            gamma[gammaInUse] = beta[j];
            gammaInUse++;
            j++;
        }
    }
    // 教科書ではγそのものを return しているが,γは一時的な格納場所なのでαやβに書き戻す
    for (i = 0; i < n; i++)
    {
        alpha[i] = gamma[i];
    }
    for (j = 0; j < m; j++)
    {
        beta[j] = gamma[n + j];
    }
    return alpha;
}

int *mergeSort(int *alpha, int i, int j)
{
    if (i == j)
    {
        return &alpha[i];
    }
    int k = (i + j - 1) / 2;
    return merge(mergeSort(alpha, i, k), k - i + 1, mergeSort(alpha, k + 1, j), j - (k + 1) + 1);
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

    data = (int *)malloc(dataAmount * sizeof(int));
    gamma = (int *)malloc(dataAmount * sizeof(int));
    fp = fopen(datafile, "r");
    for (int i = 0; i < dataAmount; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double startTime = getTime();
    data = mergeSort(data, 0, dataAmount - 1);
    double endTime = getTime();
    fprintf(stderr, "マージソートの実行時間 = %lf[秒]\n", endTime - startTime);

    free(data);
    free(gamma);

    return 0;
}