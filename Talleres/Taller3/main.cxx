#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <algorithm>

#include "avltree.hpp"

using namespace std;

void add_song(AVLTree<Song>& t, AVLTree<Song>& a, AVLTree<Song>& al, AVLTree<Song>& g, Song& s) {
    t.add(s, s.title);
    a.add(s, s.artist);
    al.add(s, s.album);
    g.add(s, s.genre);
}
void remove_song(AVLTree<Song>& t, AVLTree<Song>& a, AVLTree<Song>& al, AVLTree<Song>& g, Song& s) {
    t.remove(s, s.title);
    a.remove(s, s.artist);
    al.remove(s, s.album);
    g.remove(s, s.genre);
    printf("Canción %s de %s eliminada.\nPresione enter para continuar.", s.title, s.artist);
    string x;
    getline(cin, x);
    return;
}

void load_songs(AVLTree<Song>& t, AVLTree<Song>& a, AVLTree<Song>& al, AVLTree<Song>& g, string filename) {
    ifstream file(filename);
    if (!file) {
        printf("Could not find file `%s` or is unreadable.\n", filename.c_str());
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string title, artist, album, genre;
        getline(ss, title, ',');
        getline(ss, artist, ',');
        getline(ss, album, ',');
        getline(ss, genre, ',');

        Song s;
        s.title = title;
        s.artist = artist;
        s.album = album;
        s.genre = genre;

        add_song(t, a, al, g, s);
    }
}

void search_song(AVLTree<Song>& tree, string type, Song& songg) {
    printf("Ingrese el %s a buscar: ", type.c_str());
    string search;
    getline(std::cin, search);
    if (search.empty()) {
        printf("la búsqueda no puede ser vacía.\n");
        return;
    }
    Node<Song>* result = tree.find(search);
    if (result == nullptr) {
        printf("Canción con el %s %s no encontrada.\nPresione enter para continuar.", type.c_str(), search.c_str());
        getline(cin, search);
        return;
    } else {
        printf("  Canción encontrada!\n  Título: %s\n  Artista: %s\n  Álbum: %s\n  Género: %s\n\nPresione enter para continuar.", result->data.title.c_str(), result->data.artist.c_str(), result->data.album.c_str(), result->data.genre.c_str());
        songg = tree.nodeToSong(result);
        getline(cin, search);
        return;
    }
}

int main(){
    AVLTree<Song> title_tree;
    AVLTree<Song> artist_tree;
    AVLTree<Song> album_tree;
    AVLTree<Song> genre_tree;
    Node<Song>* re;
    Song sss;

    load_songs(title_tree, artist_tree, album_tree, genre_tree, "songs.txt");

    int opc;
    do {
        printf("--------------------------------------------------------------\n");
        printf("----------- SISTEMA DE BÚSQUEDA DE MÚSICA -----------\n");
        printf("--------------------------------------------------------------\n");
        printf("Por favor seleccione una de las siguientes opciones:\n");
        printf("1. Buscar por título.\n");
        printf("2. Buscar por artista.\n");
        printf("3. Buscar por álbum.\n");
        printf("4. Buscar por género.\n");
        printf("5. Agregar canción.\n");
        printf("6. Eliminar canción.\n");
        printf("7. Lista con la altura máxima de cada rama.\n");
        printf("8. Salir del programa.\n");
        printf("--------------------------------------------------------------\n");
        cin >> opc;
        switch (opc){
            case 1: {
                cin.ignore();
                search_song(title_tree, "título", sss);
                break;
            }
            case 2: {
                cin.ignore();
                search_song(artist_tree, "artista", sss);
                break;
            }
            case 3: {
                cin.ignore();
                search_song(album_tree, "album", sss);
                break;
            }
            case 4: {
                cin.ignore();
                search_song(genre_tree, "genre", sss);
                break;
            }
            case 5: {
                string title, artist, album, genre;
                printf("Ingrese el título: ");
                getline(std::cin, title);
                printf("Ingrese el artista: ");
                getline(std::cin, artist);
                printf("Ingrese el álbum: ");
                getline(std::cin, album);
                printf("Ingrese el género: ");
                getline(std::cin, genre);
                Song s(title, artist, album, genre);
                add_song(title_tree, artist_tree, album_tree, genre_tree, s);
                printf("Canción agregada exitosamente!\nPresione enter para continuar.");
                string x;
                getline(cin, x);
                break;
            }
            case 6: {
                remove_song(title_tree, artist_tree, album_tree, genre_tree, sss);
                break;
            }
            case 7:{
                vector<int> heights = title_tree.getHeights();
                for (auto a : heights) {
                    printf("%d\n", a);
                    //cout << a << endl;
                }
                printf("Presione enter para continuar.");
                string x;
                getline(cin, x);
                break;
            }
            default:{
                break;
            }
        }
    } while (opc != 8);
    return 0;
}