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
void priority(fila *inicio_fila);
void rr(fila *inicio_fila);
void sjf(fila *inicio_fila);
void fcfs(fila *inicio_fila);

#endif