/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: declaration the main class for the group
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#ifndef INC_2ND_COURSE_1ST_SEMESTER_EXAM_GROUP_H
#define INC_2ND_COURSE_1ST_SEMESTER_EXAM_GROUP_H

#include <string>
#include <vector>
#include "Song.h"

#define GENRESNUM 5

using namespace std;

class Group {
private:
    string name;
    int pref[GENRESNUM];           //preferences in diff genres of music from 0 to 100
    vector<Song*> songs;

public:

    Group();
    explicit Group(string name);

    string get_name();
    vector<Song*> get_songs();

    /**
    * This function adds the song to the song list of the group
    *
    * @param in the song to add
    */
    void add_song(Song* in);

};

extern vector<Group*> GROUPS;

/**
 * This function find the index of the current group in the global array
 *
 * @param in the name of the group to find
 * @return the index of the group in success of -1 in failure
 */
inline int find_group(string in){

    for(int i = 0; i < GROUPS.size(); i++){
        if(in == GROUPS[i]->get_name())
            return i;
    }
    return -1;
}

/**
 * This function adds the song to the song lis of the group or creates the new group
 *
 * @param in the song to add
 */
inline void add_group_song(Song* in){
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


#endif //INC_2ND_COURSE_1ST_SEMESTER_EXAM_GROUP_H
