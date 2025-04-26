#ifndef PACIENTE_H
#define PACIENTE_H


typedef struct{
  char nome[50];
  char RG[10];
  int idade;
  struct data *Entrada;
}Paciente;

#endif /* PACIENTE_H */