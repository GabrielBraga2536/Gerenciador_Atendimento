#ifndef ABB_H
#define ABB_H

#include "Paciente.h"
#include "Debug.h"

typedef struct CelulaABB {
  Paciente *paciente;
  struct CelulaABB *esq;
  struct CelulaABB *dir;
  struct CelulaABB *pai;
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

void InserirABB(ABB* abb, Paciente *paciente, int flag);

void RemoverABB(ABB *abb, Paciente *paciente, int flag);

void ClearABB(CelulaABB *raiz);

void LimparABB(ABB *abb);

int MAX(int x, int y);

int altura(CelulaABB *x);

int fatorBalanceamento(CelulaABB *x);

void RotacaoEsquerda(ABB *arvore, CelulaABB *x);

void RotacaoDireita(ABB *arvore, CelulaABB *x);

void Balanceie(ABB *arvore, CelulaABB *x);

#endif /* ABB_H */