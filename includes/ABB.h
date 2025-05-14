#ifndef ABB_H
#define ABB_H

#include "Paciente.h"
#include "Debug.h"

//* Declaração das estruturas presentes em uma árvore binária de busca e suas respectivas funções 

// Estrutura da célula da árvore
typedef struct CelulaABB {
  Paciente *paciente;     // Ponteiro para o paciente
  struct CelulaABB *esq;  // Ponteiro para a subárvore esquerda
  struct CelulaABB *dir;  // Ponteiro para a subárvore direita
  struct CelulaABB *pai;  // Ponteiro para o pai da célula
} CelulaABB;

typedef struct {
  CelulaABB *raiz;        // Ponteiro para a raiz da árvore
  int qtde;               // Quantidade de pacientes na árvore
} ABB;

/**
 * @brief Inicializa uma célula da árvore binária de busca.
 * @param paciente - Ponteiro para o paciente a ser armazenado na célula.
 * @return Retorna um ponteiro para a célula da árvore binária de busca.
 */
CelulaABB *CriarCelulaABB(Paciente *paciente);

/**
 * @brief Inicializa uma árvore binária de busca.
 * @param None
 * @return Retorna um ponteiro para a árvore binária de busca.
 */
ABB *CriarABB();

/**
 * @brief Exibe os pacientes da árvore em ordem.
 * @param raiz - Ponteiro para a raiz da árvore.
 * @return 
 */
void emOrdem(CelulaABB *raiz);

/**
 * @brief Exibe os pacientes da árvore em pré-ordem.
 * @param raiz - Ponteiro para a raiz da árvore.
 * @return 
 */
void preOrdem(CelulaABB *raiz);

/**
 * @brief Exibe os pacientes da árvore em pós-ordem.
 * @param raiz - Ponteiro para a raiz da árvore.
 * @return 
 */
void posOrdem(CelulaABB *raiz);

/**
 * @brief Insere um paciente na árvore binária de busca.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @param paciente - Ponteiro para o paciente a ser inserido.
 * @param flag - Indica qual método de ordenação deve ser utilizado (Ano, Mês, Dia e Idade).
 * @return 
 */
void InserirABB(ABB* abb, Paciente *paciente, int flag);

/**
 * @brief Remove um paciente da árvore binária de busca.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @param paciente - Ponteiro para o paciente a ser removido.
 * @param flag - Indica qual metódo de busca deve ser utilizado (Ano, Mês, Dia e Idade).
 * @return 
 */
void RemoverABB(ABB *abb, Paciente *paciente, int flag);

/**
 * @brief Libera a memória da árvore binária de busca.
 * @param raiz - Ponteiro para a raiz da árvore.
 * @return 
 */
void ClearABB(CelulaABB *raiz);

/**
 * @brief Limpa os elementos presentes na árvore binária de busca.
 * @param abb - Ponteiro para a árvore binária de busca.
 * @return 
 */
void LimparABB(ABB *abb);

#endif /* ABB_H */