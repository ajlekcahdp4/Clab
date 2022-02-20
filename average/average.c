#include <stdio.h>
#include <math.h>

void CalcAverage ()
{
    char* input_name = calloc (100, sizeof(char));
    printf ("Enter the name of file for average approximation\n");
    scanf ("%s", input_name);

    FILE* input  = fopen (input_name, "r");
    FILE* output = fopen ("avarage_values.txt", "w");
    
    int n_row = 0;
    fscanf (input, "%d", &n_row);

    int N = 0;
    fscanf(input, "%d", &N);

    int* row = calloc (N, sizeof (double));


    for (int i = 0; i < N; i++)
        fscanf (input, "%ld", row + i);
    double av  = AvarageVal (N, row);
    double dev = Deviation  (N, row, av);
    fprintf (output, "%g ",   av);
    fprintf (output, "%g\n", dev);
}


double AvarageVal (int N, double* row)
{
    double av = 0;
    for (int i = 0; i < N; i++)
        av += row[i];
    av /= N;
    return av;
}

double Deviation (int N, double* row, double av)
{
    double dev        = 0;
    double sum_sq_sub = 0;
    for (int i = 0; i < N; i++)
        sum_sq_sub += (av - row[i]) * (av - row[i]);
    dev = sqrtf ((1/(N - 1)) * sum_sq_sub);
    return dev;
}