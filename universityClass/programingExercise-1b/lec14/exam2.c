#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char fname[] = "cipher.dat";
    int c, m, s_i;
    int s1 = 111, s2 = 99;
    int s_prev1 = s2, s_prev2 = s1;
    int i = 1;

    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("Error!");
        return 1;
    }

    while (fscanf(fp, "%d", &c) != EOF)
    {
        if (i == 1)
        {
            s_i = s1;
        }
        else if (i == 2)
        {
            s_i = s2;
        }
        else
        {
            s_i = (s_prev1 + s_prev2) % 128;
            s_prev2 = s_prev1;
            s_prev1 = s_i;
        }

        m = (c + s_i) % 128;
        printf("%c", m);
        i++;
    }

    fclose(fp);
    return 0;
}