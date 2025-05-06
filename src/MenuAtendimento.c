#include "MenuAtendimento.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuAtendimento(){
  system("cls");
  
  MenuTitulo("Atendimento");
  MenuItem("1. Enfileirar Paciente");
  MenuItem("2. Desenfileirar Paciente");
  MenuItem("3. Mostrar Fila");
  MenuLinhaInferior();
}

