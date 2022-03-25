#include "mnk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "../SLE/SLE.h"


struct lsm_linear {
    int     N;
    double* x;
    double* y;
    double  a;
    double  b;
    double  ad;
    double  bd;
};

struct input {
    int N;
    double *x;
    double *y;
};

struct lsm_pol {
    int N;
    double *x;
    double *y;
    double *a;
};

void PolinomLsmPrint (struct lsm_pol *POL, size_t deg);
//==================================================================================================
//=============================================INPUT================================================
//==================================================================================================

double *InputRow (FILE *file, int N)
{
    double *row = calloc (N, sizeof(double));
    for (int i = 0; i < N; i++)
    {
        fscanf(file, "%lf", row + i);
    }
    return row;
}

struct input *Input ()
{
    struct input * INP = calloc (1, sizeof (struct input));

    char* input_name = calloc (100, sizeof(char));
    printf ("Enter the name of file with data for lsm calculation:\n");
    scanf ("%s", input_name);
    FILE* inputfile = fopen (input_name, "r");
    assert (inputfile);

    
    fscanf(inputfile, "%d", &INP->N);
    INP->x = InputRow (inputfile, INP->N);
    INP->y = InputRow (inputfile, INP->N);

    fclose (inputfile);
    return INP;
}


//==================================================================================================
//===========================================LINEAR=LSM=============================================
//==================================================================================================
double Sum (double* a, int N)
{
    double S = 0;
    for (int i = 0; i < N; i++)
        S += a[i];
    return S;
}

double SumMul (double* a, double* b, int N)
{
    double S = 0;
    for (int i = 0; i < N; i++)
        S += a[i] * b[i];
    return S;
}

double SumSq (double* a, int N)
{
    double S = 0;
    for (int i = 0; i < N; i++)
        S += a[i] * a[i];
    return S;
}

double Get_a (double* x, double* y, int N)
{
    double a = (N*SumMul(x, y, N) - Sum(x, N)*Sum(y, N))/(N*SumSq(x, N) - (Sum(x, N) * Sum(x, N)));
    return a;
}

double Get_b (double* x, double* y, int N)
{
    double b = (Sum(y, N) - Get_a(x, y, N)*Sum(x, N))/N;
    return b;
}
double Get_ad (double*x, double* y, int N)
{
    double a = Get_a (x, y, N);
    double ad = (1/sqrt(N)) * sqrt( N*(SumSq(y, N) - (Sum(y, N)) * Sum(y, N))/(N*(SumSq(x, N) - (Sum(x, N)) * Sum(x, N)) - (a * a)));
    return ad;
}

double Get_bd (double*x, double* y, int N)
{
    double bd = Get_ad (x, y, N) * (1/(double)N) * sqrt(N*SumSq(x, N) - (Sum (x, N) * Sum (x, N)));
    return bd;
}


struct lsm_linear *LinearCalc (struct input *INP)
{
    struct lsm_linear *LSM = calloc (1, sizeof (struct lsm_linear));
    assert (LSM);

    LSM->N = INP->N;
    LSM->x = calloc (LSM->N, sizeof(double));
    LSM->y = calloc (LSM->N, sizeof(double));
    assert (LSM->y);
    assert (LSM->x);

    memcpy (LSM->x, INP->x, LSM->N * sizeof(double));
    memcpy (LSM->y, INP->y, LSM->N * sizeof(double));

    LSM->a  = Get_a   (LSM->x, LSM->y, LSM->N);
    LSM->b  = Get_b   (LSM->x, LSM->y, LSM->N);
    LSM->ad = Get_ad  (LSM->x, LSM->y, LSM->N);
    LSM->bd = Get_bd  (LSM->x, LSM->y, LSM->N);

    return LSM;
}


void LinearLsmCalc ()
{
    struct input *INP = Input();

    struct lsm_linear *LSM = LinearCalc (INP);

    LsmPrint (LSM);

    free (LSM->x);
    free (LSM->y);
    free (LSM);

    free (INP->x);
    free (INP->y);
    free (INP);
}

//==================================================================================================
//==========================================POLINOM=LSM=============================================
//==================================================================================================

struct lsm_pol *PolinomCalc (struct input *INP, size_t deg)
{
    struct lsm_pol *POL = calloc (1, sizeof(struct lsm_pol));
    assert (POL);

    POL->N = INP->N;
    POL->x = calloc (POL->N, sizeof(double));
    POL->y = calloc (POL->N, sizeof(double));
    POL->a = calloc (POL->N, sizeof(double));
    assert (POL->x && POL->y && POL->a);

    memcpy (POL->x, INP->x, POL->N * sizeof(double));
    memcpy (POL->y, INP->y, POL->N * sizeof(double));

    POL->a = SolveSLE (INP, deg);
    
    return POL;
}



void PolinomLsmCalc (int deg)
{
    struct input *INP = Input ();

    struct lsm_pol *POL = PolinomCalc (INP, deg);
    

    PolinomLsmPrint (POL, deg);

    free (INP->x);
    free (INP->y);
    free (INP);
    free (POL->x);
    free (POL->y);
    free (POL->a);
    free (POL);
}





//==================================================================================================
//============================================OUTPUT================================================
//==================================================================================================

void LsmPrint (struct lsm_linear* LSM)
{
    FILE* out = fopen ("data/data_lsm.txt", "w");

    fprintf (out, "%d\n", LSM->N);
    for (int i = 0; i < LSM->N; i++)
        fprintf (out, "%-10.4g ", LSM->x[i]);
    fprintf (out, "\n");

    for (int i = 0; i < LSM->N; i++)
        fprintf (out, "%-10.4g ", LSM->y[i]);
    fprintf (out, "\n");

    fprintf (out, "%.4g\n", LSM->a);
    fprintf (out, "%.4g\n", LSM->b);
    fprintf (out, "%.4g\n", LSM->ad);
    fprintf (out, "%.4g\n", LSM->bd);

    fclose (out);

}

void PolinomLsmPrint (struct lsm_pol *POL, size_t deg)
{
    FILE* out = fopen ("data/data_lsm_pol.txt", "w");

    fprintf (out, "%d\n", POL->N);

    for (int i = 0; i < POL->N; i++)
        fprintf (out, "%-10.4g ", POL->x[i]);
    fprintf (out, "\n");

    for (int i = 0; i < POL->N; i++)
        fprintf (out, "%-10.4g ", POL->y[i]);
    fprintf (out, "\n");

    for (int i = 0; i <= deg; i++)
        fprintf (out, "%.4g ", POL->a[i]);
    fprintf (out, "\n");
    
}