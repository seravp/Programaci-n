
BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

$(BIN)testimagen:  $(OBJ)testimagen.o $(OBJ)imagen.o $(OBJ)pgm.o
	g++ -o $(BIN)testimagen  $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)testimagen.o -I$(INC)
$(OBJ)testimagen.o: $(SRC)testimagen.cpp $(INC)pgm.h $(INC)imagen.h
	g++ $(OPC) -c $(SRC)testimagen.cpp -o $(OBJ)testimagen.o -I$(INC)
$(OBJ)pgm.o: $(SRC)pgm.cpp $(INC)pgm.h
	g++ $(OPC) -c $(SRC)pgm.cpp -o $(OBJ)pgm.o -I$(INC)
$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)imagen.h
	g++ $(OPC) -c $(SRC)imagen.cpp -o $(OBJ)imagen.o -I$(INC)


all: $(BIN)/esteganografia $(BIN)/testcodificar $(BIN)/testimagen

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
mrproper : clean
	@rm -f $(DOC)/*
