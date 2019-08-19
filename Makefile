#meu segundo makefile

PROJ_NAME= exe

# .c files
C_SOURCE=$(wildcard *.cpp)

#.h files
H_SOURCE=$(wildcard *.hpp)

#object files

OBJ=$(C_SOURCE:.cpp=.o)

#compiler
CC=g++

#flags for compiler

CC_FLAGS=-c \
         -w \
         -Wall \
         -ansi \
         -pedantic \
         -std=c++11

#Compilation and linking

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@$(CC) -o $@ $^

%.o: %.cpp %.hpp

	@$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.cpp $(H_SOURCE)
	@$(CC) -o $@ $< $(CC_FLAGS)

install:all
	@mkdir -p obj
	@mkdir -p src
	@mv $(OBJ) obj
	@mv $(C_SOURCE) src
	@mv $(H_SOURCE) src
.PHONY: clean

run:
	@./exe

clean:
	@mv  src/* /home/geraldo/Documentos/aulas_oo/C++/exercicio02
	@rm -r obj
	@rm -r src
	@rm -rf exe
