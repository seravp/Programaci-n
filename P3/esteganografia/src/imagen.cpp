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
	nfilas=filas;
	ncolumnas=columnas;
	for (int i =0; i< filas*columnas; i++){
		datos[i]=0;	
	}
}

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	int posicion=y*ncolumnas +x;

	datos[posicion]=v;
}

byte Imagen::get(int y, int x){
	int posicion=y*ncolumnas +x;
	return datos[posicion];
}

void Imagen::setPos(int i, byte v){
	datos[i]=v;
}

byte Imagen::getPos(int i){
	return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
	if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_BINARIO){
		if((nfilas*ncolumnas)<=MAXPIXELS){
			return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);				
		}	
	}else{
		return false;
	}	
}

bool Imagen::escribirImagen(const char nombreFichero[]){
	return escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
}
