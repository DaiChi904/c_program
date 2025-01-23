#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SMALL_N 50 // 小さい整数として50を定義

double gettime()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
}

int *merge(int *alpha, int n, int *beta, int m)
{
    int *gamm = (int *)malloc((n + m) * sizeof(int));
    int gamm_used = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (alpha[i] <= beta[j])
            gamm[gamm_used++] = alpha[i++];
        else
            gamm[gamm_used++] = beta[j++];
    }

    while (i < n)
        gamm[gamm_used++] = alpha[i++];
    while (j < m)
        gamm[gamm_used++] = beta[j++];

    for (i = 0; i < n; i++)
        alpha[i] = gamm[i];
    for (j = 0; j < m; j++)
        beta[j] = gamm[n + j];

    free(gamm);
    return alpha;
}

int *m_sort(int *a, int i, int j)
{
    int k;
    if (i == j)
        return &a[i];
    k = (i + j) / 2;
    return merge(m_sort(a, i, k), k - i + 1, m_sort(a, k + 1, j), j - k);
}

int lSelect(int *a, int n, int k)
{
    if (n < SMALL_N)
    {
        m_sort(a, 0, n - 1);
        return a[k - 1];
    }

    int *M = (int *)malloc(n * sizeof(int));
    int *Medians = (int *)malloc((n / 5) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        M[i] = a[i];
    }

    for (int i = 0; i < n / 5; i++)
    {
        int T[5];
        for (int j = 0; j < 5; j++)
        {
            T[j] = a[5 * i + j];
        }
        m_sort(T, 0, 4);
        Medians[i] = T[2];
    }

    int m = lSelect(Medians, n / 5, (n / 5) / 2);
    free(Medians);

    int *S1 = (int *)malloc(n * sizeof(int));
    int *S2 = (int *)malloc(n * sizeof(int));
    int *S3 = (int *)malloc(n * sizeof(int));
    int S1Index = 0, S2Index = 0, S3Index = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < m)
            S1[S1Index++] = a[i];
        else if (a[i] == m)
            S2[S2Index++] = a[i];
        else
            S3[S3Index++] = a[i];
    }

    int result;
    if (S1Index >= k)
        result = lSelect(S1, S1Index, k);
    else if (S1Index + S2Index >= k)
        result = m;
    else
        result = lSelect(S3, S3Index, k - S1Index - S2Index);

    free(S1);
    free(S2);
    free(S3);
    free(M);

    return result;
}

int main(int argc, char *argv[])
{
    if (argc <= 3)
    {
        fprintf(stderr, "#### 使用法: %s <データファイル> <データ数> <k番目>\n", argv[0]);
        return 1;
    }

    char *datafile = argv[1];
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);

    int *data = (int *)malloc(n * sizeof(int));
    FILE *fp = fopen(datafile, "r");
    if (!fp)
    {
        fprintf(stderr, "#### ファイルを開けませんでした\n");
        free(data);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double time_start = gettime();
    int answer = lSelect(data, n, k);
    double time_end = gettime();

    printf("答え = %d\n", answer);
    fprintf(stderr, "k番目選択の実行時間 = %lf[秒]\n", time_end - time_start);

    free(data);
    return 0;
}
