#ifndef LDE_H
#define LDE_H

#include "Paciente.h"
#include "Debug.h"

typedef struct Celula {
  struct Celula *prox;
  struct Celula *ant;
  Paciente *paciente;
} Celula;

typedef struct {
  Celula *primeiro;
  int qtde;
} LDE;

LDE *CriarLDE();

void InserirLDE(LDE *lista, Paciente *paciente, FILE *arquivo);

void RemoverLDE(LDE *lista, Paciente *paciente, FILE *arquivo);

void ExibirLDE(LDE *lista);

void ClearLDE(LDE *lista);

#endif /* LDE_H */