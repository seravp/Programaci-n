/**
  * @file codificar.h
  * @brief Codificacion de imagem
  *
  * oculta y revela mensajes en una imagen
  *
  */
#include "imagen.h"

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

bool ocultar(Imagen &imagen, char cadena[]);

// es conveniente usar referencias constante
bool revelar(Imagen imagen, char cadena[], const int tam_max);

#endif

/* Fin Fichero: codificar.h */
