#include "MenuAtendimento.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuAtendimento(){
  system("cls");
  
  MenuTitulo("Atendimento");
  MenuItem("1. Enfileirar Paciente");
  MenuItem("2. Desenfileirar Paciente");
  MenuItem("3. Mostrar Fila");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void EnfileirarPaciente(Fila *fila, Paciente *paciente, Pilha *pilha){
  IsMemoryAllocated(fila);
  IsMemoryAllocated(paciente);
  
  system("cls");
  
  MenuTituloIsolado("Enfileirar Paciente");
  
  if (ValidarPaciente(paciente) == 0){
    printf("Paciente invalido.\n\n");
    system("pause");
    return;
  }
  
  Enfileirar(fila, paciente);
  Push(pilha, paciente, 0);
  
  printf("Paciente %s enfileirado com sucesso!\n\n", paciente->nome);
  system("pause");
}

void DesenfileirarPaciente(Fila *fila, Pilha *pilha){
  IsMemoryAllocated(pilha);
  IsMemoryAllocated(fila);
  
  system("cls");
  
  MenuTituloIsolado("Desenfileirar Paciente");
  
  if (fila->qtde == 0){
    printf("Fila vazia.\n\n");
    system("pause");
    return;
  }
  
  Paciente *paciente = Desenfileirar(fila);
  Push(pilha, paciente, 1);
  
  printf("Paciente desenfileirado com sucesso!\n\n");
  system("pause");
}

void ExibirFilaAtendimento(Fila *fila){
  IsMemoryAllocated(fila);
  
  system("cls");
  
  MenuTituloIsolado("Fila de Atendimento");
  
  if(fila->qtde == 0){
    printf("Nenhum paciente na fila.\n\n");
  }else{
    CelulaFila *atual = fila->head;
    while(atual != NULL){
      ExibirPaciente(atual->paciente);
      atual = atual->prox;
    }
  }
  
  system("pause");
}