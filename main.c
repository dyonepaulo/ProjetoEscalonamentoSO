#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    int opcao = 67;
    int n = 0;
    processo *todos_processos = calloc(1, sizeof(processo));
    processo *temp;

    while (opcao != 0)
    {

        printf("\n========ESCOLHA UMA OPCAO========\n"
               "\n1. FCFS (First Come, First Served)"
               "\n2. SJF (Shortest Job First)"
               "\n3. RR (Round Robin)"
               "\n4. Prioridade (Priority)"
               "\n5. Adicionar Processo"
               "\n6. Remover Processo"
               "\n7. Listar Processos"
               "\n0. Sair"
               "\n=================================\n"
               "\nDigite um numero: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            // fcfs();
            break;
        case 2:
            // sjf();
            break;
        case 3:
            // rr();
            break;
        case 4:
            system("clear");
            priority(todos_processos, n);
            break;
        case 5:
            n++;
            if (todos_processos[0].id != 0) // verifica se o primeiro indice do vetor tem processo ou n
            {
                temp = realloc(todos_processos, n * sizeof(processo));
                if (temp == NULL)
                {
                    printf("Erro de Alocacao");
                    exit(1);
                }
                else
                {
                    todos_processos = temp;
                    goto linha_61; // pula pra linha que ira adicionar o processo
                }
            }
            else
            { // preenche no primeiro vetor caso esteja vazio

            linha_61:
                printf("\nDigite a prioridade do processo: ");
                scanf("%d", &todos_processos[n - 1].prioridade);

                printf("\nDigite a duracao do processo: ");
                scanf("%d", &todos_processos[n - 1].duracao);

                printf("\nDigite a chegada do processo: ");
                scanf("%d", &todos_processos[n - 1].chegada);

                todos_processos[n - 1].id++;
                // printf("%d", todos_processos[n - 1].id);
                break;
            case 6:
                break;
            case 7:
                system("clear");
                if (todos_processos[0].id == 0) // verfica se tem algum processo na lista
                {
                    printf("\nNao há processos\n");
                    break;
                }
                printf("+------+-------------+----------+---------+\n");
                printf("| ID   | Prioridade  | Duracao  | Chegada |\n");
                printf("+------+-------------+----------+---------+\n");
                for (int i = 0; i < n; i++)
                {
                    printf("| %-4d | %-11d | %-8d | %-7d |\n",
                           todos_processos[i].id, todos_processos[i].prioridade, todos_processos[i].duracao, todos_processos[i].chegada);
                }
                printf("+------+-------------+----------+---------+\n");

                break;
            }
        }
    }
    return 0;
}