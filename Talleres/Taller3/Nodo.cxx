#include "Nodo.h"

Nodo::Nodo(string titulo,string artista,string album, string genero,Nodo * padre){
    Cancion *can=new Cancion(titulo,artista,album,genero);
    this->Dato=can;
    this->der=NULL;
    this->izq=NULL;
    this->padre=padre;
}
