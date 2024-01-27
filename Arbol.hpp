// ARBOL //
#ifndef ARBOL
#define ARBOL

#include <iostream>
#include "NodoTrie.hpp"
using namespace std;

class Arbol {
    private:
        NodoTrie *raiz;
        int numElementos;
    public:
        Arbol();
        ~Arbol();
        void insertar(string palabra);
        bool consultar(string palabra);
        void vaciar(void);
        int numElem(void);
        string alarga(string prefijo);
};

#endif