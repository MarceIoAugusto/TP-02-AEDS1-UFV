
# ============================================================
# COMPILACAO DO TP2 - AEDS1
#
# Este Makefile funciona no Linux e no Windows com GNU Make.
#
# COMO COMPILAR E EXECUTAR
#   Este Makefile fica dentro da pasta TESTE. Abra o terminal nessa pasta:
#       cd TESTE
#   Depois use:
# Linux:
#   make
#   make run -> compila e executa o programa
#   make clean -> apaga os arquivos gerados
#
# Windows com MinGW:
#   mingw32-make
#   mingw32-make run -> compila e executa o programa
#   mingw32-make clean -> apaga os arquivos gerados
# ============================================================

CC = gcc

CFLAGS = -Wall -Wextra -g -std=c99 -I../headers

SRC = ../sources
OUT = output

# Detecta o sistema operacional.
ifeq ($(OS),Windows_NT)
    EXEC = $(OUT)/tp2.exe

    MKDIR = if not exist "$(OUT)" mkdir "$(OUT)"
    RMDIR = if exist "$(OUT)" rmdir /s /q "$(OUT)"
    DEL_REPORT = if exist relatorio.txt del /q relatorio.txt
    RUN = $(EXEC)
else
    EXEC = $(OUT)/tp2

    MKDIR = mkdir -p "$(OUT)"
    RMDIR = rm -rf "$(OUT)"
    DEL_REPORT = rm -f relatorio.txt
    RUN = ./$(EXEC)
endif

# Recompila os objetos se algum cabecalho mudar.
HEADERS = $(wildcard ../headers/*.h)

# Arquivos objeto que formam o programa.
OBJS = $(OUT)/main.o \
       $(OUT)/pokemon.o \
       $(OUT)/pokelista.o \
       $(OUT)/treinador.o \
       $(OUT)/saida.o

# Compila o programa completo.
all: $(EXEC)

# Liga os arquivos objeto e gera o executavel.
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

# O main.c esta na pasta TESTE.
$(OUT)/main.o: main.c $(HEADERS)
	$(MKDIR)
	$(CC) $(CFLAGS) -c main.c -o $@

# Os demais arquivos .c estao na pasta ../sources.
$(OUT)/%.o: $(SRC)/%.c $(HEADERS)
	$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compila e executa.
run: $(EXEC)
	$(RUN)

# Remove os arquivos gerados.
clean:
	$(RMDIR)
	$(DEL_REPORT)

.PHONY: all run clean
