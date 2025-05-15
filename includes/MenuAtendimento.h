#ifndef MENUATENDIMENTO_H
#define MENUATENDIMENTO_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Fila.h"
#include "Pilha.h"

//* Declaração das funções do menu de atendimento

/**
 * @brief Exibe o menu de atendimento no terminal.
 * @return 
 */
void ExibirMenuAtendimento();

/**
 * @brief Enfileira um paciente na fila de atendimento.
 * @param fila - Ponteiro para a fila de atendimento.
 * @param paciente - Ponteiro para o paciente a ser enfileirado.
 * @param pilha - Ponteiro para a pilha de desfazer ações.
 * @return 
 */
void EnfileirarPaciente(Fila *fila, Paciente *paciente, Pilha *pilha);

/**
 * @brief Desenfileira um paciente da fila de atendimento.
 * @param fila - Ponteiro para a fila de atendimento.
 * @param pilha - Ponteiro para a pilha de desfazer ações.
 * @return 
 */
void DesenfileirarPaciente(Fila *fila, Pilha *pilha);

/**
 * @brief Exibe a fila de atendimento no terminal.
 * @param fila - Ponteiro para a fila de atendimento.
 * @return 
 */
void ExibirFilaAtendimento(Fila *fila);

#endif /* MENUATENDIMENTO_H */