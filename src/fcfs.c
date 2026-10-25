#include <stdio.h>
#include <stdlib.h>
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
// cria uma copia dos processos
processo *copia = malloc(n * sizeof(processo));

if (copia == NULL)
{
    printf("Erro ao alocar memoria\n");
    return;
}

// copia os processos para nao alterar o vetor original
for (int i = 0; i < n; i++)
{
    copia[i] = processos[i];
}

// organiza os processos pelo tempo de chegada
processo aux;

for (int i = 0; i < n - 1; i++)
{
    for (int j = i + 1; j < n; j++)
    {
    if (copia[i].chegada > copia[j].chegada ||
    (copia[i].chegada == copia[j].chegada &&
    copia[i].id > copia[j].id))
        {
            aux = copia[i];
            copia[i] = copia[j];
            copia[j] = aux;
        }
    }
}    

// mostra os processos na ordem de chegada

printf("\n===== EXECUCAO FCFS =====\n");

for (int i = 0; i < n; i++)
{
    printf("Processo: %d | Chegada: %d | Duracao: %d\n",
           copia[i].id, copia[i].chegada, copia[i].duracao);
}

printf("========================\n");

free(copia);
}