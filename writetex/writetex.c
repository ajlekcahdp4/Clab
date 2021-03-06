#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <assert.h>
#include "writetex.h"
#include "../lsm/lsm.h"
#undef NDEBUG

FILE* Start (struct mnk *MNK)
{
    setlocale (LC_ALL, "Rus");

    FILE* fp = fopen ("data/data_lsm.res", "r");
    assert (fp);

    fscanf (fp, "%d", &MNK->N);
   
    //if (MNK->y == 0)
        MNK->x = calloc (MNK->N, sizeof(double));
    //if (MNK->x == 0)
        MNK->y = calloc (MNK->N, sizeof(double));
        assert (MNK->y);
    
    for (int i = 0; i < MNK->N ; i++)
        fscanf (fp, "%lf", MNK->x + i);
    for (int i = 0; i < MNK->N ; i++)
        fscanf (fp, "%lf", MNK->y + i);

    fscanf (fp, "%lf", &MNK->a);
    fscanf (fp, "%lf", &MNK->b);
    fscanf (fp, "%lf", &MNK->ad);
    fscanf (fp, "%lf", &MNK->bd);
    
    
    char* file_name = calloc (100, sizeof(char));
    
    printf("Enter texfile name: ");
    scanf ("%s", file_name);

    FILE* f = fopen (file_name, "w");

    free(file_name);
    
    return f;
}

void PrintStart (FILE* f)
{

    printf("Enter number of lab\n");
    char* lab_num = calloc (10, sizeof(char));
    scanf ("%s", lab_num);
    
    fprintf (f, "\\documentclass{article}\n\\usepackage[T2A]{fontenc}\n\\usepackage[utf8]{inputenc}\n\\usepackage[russian]{babel}\n");
    fprintf (f, "\\usepackage{graphicx}\n\\graphicspath{ {./images/} }\n");
    fprintf (f, "\\title{Лабораторная работа № %s}\n", lab_num);
    fprintf (f, "\\author{Александр Романов Б01-107}\n\n");
    fprintf (f, "\\begin{document}\n");
    fprintf (f, "\\maketitle\n");
    fprintf (f, "\\section{Введение}\n");
    fprintf (f, "\\textbf{Цель работы:}\\\\\n\n");
    fprintf (f, "\\textbf{Используемое оборудование:}\\\\\n\n");
    fprintf(f, "\n\n\n\\section{Работа:}\n\n");

    free (lab_num);
}
void IncludePic (FILE* f, char* pic)
{
    fprintf(f, "\\begin{center}\n");
    fprintf(f, "    \\includegraphics[width=\\textwidth]{%s}\n", pic);
    fprintf(f, "\\end{center}\n\n");
}

void LineDev (FILE* f)
{
    assert (f);
    FILE* datafile = fopen ("data/data_lsm.res", "r");
    assert(datafile);
    int N = 0;
    fscanf (datafile, "%d", &N);
   
    double* x = calloc (N, sizeof(double));
    for (int i = 0; i < N ; i++)
        fscanf (datafile, "%lf", x + i);

    double* y = calloc (N, sizeof(double));
    for (int i = 0; i < N ; i++)
        fscanf (datafile, "%lf", y + i);

    double a = 0;
    fscanf (datafile, "%lf", &a);

    double b = 0;
    fscanf (datafile, "%lf", &b);

    double ad = 0;
    fscanf (datafile, "%lf", &ad);

    double bd = 0;
    fscanf (datafile, "%lf", &bd);


    fprintf (f, "Полученная линейная (вида $y = ax + b$) зависимость: $y = %.4gx + %.4g$\\\\\n", a, b);
    fprintf (f, "$\\sigma_a = %.4g$ , $\\sigma_b = %.4g$\\\\\n", ad, bd);
    fclose(datafile);
    free (x);
    free(y);
}
void MakeTabular (FILE * texfile, char *filename)
{
    int N = 0;
    int res = 0;
    FILE *inputfile = fopen(filename, "r");
    
    fscanf (inputfile, "%d", &N);
    double *x = calloc (N, sizeof(double));
    double *y = calloc (N, sizeof(double));

    for (int i = 0; i < N; i++)
    {
        res = fscanf (inputfile, "%lf", x + i);
        assert (res);
    }
    for (int i = 0; i < N; i++)
    {
        res = fscanf (inputfile, "%lf", y + i);
        assert (res);
    }


    //-----------------------------------------
    fprintf (texfile, "$$\n");
    fprintf (texfile, "\\begin{tabular}{|c|");
    for (int i = 0; i < N; i++)
        fprintf(texfile, "c|");
    fprintf (texfile, "}\n\\hline\n");

    fprintf(texfile, "\\hline\n\\multicolumn{%d}{|c|}{}\\\\\n\\hline\n", N + 1);

    for (int i = 0; i < N; i++)
        fprintf (texfile, "&%.4lf", x[i]);
    fprintf(texfile, "\\\\\\hline\n");

    for (int i = 0; i < N; i++)
        fprintf (texfile, "&%.4lf", y[i]);
    fprintf(texfile, "\\\\\\hline\n");

    fprintf (texfile, "\\end{tabular}\n$$\n\n");
}

void Tabular (FILE *f)
{
    FILE *input = fopen ("data/average_input.txt", "r"); //WTF
    FILE *average = fopen ("data/average_values.txt", "r"); //WTF
    int n_rows = 0;
    int N = 0;
    double val = 0;
    double av = 0;
    double dev = 0;

    fscanf (input, "%d", &n_rows);
    fscanf (input, "%d", &N);

    fprintf (f, "$$\n\\begin{tabular}{|c|");
    for (int i = 0; i < N + 2; i++)
        fprintf(f, "c|");
    fprintf (f, "}\n\\hline\n");

    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf (input, "%lf", &val);
            fprintf (f, "&%g", val);
        }
        fscanf (average, "%lf", &av);
        fscanf (average, "%lf", &dev);
        fprintf (f, "&%g&%g", av, dev);
        fprintf(f, "\\\\\\hline\n");
    }
    fprintf (f, "\\end{tabular}\n$$\n\n");
}
void PrintEnd (FILE* f)
{
    fprintf (f, "\\section{Краткие выводы:}\n\n");
    fprintf (f, "\\end{document}");
}