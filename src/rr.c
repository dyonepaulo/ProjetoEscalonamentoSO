#include <stdio.h>
#include "../library.h"
// feito por mim
void rr(processo *processos, int n)
{
    printf("\nA ordem de execução dos processos será: \n");

    int yoh = 67;    //optei por printar enquanto tiver duração, já q rr o processo é executado e se n terminar vai pro final da fila
    while(yoh !=69){ // enquanto houver processos com duracao > 0 continua printando
        yoh=69;      //no final fica tipo um histórico de execução
        for(int i = 0; i < n; i++)
        {
            if(processos[i].duracao > 0){
                printf("Processo %d: ID=%d, Prioridade=%d, Chegada=%d, Duracao=%d\n",
                    i + 1, processos[i].id, processos[i].prioridade, processos[i].chegada, processos[i].duracao);
                processos[i].duracao--;
                yoh=420;
            }
        }
         printf("\n");
    }
}