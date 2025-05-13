#ifndef MENUATENDIMENTO_H
#define MENUATENDIMENTO_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Fila.h"
#include "Pilha.h"

void ExibirMenuAtendimento();

void EnfileirarPaciente(Fila *fila, Paciente *paciente, Pilha *pilha);

void DesenfileirarPaciente(Fila *fila, Pilha *pilha);

void ExibirFilaAtendimento(Fila *fila);

#endif /* MENUATENDIMENTO_H */