#include <stdio.h>
#include <stdlib.h>
#include "mnk/mnk.h"
#include "average/average.h"

typedef struct mnk {
    int     N;
    double* x;
    double* y;
    double  a;
    double  b;
    double  ad;
    double  bd;
} mnk;


mnk* MnkCalc (char* file_name);
void MnkPrint (mnk* MNK);




int main ()
{
    MnkCalc ("data/input.txt");
    CalcAverage ();

    return 0;
}




mnk* MnkCalc (char* file_name)
{
    int N = 0;
    mnk * MNK = calloc (1, sizeof (mnk));

    char* input_name = calloc (100, sizeof(char));
    printf ("Enter the name of file with data for mnk calculation:\n");
    scanf ("%s", input_name);
    FILE* inputfile = fopen (input_name, "r");

    
    fscanf(inputfile, "%d", &N);

    MNK->N = N;
    MNK->x = (double*)calloc(N, sizeof(double));
    MNK->y = (double*)calloc(N, sizeof(double));

    for (int i = 0; i < N; i++)
    {
        fscanf(inputfile, "%lf", MNK->x + i);
    }

    for (int i = 0; i < N; i++)
    {
        fscanf(inputfile, "%lf", MNK->y + i);
    }
    MNK->a  = Get_a   (MNK->x, MNK->y, N);
    MNK->b  = Get_b   (MNK->x, MNK->y, N);
    MNK->ad = Get_ad  (MNK->x, MNK->y, N);
    MNK->bd = Get_bd  (MNK->x, MNK->y, N);
    MnkPrint (MNK);

    free (MNK->x);
    free (MNK->y);
    free (MNK);
}

void MnkPrint (mnk* MNK)
{
    FILE* out = fopen ("data/data_mnk.txt", "w");

    fprintf (out, "%d\n", MNK->N);
    for (int i = 0; i < MNK->N; i++)
        fprintf (out, "%.4g ", MNK->x[i]);
    fprintf (out, "\n");

    for (int i = 0; i < MNK->N; i++)
        fprintf (out, "%.4g ", MNK->y[i]);
    fprintf (out, "\n");

    fprintf (out, "%.4g\n", MNK->a);
    fprintf (out, "%.4g\n", MNK->b);
    fprintf (out, "%.4g\n", MNK->ad);
    fprintf (out, "%.4g\n", MNK->bd);

    fclose (out);

}