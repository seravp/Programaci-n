BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
OPC=-Wall -g
ZIP=./zip/
DOC=./doc/
PRJ=practica2

$(BIN)bloqueLed: $(OBJ)test.o $(LIB)libLed.a
	g++ -o $(BIN)bloqueLed $(OBJ)test.o -L$(LIB) -lLed
$(OBJ)test.o: $(SRC)test.cpp $(INC)bloqueLed.h
	g++ $(OPC) -c $(SRC)test.cpp -o $(OBJ)test.o -I$(INC)
$(OBJ)bloqueLed.o: $(SRC)bloqueLed.cpp $(INC)bloqueLed.h
	g++ $(OPC) -c $(SRC)bloqueLed.cpp -o $(OBJ)bloqueLed.o -I$(INC)
$(LIB)libLed.a: $(OBJ)bloqueLed.o 
	ar rvs $(LIB)libLed.a $(OBJ)bloqueLed.o
clean:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a
zip: install clean
	@echo "Empaquetando el proyecto"
	@zip -r $(ZIP)$(PRJ).zip ./ -i *.cpp *.h *makefile
install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(ZIP)
mrproper : clean
	@rm -f $(DOC)/*
