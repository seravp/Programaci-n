
BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
ZIP=./zip/
DOC=./doc/
PRJ=prueba
OPC=-Wall -g

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)prueba 

$(BIN)prueba:  $(OBJ)prueba.o $(OBJ)imagen.o $(OBJ)pgm.o $(LIB)libimagen.a
	g++ -o $(BIN)prueba  $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)prueba.o -L$(LIB) -limagen
$(OBJ)prueba.o: $(SRC)prueba.cpp $(INC)pgm.h $(INC)imagen.h 
	g++ $(OPC) -c $(SRC)prueba.cpp -o $(OBJ)prueba.o -I$(INC)
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
	zip -r $(ZIP)$(PRJ).zip ../prueba/* -i *lena.pgm *.cpp *.h *makefile *.pdf 
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
