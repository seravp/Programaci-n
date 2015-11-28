#include <iostream>
#include "imagen.h"
#include "pgm.h"

using namespace std;

Imagen::Imagen(){
	nfilas=0;
	ncolumnas=0;
	datos=NULL;
}

Imagen::Imagen(int filas, int columnas){
		nfilas=filas;
		ncolumnas=columnas;
		
			//datos= new byte[nfilas*ncolumnas];
		datos=0;
		crear(nfilas,ncolumnas);
}

void Imagen::crear(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;
	
	if(datos==NULL){
		datos= new byte[nfilas*ncolumnas];
	}else{ 
		delete [] datos;
		datos= new byte[nfilas*ncolumnas];
	}

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
	if(posicion < nfilas*ncolumnas && posicion >=0)
		datos[posicion]=v;
	else
		cerr << "Tamaño no valido" << endl;		
}

byte Imagen::get(int y, int x){
	int posicion=y*ncolumnas +x;
	if(posicion < nfilas*ncolumnas && posicion >=0)
		return datos[posicion];
	else{
		cerr << "Tamaño no valido" << endl;
		return 0;
		}		
}

void Imagen::setPos(int i, byte v){
	if(i < nfilas*ncolumnas  && i >=0)
		datos[i]=v;
	else
		cerr << "Tamaño no valido" << endl;	
		
}

byte Imagen::getPos(int i){
	if(i < nfilas*ncolumnas  && i >=0)
		return datos[i];
	else{
		cerr << "Tamaño no valido" << endl;
		return 0;
	}		
}

bool Imagen::leerImagen(const char nombreFichero[]){
	if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_BINARIO){
			crear(nfilas,ncolumnas);
			return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);				
	}else{
		if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_TEXTO){
			crear(nfilas,ncolumnas);
			return leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);				
		}else
			return false;
	}	
}

bool Imagen::escribirImagen(const char nombreFichero[]){
	//return escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
	return escribirPGMTexto (nombreFichero, datos,nfilas,ncolumnas);
}

Imagen::~Imagen(){
	//cout << "destructor" << endl;
	if(datos==NULL){
		cerr <<"No se realiza ninguna operacion"<< endl;
	}else{
		delete [] datos;
	}
	ncolumnas=0;
	nfilas=0;
}
/*
void Imagen::destruir(){
	if(datos==NULL){
		cerr <<"No se realiza ninguna operacion"<< endl;
	}else{
		delete [] datos;
	}
	ncolumnas=0;
	nfilas=0;
	
}
*/
Imagen::Imagen(const Imagen &ima){
	(*this).nfilas=ima.nfilas;
	(*this).ncolumnas=ima.ncolumnas;
	(*this).datos=new byte[nfilas*ncolumnas];
	for(int i=0; i < nfilas*ncolumnas; i++){
		(*this).datos[i]=ima.datos[i];
	}
}

Imagen& Imagen::operator=(const Imagen &ima){
	if(&ima!=this){
		if(datos!=0){
		delete [] (*this).datos;
		}
		(*this).nfilas=ima.nfilas;
		(*this).ncolumnas=ima.ncolumnas;
		(*this).datos=new byte[nfilas*ncolumnas];
		
		for(int i=0; i < nfilas*ncolumnas; i++){
			(*this).datos[i]=ima.datos[i];
		}
	}
	return *this;
}

void Imagen::rotar(){
	byte *paux;
	Imagen imaux(ncolumnas,nfilas);

	for(int i=0;i< ncolumnas; i++){
		for (int j=0; j < nfilas; j++){
			imaux.set(i,nfilas-j-1,get(j,i));		
		}
	}

	paux=datos;
	datos=imaux.datos;
	imaux.datos=paux;
	paux=0;
	nfilas=imaux.nfilas;
	ncolumnas=imaux.ncolumnas;
}


void Imagen::rotacion(int grados, bool sentidoHorario){
		int rotaciones;
		if(sentidoHorario){
			rotaciones =grados/90;
			for(int i=0; i < rotaciones; i++){
				rotar();
			}	
		}else{
			rotaciones =4-(grados/90);
						
			for(int i=0; i < rotaciones; i++){
				rotar();
			}		
		}
}

//Parte opcional

Imagen Imagen::operator+(const Imagen &ima) const{
	int filmayor=((this->nfilas) > (ima.nfilas)) ? this->nfilas:ima.nfilas;
	int colmayor=(this->ncolumnas) + ima.ncolumnas;
	Imagen nueva(filmayor,colmayor);

	for(int i=0; i<this->nfilas;i++){
		for(int j=0; j<this->ncolumnas; j++){
			nueva.datos[i*nueva.ncolumnas+j]= this->datos[i*(*this).ncolumnas+j];
		}
		}
	for(int i=0; i<ima.nfilas; i++){
		for(int j=0; j<ima.ncolumnas;j++){
			nueva.datos[i*nueva.ncolumnas+j+this->ncolumnas]=ima.datos[i*ima.ncolumnas+j];
		}
	}
	return nueva;
}			

