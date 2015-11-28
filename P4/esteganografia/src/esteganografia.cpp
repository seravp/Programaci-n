#include<iostream>
#include<cstring>
#include<imagen.h>
#include<codificar.h>
#include<byte.h>

using namespace std;

void lee_linea(char c[], int tamanio){
	do{
		cin.getline(c,tamanio);
	} while (c[0] == '\0');
}

void Menu(){
	cout << "------------------------------------" << endl;
	cout << "                MENU                " << endl;
	cout << "------------------------------------" << "\n\n\n";
	cout << "OPCION 1: Ocultar ------> 1" << endl;
	cout << "OPCION 2: Revelar ------> 2" << endl;
	cout << "OPCION 3: Salir --------> 3" << "\n\n";
	cout << "Seleccione una opción." << endl;
}

int main(){
	Imagen imag;
	const int MAXNOMBRE =100;
	char nombre_imagen_E[MAXNOMBRE];
	char nombre_imagen_S[MAXNOMBRE];
	const int MAXTAM=256;
	char mensaje[MAXTAM];
	int opcion;

	Menu();
	cin >> opcion;
	
	switch (opcion){
		case 1: cout << "Introduzca la imagen de entrada" << endl; 
				  //cin >> nombre_imagen_E;
					// cin.ignore()
				  lee_linea(nombre_imagen_E,MAXNOMBRE);
				  cout << "Introduzca la imagen de salida" << endl;
				  //cin >> nombre_imagen_S;
				  lee_linea(nombre_imagen_S,MAXNOMBRE); 
				  cout << "Introduzca el mensaje" << endl;	
				  lee_linea(mensaje,MAXTAM); 

				  //cout << mensaje << endl;
				  //cout << nombre_imagen_E << endl;
				  //cout << nombre_imagen_S << endl;

				  if(imag.leerImagen(nombre_imagen_E)){
					  if(ocultar(imag, mensaje)){
					  	if( !(imag.escribirImagen(nombre_imagen_S)) ){
							cerr << "No se ha podidio escribir la imagen" << endl;
						}else{
							cout << "\n\nOcultando...." << endl;
							cout << "Todo se ha realizado correctamente" << endl;
						}
					  }else{
					  	cerr << "NO se ha podido ocultar" << endl;
					  }
				  }else{
					cerr << "La imagen no se ha podido leer" << endl;
				  }
				  break;
		case 2: cout << "Introduzca la imagen de entrada" << endl; 
				  lee_linea(nombre_imagen_E,MAXNOMBRE);
				  cout << "\n\nRevelando...." << endl;
				  if(imag.leerImagen(nombre_imagen_E)){
				  	if(!(revelar(imag, mensaje, MAXTAM))){
						cerr << "No se ha podido revelar nada" << endl;
					}else{
						cout << "Todo se ha realizado correctamente" << endl;
						cout << "El mensaje oculto en la imagen es: '" << mensaje << "'\n";		
					}
				  }else{
				  	cerr << "La imagen no se ha podido leer" << endl;	
				  }
				  
				  break;
		case 3: return 0; break;
		default : cout << "Opción no válida";
	}

}
