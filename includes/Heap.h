#ifndef HEAP_H
#define HEAP_H

#include "Paciente.h"
#include "Debug.h"
#include "BaseViews.h"

//* Declaração das estruturas presentes em uma heap e suas respectivas funções

// Estrutura da heap
typedef struct {
  Paciente dados[100];
  int qtde;
} Heap;

/**
 * @brief Inicializa uma heap.
 * @param None
 * @return Retorna um ponteiro para a heap.
 */
Heap *CriarHeap();

/**
 * @brief Retorna o índice do filho esquerdo de um nó.
 * @param index - Índice do nó pai.
 * @return Retorna um valor númerico inteiro do índice do filho esquerdo.
 */
int filhoEsquerdo(int index);

/**
 * @brief Retorna o índice do filho direito de um nó.
 * @param index - Índice do nó pai.
 * @return Retorna um valor númerico inteiro do índice do filho direito.
 */
int filhoDireito(int index);

/**
 * @brief Retorna o índice do pai de um nó.
 * @param index - Índice do nó filho.
 * @return Retorna um valor númerico inteiro do índice do pai.
 */
int pai(int index);

/**
 * @brief Retorna o índice do último pai da heap.
 * @param heap - Ponteiro para a heap.
 * @return Retorna um valor númerico inteiro do índice do último pai.
 */
int ultimoPai(Heap *heap);

/**
 * @brief Reorganiza a heap para manter a propriedade de max-heap.
 * @param heap - Ponteiro para a heap.
 * @param index - Índice do nó a ser peneirado.
 * @return 
 */
void peneirar(Heap *heap, int index);

/**
 * @brief Constrói a heap a partir de um vetor.
 * @param heap - Ponteiro para a heap.
 * @return 
 */
void construirHeap(Heap *heap);

/**
 * @brief Insere um paciente na heap.
 * @param heap - Ponteiro para a heap.
 * @param paciente - Ponteiro para o paciente a ser inserido.
 * @return 
 */
void InserirHeap(Heap *heap, Paciente *paciente);

/**
 * @brief Remove o paciente com maior prioridade da heap.
 * @param heap - Ponteiro para a heap.
 * @return Retorna o paciente removido.
 */
void RemoverHeap(Heap *heap);

/**
 * @brief Exibe todos os pacientes da heap.
 * @param heap - Ponteiro para a heap.
 * @return 
 */
void ExibirHeap(Heap *heap);

/**
 * @brief Limpa todos os pacientes da heap.
 * @param heap - Ponteiro para a heap.
 * @return 
 */
void ClearHeap(Heap *heap);

#endif /* HEAP_H */