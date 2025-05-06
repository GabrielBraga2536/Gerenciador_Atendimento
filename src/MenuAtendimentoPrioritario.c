#include "MenuAtendimentoPrioritario.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuAtendimentoPrioritario(){
  system("cls");
  
  MenuTitulo("Atendimento Prioritario");
  MenuItem("1. Enfileirar Paciente ");
  MenuItem("2. Desenfileirar Paciente ");
  MenuItem("3. Mostrar Fila");
  MenuLinhaInferior();
}

