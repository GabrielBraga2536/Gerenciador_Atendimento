#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>

void IsFileOpen(FILE *file, const char *filename);

void IsMemoryAllocated(void *ptr);

#endif /* DEBUG_H */