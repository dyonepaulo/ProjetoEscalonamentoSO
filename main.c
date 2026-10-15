#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    int opcao = 67;
    fila *fila = calloc(1, sizeof(fila));

    if (fila == NULL)
    {
        printf("Erro de Alocacao");
        exit(1);
    }

    while (opcao != 0)
    {
        system("clear");
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
               "\nDigite um numero:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            fcfs(fila);
            break;
        case 2:
            sjf(fila);
            break;
        case 3:
            rr(fila);
            break;
        case 4:
            priority(fila);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            if (fila->Inicio_fila = NULL)
            {
                printf("Nao há processos");
                break; 
            }
            
            break;
        }
    }
    return 0;
}