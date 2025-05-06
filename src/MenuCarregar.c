#include "MenuCarregar.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuCarregar(){
  system("cls");
  
  MenuTitulo("Carregar/Salvar");
  MenuItem("1. Carregar Lista de Pacientes");
  MenuItem("2. Salvar Lista de Pacientes");
  MenuLinhaInferior();
}

