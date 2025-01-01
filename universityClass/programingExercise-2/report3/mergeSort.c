#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

int *gamma; // Temporal store exectuing merge sort.

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
    char *datafile;
    FILE *fp;
    int dataAmount;
    int *data;

    if (argc <= 1)
    {
        fprintf(stderr, "##### Please specify file.\n");
        return 1;
    }
    datafile = argv[1];

    if (argc <= 2)
    {
        fprintf(stderr, "##### Please specify data amount.\n");
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
    fprintf(stderr, "Merge sort run time = %lf[sec]\n", endTime - startTime);

    free(data);
    free(gamma);

    return 0;
}