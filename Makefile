# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Include directories (adiciona os subdiretórios com os arquivos .h)
INCLUDES = -IArquivo -ILista -IMenu -IPacientes

# Source files
SRCS = main.c \
       Arquivo/arquivo.c \
       Lista/lista.c \
       Menu/menu.c \
       Pacientes/pacientes.c

# Object files (substitui .c por .o)
OBJS = $(SRCS:.c=.o)

# Executável
TARGET = health_sys

# Phony targets
.PHONY: all compile run clean

# Default target (compile and run)
all: compile run

# Compilar sem executar
compile: $(TARGET)

# Executar o programa compilado
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos gerados na compilação
clean:
	rm -f $(OBJS) $(TARGET)

# Compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Linkar os arquivos objeto para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
