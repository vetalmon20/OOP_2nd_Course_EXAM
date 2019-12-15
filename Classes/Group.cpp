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

int* Group::get_pref()
{
    return pref;
}

/**
 * This function adds the song to the song list of the group
 *
 * @param in the song to add
 */
void Group::add_song(Song* in) {
    songs.push_back(in);
}

/**
 * This function find the index of the current group in the global array
 *
 * @param in the name of the group to find
 * @return the index of the group in success of -1 in failure
 */
int find_group(string in){

    for(int i = 0; i < GROUPS.size(); i++){
        if(in == GROUPS[i]->get_name())
            return i;
    }
    return -1;
}

/**
 * This function adds the song to the song list of the group or creates the new group
 *
 * @param in the song to add
 */
void add_group_song(Song* in){
    for(int i = 0; i < GROUPS.size(); i++){
        if(GROUPS[i]->get_name() == in->get_author_name()){
            GROUPS[i]->add_song(in);
            return;
        }
    }
    Group *temp = new Group(in->get_author_name());
    temp->add_song(in);
    GROUPS.push_back(temp);

}
