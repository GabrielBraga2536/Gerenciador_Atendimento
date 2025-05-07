#include "Paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Paciente *CriarPaciente(char nome[], char RG[], int idade) {
  Paciente *paciente = (Paciente *)malloc(sizeof(Paciente));
  IsMemoryAllocated(paciente);
  
  strcpy(paciente->nome, nome);
  strcpy(paciente->RG, RG);
  paciente->idade = idade;
  
  paciente->Entrada = (Data *)malloc(sizeof(Data));
  IsMemoryAllocated(paciente->Entrada);
  
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  paciente->Entrada->dia = tm.tm_mday;
  paciente->Entrada->mes = tm.tm_mon + 1;
  paciente->Entrada->ano = tm.tm_year + 1900;
  
  return paciente;
}

void ExibirPaciente(Paciente *paciente) {
  
  printf("Nome: %s\n", paciente->nome);
  printf("RG: %s\n", paciente->RG);
  printf("Idade: %d\n", paciente->idade);
  printf("Entrada: %02d/%02d/%04d\n", paciente->Entrada->dia, paciente->Entrada->mes, paciente->Entrada->ano);
  printf("\n");
}

void ClearPaciente(Paciente *paciente) {
  if (paciente != NULL) {
    free(paciente->Entrada);
    free(paciente);
  }
}