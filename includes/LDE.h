#ifndef LDE_H
#define LDE_H

#include "Paciente.h"
#include "Debug.h"

//* Declaração das estruturas presentes em uma lista duplamente encadeada e suas respectivas funções

//* Estrutura da célula da lista
typedef struct Celula {
  struct Celula *prox;    // Ponteiro para a próxima célula
  struct Celula *ant;     // Ponteiro para a célula anterior
  Paciente *paciente;     // Ponteiro para o paciente
} Celula;

//* Estrutura da lista
typedef struct {
  Celula *primeiro;       // Ponteiro para a primeira célula
  int qtde;               // Quantidade de pacientes na lista 
} LDE;

/**
 * @brief Inicializa uma lista duplamente encadeada.
 * @param None
 * @return Retorna um ponteiro para a lista duplamente encadeada.
 */
LDE *CriarLDE();

/**
 * @brief Insere um paciente na lista duplamente encadeada.
 * @param Lista - Ponteiro para a lista duplamente encadeada.
 * @param Paciente - Ponteiro para o paciente a ser inserido.
 * @return 
 */
void InserirLDE(LDE *lista, Paciente *paciente);

/**
 * @brief Remove um paciente da lista duplamente encadeada.
 * @param Lista - Ponteiro para a lista duplamente encadeada.
 * @param Paciente - Ponteiro para o paciente a ser removido.
 * @return 
 */
void RemoverLDE(LDE *lista, Paciente *paciente);

/**
 * @brief Exibe todos os pacientes da lista duplamente encadeada.
 * @param Lista - Ponteiro para a lista duplamente encadeada.
 * @return 
 */
void ExibirLDE(LDE *lista);

/**
 * @brief Remove e libera a memória de todas as células da lista duplamente encadeada.
 * @param Lista - Ponteiro para a lista duplamente encadeada.
 * @return 
 */
void ClearLDE(LDE *lista);

/**
 * @brief Busca um paciente na lista duplamente encadeada.
 * @param Lista - Ponteiro para a lista duplamente encadeada.
 * @return Retorna um ponteiro para o paciente encontrado ou um paciente vazio.
 */
Paciente *BuscarPaciente(LDE *lista);

#endif /* LDE_H */