#include "MenuCadastrar.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuCadastrar() {
  system("cls");
  
  MenuTitulo("Cadastrar");
  MenuItem("1. Cadastrar Novo Paciente");
  MenuItem("2. Consultar Paciente");
  MenuItem("3. Mostrar Lista De Pacientes");
  MenuItem("4. Atualizar Paciente");
  MenuItem("5. Remover Paciente");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void CadastrarNovoPaciente(LDE *lista, ABB *arvoreIdade, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia) {
  char nome[50], RG[10];
  int idade;
  
  system("cls");
  
  MenuTituloIsolado("Cadastrar Novo Paciente");
  
  printf("Nome: ");
  scanf("%s", nome);
  
  printf("RG: ");
  scanf("%s", RG);
  
  printf("Idade: ");
  scanf("%d", &idade);
  
  Paciente *novoPaciente = CriarPaciente(nome, RG, idade);
  
  if (novoPaciente != NULL) {
    InserirLDE(lista, novoPaciente);
    InserirABB(arvoreAno, novoPaciente, 1);
    InserirABB(arvoreMes, novoPaciente, 2);
    InserirABB(arvoreDia, novoPaciente, 3);
    InserirABB(arvoreIdade, novoPaciente, 4);
    
    printf("\nPaciente cadastrado com sucesso!\n\n");
    system("pause");
  } else {
    printf("\nErro ao cadastrar paciente.\n\n");
    system("pause");
  }
}

void ConsultarPaciente(Paciente *paciente) {
  system("cls");
  
  MenuTituloIsolado("Consultar Paciente");
  
  if (paciente->idade == 0) {
    printf("\nPaciente nao encontrado\n\n.");
  } else {
    ExibirPaciente(paciente);
  }
  
  system("pause");
}

void ExibirListaCompleta(LDE *lista) {
  system("cls");
  
  MenuTituloIsolado("Lista Completa de Pacientes");
  
  if (lista == NULL || lista->primeiro == NULL) {
    printf("Lista vazia.\n");
  } else {
    ExibirLDE(lista);
  }
  
  system("pause");
}

void AtualizarPaciente(LDE *lista, Paciente *paciente, ABB *arvoreIdade) {
  system("cls");
  
  MenuTituloIsolado("Atualizar Paciente");
  
  if (paciente->idade == 0) {
    printf("Paciente nao encontrado.\n\n");
    system("pause");
    return;
  }
  
  printf("Nome: ");
  scanf("%s", paciente->nome);
  
  printf("RG: ");
  scanf("%s", paciente->RG);
  
  printf("Idade: ");
  scanf("%d", &paciente->idade);
  
  LimparABB(arvoreIdade);
  
  Celula *temp = lista->primeiro;
  
  while (temp != NULL) {
    InserirABB(arvoreIdade, temp->paciente, 4);
    
    temp = temp->prox;
  }
  
  printf("\nPaciente atualizado com sucesso!\n\n");
  system("pause");
}

void RemoverPaciente(Paciente *paciente, LDE *lista, ABB *arvoreIdade, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia) {
  system("cls");
  
  MenuTituloIsolado("Remover Paciente");
  
  if (paciente->idade == 0) {
    printf("Paciente nao encontrado.\n\n");
    system("pause");
    return;
  }
  
  RemoverLDE(lista, paciente);
  
  LimparABB(arvoreAno);
  LimparABB(arvoreMes);
  LimparABB(arvoreDia);
  LimparABB(arvoreIdade);
  
  Celula *temp = lista->primeiro;

  while (temp != NULL) {
    InserirABB(arvoreAno, temp->paciente, 1);
    InserirABB(arvoreMes, temp->paciente, 2);
    InserirABB(arvoreDia, temp->paciente, 3);
    InserirABB(arvoreIdade, temp->paciente, 4);
    
    temp = temp->prox;
  }
  
  
  printf("\nPaciente removido com sucesso!\n\n");
  system("pause");
}