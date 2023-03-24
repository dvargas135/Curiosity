#ifndef _ARBOLTITULO_H_
#define _ARBOLTITULO_H_
#include "Nodo.h"
#include "Cancion.h"
#include <iostream>
#include <string>
using namespace std;
class ArbolTitulo{
    public:
        Nodo * raiz;
        ArbolTitulo();
        Nodo * CrearNodo(string titulo,string artista,string album, string genero,Nodo * padre);
        void Agregar_cancion(Nodo *&  arbol, Cancion  ca, Nodo * padre);
        void buscar_titulo(Nodo * arbol, string Nombre);
};
#endif
