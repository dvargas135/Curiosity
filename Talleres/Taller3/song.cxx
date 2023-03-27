#include "song.h"

Song::Song() : title(""), artist(""), album(""), genre("") {}

Song::Song(std::string t, std::string a, std::string al, std::string g) {
    title = t;
    artist = a;
    album = al;
    genre = g;
}