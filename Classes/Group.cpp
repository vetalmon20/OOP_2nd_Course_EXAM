/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: definition the main class for the group
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#include "Group.h"



Group::Group() {
    name = "Default group";

    for(int i = 0; i < GENRESNUM; i++){
        pref[i] = rand() % 100;
    }
}

Group::Group(string name) {
    this->name = name;

    for(int i = 0; i < GENRESNUM; i++){
        pref[i] = rand() % 100;
    }
}

string Group::get_name() {
    return name;
}

vector<Song*> Group::get_songs() {
    return songs;
}



/**
 * This function adds the song to the song list of the group
 *
 * @param in the song to add
 */
void Group::add_song(Song* in) {
    songs.push_back(in);
}
