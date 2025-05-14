#include "Pilha.h"

CelulaPilha *CriarCelulaPilha(Paciente *paciente, int flag) {
  CelulaPilha *nova = (CelulaPilha *)malloc(sizeof(CelulaPilha));
  IsMemoryAllocated(nova);
  IsMemoryAllocated(paciente);
  
  nova->paciente = paciente;
  nova->prox = NULL;
  nova->flag = flag;
  
  return nova;
}

Pilha *CriarPilha() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  IsMemoryAllocated(pilha);
  
  pilha->topo = NULL;
  pilha->qtde = 0;
  
  return pilha;
}

void Push(Pilha *pilha, Paciente *paciente, int flag) {
  IsMemoryAllocated(pilha);
  IsMemoryAllocated(paciente);
  
  CelulaPilha *nova = CriarCelulaPilha(paciente, flag);
  IsMemoryAllocated(nova);
  
  nova->prox = pilha->topo;
  pilha->topo = nova;
  pilha->qtde++;
}

CelulaPilha *Pop(Pilha *pilha) {
  IsMemoryAllocated(pilha);
  
  if (pilha->topo == NULL) {
    printf("Pilha vazia.\n");
    return NULL;
  }
  
  CelulaPilha *temp = pilha->topo;
  pilha->topo = pilha->topo->prox;
  pilha->qtde--;
  
  return temp;
}

void ClearPilha(Pilha *pilha) {
  IsMemoryAllocated(pilha);
  
  while (pilha->topo != NULL) {
    Pop(pilha);
  }
  
  free(pilha);
}