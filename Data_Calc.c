#include <stdlib.h>
#include "mnk/mnk.h"
#include "average/average.h"



int main ()
{
    system ("./bash_scripts/mkdir.sh data");
    MnkCalc ();
    //CalcAverage ();

    return 0;
}