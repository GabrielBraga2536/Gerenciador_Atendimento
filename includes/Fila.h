#ifndef FILA_H
#define FILA_H

#include "Paciente.h"
#include "Debug.h"

typedef struct CelulaFila {
  struct CelulaFila *prox;
  Paciente *paciente;
} CelulaFila;

typedef struct {
  CelulaFila *head;
  CelulaFila *tail;
  int qtde;
} Fila;

Fila *CriarFila();

CelulaFila *CriarCelulaFila(Paciente *paciente);

void Enfileirar(Fila *fila, Paciente *paciente);

Paciente *Desenfileirar(Fila *fila);

void ExibirFila(Fila *fila);

void RemoverCelulaFila(Fila *fila, Paciente *paciente);

void ColocarNoComeco(Fila *fila, Paciente *paciente);

void ClearFila(Fila *fila);

#endif /* FILA_H */