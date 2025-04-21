#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double gettime()
{
  struct timeval tp;
  double ret;
  gettimeofday(&tp, NULL);
  ret = (double)(tp.tv_sec & 0x00ffffff) + (double)tp.tv_usec / 1000000;
  return ret;
}

void shellB(int arr[], int n)
{
  int k = 1;
  while (k < n)
  {
    k = 3 * k + 1;
  }
  k = k / 3;

  while (k > 0)
  {
    for (int i = k; i < n; i++)
    {
      int x = arr[i];
      int j = i - k;
      while (j >= 0 && x < arr[j])
      {
        arr[j + k] = arr[j];
        j = j - k;
      }
      arr[j + k] = x;
    }

    k = k / 3;
  }
}

int main(int argc, char *argv[])
{
  char *datafile;
  FILE *fp;
  int n;
  int *data;
  double time_start, time_end;

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
  n = atoi(argv[2]);

  data = (int *)malloc(n * sizeof(int));
  fp = fopen(datafile, "r");
  for (int i = 0; i < n; i++)
  {
    fscanf(fp, "%d", &data[i]);
  }
  fclose(fp);

  time_start = gettime();
  shellB(data, n);
  time_end = gettime();

  fprintf(stderr, "Knuth shell sort run time = %lf[sec]\n", time_end - time_start);

  free(data);

  return 0;
}
