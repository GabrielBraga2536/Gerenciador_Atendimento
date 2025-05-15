#ifndef MENUCADASTRAR_H
#define MENUCADASTRAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "Pilha.h"
#include "ABB.h"

//* Declaração das funções do menu de cadastro

/**
 * @brief Exibe o menu de cadastro no terminal.
 * @return 
 */
void ExibirMenuCadastrar();

/**
 * @brief Cadastra um novo paciente.
 * @param lista - Ponteiro para a lista de pacientes.
 * @param arvore - Ponteiro para a árvore binária de busca.
 * @param arvoreAno - Ponteiro para a árvore binária de busca por ano.
 * @param arvoreMes - Ponteiro para a árvore binária de busca por mês.
 * @param arvoreDia - Ponteiro para a árvore binária de busca por dia.
 * @return 
 */
void CadastrarNovoPaciente(LDE *lista, ABB *arvore, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

/**
 * @brief Busca um paciente na lista.
 * @param lista - Ponteiro para a lista de pacientes.
 * @return Retorna um ponteiro para o paciente encontrado.
 */
void ConsultarPaciente(Paciente *paciente);

/**
 * @brief Exibe todos os pacientes cadastrados na lista.
 * @param lista - Ponteiro para a lista de pacientes.
 * @return 
 */
void ExibirListaCompleta(LDE *lista);

/**
 * @brief Atualiza os dados de um paciente.
 * @param lista - Ponteiro para a lista de pacientes.
 * @param paciente - Ponteiro para o paciente a ser atualizado.
 * @param arvoreIdade - Ponteiro para a árvore binária de busca por idade.
 * @return 
 */
void AtualizarPaciente(LDE *lista, Paciente *paciente, ABB *arvoreIdade);

/**
 * @brief Remove um paciente da lista e das árvores.
 * @param paciente - Ponteiro para o paciente a ser removido.
 * @param lista - Ponteiro para a lista de pacientes.
 * @param arvoreIdade - Ponteiro para a árvore binária de busca por idade.
 * @param arvoreAno - Ponteiro para a árvore binária de busca por ano.
 * @param arvoreMes - Ponteiro para a árvore binária de busca por mês.
 * @param arvoreDia - Ponteiro para a árvore binária de busca por dia.
 * @return 
 */
void RemoverPaciente(Paciente *paciente, LDE *lista, ABB *arvoreIdade,  ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

#endif /* MENUCADASTRAR_H */