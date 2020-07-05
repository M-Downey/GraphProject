# Project: GraphProject
# Makefile created by tony

CC       = gcc
OBJ      = main.o stats.o graph.o search.o
LINKOBJ  = main.o stats.o graph.o search.o
BIN      = search-cli
RM       = rm -f

.PHONY: clean

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $(LINKOBJ)

main.o: main.c
	$(CC) -c -o main.o main.c

stats.o: stats.c
	$(CC) -c -o stats.o stats.c

graph.o: graph.c
	$(CC) -c -o graph.o graph.c

search.o: search.c
	$(CC) -c -o search.o search.c
