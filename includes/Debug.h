#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>

//* Funções de depuração para verificar alocação de memória e abertura de arquivos

/**
 * @brief Valida se um ponteiro de arquivo está aberto.
 * @param pilha - Ponteiro para a pilha.
 * @param paciente - Ponteiro para o paciente a ser adicionado.
 * @return 
 */
void IsFileOpen(FILE *file, const char *filename);

/**
 * @brief Valida se um ponteiro de memória foi alocado corretamente.
 * @param ptr - Ponteiro a ser verificado.
 * @return 
 */
void IsMemoryAllocated(void *ptr);

#endif /* DEBUG_H */