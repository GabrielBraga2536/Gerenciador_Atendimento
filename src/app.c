#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "app.h"


int app() {
  int opcao;
  
  LDE *lista = CriarLDE();
  Fila *fila = CriarFila();
  Heap *heap = CriarHeap();
  Pilha *pilha = CriarPilha();
  ABB *arvoreIdade = CriarABB();
  ABB *arvoreAno = CriarABB();
  ABB *arvoreMes = CriarABB();
  ABB *arvoreDia = CriarABB();
  
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
              CadastrarNovoPaciente(lista, arvoreIdade, arvoreAno, arvoreMes, arvoreDia);
              break;
            case 2:
              Paciente *pacienteParaConsultar = BuscarPaciente(lista);
              ConsultarPaciente(pacienteParaConsultar);
              break;
            case 3:
              ExibirListaCompleta(lista);
              break;
            case 4:
              Paciente *pacienteParaAtualizar = BuscarPaciente(lista);
              AtualizarPaciente(lista, pacienteParaAtualizar, arvoreIdade);
              break;
            case 5:
              Paciente *pacienteParaRemover = BuscarPaciente(lista);
              RemoverPaciente(pacienteParaRemover, lista, arvoreIdade, arvoreAno, arvoreMes, arvoreDia);
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
              EnfileirarPaciente(fila, pacienteParaEnfileirar, pilha);
              break;
            case 2:
              DesenfileirarPaciente(fila, pilha);
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
      
      case 3: //* Menu de Atendimento Prioritario
        while(opcao != 0){
          ExibirMenuAtendimentoPrioritario();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              Paciente *pacienteParaEnfileirarPrioritario = BuscarPaciente(lista);
              EnfileirarPacientePrioritario(heap, pacienteParaEnfileirarPrioritario);
              break;
            case 2:
              DesenfileirarPacientePrioritario(heap);
              break;
            case 3:
              ExibirFilaPrioritaria(heap);
              break;
            case 0:
              break;
            default:
          }
        }
        break;
      
      case 4: //* Menu de Pesquisa
        while(opcao != 0){
          ExibirMenuPesquisar();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              ExibirRegistrosAno(arvoreAno);
              break;
            case 2:
              ExibirRegistrosMes(arvoreMes);
              break;
            case 3:
              ExibirRegistrosDia(arvoreDia);
              break;
            case 4:
              ExibirRegistrosIdade(arvoreIdade);
              break;
            case 0:
              break;
            default:
          }
        }
        break;
      
      case 5: //* Menu de Desfazer
        while(opcao != 0){
          ExibirMenuDesfazer();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              ExibirLogAcoes(pilha);
              break;
            case 2:
              DesfazerUltimaAcao(pilha, fila);
              break;
            case 0:
              break;
            default:
          }
        }
        break;
      
      case 6: //* Menu de Carregar/Salvar
        while(opcao != 0){
          ExibirMenuCarregar();
          opcao = MenuInputUsuario();
          
          switch (opcao){
            case 1:
              CarregarArquivo(lista, arvoreIdade, arvoreAno, arvoreMes, arvoreDia);
              break;
            case 2:
              SalvarArquivo(lista);
              break;
            case 0:
              break;
            default:
          }
        }
        break;
      
      case 7: //* Menu de Sobre
        ExibirMenuSobre();
        system("pause");
        break;
      case 0:
        ClearLDE(lista);
        ClearFila(fila);
        ClearHeap(heap);
        ClearPilha(pilha);
        ClearABB(arvoreIdade->raiz);
        ClearABB(arvoreAno->raiz);
        ClearABB(arvoreMes->raiz);
        ClearABB(arvoreDia->raiz);
        return 0;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
  }
  
  return 0;
}
