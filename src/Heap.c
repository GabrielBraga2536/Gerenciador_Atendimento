#include "Heap.h"

#include <stdio.h>
#include <stdlib.h>



Heap *CriarHeap() {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  IsMemoryAllocated(heap);
  heap->qtde = 0;
  return heap;
}

int filhoEsquerdo(int index) { return 2 * index + 1; }

int filhoDireito(int index) { return 2 * index + 2; }

int pai(int index) { return (index - 1) / 2; }

int ultimoPai(Heap *heap) { return heap->qtde / 2; }


void peneirar(Heap *heap, int index) {
  int esq = filhoEsquerdo(index);
  int dir = filhoDireito(index);
  int maior = index;
  
  
  if(esq < heap->qtde || dir < heap->qtde) {
    
    if (heap->dados[esq].idade > heap->dados[maior].idade) {
      maior = esq;
    }
    
    if (heap->dados[dir].idade > heap->dados[maior].idade) {
      maior = dir;
    }
  }
  
  if (maior != index) {
    Paciente temp = heap->dados[index];
    heap->dados[index] = heap->dados[maior];
    heap->dados[maior] = temp;
    peneirar(heap, maior);
  }
}

void construirHeap(Heap *heap) {
  for (int i = ultimoPai(heap); i >= 0; i--) {
    peneirar(heap, i);
  }
}

void InserirHeap(Heap *heap, Paciente *paciente) {
  if (heap->qtde < 100) {
    heap->dados[heap->qtde] = *paciente;
    heap->qtde++;
    construirHeap(heap);
  } else {
    printf("Heap cheia!\n");
  }
}

void RemoverHeap(Heap *heap) {
  if (heap->qtde > 0) {
    heap->dados[0] = heap->dados[heap->qtde - 1];
    heap->qtde--;
    peneirar(heap, 0);
  } else {
    printf("Heap vazia!\n");
  }
}

void ExibirHeap(Heap *heap) { 
  
  for (int i = 0; i < heap->qtde; i++) {
    ExibirPaciente(&heap->dados[i]);
  }
}

void ClearHeap(Heap *heap) {
  if (heap != NULL) {
    free(heap);
  }
}