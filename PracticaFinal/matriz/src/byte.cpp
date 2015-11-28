#include <iostream>
#include "byte.h"

using namespace std;

void on(byte &b, int pos){
	unsigned char mask = 1 << pos;
	b = b|mask;
}

/**
@brief apaga el LED @p pos del  @c bloqueLed @p b  
@param b 	el @c bloqueLed cuyo LED se quiere desactivar
@param pos 	el LED dentro de @p b que se quiere desactivar (0 más a la derecha)
*/
void off(byte &b, int pos){
	unsigned char mask = 1 << pos;
	b = b & (~mask);
}

/**
@brief devuelve el estado del LED (encendido = true, apagado = false) en la posición @p pos 
@param b 	el @c bloqueLed que se quiere consultar
@param pos 	el LED dentro de @ b que se quiere consultar (0 más a la derecha)
@retval true 	si el LED en la posición @p pos está encendido
@retval false	si el LED en la posición @p pos está apagado
*/
bool get(byte b, int pos){
	unsigned char mask = 1 << pos;
	if((b & mask) != 0){
		return true;
	}else
		return false;
}

/**
@brief Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada LED
@param b el @c bloqueLed que se quiere imprimir

Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada LED del bloqueLed donde un cero representa que un LED está apagado y un uno que el LED está encendido. Se implementa utilizando la función "get".

Por ejemplo, si en el @c bloqueLed @c b están encendidos los LEDs en posiciones 1 y 3 (0 más a la derecha), @c print(b); mostrará @c 00001010

*/
void print(byte b){
	for(int i =7; i>= 0; i--){
		cout << get(b,i);	
	}
	cout << endl;
}

/**
@brief enciende todos los LEDs
@param b el @c bloqueLed que se quiere encender completamente. 
*/
void encender(byte &b){
	for(int i =0; i< 8; i++){
		on(b,i);	
	}	
}

/**
@brief apaga todos los LEDs
@param b el @c bloqueLed que se quiere apagar completamente. 
*/
void apagar(byte &b){
	for(int i =0; i< 8; i++){
		off(b,i);	
	}	
}

/**
@brief enciende los LEDs según la configuración de @p v
@param b el @c bloqueLed sobre el que se quiere actuar 
@param v vector de 8 elementos que contiene la secuencia de LEDS que se quieren asignar

Asigna a @p b la configuración de LEDs contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
*/
void asignar(byte &b, const bool v[]){
	for(int i =0; i< 8; i++){
		if(v[i]){
			on(b,i);
		}else
			off(b,i);	
	}	
}

/**
@brief recupera la configuración de todos los LED
@param b el @c bloqueLed que se quiere consultar
@param v vector de 8 elementos que contendrá el estado de cada uno de los LEDs de @ b

Vuelca en @p v la configuración de LEDs contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
*/
void volcar(byte b, bool v[]){
	for(int i =0; i< 8; i++){
		if(get(b,i)){
			v[i]=true;
		}else
			v[i]=false;	
	}
}

/**
@brief devuelve las posiciones de los LEDs encendidos
@param b el @c bloqueLed que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posición de los LEDs de @p b que están encendidos
@param cuantos número de LEDs encendidos en @p b (número de elementos usados en el vector @p posic)
*/
void encendidos(byte b, int posic[], int &cuantos){
	cuantos=0;
	
	for(int i =0; i< 8; i++){
		if(get(b,i)){
			posic[cuantos]=i;
			cuantos++;
		}
	}
}
