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

void TabForGraph (FILE * f, double* x, double* y, int N)
{
    fprintf (f, "$$\n");
    fprintf (f, "\\begin{tabular}{|c|");
    for (int i = 0; i < N; i++)
        fprintf(f, "c|");
    fprintf (f, "}\n\\hline\n");

    fprintf (f, "&&");
    for (int i = 0; i < N; i++)
        fprintf (f, "%.4lf&", x[i]);
    fprintf(f, "\\\\\\hline\n");

    fprintf (f, "&&");
    for (int i = 0; i < N; i++)
        fprintf (f, "%.4lf&", y[i]);
    fprintf(f, "\\\\\\hline\n");

    fprintf (f, "\\hline\n");
    fprintf (f, "\\end{tabular}\n$$\n\n");
}

void PrintEnd (FILE* f)
{
    fprintf (f, "\\textbf{Краткие выводы:}\n\n");
    fprintf (f, "\\end{documment}");
}