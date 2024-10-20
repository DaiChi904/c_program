#include <stdio.h>

int main(void) {
  FILE *fp;
  char  fname[256];
  int   ch, n_cnt = 0;

  printf("File name: ");
  scanf("%255s", fname);

  fp = fopen(fname, "r");
  if (fp == NULL) {
    printf("Error!");
    return 1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      n_cnt++;
    }
  }
  
  fclose(fp);
  printf("%d lines\n", n_cnt);

  return 0;
}
