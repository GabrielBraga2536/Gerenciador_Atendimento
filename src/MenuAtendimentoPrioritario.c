#include "MenuAtendimentoPrioritario.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuAtendimentoPrioritario(){
  system("cls");
  
  MenuTitulo("Atendimento Prioritario");
  MenuItem("1. Enfileirar Paciente ");
  MenuItem("2. Desenfileirar Paciente ");
  MenuItem("3. Mostrar Fila");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void EnfileirarPacientePrioritario(Heap *heap, Paciente *paciente) {
  IsMemoryAllocated(heap);
  IsMemoryAllocated(paciente);
  
  
  system("cls");
  
  MenuTituloIsolado("Enfileirar Paciente Prioritario");
  
  if (ValidarPaciente(paciente) == 0) {
    printf("Paciente invalido.\n\n");
    system("pause");
    return;
  }
  
  if(heap->qtde == 100) {
    printf("Fila prioritaria cheia.\n");
    return;
  }
  
  InserirHeap(heap, paciente);
  
  printf("Paciente %s enfileirado com sucesso!\n", paciente->nome);
  system("pause");
}

void DesenfileirarPacientePrioritario(Heap *heap) {
  IsMemoryAllocated(heap);
  
  system("cls");
  
  MenuTituloIsolado("Desenfileirar Paciente Prioritario");
  
  if(heap->qtde == 0) {
    printf("Fila prioritaria vazia.\n");
    system("pause");
    return;
  }
  
  printf("Paciente desenfileirado com sucesso!\n");
  RemoverHeap(heap);
  system("pause");
}

void ExibirFilaPrioritaria(Heap *heap) {
  IsMemoryAllocated(heap);
  
  system("cls");
  
  MenuTituloIsolado("Fila Prioritaria");
  
  if(heap->qtde == 0) {
    printf("Fila prioritaria vazia.\n");
    system("pause");
    return;
  }
  
  ExibirHeap(heap);
  system("pause");
}