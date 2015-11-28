#include <iostream>
#include "imagen.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen(){
	nfilas=0;
	ncolumnas=0;
}

Imagen::Imagen(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;

	if (datos==NULL){
		datos=new byte [filas*columnas];
	}else{
		delete [] datos;
		datos=new byte [filas*columnas];
	}
}

void Imagen::crear(int filas, int columnas){
	if((filas*columnas)<=nfilas*ncolumnas){
		if (datos==NULL){
			datos=new byte [filas*columnas];
		}else{
			delete [] datos;
			datos=new byte [filas*columnas];
		}

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
	int posicion=y * ncolumnas +x;
	if ( posicion <=  nfilas*ncolumnas) {
		datos[posicion]=v;
	}else
		cout << "Tamaño no valido" << endl;
		
}

byte Imagen::get(int y, int x){
	int posicion=y*ncolumnas +x;
	if ( posicion <=  nfilas*ncolumnas) {
		return datos[posicion];
	}else
		cout << "Tamaño no valido" << endl;
}

void Imagen::setPos(int i, byte v){
	if(i <=(nfilas * ncolumnas)){
		datos[i]=v;	
	}else
		cout << "Tamaño no valido" << endl;
		
}

byte Imagen::getPos(int i){
	if(i <=(nfilas*ncolumnas)){
		return datos[i];
	}else
		cout << "Tamaño no valido" << endl;
}

bool Imagen::leerImagen(const char nombreFichero[]){
	if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_BINARIO){
		if((nfilas*ncolumnas)<=((*this).nfilas *(*this).ncolumnas)){
			return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);				
		}	
	}else{
		if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_TEXTO){
			if((nfilas*ncolumnas)<=((*this).nfilas *(*this).ncolumnas)){
				return leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);				
			}else{	
				return false;
			}
		}else{
			return false;	//esto se añadio despues;	
		}
	}	
}

bool Imagen::escribirImagen(const char nombreFichero[]){
	//return escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
	return escribirPGMTexto (nombreFichero, datos,nfilas,ncolumnas);
}

void Imagen::destruir(){
	if(datos==NULL){
		cout <<"No se realiza ninguna operacion"<< endl;
	}else{
		delete [] datos;
	}
	ncolumnas=0;
	nfilas=0;
}

void Imagen::rotar(){
	cout << "Entra en rotar" << endl;
	int tope=nfilas*ncolumnas;
	byte *matrizAUX;
	matrizAUX=NULL;
	matrizAUX= new byte [tope];
	int contador = nfilas-1;
	for(int i =0;i < tope;i++){
		for (int j=0;j < tope; j++){
			matrizAUX[contador*nfilas+j]=datos[i*ncolumnas+j];	
		}
		contador--;
	}
	delete [] datos;
	datos=new byte [tope];
	datos=matrizAUX;
	delete [] matrizAUX;
	cout << "Sale de rotar" << endl;
}

void Imagen::rotacion(int grados, bool sentidoHorario){
	cout << "Entra en rotacion" << endl;
	int rotaciones;
	if(sentidoHorario){
		rotaciones =grados/90;
		for(int i=0; i < rotaciones; i++){
			rotar();
		}	
	}else{
		rotaciones =grados/90;
		for(int i=0; i < rotaciones; i++){
			rotar();
		}		
	}
	cout << "Sale de rotacion" << endl;
}
