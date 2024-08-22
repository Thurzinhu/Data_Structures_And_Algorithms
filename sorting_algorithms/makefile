CC = gcc
CFLAGS = -Wall -g -O2

IDIR = ./include
SDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
RESULTSDIR = ./results

SRC = $(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: objfolder binfolder resultsfolder main

main: $(OBJ)
	$(CC) $(CFLAGS) -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o: $(SDIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(SDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

objfolder:
	mkdir -p $(OBJDIR)

binfolder:
	mkdir -p $(BINDIR)

resultsfolder:
	mkdir -p $(RESULTSDIR)

.PHONY: clean run valgrind

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(RESULTSDIR)

run:
	$(BINDIR)/main

valgrind: bin/main
	valgrind ./bin/main