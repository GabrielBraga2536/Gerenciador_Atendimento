#ifndef MENUATENDIMENTOPRIORITARIO_H
#define MENUATENDIMENTOPRIORITARIO_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Heap.h"

void ExibirMenuAtendimentoPrioritario();

void EnfileirarPacientePrioritario(Heap *heap, Paciente *paciente);

void DesenfileirarPacientePrioritario(Heap *heap);

void ExibirFilaPrioritaria(Heap *heap);



#endif /* MENUATENDIMENTOPRIORITARIO_H */