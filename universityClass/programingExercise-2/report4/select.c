#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SMALL_N 50 // 小さい整数として50を定義

double gettime()
{
    struct timeval tp;
    double ret;
    gettimeofday(&tp, NULL); // 1970/1/1 0:00 からの経過時刻を取得
    ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
    return ret;
}

int gamm[SMALL_N];

// 教科書 p.70 alpha[0, 1, ..., n−1], beta[0, 1, ..., m−1] をマージ
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
    { // nが小さい整数だった時の処理
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
        fprintf(stderr, "#### ファイルを指定してください\n");
        return 1;
    }
    datafile = argv[1]; // ファイル名の取得

    if (argc <= 2)
    {
        fprintf(stderr, "#### データ数を指定してください\n");
        return 1;
    }
    n = atoi(argv[2]); // データ数の取得

    if (argc <= 3)
    {
        fprintf(stderr, "#### 何番目のデータを選ぶのか指定してください\n");
        return 1;
    }
    k = atoi(argv[3]);

    data = (int *)malloc(n * sizeof(int)); // データ格納場所の確保
    fp = fopen(datafile, "r");             // データファイルを開く
    if (!fp)
    {
        fprintf(stderr, "#### ファイルを開けませんでした\n");
        free(data);
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &data[i]); // データを1つずつ読み込む
    }
    fclose(fp); // データファイルを閉じる

    time_start = gettime();       // 時間計測開始
    answer = selectk(data, n, k); // k番目選択を実行
    time_end = gettime();         // 時間計測終了

    printf("答え = %d\n", answer);
    fprintf(stderr, "k番目選択の実行時間 = %lf[秒]\n", time_end - time_start);

    free(data); // データ格納場所を解放
    return 0;
}
