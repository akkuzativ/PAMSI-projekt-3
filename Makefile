OUTPUT_NAME = projekt-3

FLAGS = -Wall -pedantic -g
LINKER_FLAGS = -g -lsfml-graphics -lsfml-window -lsfml-system

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = inc/

CC = g++

all: o
	$(CC) $(OBJ_PATH)* -o $(OUTPUT_NAME) $(LINKER_FLAGS)

o:
	$(CC) $(FLAGS) -c $(SRC_PATH)*
	mkdir -p $(OBJ_PATH)
	mv *.o $(OBJ_PATH)

clean:
	rm -fr $(OBJ_PATH)
	rm -f $(OUTPUT_NAME)
	rm -f *.o
