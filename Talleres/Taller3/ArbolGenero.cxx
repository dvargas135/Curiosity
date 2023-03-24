#include "ArbolGenero.h"

ArbolGenero::ArbolGenero(){
    raiz=NULL;
}

Nodo * ArbolGenero::CrearNodo(string titulo,string artista,string album, string genero, Nodo * padre){
	Nodo * nuevo= new Nodo(titulo,artista,album,genero,padre);
	return nuevo;
}
void ArbolGenero::Agregar_cancion(Nodo *&  arbol, Cancion  can, Nodo * padre){
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

void ArbolGenero::buscar_genero(Nodo * arbol, string genero){
    if(arbol==NULL){
		return;
	}
	else{
		char prim = genero[0];
		string da=arbol->Dato->getgenero();
		char n= da[0];
		if(arbol->Dato->getgenero()==genero){
			cout<<arbol->Dato->gettitulo()<<" "<<arbol->Dato->getartista()<<" "<<arbol->Dato->getalbum()<<" "<<arbol->Dato->getgenero()<<endl;
			buscar_genero(arbol->izq,genero);
			buscar_genero(arbol->der,genero);
		}
		else if(n<prim){
			buscar_genero(arbol->der,genero);
		}
		else{
			buscar_genero(arbol->izq,genero);
		}
	}
}


