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

processo aux;

// organiza os processos pelo tempo de chegada
for (int i = 0; i < n - 1; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (processos[i].chegada > processos[j].chegada)
        {
            aux = processos[i];
            processos[i] = processos[j];
            processos[j] = aux;
        }
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
}