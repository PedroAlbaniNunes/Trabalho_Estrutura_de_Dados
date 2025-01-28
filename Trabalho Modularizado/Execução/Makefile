# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Include directories (adiciona os subdiretórios com os arquivos .h)
INCLUDES = -I../Pacientes -I../Lista -I../Menu -I../Arquivo

# Source files
SRCS = main.c ../Pacientes/pacientes.c ../Lista/lista.c ../Menu/menu.c ../Arquivo/arquivo.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = health_sys.exe

# Phony targets
.PHONY: all compile run clean

# Default target (compile and run)
all: compile run

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	del /Q $(OBJS) $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
