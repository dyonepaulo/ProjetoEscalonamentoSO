// feito por erick
#include <stdio.h>
#include "../library.h"

// começo do codigo
void priority(processo *todos_processos, int n)
{
    if (todos_processos[1].id == 0) // verfica se tem algum processo na lista
    {
        printf("\nNao há processos\n");
        return;
    }
    processo temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (todos_processos[i].prioridade < todos_processos[j].prioridade)
            {
                temp = todos_processos[i];
                todos_processos[j] = todos_processos[j];
                todos_processos[i] = temp;
            }
        }
    }

    // já aqui mostra a tabela dos processos depois de organizados.
    printf("+-----------------------------------+\n"
           "| TABELA DE EXECUCAO POR PRIORIDADE |\n"
           "+------+-------------+----------+---------+-------------------+\n");
    printf("| ID   | Prioridade  | Duracao  | Chegada | Ordem de execucao |\n");
    printf("+------+-------------+----------+---------+-------------------+\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %-4d | %-11d | %-8d | %-7d | %-17d |\n",
               todos_processos[i].id, todos_processos[i].prioridade, todos_processos[i].duracao, todos_processos[i].chegada, i+1);
    }
    printf("+------+-------------+----------+---------+-------------------+\n");
}