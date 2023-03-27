#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    Song();
    Song(std::string t, std::string a, std::string al, std::string g);
};

#endif