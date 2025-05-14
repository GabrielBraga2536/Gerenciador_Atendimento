# Nome do executável
TARGET = a

# Arquivos-fonte
SRCS = main.c src/app.c src/baseViews.c src/Debug.c src/Paciente.c src/LDE.c src/Fila.c src/Heap.c src/Pilha.c src/ABB.c \
src/MenuCadastrar.c src/MenuAtendimento.c src/MenuAtendimentoPrioritario.c src/MenuPesquisar.c src/MenuDesfazer.c \
src/MenuCarregar.c src/MenuSobre.c

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I includes -I src

# Regra padrão
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Limpeza dos arquivos gerados
clean:
	-del $(TARGET).exe 2>nul || rm -f $(TARGET).exe