// TABLA_HASH //
#ifndef _TABLA_HASH
#define _TABLA_HASH

#include <iostream>
#include <list>
using namespace std;

class TablaHash {
    private:
        list<string> *T;
        int B;
        int nElem;
        long calculaHash(string palabra);
    public:
        TablaHash();
        ~TablaHash();
        void insertar(string palabra);
        bool consultar(string palabra);
        void vaciar(void);
        int numElem(void);
        void juanagrama(string palabra);
};

#endif