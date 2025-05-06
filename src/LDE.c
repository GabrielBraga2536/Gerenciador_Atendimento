#include "LDE.h"

#include <stdio.h>
#include <stdlib.h>

LDE *CriarLDE(){
  LDE *lista = (LDE*)malloc(sizeof(LDE));
  lista->primeiro = NULL;
  lista->qtde = 0;
  return lista;
}

void InserirLDE(LDE *lista, Paciente *paciente, FILE *arquivo){
  IsMemoryAllocated(lista);
  IsMemoryAllocated(paciente);
  IsFileOpen(arquivo, "pacientes.txt");
  
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
  
  // Salvar informações do paciente no arquivo
  fprintf(arquivo, "Nome: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
    paciente->nome, paciente->idade, paciente->RG, paciente->Entrada->dia, paciente->Entrada->mes, paciente->Entrada->ano
  );
  fclose(arquivo);
}

void RemoverLDE(LDE *lista, Paciente *paciente, FILE *arquivo){
  IsMemoryAllocated(lista);
  IsMemoryAllocated(paciente);
  IsFileOpen(arquivo, "pacientes.txt");
  
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
  
  // Reescrever o arquivo sem o paciente removido
  rewind(arquivo);
  Celula *temp = lista->primeiro;
  freopen("pacientes.txt", "w", arquivo); // Limpar o arquivo
  while(temp != NULL){
    fprintf(arquivo, "Paciente: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
      temp->paciente->nome, temp->paciente->idade, temp->paciente->RG, 
      temp->paciente->Entrada->dia, temp->paciente->Entrada->mes, temp->paciente->Entrada->ano
    );
    temp = temp->prox;
  }
  free(temp);
  fclose(arquivo);
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

Paciente *BuscarPaciente(LDE *lista, char RG[]){
  IsMemoryAllocated(lista);
  
  Celula *atual = lista->primeiro;
  while(atual != NULL){
    if(strcmp(atual->paciente->RG, RG) == 0){
      return atual->paciente;
    }
    atual = atual->prox;
  }
  
  Paciente *pacienteVazio;
  strcpy(pacienteVazio->nome, " ");
  strcpy(pacienteVazio->RG, " ");
  pacienteVazio->idade = 0;
  
  return pacienteVazio;
}