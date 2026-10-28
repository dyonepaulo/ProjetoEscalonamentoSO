// feito por erick
#include <stdio.h>
#include <stdlib.h>
#include "../library.h"

// começo do codigo
void priority(processo *processos, int n)//aqui eu puxo a funçao void prioridade que tem como parametro um ponteiro do tipo processo, e a variavel n que armazena o numero de processos.
{
    processo *todos_processos = malloc(n * sizeof(*todos_processos));//aqui eu crio o vetor do mesmo tamanho do original, pra pode passar todos os dados pro veotr copia.
    for (int i = 0; i < n; i++)
    {
        todos_processos[i] = processos[i];
    }

    processo temp; //variavel temporario para nao perder os dados durante a troca de posiçoes.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) //esse laço verifica a prioridade e organiza.
        {
            if (todos_processos[i].prioridade > todos_processos[j].prioridade)
            {
                temp = todos_processos[i];
                todos_processos[i] = todos_processos[j];
                todos_processos[j] = temp;
            }
        }
    }

    // já aqui mostra a tabela dos processos depois de organizados.
    printf("+-----------------------------------+\n"
           "| TABELA DE EXECUCAO POR PRIORIDADE |\n");
    tabela_execucao(todos_processos, n); //funçao que printa a tabela.
    free(todos_processos);
    return;
}