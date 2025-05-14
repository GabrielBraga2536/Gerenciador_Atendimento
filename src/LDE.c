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
  
  // Aloca memória para a nova célula
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
  
  //Percorre a lista e exibe os pacientes
  while(atual != NULL){
    ExibirPaciente(atual->paciente);
    atual = atual->prox;
  }
}

void ClearLDE(LDE *lista){
  IsMemoryAllocated(lista);
  
  Celula *atual = lista->primeiro;

  // Percorre a lista e libera a memória de cada célula
  while(atual != NULL){
    Celula *temp = atual;
    atual = atual->prox;
    ClearPaciente(temp->paciente);
    free(temp);
  }
  
  // Libera a memória da lista
  free(lista);
}

Paciente *BuscarPaciente(LDE *lista){
  IsMemoryAllocated(lista);
  char RG[10];    // RG do paciente a ser buscado
  
  system("cls");
  
  MenuTituloIsolado("Buscar Paciente");
  printf("Digite o RG do paciente: ");
  scanf("%s", RG);
  
  Celula *atual = lista->primeiro;

  // Percorre a lista e busca o paciente pelo RG	
  while(atual != NULL){
    // Compara o RG do paciente atual com o RG buscado
    if(strcmp(atual->paciente->RG, RG) == 0){   //? Se o RG for igual, o método "strcmp" retorna 0
      return atual->paciente;                   //  Retorna o paciente encontrado
    }
    atual = atual->prox;
  }
  
  // Se o paciente não for encontrado, retorna um paciente vazio
  // Um paciente vazio é um paciente com nome, RG e idade vazios, para evitar erros
  Paciente *pacienteVazio = CriarPaciente("", "", 0);
  
  return pacienteVazio;
}