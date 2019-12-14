/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: declaration the main class for the song
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#ifndef INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONG_H
#define INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONG_H

#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class Song {
private:
    string name;
    string author_name;
    string genre;               //pop,rock,techno,country,other.
    Date release;
    int popularity;             //from 0 to 100

public:

    Song();
    Song(string name, string author_name, string genre);
    Song(string name, string author_name, string genre, Date release);


    /**
     * This function calculates the popularity in the specific moment of the time
     *
     * @return the popularity that measures from 0 to 100 as integer
     */

    string get_genre();
    int get_popularity();
    string get_name();
    string get_author_name();

    void set_genre(string in);

    int calculate_popularity();
};

#endif //INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONG_H
