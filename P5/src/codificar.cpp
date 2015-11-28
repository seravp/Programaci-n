#include <iostream>
#include <cstring>
#include "codificar.h"
#include "imagen.h"
#include "byte.h"

using namespace std;

bool ocultar(Imagen &imagen, char cadena[]){
	int tama_ima = imagen.filas() * imagen.columnas();
	int tama_mens=strlen(cadena);
	int contador=0;

	if( (tama_mens +1) *8 > tama_ima){
		cerr << "La cadena es demasiado larga" << endl; // cerr
		return false;
	}else{
		for (int i =0;  i <= tama_mens; i++){
			for(int j=7; j>=0; j--){
				bool bit = get(cadena[i],j);
				byte byte_imagen = imagen.getPos(contador);
				if(bit){
					on(byte_imagen,0);
					imagen.setPos(contador,byte_imagen);
				}else{
					off(byte_imagen,0);
					imagen.setPos(contador,byte_imagen);
				}
				contador++;
			}
		}
		return true;		
	}
}

bool revelar(Imagen imagen, char cadena[], const int tam_max){
	int tama_ima = imagen.filas() * imagen.columnas();	
	int tama_mens=strlen(cadena);
	bool fin=false;
	int contador=0;

	for (int i=0; i< tam_max && i< tama_ima && !fin; i++){
		for (int j=7; j>=0; j--){
			byte byte_imagen = imagen.getPos(contador);
			if(get(byte_imagen,0)){
				unsigned char aux= cadena[i];
				on(aux,j);
				cadena[i]=aux;		
			}else{
				unsigned char aux= cadena[i];
				off(aux,j);
				cadena[i]=aux;	
			}
			contador++;
		}
		if (cadena[i]=='\0')
			fin =true;
	}
	return fin;	
}


