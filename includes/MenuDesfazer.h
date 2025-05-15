#ifndef MENUDESFAZER_H
#define MENUDESFAZER_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Fila.h"
#include "Pilha.h"

//* Declaração das funções do menu de desfazer ações

/**
 * @brief Exibe o menu de desfazer ações no terminal.
 * @return 
 */
void ExibirMenuDesfazer();

/**
 * @brief Exibe o log de ações no terminal.
 * @param pilha - Ponteiro para a pilha de desfazer ações.
 * @return 
 */
void ExibirLogAcoes(Pilha *pilha);

/**
 * @brief Desfaz a última ação registrada na pilha.
 * @param pilha - Ponteiro para a pilha de desfazer ações.
 * @param fila - Ponteiro para a fila de atendimento.
 * @return 
 */
void DesfazerUltimaAcao(Pilha *pilha, Fila *fila);

#endif /* MENUDESFAZER_H */