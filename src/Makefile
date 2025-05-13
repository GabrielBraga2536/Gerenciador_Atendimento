# Nome do executável
TARGET = a

# Arquivos-fonte
SRCS = app.c baseViews.c Debug.c Paciente.c LDE.c Fila.c Heap.c Pilha.c ABB.c\
MenuCadastrar.c MenuAtendimento.c MenuAtendimentoPrioritario.c MenuPesquisar.c MenuDesfazer.c MenuCarregar.c MenuSobre.c

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I ../includes

# Regra padrão
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpeza dos arquivos gerados
clean:
	del $(TARGET).exe