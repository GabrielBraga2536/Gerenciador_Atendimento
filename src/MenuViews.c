#include <stdio.h>
#include <stdlib.h>

#include "MenuViews.h"
#include "BaseViews.h"

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