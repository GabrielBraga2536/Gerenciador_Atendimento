#include "MenuPesquisar.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuPesquisar(){
  system("cls");
  
  MenuTitulo("Pesquisar");
  MenuItem("1. Registros por Ano");
  MenuItem("2. Registros por Mes");
  MenuItem("3. Registros por Dia");
  MenuItem("3. Registros por Idade");
  MenuLinhaInferior();
}

