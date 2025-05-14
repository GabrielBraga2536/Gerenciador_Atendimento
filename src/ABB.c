#include "ABB.h"

#include <stdio.h>
#include <stdlib.h>

CelulaABB *CriarCelulaABB(Paciente *paciente) {
  CelulaABB *nova = (CelulaABB *)malloc(sizeof(CelulaABB));
  IsMemoryAllocated(nova);
  
  nova->paciente = paciente;
  nova->esq = NULL;
  nova->dir = NULL;
  
  return nova;
}

ABB *CriarABB() {
  ABB *abb = (ABB *)malloc(sizeof(ABB));
  IsMemoryAllocated(abb);
  
  abb->raiz = NULL;
  abb->qtde = 0;
  
  return abb;
}

void emOrdem(CelulaABB *raiz) {
  if (raiz != NULL) {
    emOrdem(raiz->esq);
    ExibirPaciente(raiz->paciente);
    emOrdem(raiz->dir);
  }
}

void preOrdem(CelulaABB *raiz) {
  if (raiz != NULL) {
    ExibirPaciente(raiz->paciente);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
}

void posOrdem(CelulaABB *raiz) {
  if (raiz != NULL) {
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    ExibirPaciente(raiz->paciente);
  }
}

void InserirABB(ABB* abb, Paciente *paciente, int flag) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *nova = CriarCelulaABB(paciente);
  
  if (abb->raiz == NULL) {
    abb->raiz = nova;
  } 
  else {
    CelulaABB *atual = abb->raiz;
    CelulaABB *anterior = NULL;
    
    switch (flag){
    case 1: //* Ordena por Ano
      while (atual != NULL) {
        anterior = atual;
        if (paciente->Entrada->ano < atual->paciente->Entrada->ano) {
          atual = atual->esq;
        } 
        else {
          atual = atual->dir;
        }
      }
      
      if (paciente->Entrada->ano < anterior->paciente->Entrada->ano) {
        anterior->esq = nova;
      } 
      else {
        anterior->dir = nova;
      }
      break;
      
    case 2: //* Ordena por Mes
      while (atual != NULL) {
        anterior = atual;
        if (paciente->Entrada->mes < atual->paciente->Entrada->mes) {
          atual = atual->esq;
        } 
        else {
          atual = atual->dir;
        }
      } 
      
      if (paciente->Entrada->mes < anterior->paciente->Entrada->mes) {
        anterior->esq = nova;
      } 
      else {
        anterior->dir = nova;
      }
      break;
    
    case 3: //* Ordena por Dia
      while (atual != NULL) {
        anterior = atual;
        if (paciente->Entrada->dia < atual->paciente->Entrada->dia) {
          atual = atual->esq;
        } 
        else {
          atual = atual->dir;
        }
      } 
      
      if (paciente->Entrada->dia < anterior->paciente->Entrada->dia) {
        anterior->esq = nova;
      } 
      else {
        anterior->dir = nova;
      }
      break;
    
    case 4: //* Ordena por Idade
      while (atual != NULL) {
        anterior = atual;
        if (paciente->idade < atual->paciente->idade) {
          atual = atual->esq;
        } 
        else {
          atual = atual->dir;
        }
      } 
      
      if (paciente->idade < anterior->paciente->idade) {
        anterior->esq = nova;
      } 
      else {
        anterior->dir = nova;
      }
      break;
    default:
      break;
    }
    
  }
  
  abb->qtde++;
}

