#include <iostream>
#include "imagen.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen(){
	nfilas=0;
	ncolumnas=0;
}

Imagen::Imagen(int filas, int columnas){
	if((filas*columnas)<=MAXPIXELS){
		nfilas=filas;
		ncolumnas=columnas;
	}else
		cout << "Tamaño no valido" << endl;
}

void Imagen::crear(int filas, int columnas){
	if((filas*columnas)<=MAXPIXELS){
		nfilas=filas;
		ncolumnas=columnas;
		for (int i =0; i< filas*columnas; i++){
			datos[i]=0;	
		}
	}else
		cout << "Tamaño no valido" << endl;
}

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	int posicion=y*ncolumnas +x;
	if(MAXPIXELS<=posicion){
		cout << "Tamaño no valido" << endl;
	}else
		datos[posicion]=v;
}

byte Imagen::get(int y, int x){
	int posicion=y*ncolumnas +x;
	if(MAXPIXELS<=posicion){
		cout << "Tamaño no valido" << endl;
	}else
		return datos[posicion];
}

void Imagen::setPos(int i, byte v){
	if(MAXPIXELS<=i){
		cout << "Tamaño no valido" << endl;
	}else
		datos[i]=v;
}

byte Imagen::getPos(int i){
	if(MAXPIXELS<=i){
		cout << "Tamaño no valido" << endl;
	}else
		return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
	if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_BINARIO){
		if((nfilas*ncolumnas)<=MAXPIXELS){
			return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);				
		}	
	}else{
		if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_TEXTO){
			if((nfilas*ncolumnas)<=MAXPIXELS){
				return leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);				
			}else{	
				return false;
			}
		}
	}	
}

bool Imagen::escribirImagen(const char nombreFichero[]){
	//return escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
	return escribirPGMTexto (nombreFichero, datos,nfilas,ncolumnas);
}
