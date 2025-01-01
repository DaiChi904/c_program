#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/time.h>

double getTime()
{
    struct timeval tp;
    double ret;
    gettimeofday(&tp, NULL);
    ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
    return ret;
}

double bubbleSort(int *a, int n)
{
    double startTime = getTime();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
    
    double endTime = getTime();

    return endTime - startTime;
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
    fp = fopen(datafile, "r");
    for (int i = 0; i < dataAmount; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double timeOfBubble = bubbleSort(data, dataAmount);
    fprintf(stderr, "Bubble sort run time = %lf[sec]\n", timeOfBubble);

    free(data);

    return 0;
}
