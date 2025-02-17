
#include "./comp-p1.h"
#include <string.h>
int main(int argc, char **argv)
{

    int i;
                               
    printf("flag argument: %s\n", argv[1]);

    ofile = stdout;                     
    ofile = fopen(PRINTDESTFILE, "w");
    if (ofile == NULL)
        WARNING(0, (ofile, "Problem creating %s", PRINTDESTFILE));

    errfile = stdout;                     
    errfile = fopen(PRINTERRORFILE, "w");
    if (errfile != NULL)
        WARNING(0, (ofile, "Problem creating %s", PRINTERRORFILE));

                       
    fprintf(ofile, "Arguments:\n");
    for (i = 0; i < argc; i++)
    {
        fprintf(ofile, "%i: %s\n", i, argv[i]);
#if (PRINTWARNING == ON)
        WARNING(i, (errfile, "warning print example %s \n", argv[i]));
#endif
    }

#if (PRINTERROR == ON)
    ERROR(i, (errfile, "This is an error, and it stops"));
#endif

    fclose(ofile);
    fclose(errfile);

    return 0;
}
