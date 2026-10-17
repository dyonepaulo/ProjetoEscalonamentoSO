#include <stdio.h>
#include "../library.h"

// Feito por Wender
void fcfs(processo *processos, int n)
{
    // verifica se existem processos cadastrados
    if (n == 0)
    {
        printf("\n================"
               "\nNao ha processos"
               "\n================\n");
        return;
    }
}
// mostra os processos cadastrados
printf("\n===== PROCESSOS =====\n");

for (int i = 0; i < n; i++)
{
    printf("Processo: %d | Chegada: %d | Duracao: %d\n",
           processos[i].id,
           processos[i].chegada,
           processos[i].duracao);
}

printf("=====================\n");
