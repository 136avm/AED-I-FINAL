#include "NodoTrie.hpp"
using namespace std;

NodoTrie::NodoTrie() {
    sig = nullptr;
    ptr = nullptr;
}

NodoTrie::~NodoTrie() {
    delete sig;
    delete ptr;
}

NodoTrie* NodoTrie::consulta(char letra) {
    NodoTrie* nodo = this->ptr;
    while (nodo != nullptr && nodo->car != letra) {
        nodo = nodo->sig;
    }
    return nodo;
}

void NodoTrie::inserta(char letra, NodoTrie *p) {
    NodoTrie* nodo = new NodoTrie();
    nodo->car = letra;
    nodo->ptr = p;
    if (this->ptr == nullptr) {
        this->ptr = nodo;
    } else {
        NodoTrie* hermano = this->ptr;
        while (hermano->sig != nullptr) {
            hermano = hermano->sig;
        }
        hermano->sig = nodo;
    }
}