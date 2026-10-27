# ==========================================================================
# COMO COMPILAR E EXECUTAR
#   Este Makefile fica dentro da pasta TESTE. Abra o terminal nessa pasta:
#       cd TESTE
#   Depois use:
#       mingw32-make        -> compila tudo e gera o executavel output/tp1.exe
#       mingw32-make run    -> compila e executa o programa
#       mingw32-make clean  -> apaga os arquivos gerados
#	O arquivo de teste devera estar presente na pasta TESTE.
#	O Programa solicitara o nome do arquivo <- se não for lido favor usar o comando mingw32-make clean
# ==========================================================================

CC = gcc

# -I../headers -> diz ao compilador onde estao os arquivos .h
CFLAGS = -Wall -Wextra -g -std=c99 -I../headers

SRC = ../sources
OUT = output
EXEC = $(OUT)/tp1.exe

# Se algum .h mudar, tudo e recompilado
HEADERS = $(wildcard ../headers/*.h)

OBJS = $(OUT)/main.o $(OUT)/pokemon.o $(OUT)/pokelista.o $(OUT)/treinador.o $(OUT)/centropesquisa.o $(OUT)/saida.o


all: $(EXEC)


# Liga todos os objetos e gera o executavel
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) -lm


# main.c esta na pasta TESTE
$(OUT)/main.o: main.c $(HEADERS)
	if not exist $(OUT) mkdir $(OUT)
	$(CC) $(CFLAGS) -c main.c -o $@


# Os demais .c estao na pasta ../sources
$(OUT)/%.o: $(SRC)/%.c $(HEADERS)
	if not exist $(OUT) mkdir $(OUT)
	$(CC) $(CFLAGS) -c $< -o $@


# Compila e executa
run: $(EXEC)
	.\$(EXEC)


# Apaga os arquivos gerados
clean:
	if exist $(OUT) rmdir /s /q $(OUT)
	if exist relatorio.txt del /q relatorio.txt


.PHONY: all run clean