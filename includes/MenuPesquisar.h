#ifndef MENUPESQUISAR_H
#define MENUPESQUISAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "ABB.h"

//* Declaração das funções do menu de pesquisa

/**
 * @brief Exibe o menu de pesquisa no terminal.
 * @return 
 */
void ExibirMenuPesquisar();

/**
 * @brief Exibe os registros de pacientes por ano.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @return 
 */
void ExibirRegistrosAno(ABB *abb);

/**
 * @brief Exibe os registros de pacientes por mês.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @return 
 */
void ExibirRegistrosMes(ABB *abb);

/**
 * @brief Exibe os registros de pacientes por dia.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @return 
 */
void ExibirRegistrosDia(ABB *abb);

/**
 * @brief Exibe os registros de pacientes por idade.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @return 
 */
void ExibirRegistrosIdade(ABB *abb);


#endif /* MENUPESQUISAR_H */