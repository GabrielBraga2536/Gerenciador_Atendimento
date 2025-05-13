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

void InserirABB_Idade(ABB *abb, Paciente *paciente) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *nova = CriarCelulaABB(paciente);
  
  if (abb->raiz == NULL) {
    abb->raiz = nova;
  } 
  else {
    CelulaABB *atual = abb->raiz;
    CelulaABB *anterior = NULL;
    
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
  }
  
  abb->qtde++;
}

void InserirABB_Ano(ABB *abb, Paciente *paciente) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *nova = CriarCelulaABB(paciente);
  
  if (abb->raiz == NULL) {
    abb->raiz = nova;
  } 
  else {
    CelulaABB *atual = abb->raiz;
    CelulaABB *anterior = NULL;
    
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
  }
  
  abb->qtde++;
}

void InserirABB_Mes(ABB *abb, Paciente *paciente) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *nova = CriarCelulaABB(paciente);
  
  if (abb->raiz == NULL) {
    abb->raiz = nova;
  } 
  else {
    CelulaABB *atual = abb->raiz;
    CelulaABB *anterior = NULL;
    
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
  }
  
  abb->qtde++;
}

void InserirABB_Dia(ABB *abb, Paciente *paciente) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *nova = CriarCelulaABB(paciente);
  
  if (abb->raiz == NULL) {
    abb->raiz = nova;
  } 
  else {
    CelulaABB *atual = abb->raiz;
    CelulaABB *anterior = NULL;
    
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
  }
  
  abb->qtde++;
}

void RemoverABB(ABB *abb, Paciente *paciente) {
  IsMemoryAllocated(abb);
  IsMemoryAllocated(paciente);
  
  CelulaABB *atual = abb->raiz;
  CelulaABB *anterior = NULL;
  
  while (atual != NULL && atual->paciente != paciente) {
    anterior = atual;
    if (paciente->idade < atual->paciente->idade) {
      atual = atual->esq;
    } else {
      atual = atual->dir;
    }
  }
  
  if (atual == NULL) {
    printf("Paciente nao encontrado na ABB.\n");
    return;
  }
  
  if (atual->esq == NULL && atual->dir == NULL) { // Folha
    if (anterior == NULL) {
      abb->raiz = NULL;
    } else if (anterior->esq == atual) {
      anterior->esq = NULL;
    } else {
      anterior->dir = NULL;
    }
  } else if (atual->esq == NULL || atual->dir == NULL) { // Um filho
    CelulaABB *filho = (atual->esq != NULL) ? atual->esq : atual->dir;
    
    if (anterior == NULL) {
      abb->raiz = filho;
    } else if (anterior->esq == atual) {
      anterior->esq = filho;
    } else {
      anterior->dir = filho;
    }
  } else { // Dois filhos
    // Encontrar o sucessor
    CelulaABB *sucessor = atual->dir;
    CelulaABB *sucessorAnterior = atual;
    
    while (sucessor->esq != NULL) {
      sucessorAnterior = sucessor;
      sucessor = sucessor->esq;
    }
    
    // Substituir o valor do nó a ser removido pelo sucessor
    atual->paciente = sucessor->paciente;
    
    // Remover o sucessor
    if (sucessorAnterior == atual) {
      sucessorAnterior->dir = sucessor->dir;
    } else {
      sucessorAnterior->esq = sucessor->dir;
    }
    
    free(sucessor);
  }
  
  ClearPaciente(atual->paciente);
  free(atual);
}

void ClearABB(CelulaABB *raiz) {
  if (raiz != NULL) {
    ClearABB(raiz->esq);
    ClearABB(raiz->dir);
    ClearPaciente(raiz->paciente);
    free(raiz);
  }
}

