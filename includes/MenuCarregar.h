#ifndef MENUCARREGAR_H
#define MENUCARREGAR_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "LDE.h"
#include "ABB.h"

void ExibirMenuCarregar();

void CarregarArquivo(LDE *lista, ABB *arvore, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia);

void SalvarArquivo(LDE *lista);

#endif /* MENUCARREGAR_H */