/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 5 de octubre de 2016, 11:15 AM
 */

#include <iostream>
using namespace std;

#include "Grafo.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Grafo g(10,0.5);
    cout << g.verAdyacencias() << endl;
    for(int i = 0; i < 10; i++)
        cout << "CA(" << i << "): " << g.coeficienteAgrupamiento(i) << endl;
    cout << "camino entre 0 y 7: " << g.existeCamino(0,7) << endl;
    return 0;
}
