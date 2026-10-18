#ifndef FUNCOES_H
#define FUNCOES_H

// estruturas
typedef struct no no; //estou dizendo que futuramente tera uma estrutura chamado no, ent o compilador sabe que ela existe mesmo antes de eu defini-la possibilitando a linha 18

typedef struct
{
    int id;
    int prioridade;
    int chegada;
    int duracao;
} processo;

struct no
{
    processo processo;
    no *proximo;
};

typedef struct
{
    no *Inicio_fila;
    no *fim_fila; // necessario para insercao de um novo processso
    int tamanho_fila;
} fila;

// funcoes de cada tipo de escalonamento
void priority(processo *processos, int n);
void rr(processo *processos, int n);
void sjf(processo *processos, int n);
void fcfs(processo *processos, int n);

// funcoes auxiliares 
void tabela_execucao(processo *todos_processos, int n);
void listar_processos(int n, processo *todos_processos);
void remover_processo(processo *processos, int *n, int id);

#endif