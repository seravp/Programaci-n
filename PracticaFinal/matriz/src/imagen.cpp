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
		
		//datos= new byte* [nfilas];
		//datos[0]= new byte[nfilas*ncolumnas];
		
	//for(int i=1; i<nfilas; i++){
		//datos[i]=datos[i-1] + ncolumnas;
		datos=0;
		crear(nfilas,ncolumnas);	
}

void Imagen::crear(int filas, int columnas){
	nfilas=filas;
	ncolumnas=columnas;
	
	if(datos==NULL){
		datos= new byte* [nfilas];
		datos[0]= new byte[nfilas*ncolumnas];
	}else{ 
		delete [] datos[0];
		delete [] datos;
		datos= new byte* [nfilas];
		datos[0]= new byte[nfilas*ncolumnas];
	}

	for(int i=1; i<nfilas; ++i){
		datos[i]=datos[i-1] + ncolumnas;
	}

	for(int i =0; i< nfilas*ncolumnas; i++){
		datos[0][i]=0;
	}
}

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	if(y>=0 && y<=nfilas && x>=0 && x<=ncolumnas)
		datos[y][x]=v;
	else
		cerr << "Tamaño no valido" << endl;		
}

byte Imagen::get(int y, int x){
	if(y>=0 && y<=nfilas && x>=0 && x<=ncolumnas)
		return datos[y][x];
	else{
		cerr << "Tamaño no valido" << endl;	
		return 0;
	}	
}

void Imagen::setPos(int i, byte v){
	if(i < nfilas*ncolumnas  && i >=0)
		datos[0][i]=v;
	else
		cerr << "Tamaño no valido" << endl;	
		
}

byte Imagen::getPos(int i){
	if(i < nfilas*ncolumnas  && i >=0)
		return datos[0][i];
	else{
		cerr << "Tamaño no valido" << endl;	
		return 0;
	}	
}



bool Imagen::leerImagen(const char nombreFichero[]){
	if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_BINARIO){
			crear(nfilas,ncolumnas);
			return leerPGMBinario(nombreFichero,datos[0],nfilas,ncolumnas);				
	}else{
		if(infoPGM(nombreFichero,nfilas,ncolumnas)==IMG_PGM_TEXTO){
			crear(nfilas,ncolumnas);
			return leerPGMTexto(nombreFichero,datos[0],nfilas,ncolumnas);				
		}else
			return false;
	}	
}

bool Imagen::escribirImagen(const char nombreFichero[]){
	//return escribirPGMBinario (nombreFichero, datos,nfilas,ncolumnas);
	return escribirPGMTexto (nombreFichero, datos[0],nfilas,ncolumnas);
}

Imagen::~Imagen(){
	//cout << "destructor" << endl;
	if(datos==NULL){
		cerr <<"No se realiza ninguna operacion"<< endl;
	}else{
		delete[] datos[0];
		delete[] datos;
	}
	ncolumnas=0;
	nfilas=0;
}

/*
void Imagen::destruir(){
	if(datos==NULL){
		cerr <<"No se realiza ninguna operacion"<< endl;
	}else{
		delete[] datos[0];
		delete [] datos;
	}
	ncolumnas=0;
	nfilas=0;
	
}
*/
Imagen::Imagen(const Imagen &ima){
	(*this).nfilas=ima.nfilas;
	(*this).ncolumnas=ima.ncolumnas;
	(*this).datos=new byte*[nfilas];
	(*this).datos[0]=new byte[nfilas*ncolumnas];
	for(int i=1;i<nfilas;++i){
		datos[i]=datos[i-1]+ncolumnas;
	}
	for(int i=0; i < nfilas*ncolumnas; i++){
		(*this).datos[0][i]=ima.datos[0][i];
	}
}

Imagen& Imagen::operator=(const Imagen &ima){
	if(&ima!=this){
		if(datos!=0){
		delete [] (*this).datos[0];
		delete [] (*this).datos;
		}
		(*this).nfilas=ima.nfilas;
		(*this).ncolumnas=ima.ncolumnas;
		(*this).datos=new byte*[nfilas];
		(*this).datos[0]=new byte[nfilas*ncolumnas];
		for(int i=1;i<nfilas;++i){
			datos[i]=datos[i-1]+ncolumnas;
		}
		
		for(int i=0; i < nfilas*ncolumnas; i++){
			(*this).datos[0][i]=ima.datos[0][i];
		}
	}
	return *this;
}

void Imagen::rotar(){
	byte **paux;
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
//PARTE OPCIONAL

Imagen Imagen::operator+(const Imagen &ima) const{
	int filmayor=((this->nfilas) > (ima.nfilas)) ? this->nfilas:ima.nfilas;
	int colmayor=(this->ncolumnas) + ima.ncolumnas;
	Imagen nueva(filmayor,colmayor);

	for(int i=0; i<this->nfilas;i++){
		for(int j=0; j<this->ncolumnas; j++){
			nueva.datos[i][j]= this->datos[i][j];
		}
		}
	for(int i=0; i<ima.nfilas; i++){
		for(int j=0; j<ima.ncolumnas;j++){
			nueva.datos[i][j+this->ncolumnas]=ima.datos[i][j];
			}
			}
	return nueva;
}		
