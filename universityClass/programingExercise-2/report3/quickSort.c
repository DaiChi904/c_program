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

void subSort(int array[], int lower, int upper)
{
    int i = lower;
    int j = upper;
    int base = array[(lower + upper) / 2];

    do
    {
        while (array[i] < base)
        {
            i++;
        }
        while (array[j] > base)
        {
            j--;
        }
        if (i <= j)
        {
            int buffer = array[i];
            array[i] = array[j];
            array[j] = buffer;
            i++;
            j--;
        }
    } while (i <= j);

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

    double timeOfQuickSort = quickSort(data, dataAmount);
    fprintf(stderr, "Quick sort run time = %lf[sec]\n", timeOfQuickSort);

    free(data);

    return 0;
}
