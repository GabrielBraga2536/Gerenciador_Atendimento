#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Debug.h"
#include "BaseViews.h"

typedef struct Data{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct{
  char nome[50];
  char RG[10];
  int idade;
  struct Data *Entrada;
}Paciente;

Paciente *CriarPaciente(char nome[], char RG[], int idade);

void ExibirPaciente(Paciente *paciente);

void ClearPaciente(Paciente *paciente);

int ValidarPaciente(Paciente *paciente);

#endif /* PACIENTE_H */