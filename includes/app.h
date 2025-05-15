#ifndef APP_H
#define APP_H

#include "BaseViews.h"
#include "Paciente.h"
#include "LDE.h"
#include "Fila.h"
#include "Heap.h"
#include "Pilha.h"
#include "ABB.h"

#include "Debug.h"

#include "MenuCadastrar.h"
#include "MenuAtendimento.h"
#include "MenuAtendimentoPrioritario.h"
#include "MenuPesquisar.h"
#include "MenuDesfazer.h"
#include "MenuCarregar.h"
#include "MenuSobre.h"


/**
 * @brief Função principal do aplicativo.
 * @return 0 se o aplicativo for encerrado com sucesso.
 */
int app();

#endif /* APP_H */