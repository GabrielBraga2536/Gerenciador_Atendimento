#include "Heap.h"

#include <stdio.h>
#include <stdlib.h>

Heap *CriarHeap() {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  IsMemoryAllocated(heap);
  heap->qtde = 0;
  return heap;
}

//* Funções auxiliares para calcular os índices dos filhos e do pai
int filhoEsquerdo(int index) { return 2 * index + 1; }

int filhoDireito(int index) { return 2 * index + 2; }

int pai(int index) { return (index - 1) / 2; }

int ultimoPai(Heap *heap) { return heap->qtde / 2; }


void peneirar(Heap *heap, int index) {
  int esq = filhoEsquerdo(index);
  int dir = filhoDireito(index);
  int maior = index;
  
  // Verifica se o filho esquerdo ou o direito existem
  if(esq < heap->qtde || dir < heap->qtde) {
    
    // Verifica se o filho esquerdo é maior que o pai
    if (heap->dados[esq].idade > heap->dados[maior].idade) {
      maior = esq;
    }
    
    // Verifica se o filho direito é maior que o pai
    if (heap->dados[dir].idade > heap->dados[maior].idade) {
      maior = dir;
    }
  }
  
  //? Se o maior não for o pai, troca os valores
  if (maior != index) {
    Paciente temp = heap->dados[index];
    heap->dados[index] = heap->dados[maior];
    heap->dados[maior] = temp;
    peneirar(heap, maior);  // Chama a função recursivamente para continuar a peneiração
  }
}

void construirHeap(Heap *heap) {  
  for (int i = ultimoPai(heap); i >= 0; i--) {
    peneirar(heap, i);    // Chama a função de peneiração para cada pai da heap
  }
}

void InserirHeap(Heap *heap, Paciente *paciente) {
  // Verifica se a heap não está cheia
  if (heap->qtde < 100) {
    heap->dados[heap->qtde] = *paciente;  // Adiciona o paciente no final da heap
    heap->qtde++;
    construirHeap(heap);                  // Constrói a heap após a inserção
  } else {
    printf("Heap cheia!\n");              // Se a heap estiver cheia, exibe a mensagem 
  }
}

void RemoverHeap(Heap *heap) {
  // Verifica se a heap não está vazia
  if (heap->qtde > 0) {
    heap->dados[0] = heap->dados[heap->qtde - 1]; // Troca o primeiro elemento com o último
    heap->qtde--;                                 // Remove o último elemento
    peneirar(heap, 0);                            // Peneira a heap para manter a propriedade de max-heap
  } else {
    printf("Heap vazia!\n");
  }
}

void ExibirHeap(Heap *heap) { 
  // Percorre a heap e exibe os pacientes
  for (int i = 0; i < heap->qtde; i++) {
    ExibirPaciente(&heap->dados[i]);
  }
}

void ClearHeap(Heap *heap) {
  if (heap != NULL) {
    free(heap);   // Libera a memória alocada para a heap
  }
}