#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "writetex/writetex.h"
#include "mnk/mnk.h"

int main ()
{
    setlocale (LC_ALL, "Rus");

    FILE* fp = fopen ("data.txt", "r");

    int N = 0;
    fscanf (fp, "%d", &N);
   
    double* x = calloc (N, sizeof(double));
    for (int i = 0; i < N ; i++)
        fscanf (fp, "%lf", x + i);

    double* y = calloc (N, sizeof(double));
    for (int i = 0; i < N ; i++)
        fscanf (fp, "%lf", y + i);

    double a = 0;
    fscanf (fp, "%lf", &a);

    double b = 0;
    fscanf (fp, "%lf", &b);

    double ad = 0;
    fscanf (fp, "%lf", &ad);

    double bd = 0;
    fscanf (fp, "%lf", &bd);
    
    
    char* file_name = calloc (10, sizeof(char));
    
    printf("Enter texfile name: ");
    scanf ("%s", file_name);

    FILE* f = fopen (file_name, "w");

    printf("Enter number of lab\n");
    char* lab_name = calloc (10, sizeof(char));
    scanf ("%s", lab_name);
//=================================================================
//Here you can combine your own .tex file:
//=================================================================
    PrintStart (f, lab_name);
    TabForGraph(f, x, y, N);
    IncludePic (f, "graph.png");
    LineDev (f);
    PrintEnd (f);

//=================================================================

    fclose(f);
    fclose (fp);
    free(x);
    free(y);
    free(file_name);


    return 0;
}