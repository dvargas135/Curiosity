#ifndef _ARBOLGENERO_H_
#define _ARBOLGENERO_H_
#include "Nodo.h"
#include "Cancion.h"
#include <iostream>
#include <string>
using namespace std;

class ArbolGenero{
    public:
        Nodo * raiz;
        ArbolGenero();
        Nodo * CrearNodo(string titulo,string artista,string album, string genero,Nodo * padre);
        void Agregar_cancion(Nodo *&  arbol, Cancion  ca, Nodo * padre);
        void buscar_genero(Nodo * arbol, string genero);
};

#endif
