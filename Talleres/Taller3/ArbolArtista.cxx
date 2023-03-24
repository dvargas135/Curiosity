#include "ArbolArtista.h"

ArbolArtista::ArbolArtista(){
    raiz=NULL;
}

Nodo * ArbolArtista::CrearNodo(string titulo,string artista,string album, string genero, Nodo * padre){
	Nodo * nuevo= new Nodo(titulo,artista,album,genero,padre);
	return nuevo;
}
void ArbolArtista::Agregar_cancion(Nodo *&  arbol, Cancion  can, Nodo * padre){
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

void ArbolArtista::eliminar_cancion(Nodo * arbol, string nombre,string artista,string album,string genero){
    if(arbol==NULL){
        return;
    }
	else{
		char primera = artista[0];
		char n = arbol->Dato->getartista()[0];
		if(artista==arbol->Dato->getartista() && nombre==arbol->Dato->gettitulo() && album==arbol->Dato->getalbum() && genero==arbol->Dato->getgenero()){
			eliminar(arbol);
			return;
		}
		else if(n==primera){
			eliminar_cancion(arbol->izq,nombre,artista,album,genero);
			eliminar_cancion(arbol->izq,nombre,artista,album,genero);
		}
		else if(n>primera){
			eliminar_cancion(arbol->izq,nombre,artista,album,genero);
		}
		else if(n<primera){
			eliminar_cancion(arbol->der,nombre,artista,album,genero);
		}
	}
}

void ArbolArtista::eliminar(Nodo * elim){
    if(elim->der && elim->izq){
		Nodo * menor= minimo(elim->der);
		elim->Dato=menor->Dato;
		eliminar(menor);
	}
	else if(elim->izq){
		remplazar(elim,elim->izq);
		destruir(elim);
	}
	else if(elim->der){
		remplazar(elim,elim->der);
		destruir(elim);
	}
	else{
		remplazar(elim,NULL);
		destruir(elim);
	}
}

Nodo *ArbolArtista::minimo(Nodo * arbol){
	if(arbol!=NULL){
		return NULL;
	}
	if(arbol->izq){
		minimo(arbol->izq);
	}
		return arbol;
}

void ArbolArtista::remplazar(Nodo * arbol,Nodo * nuevo){
	if(arbol->padre){
		if(arbol->Dato==arbol->padre->izq->Dato){
			arbol->padre->izq=nuevo;
		}
		else if(arbol->Dato==arbol->padre->der->Dato){
			arbol->padre->der=nuevo;
		}
	}
	if(nuevo){
		nuevo->padre=arbol->padre;
	}
}
void ArbolArtista::destruir(Nodo * eliminar){
	eliminar->izq=NULL;
	eliminar->der=NULL;
	delete eliminar;
}
void ArbolArtista::buscar_artista(Nodo * arbol, string artista){

    if(arbol==NULL){
		return;
	}
	else{
		char prim = artista[0];
		string da=arbol->Dato->getartista();
		char n= da[0];
		if(arbol->Dato->getartista()==artista){
			cout<<arbol->Dato->gettitulo()<<" "<<arbol->Dato->getartista()<<" "<<arbol->Dato->getalbum()<<" "<<arbol->Dato->getgenero()<<endl;
			buscar_artista(arbol->izq,artista);
			buscar_artista(arbol->der,artista);
		}
		else if(n<prim){
			buscar_artista(arbol->der,artista);
		}
		else{
			buscar_artista(arbol->izq,artista);
		}
	}
}




