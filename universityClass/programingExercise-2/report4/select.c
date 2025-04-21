#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SMALL_N 50

double gettime()
{
    struct timeval tp;
    double ret;
    gettimeofday(&tp, NULL);
    ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
    return ret;
}

int gamm[SMALL_N];

int *merge(int *alpha, int n, int *beta, int m)
{
    int gamm_used = 0;
    int i, j;

    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (alpha[i] <= beta[j])
            gamm[gamm_used++] = alpha[i++];
        else
            gamm[gamm_used++] = beta[j++];
    }
    if (i < n && j >= m)
    {
        while (i < n)
            gamm[gamm_used++] = alpha[i++];
    }
    if (i >= n && j < m)
    {
        while (j < m)
            gamm[gamm_used++] = beta[j++];
    }

    for (i = 0; i < n; i++)
        alpha[i] = gamm[i];
    for (j = 0; j < m; j++)
        beta[j] = gamm[n + j];

    return alpha;
}

int *m_sort(int *a, int i, int j)
{
    int k;
    if (i == j)
        return &a[i];
    k = (i + j - 1) / 2;
    return merge(m_sort(a, i, k), k - i + 1, m_sort(a, k + 1, j), j - (k + 1) + 1);
}

int selectk(int *a, int n, int k)
{
    int i, p, used;
    int u, v;
    int *U, *V;
    int answer;

    if (n < SMALL_N)
    {
        m_sort(a, 0, n - 1);
        return a[k - 1];
    }

    p = a[rand() % n];
    u = 0;
    v = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < p)
            u++;
        if (a[i] <= p)
            v++;
    }

    if (k <= u)
    {
        U = (int *)malloc(u * sizeof(int));
        used = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] < p)
                U[used++] = a[i];
        }
        answer = selectk(U, u, k);
        free(U);
        return answer;
    }
    if (k <= v)
        return p;

    V = (int *)malloc((n - v) * sizeof(int));
    used = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > p)
            V[used++] = a[i];
    }
    answer = selectk(V, n - v, k - v);
    free(V);
    return answer;
}

int main(int argc, char *argv[])
{
    char *datafile; // 入力データのファイル名
    FILE *fp;       // 入力データのファイルポインタ
    int n;          // 入力データのデータ数
    int *data;      // 入力データの格納場所
    int k;          // 何番目に小さい数を選ぶのか
    int i;
    double time_start, time_end;
    int answer;

    if (argc <= 1)
    {
        fprintf(stderr, "#### Please specify file.\n");
        return 1;
    }
    datafile = argv[1];

    if (argc <= 2)
    {
        fprintf(stderr, "##### Please specify data amount.\n");
        return 1;
    }
    n = atoi(argv[2]);

    if (argc <= 3)
    {
        fprintf(stderr, "#### Please specify the value(number) of the data which you want to search.\n");
        return 1;
    }
    k = atoi(argv[3]);

    data = (int *)malloc(n * sizeof(int));
    fp = fopen(datafile, "r");
    if (!fp)
    {
        fprintf(stderr, "#### Failed to open the file.\n");
        free(data);
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    time_start = gettime();
    answer = selectk(data, n, k);
    time_end = gettime();

<<<<<<< HEAD
    printf("Answer = %d\n", answer);
    fprintf(stderr, "Index of searched value = %d, Runtime = %lf[sec]\n", k, time_end - time_start);
=======
    printf("答え = %d\n", answer);
    fprintf(stderr, "k番目選択の実行時間 = %lf[秒]\n", time_end - time_start);
>>>>>>> origin/main

    free(data);
    return 0;
}
