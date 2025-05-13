#ifndef MENUDESFAZER_H
#define MENUDESFAZER_H

#include "Paciente.h"
#include "BaseViews.h"
#include "Debug.h"
#include "Fila.h"
#include "Pilha.h"

void ExibirMenuDesfazer();

void ExibirLogAcoes(Pilha *pilha);

void DesfazerUltimaAcao(Pilha *pilha, Fila *fila);

#endif /* MENUDESFAZER_H */