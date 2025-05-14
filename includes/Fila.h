#ifndef FILA_H
#define FILA_H

#include "Paciente.h"
#include "Debug.h"

//* Definição da fila dinâmica e suas respectivas funções

// Estrutura da célula da fila
typedef struct CelulaFila {
  struct CelulaFila *prox;    // Ponteiro para a próxima célula
  Paciente *paciente;         // Ponteiro para o paciente
} CelulaFila;

// Estrutura da fila
typedef struct {
  CelulaFila *head;           // Ponteiro para o início da fila
  CelulaFila *tail;           // Ponteiro para o fim da fila
  int qtde;                   // Quantidade de pacientes na fila
} Fila;


/**
 * @brief Inicializa uma fila dinâmica.
 * @param None
 * @return Retorna um ponteiro para a fila.
 */
Fila *CriarFila();

/**
 * @brief Inicializa uma célula da fila.
 * @param Paciente - Ponteiro para o paciente associado a célula.
 * @return Retorna um ponteiro para a célula.
 */
CelulaFila *CriarCelulaFila(Paciente *paciente);

/**
 * @brief Enfileirar um paciente.
 * @param Fila - Ponteiro para a fila.
 * @param Paciente - Ponteiro para o paciente a ser adicionado.
 * @return 
 */
void Enfileirar(Fila *fila, Paciente *paciente);

/**
 * @brief Desenfileirar um paciente.
 * @param Fila - Ponteiro para a fila.
 * @return Retorna o paciente desenfileirado. (Utilizado em conjunto com a pilha do desfazer)
 */
Paciente *Desenfileirar(Fila *fila);

/**
 * @brief Exibe todos os pacientes da fila.
 * @param Fila - Ponteiro para a fila.
 * @return 
 */
void ExibirFila(Fila *fila);

/**
 * @brief Remove um paciente de uma posição específica na fila.
 * @param Fila - Ponteiro para a fila.
 * @param Paciente - Ponteiro para o paciente a ser removido.
 * @return 
 */
void RemoverCelulaFila(Fila *fila, Paciente *paciente);

/**
 * @brief Coloca um paciente no início da fila, independentemente da ordem da fila.
 * @param Fila - Ponteiro para a fila.
 * @param Paciente - Ponteiro para o paciente a ser colocado.
 * @return 
 */
void ColocarNoComeco(Fila *fila, Paciente *paciente);

/**
 * @brief Limpa todos os pacientes da fila.
 * @param Fila - Ponteiro para a fila.
 * @return 
 */
void ClearFila(Fila *fila);

#endif /* FILA_H */