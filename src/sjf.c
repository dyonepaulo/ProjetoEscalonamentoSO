
#include "../library.h"
#include <stdio.h>
#include <stdlib.h>

// feito pelo goat dyone
void sjf(processo *processos, int n)
{
    if (processos[0].id == 0) // verfica se tem algum processo na lista
    {
        printf("\n================"
               "\nNao há processos"
               "\n================");
        return;
    }
    processo *todos_processos = malloc(n * sizeof(*todos_processos));
    for (int i = 0; i < n; i++)
    {
        todos_processos[i] = processos[i];
    }

    processo temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (todos_processos[i].duracao > todos_processos[j].duracao)
            {
                temp = todos_processos[i];
                todos_processos[i] = todos_processos[j];
                todos_processos[j] = temp;
            }
        }
    }

    // já aqui mostra a tabela dos processos depois de organizados.
    printf("+---------------------------------------------+\n"
           "| TABELA DE EXECUCAO SJF (Shortest Job First) |\n");
    tabela_execucao(todos_processos, n);
    free(todos_processos);
    return;
}