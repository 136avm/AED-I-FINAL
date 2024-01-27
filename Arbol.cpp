#include "Arbol.hpp"
using namespace std;

int longitudReal(string palabra){
    int longitud=0;
    int i=0;
    while(i<palabra.length()){
        if(palabra[i]=='\xC3'){
            i++;
        }
        i++;
        longitud++;
    }
    return longitud;
}

Arbol::Arbol() {
    raiz = new NodoTrie();
    numElementos = 0;
}

Arbol::~Arbol() {
    delete raiz;
}

void Arbol::insertar(string palabra) {
    NodoTrie* nodo = raiz;
    for (char letra : palabra) {
        NodoTrie* siguienteNodo = nodo->consulta(letra);
        if (siguienteNodo == nullptr) {
            nodo->inserta(letra, nullptr);
            siguienteNodo = nodo->consulta(letra);
        }
        nodo = siguienteNodo;
    }
    if (nodo->consulta('$') == nullptr) {
        nodo->inserta('$', nullptr);
        numElementos++;
    }
}

bool Arbol::consultar(string palabra) {
    NodoTrie* nodo = raiz;
    for (char letra : palabra) {
        nodo = nodo->consulta(letra);
        if (nodo == nullptr) {
            return false;
        }
    }
    return nodo->consulta('$') != nullptr;
}

void Arbol::vaciar() {
    delete raiz;
    raiz = new NodoTrie();
    numElementos = 0;
}

int Arbol::numElem() {
    return numElementos;
}

string Arbol::alarga(string prefijo) {
    string palabraMasLarga = "";
    NodoTrie* nodo = raiz;
    for (char letra : prefijo) {
        nodo = nodo->consulta(letra);
        if (nodo == nullptr) {
            return "";
        }
    }
    if (nodo->consulta('$') != nullptr) {
        palabraMasLarga = prefijo;
    }
    for (NodoTrie* hijo = nodo->ptr; hijo != nullptr; hijo = hijo->sig) {
        string palabra = prefijo + hijo->car;
        string palabraAlargada = alarga(palabra);
        if (longitudReal(palabraAlargada) > longitudReal(palabraMasLarga) || (longitudReal(palabraAlargada) == longitudReal(palabraMasLarga) && palabraAlargada < palabraMasLarga)) {
            palabraMasLarga = palabraAlargada;
        }
    }
    if (!palabraMasLarga.empty() && palabraMasLarga.back() == '$') {
        palabraMasLarga.pop_back();
    }
    return palabraMasLarga;
}