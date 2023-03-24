#ifndef _NODO_H_
#define _NODO_H_
#include "Cancion.h"
#include "ArbolArtista.h"
#include <iostream>
class Nodo{
    public:
        Cancion *Dato;
        Nodo *der;
        Nodo *izq;   
        Nodo * padre;
        Nodo(string titulo,string artista,string album, string genero,Nodo * padre);    
};
#endif