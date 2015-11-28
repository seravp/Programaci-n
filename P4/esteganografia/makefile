
BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
ZIP=./zip/
DOC=./doc/
PRJ=esteganografia

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)esteganografia $(BIN)testcodificar $(BIN)testimagen

$(BIN)testcodificar:  $(OBJ)testcodificar.o $(OBJ)imagen.o $(OBJ)pgm.o $(LIB)libimagen.a
	g++ -o $(BIN)testcodificar  $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)testcodificar.o -L$(LIB) -limagen
$(BIN)testimagen:  $(OBJ)testimagen.o $(OBJ)imagen.o $(OBJ)pgm.o
	g++ -o $(BIN)testimagen  $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)testimagen.o -I$(INC)
$(OBJ)testimagen.o: $(SRC)testimagen.cpp $(INC)pgm.h $(INC)imagen.h
	g++ $(OPC) -c $(SRC)testimagen.cpp -o $(OBJ)testimagen.o -I$(INC)
$(OBJ)testcodificar.o: $(SRC)testcodificar.cpp $(INC)pgm.h $(INC)imagen.h $(INC)codificar.h
	g++ $(OPC) -c $(SRC)testcodificar.cpp -o $(OBJ)testcodificar.o -I$(INC)
$(BIN)esteganografia:  $(OBJ)esteganografia.o $(OBJ)imagen.o $(OBJ)pgm.o $(LIB)libimagen.a
	g++ -o $(BIN)esteganografia  $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)esteganografia.o -L$(LIB) -limagen
$(OBJ)esteganografia.o: $(SRC)esteganografia.cpp $(INC)pgm.h $(INC)imagen.h 
	g++ $(OPC) -c $(SRC)esteganografia.cpp -o $(OBJ)esteganografia.o -I$(INC)
$(OBJ)pgm.o: $(SRC)pgm.cpp $(INC)pgm.h
	g++ $(OPC) -c $(SRC)pgm.cpp -o $(OBJ)pgm.o -I$(INC)
$(OBJ)imagen.o: $(SRC)imagen.cpp $(INC)imagen.h
	g++ $(OPC) -c $(SRC)imagen.cpp -o $(OBJ)imagen.o -I$(INC)
$(OBJ)codificar.o: $(SRC)codificar.cpp $(INC)codificar.h
	g++ $(OPC) -c $(SRC)codificar.cpp -o $(OBJ)codificar.o -I$(INC)
$(OBJ)byte.o: $(SRC)byte.cpp $(INC)byte.h
	g++ $(OPC) -c $(SRC)byte.cpp -o $(OBJ)byte.o -I$(INC)
$(LIB)libimagen.a: $(OBJ)codificar.o $(OBJ)byte.o
	ar rvs $(LIB)libimagen.a $(OBJ)codificar.o $(OBJ)byte.o


zip: install clean
	@echo "Empaquetando el proyecto"
	# ../esteganografia es el nombre de la carpeta donde esta todo metido
	zip -r $(ZIP)$(PRJ).zip ../esteganografia/* -i *lena.pgm *.cpp *.h *makefile *.pdf 
install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(ZIP) $(DOC)


# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
mrproper : clean
	@rm -f $(DOC)/* $*
