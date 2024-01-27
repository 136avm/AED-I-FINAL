#include <iostream>
#include "DicPalabras.hpp"
using namespace std;

DicPalabras dic;
bool funcionando = true;

string normalizarPalabras(string palabra) {
    string palabraNorm;
    for (unsigned int i=0; i<palabra.length(); i++){
        if (palabra[i]>=char(97) && palabra[i]<=char(122)){
            palabraNorm += palabra[i] - 32;
        }
        else if (palabra[i]==char(0xC3)){
            i++;
            if (palabra[i]==char(0xB1)){
                palabraNorm = palabraNorm + char(0xC3)+char(0x91);
            } else if (palabra[i]==char(0xA1)) {
				palabraNorm += 'A';
			} else if (palabra[i]==char(0xA9)) {
				palabraNorm += 'E';
			} else if (palabra[i]==char(0xAD)) {
				palabraNorm += 'I';
			} else if (palabra[i]==char(0xB3)) {
				palabraNorm += 'O';
			} else if (palabra[i]==char(0xBA)) {
				palabraNorm += 'U';
			} else if (palabra[i]==char(0xBC)) {
				palabraNorm = palabraNorm + char(0xC3)+char(0x9C);
			} else if (palabra[i]==char(0x81)) {
				palabraNorm += 'A';
			} else if (palabra[i]==char(0x89)) {
				palabraNorm += 'E';
			} else if (palabra[i]==char(0x8D)) {
				palabraNorm += 'I';
			} else if (palabra[i]==char(0x93)) {
				palabraNorm += 'O';
			} else if (palabra[i]==char(0x9A)) {
				palabraNorm += 'U';
			} else if (palabra[i]==char(0xA1)) {
				palabraNorm += 'U';
			} else {
				palabraNorm = palabraNorm + char(0xC3) + palabra[i];
			}
        } else {
            palabraNorm = palabraNorm + palabra[i];
        }
    }
    return palabraNorm;
}

void insertar(string comando) {
    int counter = 0;

    while(cin>>comando){
        if (comando == "</insertar>"){
            break;
        }
        dic.insertar(normalizarPalabras(comando));
        counter++;
    }
    cout << "Insertando: " << counter << " palabras" << endl;
    cout << "Total diccionario: " << dic.numElem() << " palabras" << endl;
}

void vaciar() {
    dic.vaciar();
    cout << "Vaciando" << endl;
    cout << "Total diccionario: " << dic.numElem() << " palabras" << endl;
}

void buscar(string palabra) {
    if (dic.consultar(normalizarPalabras(palabra)) == true){
        cout << "Buscando: " << normalizarPalabras(palabra) << " -> Encontrada" << endl; 
    } else {
        cout << "Buscando: " << normalizarPalabras(palabra) << " -> No encontrada" << endl; 
    }
    
}

void partidas(string palabra){
    cout << "Partidas:";
    while(cin>>palabra){
        if(palabra.compare("</partidas>")==0){
            break;
        } else {
            cout << " ";
            cout << normalizarPalabras(palabra);
        }
    }
    cout << endl;
    cout << "No implementado" << endl;
}

void alocado(string palabra){
    cout << "Alocado: " << normalizarPalabras(palabra) << endl;
    cout << "No implementado" << endl;
}

void cesar(string palabra) {
    cout << "César: " << normalizarPalabras(palabra) << endl;
    cout << "No implementado" << endl;
}

void juanagrama(string palabra) {
    cout << "Juanagrama: " << normalizarPalabras(palabra) << " ->";
    dic.juanagrama(normalizarPalabras(palabra));
}

void saco(string palabra){
    int contador = 0;
    cout << "Saco:";
    while(contador < 2){
        contador++;
        cin >> palabra;
        cout << " ";
        cout << normalizarPalabras(palabra);
    }
    cout << endl;
    cout << "No implementado" << endl;
}

void consome(string palabra) {
    cout << "Consomé: " << normalizarPalabras(palabra) << endl;
    cout << "No implementado" << endl;
}

void alarga(string palabra) {
    cout << "Alarga: " << normalizarPalabras(palabra) << " ->";
    palabra = dic.alarga(normalizarPalabras(palabra));
    if (palabra != "") {
        cout << " " << palabra << endl;
    } else {
        cout << endl;
    }
}

void salir() {
    dic.vaciar();
    cout << "Saliendo..." << endl;
    funcionando = false;
}

void interprete(string comando){
    if (comando.compare("<insertar>")==0){
        insertar(comando);
    }
    else if (comando.compare("<vaciar>")==0){
        vaciar();
    }
    else if (comando.compare("<buscar>")==0){
        cin >> comando;
        buscar(comando);
    }
    else if (comando.compare("<partidas>")==0){
        partidas(comando);
    }
    else if (comando.compare("<alocado>")==0){
        cin >> comando;
        alocado(comando);
    }
    else if (comando.compare("<césar>")==0){
        cin >> comando;
        cesar(comando);
    }
    else if (comando.compare("<juanagra>")==0){
        cin >> comando;
        juanagrama(comando);
    }
    else if (comando.compare("<saco>")==0){
        saco(comando);
    }
    else if (comando.compare("<consomé>")==0){
        cin >> comando;
        consome(comando);
    }
    else if (comando.compare("<alarga>")==0){
        cin >> comando;
        alarga(comando);
    }
    else if (comando.compare("<exit>")==0){
        salir();
    }
}

int main() {
    string comando;
    while(funcionando && cin >> comando) {
        interprete(comando);
    }
    return 0;
}