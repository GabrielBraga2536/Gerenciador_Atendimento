#ifndef PILHA_H
#define PILHA_H

#include "Paciente.h"
#include "BaseViews.h"

typedef struct CelulaPilha {
  struct CelulaPilha *prox;
  int flag; // 0 = foi adicionado, 1 = foi removido
  Paciente *paciente;
} CelulaPilha;

typedef struct {
  CelulaPilha *topo;
  int qtde;
} Pilha;

CelulaPilha *CriarCelulaPilha(Paciente *paciente, int flag);

Pilha *CriarPilha();

void Push(Pilha *pilha, Paciente *paciente, int flag);

void Pop(Pilha *pilha);

void ClearPilha(Pilha *pilha);

#endif /* PILHA_H */