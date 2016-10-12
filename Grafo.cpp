/* 
 * File:   Grafo.cpp
 * Author: alan.calderon
 * 
 * Created on 5 de octubre de 2016, 11:16 AM
 */

#include "Grafo.h"

Grafo::Grafo(int N, double beta) : N(N) {
    int filas = N;
    int columnas = N;
    int tam = N * N;
    double prb;
    matrizAdyacencias = new int[tam];
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++){
            prb = distribution(generator);
            if(prb <= beta)
                matrizAdyacencias[i*N+j] = 1;
            else
                matrizAdyacencias[i*N+j] = 0;
        }
}

Grafo::~Grafo() {
    delete[] matrizAdyacencias;
}

double Grafo::coeficienteAgrupamiento(int nodo) {
    double coef = 0.0;
    int adyEntreSi = 0;
    int cntAdy = 0;
    int pos; int ady;
    int* arrAdy; //Un arreglo unidimensional para guardar los adyacentes de nodo
    for(int j = 0; j < N; j++){
        if(matrizAdyacencias[nodo*N+j] == 1){
            cntAdy++;
        }
    }
    arrAdy = new int[cntAdy];
    for(int j = 0; j < N; j++){
        if(matrizAdyacencias[nodo*N+j] == 1){
            arrAdy[pos] = j;
            pos++;
        }
    }
    for(int i = 0; i < cntAdy-1; i++){
        for(int j = i+1; j < cntAdy; j++){
            if(matrizAdyacencias[arrAdy[i]*N+arrAdy[j] == 1])
                adyEntreSi++;
        }
    }
    coef = (2.0*adyEntreSi) / (cntAdy*(cntAdy-1));
    return coef;
}

string Grafo::existeCamino(int nodoInicio, int nodoDestino) {
    stringstream fs; // construye una instancia de flujo de salida
    int nvoNodoInicio;
    //La idea con el algoritmo de abajo es pasar al flujo de salida los nodos por medio de recursividad.
    if(matrizAdyacencias[nodoInicio*N+nodoDestino] == 1){
        fs << '"';
        fs << '(';
        fs << nodoInicio;
        fs << ',';
        fs << nodoDestino;
        fs << ')';
    }else {
        fs << nodoInicio;
        fs << ',';
        for(int i = 0; i < N; i++){
            if(matrizAdyacencias[nodoInicio*N+i] == 1){
                nvoNodoInicio = i;
                Grafo::existeCamino(i,nodoDestino);
            }else{
                fs << '"';
                fs << '"';
            }
        }
        fs << ')';
    }
    return fs.str();
}

string Grafo::verAdyacencias(){
    stringstream fs; // construye una instancia de flujo de salida
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            fs << matrizAdyacencias[i*N+j];
        fs << endl;
    }
    return fs.str();
}