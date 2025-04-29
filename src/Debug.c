#include "Debug.h"

#include <stdio.h>
#include <stdlib.h>

void IsFileOpen(FILE *file, const char *filename) {
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo: %s\n", filename);
    exit(EXIT_FAILURE);
  }
}

void IsMemoryAllocated(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Erro ao alocar memoria.\n");
    exit(EXIT_FAILURE);
  }
}