/* 
 * File:   Grafo.h
 * Author: alan.calderon
 *
 * Created on 5 de octubre de 2016, 11:16 AM
 */

#ifndef GRAFO_H
#define	GRAFO_H


#include <string>
#include <sstream>
#include <random>
#include <chrono>
using namespace std;

class Grafo {
public:
    // Esta clase representa un grafo con nodos identificados del 0 al N-1.
    
    // REQ: beta < 1.0.
    // EFE: construye un grafo con N nodos y probabilidad beta de adyacencia
    //      entre cualesquiera dos nodos.
    Grafo(int N, double beta);
    
    // EFE: retorna al control del sistema operativo la memoria ocupada por *this.
    virtual ~Grafo();
    
    // REQ: 0 <= nodo <= N - 1.
    // EFE: calcula el coeficiente de agrupamiento de nodo de acuerdo con la 
    //      definición usada en el laboratorio.
    double coeficienteAgrupamiento(int nodo);
    
    // REQ: (0 <= nodoInicio <= N - 1)&&(0 <= nodoDestino <= N - 1).
    // EFE: retorna una hilera como “0,4,1,7” cuando nodoInicio == 0 y nodoDestino == 7.
    //      retorna una hilera vacía "" cuando no existe ningún camino entre los nodos.
    string existeCamino(int nodoInicio, int nodoDestino);
    
	// EFE: saca por consola las adyacencias de cada nodo.
    string verAdyacencias();
private:
    
    int N; // representa la cantidad de nodos.
    int* matrizAdyacencias; 
        // Representa la matriz de adyacencias. 1 = SÍ hay adyacencia, 0 NO.
        // OJO: arreglo de una sola dimensión: matBits[f][c] --> matBits[f*N+c]. 
};

#endif	/* GRAFO_H */