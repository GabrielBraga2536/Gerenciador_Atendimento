//* Lógica da aplicação e implementação dos menus
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "MenuViews.h"
#include "BaseViews.h"
#include "Paciente.h"
#include "LDE.h"


int main(){  
  setlocale(LC_ALL, "Portuguese");
  
  FILE *arquivo = fopen("pacientes.txt", "a+");
  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  
  LDE *lista = CriarLDE();
  Paciente *paciente1 = CriarPaciente("Marcos", "12.345.678-9", 30);
  Paciente *paciente2 = CriarPaciente("Wagner", "12.345.678-9", 43);
  
  InserirLDE(lista, paciente1, arquivo);
  InserirLDE(lista, paciente2, arquivo);
  ExibirLDE(lista);
  RemoverLDE(lista, paciente1, arquivo);
  ExibirLDE(lista);
  
  return 0;
}