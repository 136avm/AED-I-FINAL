#include "TablaHash.hpp"
#include <algorithm>
using namespace std;

const int TAM_INIT = 100000;

TablaHash::TablaHash() {
    T = new list<string>[TAM_INIT];
    B = TAM_INIT;
    nElem = 0;
}

TablaHash::~TablaHash() {
    delete[] T;
}

long TablaHash::calculaHash(string palabra) {
    string palabraOrdenada = palabra;
    sort(palabraOrdenada.begin(), palabraOrdenada.end());

    unsigned long indice = 2166136261;
    for (char c: palabraOrdenada) {
        indice = indice*16777619 ^ static_cast<int>(c);
    }
    indice = indice % B;
    return indice;
}

void TablaHash::insertar(string palabra) {
    long indice = calculaHash(palabra);
    list<string>& lista = T[indice];
    list<string>::iterator EA = lista.begin();

    while(EA != lista.end() && *EA < palabra) {
        EA++;
    }
    if(EA == lista.end() || *EA != palabra) {
        lista.insert(EA, palabra);
        nElem++;
    }
}

bool TablaHash::consultar(string palabra) {
    long indice = calculaHash(palabra);
    list<string>& lista = T[indice];
    list<string>::iterator EA = lista.begin();

    while(EA != lista.end() && *EA < palabra) {
        EA++;
    }
    if (EA != lista.end() && *EA == palabra){
        return true;
    } else {
        return false;
    }
}

void TablaHash::vaciar(void) {
    for (int i=0; i<B; i++) {
        T[i].clear();
    }
    nElem=0;
}

int TablaHash::numElem(void) {
    return nElem;
}

void TablaHash::juanagrama(string palabra) {
    string palabraOrdenada = palabra;
    sort(palabraOrdenada.begin(), palabraOrdenada.end());

    string anagrama = "";
    for (string pal: T[calculaHash(palabra)]) {
        if (pal.length() == palabra.length()) {
            string palOrdenada = pal;
            sort(palOrdenada.begin(), palOrdenada.end());
            if (palOrdenada == palabraOrdenada) {
                if (anagrama > pal || anagrama == "") {
                    anagrama = pal;
                }
            }
        }
    }

    if (anagrama != "") {
        cout << " " << anagrama;
    }
    cout << endl;
}