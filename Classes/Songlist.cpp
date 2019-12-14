/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: declaration the auxiliary class for the song class
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#include "Songlist.h"
#include <iostream>

void Songlist::add_song(Song* in) {

    allsongs.push_back(in);

    if(in->get_genre() == "pop"){
        popsongs.push_back(in);
        return;
    }
    if(in->get_genre() == "rock"){
        rocksongs.push_back(in);
        return;
    }
    if(in->get_genre() == "techno"){
        technosongs.push_back(in);
        return;
    }
    if(in->get_genre() == "country"){
        countrysongs.push_back(in);
        return;
    }
    if(in->get_genre() == "other"){
        othersongs.push_back(in);
        return;
    }
    std::cout << "Unexpected error. There is no such genre of music." << endl;
}

vector<Song *> Songlist::determine_genre(string in) {

    if(in == "pop"){
        return popsongs;
    }
    if(in == "rock"){
        return rocksongs;
    }
    if(in == "techno"){
        return technosongs;
    }
    if(in == "country"){
        return countrysongs;
    }
    if(in == "other"){
        return othersongs;
    }
    std::cout << "Unexpected error. There is no such genre of music.." << endl;

    return allsongs;
}
