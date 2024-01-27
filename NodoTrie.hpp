// NODO_TRIE //
#ifndef _NODO_TRIE
#define _NODO_TRIE

#include <iostream>
using namespace std;

class NodoTrie {
    friend class Arbol;
    private:
        char car;
        NodoTrie *sig, *ptr;
    public:
        NodoTrie();
        ~NodoTrie();
        NodoTrie* consulta(char letra);
        void inserta(char letra, NodoTrie *p);
};

#endif