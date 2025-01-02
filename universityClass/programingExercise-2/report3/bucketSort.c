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

double bucketSort(int array[], int bucket[], int dataAmount, int max) {
    double startTime = getTime();
    for (int i = 0; i < dataAmount; i++) {
        if (array[i] < max) {
            bucket[array[i]] = bucket[array[i]] + 1;
        }
    }
    int index = 0;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            array[index] = bucket[i];
            index++;
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
    int *bucket;
    int max;

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
    max = atoi(argv[3]);

    bucket = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max; i++){
        bucket[i] = 0;
    }

    data = (int *)malloc(dataAmount * sizeof(int));
    fp = fopen(datafile, "r");
    for (int i = 0; i < dataAmount; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    double timeOfBucketSort = bucketSort(data, bucket, dataAmount, max);
    fprintf(stderr, "Bucket sort run time = %lf[sec]\n", timeOfBucketSort);

    free(data);

    return 0;
}
