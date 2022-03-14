#include <stdio.h>
#include <stdlib.h>
#include "writetex/writetex.h"
#include "mnk/mnk.h"

int main ()
{
    struct mnk *MNK = calloc (1, sizeof(struct mnk));

//=================================================================
//===========Here=you=can=combine=your=own=.tex=file:==============
//=================================================================
    FILE *f = Start (MNK);
    
    PrintStart (f);

    TabForGraph(f, MNK);
    IncludePic (f, "tex/graph1.eps");



    LineDev (f);
    PrintEnd (f);

//=================================================================
//===========================Not=there=============================
//=================================================================
    fclose(f);
    return 0;
}