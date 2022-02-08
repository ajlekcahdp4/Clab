#include "mnk.h"
#include <math.h>

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
    int a = (N*SumMul(x, y, N) - Sum(x, N)*Sum(y, N))/(N*SumSq(x, N) - (Sum(x, N) * Sum(x, N)));
    return a;
}

double Get_b (double* x, double* y, int N)
{
    int b = (Sum(y, N) - Get_a(x, y, N)*Sum(x, N))/N;
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
    double bd = Get_ad (x, y, N) * (1/N) * sqrt(N*SumSq(x, N) - (Sum (x, N) * Sum (x, N)));
    return bd;
}