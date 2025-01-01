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

void makeHeap(int array[], int level, int remaingData)
{
    int parentIndex = level;
    int leftChildIndex = 2 * level + 1;
    int rightChildIndex = 2 * level + 2;

    // Compare with child node on the left.
    if (leftChildIndex < remaingData && array[leftChildIndex] > array[parentIndex])
    {
        parentIndex = leftChildIndex;
    }

    // Compare with child node on the right.
    if (rightChildIndex < remaingData && array[rightChildIndex] > array[parentIndex])
    {
        parentIndex = rightChildIndex;
    }

    // If the maximum value is not the parent, it is exchanged and modified recursively.
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

    // Heap all subtrees.
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

    double timeOfHeapSort = heapSort(data, dataAmount);
    fprintf(stderr, "Heap sort run time = %lf[sec]\n", timeOfHeapSort);
    free(data);

    return 0;
}
