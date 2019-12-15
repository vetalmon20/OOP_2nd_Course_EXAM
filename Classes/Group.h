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
    int* get_pref();

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
int find_group(string in);

/**
 * This function adds the song to the song list of the group or creates the new group
 *
 * @param in the song to add
 */
void add_group_song(Song* in);





#endif //INC_2ND_COURSE_1ST_SEMESTER_EXAM_GROUP_H
