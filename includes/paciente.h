#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Debug.h"
#include "BaseViews.h"

//* Declaração das estruturas presentes em uma pilha dinâmica e suas respectivas funções

// Estrutura da data de entrada de um paciente
typedef struct Data{
  int dia;    
  int mes;
  int ano;
}Data;

// Estrutura do paciente
typedef struct{
  char nome[50];          // Nome do paciente
  char RG[10];            // Registro Geral do paciente
  int idade;              // Idade do paciente
  struct Data *Entrada;   // Ponteiro para a data de entrada do paciente
}Paciente;

/**
 * @brief Cria um novo paciente.
 * @param nome - Nome do paciente.
 * @param RG - Registro Geral do paciente.
 * @param idade - Idade do paciente.
 * @return 
 */
Paciente *CriarPaciente(char nome[], char RG[], int idade);

/**
 * @brief Exibe os dados de um paciente no terminal.
 * @param paciente - Ponteiro para o paciente a ser liberado.
 * @return 
 */
void ExibirPaciente(Paciente *paciente);

/**
 * @brief Libera a memória de um paciente.
 * @param paciente - Ponteiro para o paciente a ser liberado.
 * @return 
 */
void ClearPaciente(Paciente *paciente);

/**
 * @brief Valida os dados de um paciente.
 * @param paciente - Ponteiro para o paciente a ser validado.
 * @return Retorna 1 se os dados forem válidos, 0 caso contrário.
 */
int ValidarPaciente(Paciente *paciente);

#endif /* PACIENTE_H */