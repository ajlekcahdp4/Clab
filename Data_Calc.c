#include <stdlib.h>
#include "mnk/mnk.h"
#include "average/average.h"



int main ()
{
    system ("chmod +x bash_scripts/*");
    system ("./bash_scripts/mkdir.sh data");
    MnkCalc ();
    //CalcAverage ();

    return 0;
}