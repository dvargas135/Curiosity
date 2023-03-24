#ifndef _ARBOLARTISTA_H_
#define _ARBOLARTISTA_H_
#include "Nodo.h"
#include "Cancion.h"
#include <iostream>
#include <string>
using namespace std;
class ArbolArtista{
    public:
        Nodo * raiz;
        ArbolArtista();  
        Nodo * CrearNodo(string titulo,string artista,string album, string genero,Nodo * padre);
        void Agregar_cancion(Nodo *&  arbol, Cancion  ca, Nodo * padre);
        void eliminar_cancion(Nodo * arbol, string nombre,string artista,string album,string genero);
        void eliminar(Nodo * elim);
        void remplazar(Nodo * arbol,Nodo * nuevo);
        void destruir(Nodo * eliminar);
        Nodo * minimo(Nodo * arbol);
        void buscar_artista(Nodo * arbol, string artista);

};

#endif