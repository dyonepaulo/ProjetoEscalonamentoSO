// feito por erick
#include <stdio.h>
#include "../library.h"

// começo do codigo
void priority(fila *fila)
{
    if (fila->Inicio_fila = NULL)
    {
        printf("Nao há processos");
        return 0;
    }

    int id = 0;
    int n;
    printf("\n Digite o numero de processos: ");
    scanf("%d", &n);
    processo todos_processos[n];
    // aqui estamos adicionando os processos.
    for (int i = 0; i < n; i++)
    {

        printf("\n Digite a prioridade do processo %d:", i);
        scanf("%d", &todos_processos[i].prioridade);

        printf("\n Digite a chegada do processo %d:", i);
        scanf("%d", &todos_processos[i].chegada);

        printf("\n Digite a duracao do processo %d:", i);
        scanf("%d", &todos_processos[i].duracao);
        id++;
        todos_processos[i].id = id;
    }
    // já aqui mostra a tabela dos processos antes de organizados.
    printf("\nprocesso id | chegada |  duracao |  prioridade");
    for (int i = 0; i < n; i++)
    {
        printf("\n     %d    ,     %d    ,     %d    ,     %d    ", todos_processos[i].id, todos_processos[i].chegada, todos_processos[i].duracao, todos_processos[i].prioridade);
    }
}