void RemoverABB(ABB* arvore, Paciente *paciente, int flag) {
  IsMemoryAllocated(arvore);
  IsMemoryAllocated(paciente);
  
  CelulaABB *vertice = arvore->raiz;
  CelulaABB *verticePai = NULL;
  
  
  
  // Buscar o vertice a ser removido
  while (vertice != NULL && vertice->paciente->RG != paciente->RG) {
    verticePai = vertice;
    
    if(flag == 1){
      if (paciente->Entrada->ano < vertice->paciente->Entrada->ano) {
        vertice = vertice->esq;
      } else {
        vertice = vertice->dir;
      }
    }
    else if(flag == 2){
      if (paciente->Entrada->mes < vertice->paciente->Entrada->mes) {
        vertice = vertice->esq;
      } else {
        vertice = vertice->dir;
      }
    }
    else if(flag == 3){
      if (paciente->Entrada->dia < vertice->paciente->Entrada->dia) {
        vertice = vertice->esq;
      } else {
        vertice = vertice->dir;
      }
    }
    else if(flag == 4){
      if (paciente->idade < vertice->paciente->idade) {
        vertice = vertice->esq;
      } else {
        vertice = vertice->dir;
      }
    }
  }
  
  if (vertice == NULL) {
    printf("Paciente não encontrado na árvore.\n");
    return;
  }
  
  // Caso 1: Nó sem filhos
  if (vertice->esq == NULL && vertice->dir == NULL) {
    if (verticePai == NULL) { // Nó é a raiz
      arvore->raiz = NULL;
    } else if (verticePai->esq == vertice) {
      verticePai->esq = NULL;
    } else {
      verticePai->dir = NULL;
    }
    free(vertice);
  }
  // Caso 2: Nó com um único filho
  else if (vertice->esq == NULL || vertice->dir == NULL) {
    CelulaABB *filho = (vertice->esq != NULL) ? vertice->esq : vertice->dir;
    
    if (verticePai == NULL) { // Nó é a raiz
        arvore->raiz = filho;
    } else if (verticePai->esq == vertice) {
        verticePai->esq = filho;
    } else {
        verticePai->dir = filho;
    }
    filho->pai = verticePai;
    free(vertice);
  }
  // Caso 3: Nó com dois filhos
  else {
    CelulaABB *sucessor = vertice->dir;
    while (sucessor->esq != NULL) {
        sucessor = sucessor->esq;
    }
    
    vertice->paciente = sucessor->paciente; // Troca os valores
    RemoverABB(arvore, sucessor->paciente, flag);   // Remove o sucessor
  }

  arvore->qtde--;
}

void ClearABB(CelulaABB *raiz) {
  if (raiz != NULL) {
    ClearABB(raiz->esq);
    ClearABB(raiz->dir);
    // Remova a linha abaixo se Paciente é liberado em outro lugar
    // ClearPaciente(raiz->paciente);
    free(raiz);
  }
}

// Função para limpar toda a ABB e atualizar a raiz para NULL
void LimparABB(ABB *abb) {
  if (abb != NULL && abb->raiz != NULL) {
    ClearABB(abb->raiz);
    abb->raiz = NULL;
    abb->qtde = 0;
  }
}

int MAX(int x, int y) {
  if (x >= y)
    return x;
  else
    return y;
}

int altura(CelulaABB *x) {
  if (x == NULL) {
    return -1;
  }
  return MAX(altura(x->esq), altura(x->dir)) + 1;
}

int fatorBalanceamento(CelulaABB *x) { return altura(x->dir) - altura(x->esq); }

void RotacaoEsquerda(ABB *arvore, CelulaABB *x) {
  CelulaABB *y = x->dir;
  
  x->dir = y->esq;
  
  if (y->esq != NULL) {
    y->esq->pai = x;
  }
  
  y->pai = x->pai;
  
  if (x->pai == NULL) {
    arvore->raiz = y;
  } 
  else if (x == x->pai->esq) {
    x->pai->esq = y;
  } 
  else {
    x->pai->dir = y;
  }
  
  y->esq = x;
  x->pai = y;
  
}

void RotacaoDireita(ABB *arvore, CelulaABB *x) {
  CelulaABB *y = x->esq;
  
  x->esq = y->dir;
  
  if (y->dir != NULL) {
    y->dir->pai = x;
  }
  
  y->pai = x->pai;
  
  if (x->pai == NULL) {
    arvore->raiz = y;
  } 
  else if (x == x->pai->dir) {
    x->pai->dir = y;
  } 
  else {
    x->pai->esq = y;
  }
  
  y->dir = x;
  x->pai = y;
  
}

void Balanceie(ABB *arvore, CelulaABB *x) {
  int fb = fatorBalanceamento(x);
  
  if (fb == 2) {
    if (fatorBalanceamento(x->dir) < 0) {
      RotacaoDireita(arvore, x->dir);
    }
    RotacaoEsquerda(arvore, x);
  } 
  else if (fb == -2) {
    if (fatorBalanceamento(x->esq) > 0) {
      RotacaoEsquerda(arvore, x->esq);
    }
    RotacaoDireita(arvore, x);
  }
  
  if (fb > 1 || fb < -1) {
    if (x->pai != NULL) {
      Balanceie(arvore, x->pai);
    } else {
      arvore->raiz = x;
    }
  }
}