#include "ArbolTitulo.h"

ArbolTitulo::ArbolTitulo(){
    raiz=NULL;
}

Nodo * ArbolTitulo::CrearNodo(string titulo,string artista,string album, string genero, Nodo * padre){
	Nodo * nuevo= new Nodo(titulo,artista,album,genero,padre);
	return nuevo;
}
void ArbolTitulo::Agregar_cancion(Nodo *&  arbol, Cancion  can, Nodo * padre){
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

void ArbolTitulo::buscar_titulo(Nodo * arbol, string Nombre){
   if(arbol==NULL){
		return;
	}
	else{
		char prim = Nombre[0];
		string da=arbol->Dato->gettitulo();
		char n= da[0];
		if(arbol->Dato->gettitulo()==Nombre){
			cout<<arbol->Dato->gettitulo()<<" "<<arbol->Dato->getartista()<<" "<<arbol->Dato->getalbum()<<" "<<arbol->Dato->getgenero()<<endl;
			buscar_titulo(arbol->izq,Nombre);
			buscar_titulo(arbol->der,Nombre);
		}
		else if(n<prim){
			buscar_titulo(arbol->der,Nombre);
		}
		else{
			buscar_titulo(arbol->izq,Nombre);
		}
	}
}

