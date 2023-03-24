#include "ArbolAlbum.h"

ArbolAlbum::ArbolAlbum(){
    raiz=NULL;
}

Nodo * ArbolAlbum::CrearNodo(string titulo,string artista,string album, string genero, Nodo * padre){
	Nodo * nuevo= new Nodo(titulo,artista,album,genero,padre);
	return nuevo;
}

void ArbolAlbum::Agregar_cancion(Nodo *&  arbol, Cancion  can, Nodo * padre){
	if(arbol==NULL){
		Nodo * nuevo= CrearNodo(can.gettitulo(),can.getartista(),can.getalbum(),can.getgenero(),padre);
		arbol=nuevo;
		cout<<"Dato guardado"<<endl;
	}
    else{
        char primera= can.getartista()[0];
        char valorraiz=arbol->Dato->getartista()[0];
        if(primera>valorraiz){
            Agregar_cancion(arbol->der,can,arbol);
        }
        else{
            Agregar_cancion(arbol->izq,can,arbol);
        }
    }
}

void ArbolAlbum::buscar_album(Nodo * arbol, string album){
    if(arbol==NULL){
		return;
	}
	else{
		char prim = album[0];
		string da=arbol->Dato->getalbum();
		char n= da[0];
		if(arbol->Dato->getalbum()==album){
			cout<<arbol->Dato->gettitulo()<<" "<<arbol->Dato->getartista()<<" "<<arbol->Dato->getalbum()<<" "<<arbol->Dato->getgenero()<<endl;
			buscar_album(arbol->izq,album);
			buscar_album(arbol->der,album);
		}
		else if(n<prim){
			buscar_album(arbol->der,album);
		}
		else{
			buscar_album(arbol->izq,album);
		}
	}
}
