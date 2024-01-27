#include "DicPalabras.hpp"
#include "TablaHash.hpp"
#include "Arbol.hpp"
using namespace std;

DicPalabras::DicPalabras(){
    TablaHash tabla = TablaHash();
    Arbol arbol = Arbol();
}

void DicPalabras::vaciar(){
    tabla.vaciar();
    arbol.vaciar();
}

void DicPalabras::insertar(string palabra){
    tabla.insertar(palabra);
    arbol.insertar(palabra);
}

bool DicPalabras::consultar(string palabra){
    //return tabla.consultar(palabra);
    return arbol.consultar(palabra);
}

int DicPalabras::numElem(){
    //return tabla.numElem();
    return arbol.numElem();
}

void DicPalabras::juanagrama(string palabra) {
    tabla.juanagrama(palabra);
}

string DicPalabras::alarga(string prefijo) {
    return arbol.alarga(prefijo);
}