/**
* 2nd Course K-29
* Exam work. Variant 32
* Description: definition the main class for the song
*
*@author Vitaliy Datsiuk
*@version 1 13/12/19
*/

#include "Song.h"
#include <iostream>
#include "Songlist.h"
#include "Group.h"

#define GENRESNUM 5

using namespace std;

extern Songlist SONGS;
extern vector<Group*> GROUPS;

/**
 * This function calculates the popularity in the specific moment of the time
 *
 * @return the popularity that measures from 0 to 100 as integer
 */
int Song::calculate_popularity() {

    Date curr_date;
    long int curr_days, release_days;
    int coeff_rand, average_groupsongs_popularity, average_genresongs_popularity, average_popularity, genre_respector;
    float coeff_days;
    bool factor[GENRESNUM];
    vector<Song*> genre_songs, group_songs;

    //randoming the factors that will influence the popularity
    for(int i = 0; i < GENRESNUM; i++){
        factor[i] = rand() % 2;
    }

    curr_date.to_current_date();               //sets curr_date the current y.m.d.
    curr_days = curr_date.to_days();
    release_days = release.to_days();
    coeff_days = (float)release_days / (float)curr_days;
    coeff_rand = rand() % 50 - 25;

    int i = find_group(author_name);
    if(i != -1)
        group_songs = GROUPS[i]->get_songs();

    average_groupsongs_popularity = 50;
    if(!group_songs.empty()){
        average_groupsongs_popularity = 0;
        for(int i = 0; i < group_songs.size(); i++){
            average_groupsongs_popularity += group_songs[i]->get_popularity();
        }
        average_groupsongs_popularity = average_groupsongs_popularity / group_songs.size();
    }

    genre_songs = SONGS.determine_genre(genre);
    average_genresongs_popularity = 50;
    if(!genre_songs.empty()){
        average_genresongs_popularity = 0;
        for(int i = 0; i < genre_songs.size(); i++){
            average_genresongs_popularity += genre_songs[i]->get_popularity();
        }
        average_genresongs_popularity = average_genresongs_popularity / genre_songs.size();
    }

    average_popularity = (average_genresongs_popularity + average_groupsongs_popularity) / 2;

    genre_respector = 0;
    if(!group_songs.empty()){
        for(int i = 0; i < group_songs.size(); i++){
            if(this->genre == group_songs[i]->get_genre())
                genre_respector += 5;
            else
                genre_respector -= 3;
        }
    }

    average_popularity = average_popularity + genre_respector + coeff_rand;
    if(average_popularity > 100)
        average_popularity = 100;
    if(average_popularity < 0)
        average_popularity = 0;
    average_popularity = average_popularity * coeff_days;

    popularity = average_popularity;

    return average_popularity;
}

Song::Song() {

    name = "Default song";
    author_name = "Default group";
    genre = "other";
    Date default_date;
    release = default_date;
    popularity = calculate_popularity();

    SONGS.add_song(this);
    add_group_song(this);

}

Song::Song(string name, string author_name, string genre) {
    this->name = name;
    this->author_name = author_name;
    this->genre = genre;
    Date default_date;
    release = default_date;
    popularity = calculate_popularity();

    SONGS.add_song(this);
    add_group_song(this);
}

Song::Song(string name, string author_name, string genre, Date release) {
    this->name = name;
    this->author_name = author_name;
    this->genre = genre;
    this->release = release;
    popularity = calculate_popularity();

    SONGS.add_song(this);
    add_group_song(this);
}

string Song::get_genre() {
    return this->genre;
}

void Song::set_genre(string in) {
    genre = in;
}

int Song::get_popularity() {
    return popularity;
}

string Song::get_name() {
    return name;
}

string Song::get_author_name() {
    return author_name;
}


