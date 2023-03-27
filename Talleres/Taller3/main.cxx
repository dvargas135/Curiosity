#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Song {
public:
    string title;
    string artist;
    string album;
    string genre;
    Song() : title(""), artist(""), album(""), genre("") {}
    Song(string t, string a, string al, string g) {
        title = t;
        artist = a;
        album = al;
        genre = g;
    }
};

template<typename T>
class Node {
public:
    T data;
    int height;
    string search_attr;
    Node<T>* left;
    Node<T>* right;

    Node(T val, string attr) {
        data = val;
        height = 1;
        left = right = nullptr;
        search_attr = attr;
    }
};

template<typename T>
class AVLTree {
private:
    Node<T>* root;
    int height(Node<T>* node) {
        return node == nullptr ? 0 : node->height;
    }
    int balanceFactor(Node<T>* node) {
        return height(node->left) - height(node->right);
    }
    void updateHeight(Node<T>* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
    Node<T>* rotateLeft(Node<T>* node) {
        Node<T>* rightChild = node->right;
        Node<T>* leftSubtree = rightChild->left;
        rightChild->left = node;
        node->right = leftSubtree;
        updateHeight(node);
        updateHeight(rightChild);
        return rightChild;
    }
    Node<T>* rotateRight(Node<T>* node) {
        Node<T>* leftChild = node->left;
        Node<T>* rightSubtree = leftChild->right;
        leftChild->right = node;
        node->left = rightSubtree;
        updateHeight(node);
        updateHeight(leftChild);
        return leftChild;
    }
    Node<T>* balance(Node<T>* node) {
        updateHeight(node);
        int bf = balanceFactor(node);
        if (bf > 1 && balanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }
        if (bf < -1 && balanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        if (bf > 1 && balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (bf < -1 && balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    Node<T>* insert(Node<T>* node, T val, string attr) {
        if (node == nullptr) {
            return new Node<T>(val, attr);
        }
        if (attr < node->search_attr) {
            node->left = insert(node->left, val, attr);
        } else {
            node->right = insert(node->right, val, attr);
        }
        return balance(node);
    }
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node<T>* remove(Node<T>* node, T val, string attr) {
        if (node == nullptr) {
            return node;
        }
        if (attr < node->search_attr) {
            node->left = remove(node->left, val, attr);
        } else if (attr > node->search_attr) {
            node->right = remove(node->right, val, attr);
        } else {
            Node<T>* leftChild = node->left;
            Node<T>* rightChild = node->right;
            delete node;
            if (rightChild == nullptr) {
                return leftChild;
            }
            Node<T>* minNode = findMin(rightChild);
            minNode->right = remove(rightChild, minNode->data);
            minNode->left = leftChild;
            return balance(minNode);
        }
        return balance(node);
    }
    Node<T>* search(Node<T>* node, string attr) {
        if (node == nullptr || node->search_attr == attr) {
            return node;
        }
        if (attr < node->search_attr) {
            return search(node->left, attr);
        } else {
            return search(node->right, attr);
        }
    }
    vector<int> getBranchHeights() {
        vector<int> branchHeights;
        if (root) {
            vector<Node<T>*> stack;
            stack.push_back(root);
            while (!stack.empty()) {
                Node<T>* node = stack.back();
                stack.pop_back();
                if (!node->left && !node->right) {
                    // Leaf node, so add its height to branchHeights
                    branchHeights.push_back(node->height);
                } else {
                    // Non-leaf node, so add its children to stack
                    if (node->left) {
                        stack.push_back(node->left);
                    }
                    if (node->right) {
                        stack.push_back(node->right);
                    }
                }
            }
        }
        return branchHeights;
    }
public:
    AVLTree() {
        root = nullptr;
    }
    vector<int> getHeights() {
        return getBranchHeights();
    }
    Node<T>* getRoot() const {
	    return root;
    }
    void add(T val, string attr) {
        root = insert(root, val, attr);
    }
    void remove(T val, string attr) {
        root = remove(root, val, attr);
    }
    Node<T>* find(string title) {
        return search(root, title);
    }
};

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
        /*
        t.add(s, s.title);
        a.add(s, s.artist);
        al.add(s, s.album);
        g.add(s, s.genre);
        */
    }
}

void search_song(AVLTree<Song>& tree, string type) {
    string x;
    if (o = 1) { x = "título"; y = "title";}
    if (o = 2) { x = "artista"; y = "artist";}
    if (o = 3) { x = "álbum"; y = "album";}
    if (o = 4) { x = "género"; y = "genre";}
    printf("Ingrese el %s a buscar", type.c_str());
    //cout << "Ingrese el título a buscar: ";
    string search;
    getline(std::cin, search);
    if (search.empty()) {
        printf("la búsqueda no puede ser vacía.\n");
        break;
    }
    Node<Song>* result = tree.find(search);
    if (result == nullptr) {
        cout << "Canción con el título " << search << " no encontrada." << endl;
        printf("Canción con el %s %s no encontrada.\n", type.c_str(), search.c_str())
    } else {
        cout << "Canción encontrada:\n  Título: " << result->data.title << "\n  Artista: " << result->data.artist << "\n  Álbum: " >> result->data.album << "\n  Género: " << result->data.genre << endl;
    }

}

int main(){
    int opc;
    do {
        cout << "--------------------------------------------------------------" << endl;
        cout << "----------- SISTEMA DE BUSQUEDA DE MUSICA -----------" << endl;
        cout << "--------------------------------------------------------------"<<"\nPor favor seleccione una de las siguientes opciones:"<<endl;
        cout << "1. Buscar cancion por titulo."<<endl;
        cout << "2. Buscar cancion por artista."<<endl;
        cout << "3. Buscar cancion por album."<<endl;
        cout << "4. Buscar cancion por genero."<<endl;
        cout << "5. Agregar cancion."<<endl;
        cout << "6. Eliminar cancion."<<endl;
        cout << "7. Salir del programa."<<endl;
        cout << "--------------------------------------------------------------" << endl;
        cin >> opc;
        switch (opc){
            case 1:{
                search_song(title_tree, "título");
                break;
            }
            case 2:{
                cout << "Ingrese el artista a buscar: ";
                string search_artist;
                getline(std::cin, search_artist);
                if (search_artist.empty()) {
                    printf("la búsqueda no puede ser vacía.\n");
                    break;
                }
                Node<Song>* result = artist_tree.find(search_artist);
                if (result == nullptr) {
                    cout << "Canción con el artista " << search_artist << " no encontrada." << endl;
                } else {
                    cout << "Canción encontrada:\n  Título: " << result->data.title << "\n  Artista: " << result->data.artist << "\n  Álbum: " >> result->data.album << "\n  Género: " << result->data.genre << endl;
                }
                break;
            }
            case 3:{
                cout << "Ingrese el álbum a buscar: ";
                string search_album;
                getline(std::cin, search_album);
                if (search_album.empty()) {
                    printf("la búsqueda no puede ser vacía.\n");
                    break;
                }
                Node<Song>* result = album_tree.find(search_album);
                if (result == nullptr) {
                    cout << "Canción con el álbum " << search_album << " no encontrada." << endl;
                } else {
                    cout << "Canción encontrada:\n  Título: " << result->data.title << "\n  Artista: " << result->data.artist << "\n  Álbum: " >> result->data.album << "\n  Género: " << result->data.genre << endl;
                }
                break;
            }
            case 4:{
                cout << "Ingrese el género a buscar: ";
                string search_genre;
                getline(std::cin, search_genre);
                if (search_genre.empty()) {
                    printf("la búsqueda no puede ser vacía.\n");
                    break;
                }
                Node<Song>* result = genre_tree.find(search_genre);
                if (result == nullptr) {
                    cout << "Canción con el género " << search_genre << " no encontrada." << endl;
                } else {
                    cout << "Canción encontrada:\n  Título: " << result->data.title << "\n  Artista: " << result->data.artist << "\n  Álbum: " >> result->data.album << "\n  Género: " << result->data.genre << endl;
                }
                break;
            }
            case 5:{
                string title, artist, album, genre;
                cout << "Ingrese el título: ";
                getline(std::cin, title);
                cout << "Ingrese el artista: ";
                getline(std::cin, artist);
                cout << "Ingrese el álbum: ";
                getline(std::cin, album);
                cout << "Ingrese el género: ";
                getline(std::cin, genre);
                Song s(title, artist, album, genre);
                add_song(title_tree, artist_tree, album_tree, genre_tree, s);
                printf("Canción agregada exitosamente!")
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
    }while (opc!=7);
    return 0;
}

int main() {
    AVLTree<Song> title_tree;
    AVLTree<Song> artist_tree;
    AVLTree<Song> album_tree;
    AVLTree<Song> genre_tree;

    Song s1("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock");
    Song s2("Bohemian Rhapsodye", "Queef", "A Night at the Opere", "Punk");
    Song s3("Rohemian Rhapsodye", "Queem", "A Day at the Opere", "House");
    genre_tree.add(s1, s1.genre);
    genre_tree.add(s2, s2.genre);
    genre_tree.add(s3, s3.genre);

    string search_genre = "Rock";
    Node<Song>* result = genre_tree.find(search_genre);
    //Node<Song>* song_node = title_tree.find("Rock", search_genre);

    if (result == nullptr) {
        cout << "Song with genre " << search_genre << " not found." << endl;
    } else {
        cout << "Song found: " << result->data.title << " by " << result->data.artist << endl;
    }

    vector<int> heights = genre_tree.getHeights();

    for (auto a : heights) {
        cout << a << endl;
    }

    /*
    // Create an AVL tree of songs ordered by title
    AVLTree<Song> title_tree;

    // Add two songs
    title_tree.add(Song("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock"));
    title_tree.add(Song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "Rock"));

    // Search for a song by title
    Node<Song>* song_node = title_tree.find("Bohemian Rhapsody");
    if (song_node != nullptr) {
        cout << "Found song: " << song_node->data.title << " by " << song_node->data.artist << endl;
    } else {
        cout << "Song not found." << endl;
    }

    song_node = title_tree.find("Stairway to Heaven");
    if (song_node != nullptr) {
        cout << "Found song: " << song_node->data.title << " by " << song_node->data.artist << endl;
    } else {
        cout << "Song not found." << endl;
    }

    // Remove a song
    title_tree.remove(Song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "Rock"));

    // Search for the removed song
    song_node = title_tree.find("Stairway to Heaven");
    if (song_node != nullptr) {
        cout << "Found song: " << song_node->data.title << " by " << song_node->data.artist << endl;
    } else {
        cout << "Song not found." << endl;
    }
    */
    return 0;
}
