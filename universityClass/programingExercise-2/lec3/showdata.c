#include <stdio.h>
#include <stdlib.h>

long readData( char *filename, int *data ) {
  long i;
  FILE *fp = fopen( filename, "r" );
  for (i = 0; ; ) {
    int d;
    fscanf( fp, "%d", &d );
    data[i] = d;
  }
  fclose( fp );
  
  return i;
}

void printData( int *data, long data_num ) {
  long i;
  for (i = 0; i < data_num; i++) {
    printf("%6d ", data[i]);
    if ( i % 8 == 7 ) printf("\n");
  }
  printf("\n");
}

int main( int argc, char *argv[] ) {
  long alloc_num = atol( argv[2] );
  int *data = (int *)malloc( alloc_num * sizeof(int));
  long data_num = readData( argv[1], data );
  printData( data, data_num );

  free( data );
  return 0;
}
