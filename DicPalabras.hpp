// DICPALABRAS //
#ifndef _DIC_PALABRAS
#define _DIC_PALABRAS

#include <list>
#include <iostream>
#include "TablaHash.hpp"
#include "Arbol.hpp"
using namespace std;

class DicPalabras {
    private:
        TablaHash tabla;
        Arbol arbol;
    public:
        DicPalabras();
        void vaciar();
        void insertar(string palabra);
        bool consultar(string palabra);
        int numElem();
        void juanagrama(string palabra);
        string alarga(string prefijo);
};

#endif