#ifndef ABB_H
#define ABB_H

#include "Paciente.h"
#include "Debug.h"

typedef struct CelulaABB {
  Paciente *paciente;
  struct CelulaABB *esq;
  struct CelulaABB *dir;
} CelulaABB;

typedef struct {
  CelulaABB *raiz;
  int qtde;
} ABB;

CelulaABB *CriarCelulaABB(Paciente *paciente);

ABB *CriarABB();

void emOrdem(CelulaABB *raiz);

void preOrdem(CelulaABB *raiz);

void posOrdem(CelulaABB *raiz);

void InserirABB(ABB *abb, Paciente *paciente);

void RemoverABB(ABB *abb, Paciente *paciente);

void ClearABB(CelulaABB *raiz);

int cmpAno(const void *a, const void *b);

int cmpMes(Paciente *a, Paciente *b);

int cmpDia(Paciente *a, Paciente *b);

void coletarRegistros(CelulaABB *raiz, Paciente *vetor, int i);

#endif /* ABB_H */