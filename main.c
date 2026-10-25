#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    int opcao = 67; // variavel utilizada para escolher as opcaoes do switch alem de servir como condicao pro while do menu
    int n = 0;      // guardar o tamanho da lista, necessario para saber ate onde os for devem pecorrer a lista sem acessar memoria n alocada
    int id = 0;     // necessario para preencher id de forma que cada processo tenha um unico
    int remover_id;
    processo *todos_processos = calloc(1, sizeof(processo));
    processo *temp; // utilizado para evitar perda do endereco da lista de processos caso ocorra uma falha
    system("clear");
    if (todos_processos == NULL)
    {
        printf("Erro de Alocacao");
        exit(1);
    }
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
            system("clear");
            fcfs(todos_processos, n);
            break;
        case 2:
            system("clear");
            if (n == 0) // verfica se tem algum processo na lista
            {
                printf("\n================"
                       "\nNao há processos"
                       "\n================");
                break;
            }
            printf("\n+---------------------------------------+"
                   "\n| Lista dos processos sem escalonamento |\n");
            listar_processos(n, todos_processos);
            sjf(todos_processos, n);
            break;

        case 3:
            system("clear");
            if (n == 0) // verfica se tem algum processo na lista
            {
                printf("\n================"
                       "\nNao há processos"
                       "\n================");
                break;
            }
            listar_processos(n, todos_processos);
            rr(todos_processos, n);
            break;
        case 4:
            system("clear");
            if (n == 0) // verfica se tem algum processo na lista
            {
                printf("\n================"
                       "\nNao há processos"
                       "\n================");
                break;
            }
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
                if (temp == NULL) // verifica se o redimencionamento da lista de processos ocorreu sem erros
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
                if (n == 0) // verfica se tem algum processo na lista
                {
                    printf("\n================"
                           "\nNao há processos"
                           "\n================");
                    break;
                }
                listar_processos(n, todos_processos);
                printf("\nDigite o ID do processo que deseja remover!!!\n");
                scanf("%d", &remover_id);
                remover_processo(todos_processos, &n, remover_id);
                break;
            case 7:
                system("clear");
                if (n == 0) // verfica se tem algum processo na lista
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