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
  
  Paciente vetor[abb->qtde];
  coletarRegistros(abb->raiz, vetor, 0);
  
  qsort(vetor, abb->qtde, sizeof(vetor)/(sizeof(Paciente)), cmpAno);
  
  for (int i = 0; i < abb->qtde; i++) {
    ExibirPaciente(&vetor[i]);
  }
  
  system("pause");
}

void ExibirRegistrosIdade(ABB *abb) {
  system("cls");
  
  MenuTituloIsolado("Pesquisar por Idade");
  
  emOrdem(abb->raiz);
  
  system("pause");
}