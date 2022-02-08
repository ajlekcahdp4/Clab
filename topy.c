#include <stdio.h>
#include <stdlib.h>
#include "mnk/mnk.h"

int main ()
{
    int N = 0;
    FILE* inputfile = fopen ("input.txt", "r");
    fscanf(inputfile, "%d", &N);

    double* x = (double*)calloc(N, sizeof(double));
    double* y = (double*)calloc(N, sizeof(double));

    for (int i = 0; i < N; i++)
    {
        fscanf(inputfile, "%lf", x + i);
    }

    for (int i = 0; i < N; i++)
    {
        fscanf(inputfile, "%lf", y + i);
    }

    double a = Get_a (x, y, N);
    double b = Get_b (x, y, N);
    double ad = Get_ad (x, y, N);
    double bd = Get_bd (x, y, N);

    FILE* fp = fopen ("data.txt", "w");
    fprintf (fp, "%d\n", N);
    for (int i = 0; i < N; i++)
        fprintf (fp, "%.4g ", x[i]);
    fprintf (fp, "\n");

    for (int i = 0; i < N; i++)
        fprintf (fp, "%.4g ", y[i]);
    fprintf (fp, "\n");

    fprintf (fp, "%.4g\n", a);
    fprintf (fp, "%.4g\n", b);
    fprintf (fp, "%.4g\n", ad);
    fprintf (fp, "%.4g\n", bd);

    fclose (fp);

    return 0;
}
