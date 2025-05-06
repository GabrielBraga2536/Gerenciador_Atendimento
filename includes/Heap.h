#ifndef HEAP_H
#define HEAP_H

#include "Paciente.h"
#include "Debug.h"
#include "BaseViews.h"


typedef struct {
  Paciente dados[100];
  int qtde;
} Heap;

Heap *CriarHeap();

int filhoEsquerdo(int index);

int filhoDireito(int index);

int pai(int index);

int ultimoPai(Heap *heap);


void peneirar(Heap *heap, int index);

void construirHeap(Heap *heap);


void InserirHeap(Heap *heap, Paciente *paciente);

void RemoverHeap(Heap *heap);

void ExibirHeap(Heap *heap);

void ClearHeap(Heap *heap);

#endif /* HEAP_H */