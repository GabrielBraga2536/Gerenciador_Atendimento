#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "BaseViews.h"
#include "Paciente.h"
#include "LDE.h"
#include "Fila.h"
#include "Heap.h"
#include "Debug.h"

#include "MenuCadastrar.h"


int main() {
  int opcao;
  char RG[10];
  
  FILE *arquivo = fopen("pacientes.txt", "a+");
  IsFileOpen(arquivo, "pacientes.txt");
  
  LDE *lista = CriarLDE();
  Fila *fila = CriarFila();
  Heap *heap = CriarHeap();
  
  while(1){
    system("cls");
    ExibirMenuPrincipal();
    
    opcao = MenuInputUsuario();
    
    switch(opcao){
      case 1: //* Menu de Cadastro
        while(opcao != 0){ 
          ExibirMenuCadastrar();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              CadastrarNovoPaciente(lista, arquivo, fila, heap);
              break;
            case 2:
              ConsultarPaciente(lista, fila->head->paciente);
              break;
            case 3:
              ExibirListaCompleta(lista);
              break;
            case 4:
              scanf("%s", RG);
              Paciente *pacienteParaAtualizar = BuscarPaciente(lista, RG);
              AtualizarPaciente(pacienteParaAtualizar, lista);
              break;
            case 5:
              scanf("%s", RG);
              Paciente *pacienteParaRemover = BuscarPaciente(lista, RG);
              RemoverPaciente(pacienteParaRemover, lista, fila, heap, arquivo);
              break;
            case 0:
              break;
            default:
          }
          
        }
        break;
      case 0:
        fclose(arquivo);
        ClearLDE(lista);
        ClearFila(fila);
        ClearHeap(heap);
        return 0;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
  }
  
  return 0;
}
