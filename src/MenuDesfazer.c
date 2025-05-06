#include "MenuDesfazer.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuDesfazer(){
  system("cls");
  
  MenuTitulo("Desfazer");
  MenuItem("1. Log Fila de Atendimento");
  MenuItem("2. Desfazer Ultima Acao");
  MenuLinhaInferior();
}

