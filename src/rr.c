#include <stdio.h>
#include "../library.h"

void rr(processo *processos, int n)
{
    if (processos[1].id == 0) // verfica se tem algum processo na lista
    {
        printf("\n================"
               "\nNao há processos"
               "\n================");
        return;
    }
}