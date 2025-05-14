#ifndef MENUCADASTRAR_H
#define MENUCADASTRAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "Pilha.h"
#include "ABB.h"


void ExibirMenuCadastrar();

void CadastrarNovoPaciente(LDE *lista, ABB *arvore, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

void ConsultarPaciente(Paciente *paciente);

void ExibirListaCompleta(LDE *lista);

void AtualizarPaciente(LDE *lista, Paciente *paciente, ABB *arvoreIdade);

void RemoverPaciente(Paciente *paciente, LDE *lista, ABB *arvoreIdade,  ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

#endif /* MENUCADASTRAR_H */