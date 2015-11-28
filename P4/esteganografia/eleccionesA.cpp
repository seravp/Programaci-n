#include <iostream>
#include <fstream>
using namespace std;

int main(){
int numero_parejas;
char partido;
int votos;
int opcion;
int recuento[8]= {0};


//ifstream fichero("eleccionesB.txt");
ifstream fichero;
cin >> opcion;
if (opcion == 1){
	fichero.open("eleccionesA.txt");
}else
	if(opcion == 2){
		fichero.open("eleccionesB.txt");
	}

if(!fichero){
		cerr << "No se ha podido abrir el fichero";
	}else{	
	fichero >> numero_parejas;

	for (int i =0; i < numero_parejas; i++){
		fichero >> partido;
		fichero >> votos;
		if(!fichero){
			cerr << "No se han podido leer los datos";
		}else{
			recuento[partido -'A']+= votos;
		}		
	}
	fichero.close();
}

cout << "El partido A ha obtenido " << recuento[0] << " votos." << endl;
cout << "El partido B ha obtenido " << recuento[1] << " votos." << endl;
cout << "El partido C ha obtenido " << recuento[2] << " votos." << endl;
cout << "El partido D ha obtenido " << recuento[3] << " votos." << endl;
cout << "El partido E ha obtenido " << recuento[4] << " votos." << endl;
cout << "El partido F ha obtenido " << recuento[5] << " votos." << endl;
cout << "El partido G ha obtenido " << recuento[6] << " votos." << endl;
cout << "El partido H ha obtenido " << recuento[7] << " votos." << endl;

}
