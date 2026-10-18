#include <stdio.h>
#include "../library.h"
// feito por mim
void rr(processo *processos, int n)
{
    if (processos[0].id == 0) // verfica se tem algum processo na lista
    {
        printf("\n================"
               "\nNao há processos"
               "\n================");
        return;
    }
    int yoh = 67;
    printf("a ordem de execução dos processos será: \n");
    while(yoh !=69){
        yoh=69;
        for(int i = 0; i < n; i++)
        {
            if(processos[i].duracao > 0){
                printf("Processo %d: ID=%d, Prioridade=%d, Chegada=%d, Duracao=%d\n",
                    i + 1, processos[i].id, processos[i].prioridade, processos[i].chegada, processos[i].duracao);
                processos[i].duracao--;
                yoh=420;
            }
            printf("\n");
        }
    }
}