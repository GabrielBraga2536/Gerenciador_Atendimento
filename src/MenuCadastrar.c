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

void CadastrarNovoPaciente(LDE *lista, FILE *arquivo, Fila *fila, Heap *heap) {
  char nome[50], RG[10];
  int idade;
  
  system("cls");
  
  MenuTitulo("Cadastrar Novo Paciente");
  
  printf("Nome: ");
  scanf("%s", nome);
  
  printf("RG: ");
  scanf("%s", RG);
  
  printf("Idade: ");
  scanf("%d", &idade);
  
  Paciente *novoPaciente = CriarPaciente(nome, RG, idade);
  
  if (novoPaciente != NULL) {
    InserirHeap(heap, novoPaciente);
    Enfileirar(fila, novoPaciente);
    InserirLDE(lista, novoPaciente, arquivo);
    
    printf("\nPaciente cadastrado com sucesso!\n\n");
    system("pause");
  } else {
    printf("\nErro ao cadastrar paciente.\n\n");
    system("pause");
  }
}

void ConsultarPaciente(LDE *lista, Paciente *paciente) {
  system("cls");
  
  MenuTitulo("Consultar Paciente");
  
  if (paciente == NULL) {
    MenuItem("Paciente nao encontrado.");
    MenuLinhaInferior();
  } else {
    ExibirPaciente(paciente);
  }
  
  system("pause");
}

void ExibirListaCompleta(LDE *lista) {
  system("cls");
  
  MenuTitulo("Lista Completa de Pacientes");
  
  if (lista == NULL || lista->primeiro == NULL) {
    printf("Lista vazia.\n");
  } else {
    ExibirLDE(lista);
  }
  
  system("pause");
}

void AtualizarPaciente(Paciente *paciente, LDE *lista) {
  system("cls");
  
  MenuTitulo("Atualizar Paciente");
  
  if (paciente == NULL) {
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
  
  // Atualizar o arquivo com os dados do paciente atualizado
  FILE *arquivoTemp = fopen("pacientes_temp.txt", "w+");
  IsFileOpen(arquivoTemp, "pacientes_temp.txt");
  
  Celula *atual = lista->primeiro;
  while (atual != NULL) {
    if (atual->paciente == paciente) {
      fprintf(arquivoTemp, "Nome: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
        paciente->nome, paciente->idade, paciente->RG, 
        paciente->Entrada->dia, paciente->Entrada->mes, paciente->Entrada->ano
      );
    } else {
      fprintf(arquivoTemp, "Nome: %s\nIdade: %d\nRG: %s\nEntrada: %d/%d/%d\n\n", 
        atual->paciente->nome, atual->paciente->idade, atual->paciente->RG, 
        atual->paciente->Entrada->dia, atual->paciente->Entrada->mes, atual->paciente->Entrada->ano
      );
    }
    atual = atual->prox;
  }
  fclose(arquivoTemp);
  
  // Substituir o arquivo original pelo temporário
  remove("pacientes.txt");
  rename("pacientes_temp.txt", "pacientes.txt");
  
}

void RemoverPaciente(Paciente *paciente, LDE *lista, Fila *fila, Heap *heap, FILE *arquivo) {
  system("cls");
  
  MenuTitulo("Remover Paciente");
  
  if (paciente == NULL) {
    printf("Paciente nao encontrado.\n\n");
    system("pause");
    return;
  }
  
  RemoverLDE(lista, paciente, arquivo);
  Desenfileirar(fila, paciente);
  RemoverHeap(heap);
  
  printf("\nPaciente removido com sucesso!\n\n");
  system("pause");
}