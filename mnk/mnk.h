
struct lsm_linear;

double Sum      (double* a, int N);
double SumMul   (double* a, double* b, int N);
double SumSq    (double* a, int N);
double Get_a    (double* x, double* y, int N);
double Get_b    (double* x, double* y, int N);
double Get_ad   (double*x, double* y, int N);
double Get_bd   (double*x, double* y, int N);
void   LinearLsmCalc  (void);
void PolinomLsmCalc (void);

void   LsmPrint (struct lsm_linear* LSM);