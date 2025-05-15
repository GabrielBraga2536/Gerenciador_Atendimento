#ifndef MENUATENDIMENTOPRIORITARIO_H
#define MENUATENDIMENTOPRIORITARIO_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Heap.h"

//* Declaração das funções do menu de atendimento prioritário

/**
 * @brief Exibe o menu de atendimento prioritário no terminal.
 * @return 
 */
void ExibirMenuAtendimentoPrioritario();

/**
 * @brief Enfileira um paciente prioritário na fila de atendimento.
 * @param heap - Ponteiro para a fila de atendimento prioritário.
 * @param paciente - Ponteiro para o paciente a ser enfileirado.
 * @return 
 */
void EnfileirarPacientePrioritario(Heap *heap, Paciente *paciente);

/**
 * @brief Desenfileira um paciente prioritário da fila de atendimento.
 * @param heap - Ponteiro para a fila de atendimento prioritário.
 * @return 
 */
void DesenfileirarPacientePrioritario(Heap *heap);

/**
 * @brief Exibe a fila de atendimento prioritário no terminal.
 * @param heap - Ponteiro para a fila de atendimento prioritário.
 * @return 
 */
void ExibirFilaPrioritaria(Heap *heap);


#endif /* MENUATENDIMENTOPRIORITARIO_H */