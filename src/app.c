#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "BaseViews.h"
#include "Paciente.h"
#include "LDE.h"
#include "Fila.h"
#include "Heap.h"
#include "Pilha.h"

#include "Debug.h"

#include "MenuCadastrar.h"
#include "MenuAtendimento.h"
#include "MenuSobre.h"


int main() {
  int opcao;
  
  FILE *arquivo = fopen("pacientes.txt", "a+");
  IsFileOpen(arquivo, "pacientes.txt");
  
  LDE *lista = CriarLDE();
  Fila *fila = CriarFila();
  Heap *heap = CriarHeap();
  Pilha *pilha = CriarPilha();
  
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
              CadastrarNovoPaciente(lista, arquivo);
              break;
            case 2:
              Paciente *pacienteParaConsultar = BuscarPaciente(lista);
              ConsultarPaciente(lista, pacienteParaConsultar);
              break;
            case 3:
              ExibirListaCompleta(lista);
              break;
            case 4:
              Paciente *pacienteParaAtualizar = BuscarPaciente(lista);
              AtualizarPaciente(lista, pacienteParaAtualizar);
              break;
            case 5:
              Paciente *pacienteParaRemover = BuscarPaciente(lista);
              RemoverPaciente(pacienteParaRemover, lista, arquivo);
              break;
            case 0:
              break;
            default:
          }
          
        }
        break;
      
      case 2: //* Menu de Atendimento
        while(opcao != 0){
          ExibirMenuAtendimento();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              Paciente *pacienteParaEnfileirar = BuscarPaciente(lista);
              EnfileirarPaciente(fila, pacienteParaEnfileirar);
              break;
            case 2:
              DesenfileirarPaciente(fila);
              break;
            case 3:
              ExibirFilaAtendimento(fila);
              break;
            case 0:
              break;
            default:
          }
        }
        break;
      case 6:
        ExibirMenuSobre();
        system("pause");
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
