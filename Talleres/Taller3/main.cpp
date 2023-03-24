#include "Nodo.h"
#include "ArbolArtista.h"
#include "ArbolAlbum.h"
#include "ArbolGenero.h"
#include "ArbolTitulo.h"
#include "Cancion.h"
#include <iostream>
#include <vector>

void correr();
using namespace std;
int main( int argc, char** argv){
    int opc;
    do {

        cout << "--------------------------------------------------------------" << endl;
        cout << "----------- SISTEMA DE BUSQUEDA DE MUSICA -----------" << endl;
        cout << "--------------------------------------------------------------"<<"\nPor favor seleccione una de las siguientes opciones:"<<endl;
        cout << "1. Buscar cancion por titulo."<<endl;
        cout << "2. Buscar cancion por artista."<<endl;
        cout << "3. Buscar cancion por album."<<endl;
        cout << "4. Buscar cancion por genero."<<endl;
        cout << "5. Agregar cancion por titulo."<<endl;
        cout << "6. Agregar cancion por artista."<<endl;
        cout << "7. Agregar cancion por album."<<endl;
        cout << "8. Agregar cancion por genero."<<endl;
        cout << "9. Eliminar cancion."<<endl;
        cout << "10. Salir del programa."<<endl;
        cout << "--------------------------------------------------------------" << endl;
        cin >> opc;
        switch (opc){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                Cancion nuevaCancion;
                nuevaCancion.crearNuevaCancion();
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                break;
            }
            case 9:{
                break;
            }
            default:{
                break;
            }
        }
    }while (opc!=10);
    correr();
    return 0;
}

void correr (){
}