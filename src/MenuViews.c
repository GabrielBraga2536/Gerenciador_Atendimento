#include <stdio.h>
#include <stdlib.h>

#include "MenuViews.h"
#include "BaseViews.h"

void ExibirMenuAtendimentoPrioritario(){
  system("cls");
  
  MenuTitulo("Atendimento Prioritario");
  MenuItem("1. Enfileirar Paciente ");
  MenuItem("2. Desenfileirar Paciente ");
  MenuItem("3. Mostrar Fila");
  MenuLinhaInferior();
}

void ExibirMenuPesquisar(){
  system("cls");
  
  MenuTitulo("Pesquisar");
  MenuItem("1. Registros por Ano");
  MenuItem("2. Registros por Mes");
  MenuItem("3. Registros por Dia");
  MenuItem("3. Registros por Idade");
  MenuLinhaInferior();
}

void ExibirMenuDesfazer(){
  system("cls");
  
  MenuTitulo("Desfazer");
  MenuItem("1. Log Fila de Atendimento");
  MenuItem("2. Desfazer Ultima Acao");
  MenuLinhaInferior();
}

void ExibirMenuCarregar(){
  system("cls");
  
  MenuTitulo("Carregar/Salvar");
  MenuItem("1. Carregar Lista de Pacientes");
  MenuItem("2. Salvar Lista de Pacientes");
  MenuLinhaInferior();
}

void ExibirMenuSobre(){
  system("cls");
  
  MenuTitulo("Sobre");
  MenuItem("Alunos: ");
  MenuItem("-> Manuella Valles Egrejas");
  MenuItem("-> Gabriel Braga de Souza Otero");
  MenuItem("Ciclo: 7");
  MenuItem("Curso: Engenharia de Robos");
  MenuItem("Disciplina: Estruturas de Dados");
  MenuItem("2023-10-01 - Exemplo");
  MenuLinhaInferior();
}