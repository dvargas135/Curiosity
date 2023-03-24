#ifndef _CANCION_H_
#define _CANCION_H_
#include "ArbolArtista.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Cancion{
    private:
        string titulo;
        string artista;
        string album;
        string genero;
    public:
        Cancion();
        Cancion(string titulo,string artista, string album, string genero);
        string gettitulo();
        string getartista();
        string getalbum();
        string getgenero();    
        void crearNuevaCancion();
        vector<string> leerArchivo();
};

#endif 