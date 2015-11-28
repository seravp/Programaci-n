BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
OPC=-Wall -g
ZIP=./zip/
PRJ=practica1

$(BIN)central: $(OBJ)central.o $(LIB)libformas.a
	g++ -o $(BIN)central $(OBJ)central.o -L$(LIB) -lformas
$(OBJ)central.o: $(SRC)central.cpp $(INC)circulo.h $(INC)punto.h
	g++ $(OPC) -c $(SRC)central.cpp -o $(OBJ)central.o -I$(INC)
$(OBJ)punto.o: $(SRC)punto.cpp $(INC)punto.h
	g++ $(OPC) -c $(SRC)punto.cpp -o $(OBJ)punto.o -I$(INC)
$(OBJ)circulo.o: $(SRC)circulo.cpp $(INC)circulo.h
	g++ $(OPC) -c $(SRC)circulo.cpp -o $(OBJ)circulo.o -I$(INC)
$(LIB)libformas.a: $(OBJ)circulo.o $(OBJ)punto.o
	ar rvs $(LIB)libformas.a $(OBJ)circulo.o $(OBJ)punto.o
clean:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
zip: install clean
	@echo "Empaquetando el proyecto"
	@zip -r $(ZIP)$(PRJ).zip ./ -i *.cpp *.h *makefile
install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(ZIP)
