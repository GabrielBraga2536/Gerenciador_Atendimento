#ifndef MENUATENDIMENTO_H
#define MENUATENDIMENTO_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "Fila.h"
#include "Heap.h"

void ExibirMenuAtendimento();

void EnfileirarPaciente(Fila *fila, Paciente *paciente);

void DesenfileirarPaciente(Fila *fila);

void ExibirFilaAtendimento(Fila *fila);

#endif /* MENUATENDIMENTO_H */