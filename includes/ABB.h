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

void InserirABB_Idade(ABB *abb, Paciente *paciente);

void InserirABB_Ano(ABB *abb, Paciente *paciente);

void InserirABB_Mes(ABB *abb, Paciente *paciente);

void InserirABB_Dia(ABB *abb, Paciente *paciente);

void RemoverABB(ABB *abb, Paciente *paciente);

void ClearABB(CelulaABB *raiz);

#endif /* ABB_H */