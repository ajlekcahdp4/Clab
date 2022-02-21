#include <stdlib.h>
#include <assert.h>
#include "writetex.h"
#include "../mnk/mnk.h"
void PrintStart (FILE* f, char* lab_num)
{
    fprintf (f, "\\documentclass{article}\n\\usepackage[T2A]{fontenc}\n\\usepackage[utf8]{inputenc}\n\\usepackage[russian]{babel}\n");
    fprintf (f, "\\usepackage{graphicx}\n\\graphicspath{ {./images/} }\n");
    fprintf (f, "\\title{Лабораторная работа № %s}\n", lab_num);
    fprintf (f, "\\author{Александр Романов Б01-107}\n\n");
    fprintf (f, "\\begin{document}\n");
    fprintf (f, "\\maketitle\n");
    fprintf (f, "\\section{Введение}\n");
    fprintf (f, "\\textbf{Цель работы:}\n\n");
    fprintf (f, "\\textbf{Используемое оборудование:}\n\n");
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
    FILE* datafile = fopen ("data/data_mnk.txt", "r");
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
void TabForGraph (FILE * f, double* x, double* y, int N)
{
    fprintf (f, "$$\n");
    fprintf (f, "\\begin{tabular}{|c|");
    for (int i = 0; i < N; i++)
        fprintf(f, "c|");
    fprintf (f, "}\n\\hline\n");

    for (int i = 0; i < N; i++)
        fprintf (f, "&%.4lf", x[i]);
    fprintf(f, "\\\\\\hline\n");

    for (int i = 0; i < N; i++)
        fprintf (f, "&%.1lf", y[i]);
    fprintf(f, "\\\\\\hline\n");

    fprintf (f, "\\end{tabular}\n$$\n\n");
}

void Tabular (FILE *f)
{
    FILE *input = fopen ("data/average_input.txt", "r");
    FILE *average = fopen ("data/average_values.txt", "r");
    int n_rows = 0;
    int N = 0;
    int val = 0;
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
            fscanf (input, "%d", &val);
            fprintf (f, "&%d", val);
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
    fprintf (f, "\\textbf{Краткие выводы:}\n\n");
    fprintf (f, "\\end{document}");
}