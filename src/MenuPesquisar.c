#include "MenuPesquisar.h"

#include <stdio.h>
#include <stdlib.h>

void ExibirMenuPesquisar(){
  system("cls");
  
  MenuTitulo("Pesquisar");
  MenuItem("1. Registros por Ano");
  MenuItem("2. Registros por Mes");
  MenuItem("3. Registros por Dia");
  MenuItem("4. Registros por Idade");
  MenuItem("0. Voltar ao Menu Principal");
  MenuLinhaInferior();
}

void ExibirRegistrosAno(ABB *abb) {
  system("cls");
  
  MenuTituloIsolado("Pesquisar por Ano");
  
  if (abb->qtde == 0) {
    printf("Nenhum registro encontrado.\n\n");
    system("pause");
    return;
  }
  
  emOrdem(abb->raiz);
  
  system("pause");
}

void ExibirRegistrosMes(ABB *abb) {
  system("cls");
  
  MenuTituloIsolado("Pesquisar por Mes");
  
  if (abb->qtde == 0) {
    printf("Nenhum registro encontrado.\n\n");
    system("pause");
    return;
  }
  
  emOrdem(abb->raiz);
  
  system("pause");
}

void ExibirRegistrosDia(ABB *abb) {
  system("cls");
  
  MenuTituloIsolado("Pesquisar por Dia");
  
  if (abb->qtde == 0) {
    printf("Nenhum registro encontrado.\n\n");
    system("pause");
    return;
  }
  
  emOrdem(abb->raiz);
  
  system("pause");
}

void ExibirRegistrosIdade(ABB *abb) {
  system("cls");
  
  MenuTituloIsolado("Pesquisar por Idade");
  
  if (abb->qtde == 0) {
    printf("Nenhum registro encontrado.\n\n");
    system("pause");
    return;
  }

  emOrdem(abb->raiz);
  
  system("pause");
}