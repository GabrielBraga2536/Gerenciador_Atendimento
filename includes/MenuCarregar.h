#ifndef MENUCARREGAR_H
#define MENUCARREGAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "ABB.h"

//* Declaração das funções do menu de carregar e salvar

/**
 * @brief Exibe o menu de carregar e salvar no terminal.
 * @return 
 */
void ExibirMenuCarregar();

/**
 * @brief Carrega os dados de um arquivo para a lista e árvores.
 * @param lista - Ponteiro para a lista de pacientes.
 * @param arvore - Ponteiro para a árvore binária de busca.
 * @param arvoreAno - Ponteiro para a árvore binária de busca por ano.
 * @param arvoreMes - Ponteiro para a árvore binária de busca por mês.
 * @param arvoreDia - Ponteiro para a árvore binária de busca por dia.
 * @return 
 */
void CarregarArquivo(LDE *lista, ABB *arvore, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

/**
 * @brief Salva os dados da lista em um arquivo.
 * @param lista - Ponteiro para a lista de pacientes.
 * @return 
 */
void SalvarArquivo(LDE *lista);

#endif /* MENUCARREGAR_H */