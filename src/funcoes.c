#include "../library.h"
#include <stdio.h>

void tabela_execucao(processo *todos_processos, int n)
{

    printf("+------+-------------+----------+---------+-------------------+\n");
    printf("| ID   | Prioridade  | Duracao  | Chegada | Ordem de execucao |\n");
    printf("+------+-------------+----------+---------+-------------------+\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %-4d | %-11d | %-8d | %-7d | %-17d |\n",
               todos_processos[i].id, todos_processos[i].prioridade, todos_processos[i].duracao, todos_processos[i].chegada, i + 1);
    }
    printf("+------+-------------+----------+---------+-------------------+\n");
}
void listar_processos(int n, processo *todos_processos)
{
    printf("+------+-------------+----------+---------+\n");
    printf("| ID   | Prioridade  | Duracao  | Chegada |\n");
    printf("+------+-------------+----------+---------+\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %-4d | %-11d | %-8d | %-7d |\n",
               todos_processos[i].id, todos_processos[i].prioridade, todos_processos[i].duracao, todos_processos[i].chegada);
    }
    printf("+------+-------------+----------+---------+\n");
}

void remover_processo(processo *processos, int *n, int id)
{
    int index = -1;
    for (int i = 0; i < *n; i++)
    {
        if (processos[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < *n - 1; i++)
        {
            processos[i] = processos[i + 1];
        }
        (*n)--;
    }
}