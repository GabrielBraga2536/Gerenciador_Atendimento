#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "BaseViews.h"

#define MAX_LENGTH 40

void MenuLinhaSuperior(){
  printf("%c", 201);
  for(int i = 0; i < MAX_LENGTH; i++){
    printf("%c", 205);
  }
  printf("%c\n", 187);
}

void MenuLinhaInferior(){
  printf("%c", 200);
  for(int i = 0; i < MAX_LENGTH; i++){
    printf("%c", 205);
  }
  printf("%c\n", 188);
}

void MenuItem(char *item){
  printf("%c", 186);
  
  printf("%-*s", MAX_LENGTH, item);
  
  printf("%c\n", 186);
}

void MenuTitulo(char *titulo){
  MenuLinhaSuperior();
  
  printf("%c", 186);
  
  int padding = (MAX_LENGTH - strlen(titulo)) / 2;
  printf("%*s", padding, "");
  printf("%-*s", MAX_LENGTH - padding, titulo);
  
  printf("%c\n", 186);
  
  
  printf("%c", 204);
  for(int i = 0; i < MAX_LENGTH; i++){
    printf("%c", 205);
  }
  printf("%c\n", 185);
}

int MenuInputUsuario(){
  int opcao;
  printf("\n");
  printf("Digite uma opcao: ");
  scanf("%d", &opcao);
  return opcao;
}

void ExibirMenuPrincipal(){
  system("cls");
  
  MenuTitulo("Menu Principal");
  MenuItem("1. Cadastrar");
  MenuItem("2. Atendimento");
  MenuItem("3. Atendimento Prioritario");
  MenuItem("4. Pesquisar");
  MenuItem("5. Desfazer");
  MenuItem("6. Sobre");
  MenuItem("0. Sair");
  MenuLinhaInferior();
}