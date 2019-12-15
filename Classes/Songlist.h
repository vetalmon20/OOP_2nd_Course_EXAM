/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: declaration the auxiliary class for the song class
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#ifndef INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONGLIST_H
#define INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONGLIST_H

#include "Song.h"

class Songlist {
public:
    vector<Song*> allsongs;

    vector<Song*> popsongs;
    vector<Song*> rocksongs;
    vector<Song*> technosongs;
    vector<Song*> countrysongs;
    vector<Song*> othersongs;

    /**
     * This function correctly adds the song respectively to the genre
     *
     * @param in the song to add
     */
    void add_song(Song* in);

    vector<Song*> determine_genre(string in);
};


#endif //INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONGLIST_H
