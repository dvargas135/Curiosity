#ifndef _ARBOLALBUM_H_
#define _ARBOLALBUM_H_
#include "Nodo.h"
#include "Cancion.h"
#include <iostream>
#include <string>
using namespace std;
class ArbolAlbum{
    public:
        Nodo * raiz;
        ArbolAlbum();
        Nodo * CrearNodo(string titulo,string artista,string album, string genero,Nodo * padre);
        void Agregar_cancion(Nodo *&  arbol, Cancion  ca, Nodo * padre);
        void buscar_album(Nodo * arbol, string album);
};

#endif
