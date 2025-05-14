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

void DesfazerUltimaAcao(Pilha *pilha, Fila *fila){
  IsMemoryAllocated(pilha);
  IsMemoryAllocated(fila);
  
  system("cls");
  
  MenuTituloIsolado("Desfazer Ultima Acao");
  
  if (pilha->qtde == 0){
    printf("Nenhuma acao registrada.\n\n");
    system("pause");
    return;
  }
  
  CelulaPilha *celula = Pop(pilha);
  
  if(celula->flag == 0) {
    printf("Paciente %s removido da fila.\n", celula->paciente->nome);
    if(fila->qtde == 1) {
      Desenfileirar(fila);
    }
    else {
      RemoverCelulaFila(fila, celula->paciente);
    }
  } 
  else {
    printf("Paciente %s adicionado novamente a fila.\n", celula->paciente->nome);
    if(fila->qtde == 0) {
      Enfileirar(fila, celula->paciente);
    }
    else {
      ColocarNoComeco(fila, celula->paciente);
    }
  }
  
  system("pause");
}