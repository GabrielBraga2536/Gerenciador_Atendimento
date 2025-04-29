# Nome do executável
TARGET = a

# Arquivos-fonte
SRCS = app.c baseViews.c MenuViews.c Debug.c Paciente.c LDE.c

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I ../includes

# Regra padrão
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpeza dos arquivos gerados
clean:
	del $(TARGET).exe