a.out: main.o TablaHash.o DicPalabras.o Arbol.o NodoTrie.o
	g++ main.o TablaHash.o DicPalabras.o Arbol.o NodoTrie.o

TablaHash.o: TablaHash.cpp TablaHash.hpp
	g++ -c TablaHash.cpp

NodoTrie.o: NodoTrie.cpp NodoTrie.hpp
	g++ -c NodoTrie.cpp

Arbol.o: Arbol.cpp Arbol.hpp NodoTrie.hpp
	g++ -c Arbol.cpp

DicPalabras.o: DicPalabras.cpp DicPalabras.hpp TablaHash.hpp Arbol.hpp
	g++ -c DicPalabras.cpp 

main.o: main.cpp DicPalabras.hpp
	g++ -c main.cpp