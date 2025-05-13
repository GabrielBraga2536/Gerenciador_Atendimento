#include "MenuSobre.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuSobre(){
  system("cls");
  
  MenuTitulo("Sobre");
  MenuItem("Alunos: ");
  MenuItem("-> Manuella Valles Egrejas");
  MenuItem("-> Gabriel Braga de Souza Otero");
  MenuItem("Ciclo: 7");
  MenuItem("Curso: Engenharia de Robos");
  MenuItem("Disciplina: Estruturas de Dados");
  MenuItem("14/05/2025");
  MenuLinhaInferior();
}
