#ifndef MENUCADASTRAR_H
#define MENUCADASTRAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "Fila.h"
#include "Heap.h"


void ExibirMenuCadastrar();

void CadastrarNovoPaciente(LDE *lista, FILE *arquivo);

void ConsultarPaciente(LDE *lista, Paciente *paciente);

void ExibirListaCompleta(LDE *lista);

void AtualizarPaciente(LDE *lista, Paciente *paciente);

void RemoverPaciente(Paciente *paciente, LDE *lista, FILE *arquivo);



#endif /* MENUCADASTRAR_H */