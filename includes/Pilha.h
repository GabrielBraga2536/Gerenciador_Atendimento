#ifndef PILHA_H
#define PILHA_H

#include "Paciente.h"
#include "BaseViews.h"

//* Declaração das estruturas presentes em uma pilha dinâmica e suas respectivas funções

//* Estrutura da célula da pilha
typedef struct CelulaPilha {
  struct CelulaPilha *prox;     // Ponteiro para a próxima célula
  int flag;                     // 0 = Paciente foi adicionado, 1 = Paciente foi removido
  Paciente *paciente;           // Ponteiro para o paciente
} CelulaPilha;

//* Estrutura da pilha
typedef struct {
  CelulaPilha *topo;        // Ponteiro para o topo da pilha
  int qtde;                 // Quantidade de pacientes na pilha  
} Pilha;

/**
 * @brief Inicializa uma célula da pilha.
 * @param paciente - Ponteiro para o paciente a ser armazenado na célula.
 * @param flag - Indica se o paciente foi adicionado ou removido.
 * @return Retorna um ponteiro para a célula da pilha.
 */
CelulaPilha *CriarCelulaPilha(Paciente *paciente, int flag);

/**
 * @brief Inicializa uma pilha.
 * @param None
 * @return Retorna um ponteiro para a pilha.
 */
Pilha *CriarPilha();

/**
 * @brief Adiciona um paciente na pilha.
 * @param pilha - Ponteiro para a pilha.
 * @param paciente - Ponteiro para o paciente a ser adicionado.
 * @param flag - Indica se o paciente foi adicionado ou removido.
 * @return 
 */
void Push(Pilha *pilha, Paciente *paciente, int flag);

/**
 * @brief Remove um paciente da pilha.
 * @param pilha - Ponteiro para a pilha.
 * @return Retorna um ponteiro para a célula removida da pilha.
 */
CelulaPilha *Pop(Pilha *pilha);

/**
 * @brief Libera a memória da pilha.
 * @param pilha - Ponteiro para a pilha.
 * @return 
 */
void ClearPilha(Pilha *pilha);

#endif /* PILHA_H */