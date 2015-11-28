#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
#include <cmath>

using namespace std;
class Punto {
private:
    double x; ///< coordenada x del punto
    double y; ///< coordenada y del punto

public:
    Punto(); ///< constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); ///< constructor. Inicializa un punto con dos valores x y
    double getX(); ///< Devuelve la coordenada x del punto
    double getY(); ///< Devuelve la coordenada y del punto
    void setX(double newXValue); ///< Asigna el valor newXValue a la coordenada x del punto
    void setY(double newYValue); ///< Asigna el valor newYValue a la coordenada y del punto
    void escribir(); ///<  Escribe un punto en formato (x,y)
    void leer(); ///< // Lee un punto en el formato (x,y)
};

double distancia(Punto p1, Punto p2);
Punto puntoMedio(Punto p1, Punto p2);

#endif
