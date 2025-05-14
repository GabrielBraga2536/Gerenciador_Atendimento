#include "MenuCarregar.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuCarregar(){
  system("cls");
  
  MenuTitulo("Carregar/Salvar");
  MenuItem("1. Carregar Lista de Pacientes");
  MenuItem("2. Salvar Lista de Pacientes");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void CarregarArquivo(LDE *lista, ABB *arvoreIdade, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia) {
  FILE *arquivo = fopen("src/pacientes.txt", "r");
  IsFileOpen(arquivo, "pacientes.txt");
  
  system("cls");
  MenuTituloIsolado("Carregar Lista de Pacientes");
  
  char nome[50], RG[10];
  int idade, dia, mes, ano;
  
  while (fscanf(arquivo, "Nome: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
    nome, &idade, RG, &dia, &mes, &ano) != EOF) {
    
    Paciente *novoPaciente = CriarPaciente(nome, RG, idade);
    novoPaciente->Entrada->dia = dia;
    novoPaciente->Entrada->mes = mes;
    novoPaciente->Entrada->ano = ano;
    
    InserirLDE(lista, novoPaciente);
    InserirABB(arvoreAno, novoPaciente, 1);
    InserirABB(arvoreMes, novoPaciente, 2);
    InserirABB(arvoreDia, novoPaciente, 3);
    InserirABB(arvoreIdade, novoPaciente, 4);
  }
  
  fclose(arquivo);
  
  printf("\nLista de pacientes carregada com sucesso!\n\n");
  system("pause");
}

void SalvarArquivo(LDE *lista) {
  FILE *arquivo = fopen("src/pacientesSalvos.txt", "w+");
  IsFileOpen(arquivo, "pacientesSalvos.txt");
  
  system("cls");
  MenuTituloIsolado("Salvar Lista de Pacientes");
  
  Celula *atual = lista->primeiro;
  while (atual != NULL) {
    fprintf(arquivo, "Nome: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
      atual->paciente->nome, atual->paciente->idade, atual->paciente->RG, 
      atual->paciente->Entrada->dia, atual->paciente->Entrada->mes, atual->paciente->Entrada->ano
    );
    atual = atual->prox;
  }
  
  fclose(arquivo);
  
  printf("\nLista de pacientes salva com sucesso!\n\n");
  system("pause");
}