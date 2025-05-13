#include "Fila.h"

#include <stdio.h>
#include <stdlib.h>

Fila *CriarFila(){
  Fila *fila = (Fila*)malloc(sizeof(Fila));
  fila->head = NULL;
  fila->tail = NULL;
  fila->qtde = 0;
  return fila;
}

CelulaFila *CriarCelulaFila(Paciente *paciente){
  CelulaFila *nova = (CelulaFila*)malloc(sizeof(CelulaFila));
  nova->paciente = paciente;
  nova->prox = NULL;
  return nova;
}

void Enfileirar(Fila *fila, Paciente *paciente){
  IsMemoryAllocated(fila);
  IsMemoryAllocated(paciente);
  
  CelulaFila *nova = CriarCelulaFila(paciente);
  
  if(fila->tail == NULL){
    fila->head = nova;
    fila->tail = nova;
  }else{
    fila->tail->prox = nova;
    fila->tail = nova;
  }
  
  fila->qtde++;
}

Paciente *Desenfileirar(Fila *fila){
  IsMemoryAllocated(fila);
  
  if(fila->head == NULL){
    printf("Fila vazia.\n");
    return NULL;
  }
  
  CelulaFila *temp = fila->head;
  fila->head = fila->head->prox;
  
  if(fila->head == NULL){
    fila->tail = NULL;
  }
  
  fila->qtde--;
  
  return temp->paciente;
}

void ExibirFila(Fila *fila){
  IsMemoryAllocated(fila);
  
  if(fila->head == NULL){
    printf("Fila vazia.\n");
    return;
  }
  
  CelulaFila *atual = fila->head;
  while(atual != NULL){
    ExibirPaciente(atual->paciente);
    atual = atual->prox;
  }
}

void ClearFila(Fila *fila){
  IsMemoryAllocated(fila);
  
  CelulaFila *atual = fila->head;
  while(atual != NULL){
    CelulaFila *temp = atual;
    atual = atual->prox;
    free(temp);
  }
  
  free(fila);
}