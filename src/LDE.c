#include "LDE.h"

#include <stdio.h>
#include <stdlib.h>

LDE *CriarLDE(){
  LDE *lista = (LDE*)malloc(sizeof(LDE));
  lista->primeiro = NULL;
  lista->qtde = 0;
  return lista;
}

void InserirLDE(LDE *lista, Paciente *paciente){
  IsMemoryAllocated(lista);
  IsMemoryAllocated(paciente);
  
  // Criar nova célula
  Celula *nova = (Celula*)malloc(sizeof(Celula));
  nova->paciente = paciente;
  nova->prox = NULL;
  nova->ant = NULL;
  
  // Inserir no início da lista
  if(lista->primeiro == NULL){
    lista->primeiro = nova;
  }else{
    nova->prox = lista->primeiro;
    lista->primeiro->ant = nova;
    lista->primeiro = nova;
  }
  
  lista->qtde++;
}

void RemoverLDE(LDE *lista, Paciente *paciente){
  IsMemoryAllocated(lista);
  IsMemoryAllocated(paciente);
  
  Celula *atual = lista->primeiro;
  while(atual != NULL && atual->paciente != paciente){
    atual = atual->prox;
  }
  
  if(atual != NULL){
    if(atual->ant != NULL){
      atual->ant->prox = atual->prox;
    }else{
      lista->primeiro = atual->prox;
    }
    
    if(atual->prox != NULL){
      atual->prox->ant = atual->ant;
    }
    
    free(atual);
    lista->qtde--;
  }
}

void ExibirLDE(LDE *lista){
  IsMemoryAllocated(lista);
  
  Celula *atual = lista->primeiro;
  while(atual != NULL){
    ExibirPaciente(atual->paciente);
    atual = atual->prox;
  }
}

void ClearLDE(LDE *lista){
  IsMemoryAllocated(lista);
  
  Celula *atual = lista->primeiro;
  while(atual != NULL){
    Celula *temp = atual;
    atual = atual->prox;
    ClearPaciente(temp->paciente);
    free(temp);
  }
  
  free(lista);
}

Paciente *BuscarPaciente(LDE *lista){
  IsMemoryAllocated(lista);
  char RG[10];
  
  system("cls");
  
  MenuTituloIsolado("Buscar Paciente");
  printf("Digite o RG do paciente: ");
  scanf("%s", RG);
  
  Celula *atual = lista->primeiro;
  while(atual != NULL){
    if(strcmp(atual->paciente->RG, RG) == 0){
      return atual->paciente;
    }
    atual = atual->prox;
  }
  
  Paciente *pacienteVazio = CriarPaciente("", "", 0);
  
  return pacienteVazio;
}