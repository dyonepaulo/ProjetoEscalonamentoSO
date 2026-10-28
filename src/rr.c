#include <stdio.h>
#include "../library.h"
// feito por mim
void rr(processo *processos, int n)
{
    printf("\nA ordem de execução dos processos será: \n");

    processo *copia_processos = malloc(n * sizeof(*copia_processos));

    for(int i = 0; i < n; i++){
        copia_processos[i] = processos[i];
    }

    int ctrl = 67;
    while(ctrl !=69){ // enquanto houver processos com duracao > 0 continua printando
        ctrl=69;
        for(int i = 0; i < n; i++)
        {
            if(copia_processos[i].duracao > 0){
                printf("Processo %d: ID=%d, Prioridade=%d, Chegada=%d, Duracao=%d\n",
                    i + 1, copia_processos[i].id, copia_processos[i].prioridade, copia_processos[i].chegada, copia_processos[i].duracao);
                copia_processos[i].duracao--;
                ctrl=420;
            }
        }
         printf("\n");
    }
    free(copia_processos);
}