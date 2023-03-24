#include "Cancion.h"

Cancion::Cancion(string titulo,string artista, string album, string genero){
    this->titulo=titulo;
    this->artista=artista;
    this->album=album;
    this->genero=genero;
}
void Cancion::crearNuevaCancion(){
    cout<<"ingrese el titulo de la cancion"<<endl;
    cin>>Cancion::titulo;
    cout<<"ingrese el artista de la cancion"<<endl;
    cin>>Cancion::artista;
    cout<<"ingrese el album de la cancion"<<endl;
    cin>>Cancion::album;
    cout<<"ingrese el genero de la cancion"<<endl;
    cin>>Cancion::genero;
    Cancion *nuevaCancion = new Cancion (titulo,artista,album,genero);
}

//funcion para leer el archivo de canciones y guardarlo en un vector Cancion
std::vector<string> leerArchivo(){
	vector <string> expresion;
	vector<Cancion>vecCanciones;
	ifstream archivo;
	string texto;
	archivo.open("canciones.txt", ios::in); //para abrir el archivo en modo lectura 
	if(archivo.fail()){
		cout<< "No se pudo abrir el archivo.";
		exit(1);//para salir del programa
	}
	while (!archivo.eof()){ //mientras que no sea el final del archivo, para recorrer el archivo
		getline(archivo, texto); //todo lo que se encuentre en el archivo se va a guardar en la variable texto
		expresion.push_back(texto); 
	}
	for(const auto& cancion_str:expresion){
		stringstream ss(cancion_str);
		string titulo, artista, album, genero;
		getline(ss, titulo, ',');
		getline(ss, artista, ',');
		getline(ss, album, ',');
		getline(ss, genero, ',');
		vecCanciones.emplace_back(titulo, artista, album, genero);
	}
    //para comprobar que si se esta guardando correctamente en el vecto de tipo Cancion
	/*for (auto& cancion:vecCanciones){ 
		cout<<cancion.gettitulo()<<"-"<<cancion.getartista()<<"-"<<cancion.getalbum()<<"-"<<cancion.getgenero()<<endl;
	}*/
	archivo.close();
	//return expresionSeparada;
}

string Cancion::gettitulo(){
return this->titulo;
}
string Cancion::getartista(){
    return this->artista;
}
string Cancion::getalbum(){
    return this->album;
}
string Cancion::getgenero(){
    return this->genero;
}


