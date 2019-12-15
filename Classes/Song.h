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
    string get_popularity_text();
    string get_name();
    string get_author_name();
    Date get_release_date();

    void set_genre(string in);
    void set_date(int year, int month, int day);
    void set_date(Date in);

    int calculate_popularity();

    /**
     * This function displays on the screen the name and the popularity of the song
     */
    void display();

    void display_full();
};

/**
 * This function takes the array of the song as argument and sorts it by popularity
 *
 * @param in the array to sort
 * @return the sorted by popularity list of songs
 */
vector<Song*> sort_songs(vector<Song*> in, bool type);

/**
 * This function just prints the names of the songs and their popularity on the screen
 *
 * @param in the music to display
 */
void print_songs(vector<Song*> in);

/**
 * This function calculates the popularity for each song in the array in particular moment of the
 *      time and sorts it is descending order
 *
 * @param in the array to calculate popularity and sort to
 * @return the sorted by popularity array
 */
vector<Song*> rating_songs(vector<Song*> in);

/**
 * This function sorts songs by date
 *
 * @param in the array to sort
 * @return the sorted array
 */
vector<Song*> date_songs(vector<Song*> in);

#endif //INC_2ND_COURSE_1ST_SEMESTER_EXAM_SONG_H
