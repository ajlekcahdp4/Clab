struct mnk {
    int     N;
    double* x;
    double* y;
    double  a;
    double  b;
    double  ad;
    double  bd;
};

FILE* Start (struct mnk *MNK);

void PrintStart (FILE* f);
void Tabular (FILE *f);
void IncludePic (FILE* f, char* pic);
void LineDev (FILE* f);
void TabForGraph (FILE * f, struct mnk *MNK);
void PrintEnd (FILE* f);
