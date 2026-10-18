#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    int opcao = 67;
    int n = 0;
    int id = 0;
    processo *todos_processos = calloc(1, sizeof(processo));
    processo *temp;
    system("clear");
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
            fcfs (todos_processos, n);
            break;
        case 2:
            system("clear");
            printf("\n+---------------------------------------+"
                   "\n| Lista dos processos sem escalonamento |\n");
            listar_processos(n, todos_processos);
            sjf(todos_processos, n);
            break;

        case 3:
            system("clear");
            listar_processos(n, todos_processos);
            rr(todos_processos, n);
            break;
        case 4:
            system("clear");
            printf("\n+---------------------------------------+"
                   "\n| Lista dos processos sem escalonamento |\n");
            listar_processos(n, todos_processos);
            priority(todos_processos, n);
            break;
        case 5:
            system("clear");
            n++;
            id++;
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

                todos_processos[n - 1].id = id;
                break;
            case 6:
                system("clear");
                break;
            case 7:
                system("clear");
                if (todos_processos[0].id == 0) // verfica se tem algum processo na lista
                {
                    printf("\n================"
                           "\nNao há processos"
                           "\n================");
                    break;
                }
                listar_processos(n, todos_processos);
                break;
            }
        }
    }
    free(todos_processos);
    return 0;
}