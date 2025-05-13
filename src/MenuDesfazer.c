#include "MenuDesfazer.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuDesfazer(){
  system("cls");
  
  MenuTitulo("Desfazer");
  MenuItem("1. Log de Acoes");
  MenuItem("2. Desfazer Ultima Acao");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void ExibirLogAcoes(Pilha *pilha){
  IsMemoryAllocated(pilha);
  
  system("cls");
  
  MenuTituloIsolado("Log de Acoes");
  
  if (pilha->qtde == 0){
    printf("Nenhuma acao registrada.\n\n");
    system("pause");
    return;
  }
  
  CelulaPilha *atual = pilha->topo;
  
  while (atual != NULL){
    printf("Paciente: %s | Acao: %s\n", atual->paciente->nome, atual->flag == 0 ? "Adicionado" : "Removido");
    atual = atual->prox;
  }
  
  printf("\n");
  system("pause");
}