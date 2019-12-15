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

    //if the group is present(it must be true!)
    int i = find_group(author_name);
    if(i != -1)
        group_songs = GROUPS[i]->get_songs();

    //calculating the average popularity for this group
    average_groupsongs_popularity = 50;
    if(!group_songs.empty()){
        average_groupsongs_popularity = 0;
        for(int i = 0; i < group_songs.size(); i++){
            average_groupsongs_popularity += group_songs[i]->get_popularity();
        }
        average_groupsongs_popularity = average_groupsongs_popularity / group_songs.size();
    }

    //calculating the average popularity for this genre
    genre_songs = SONGS.determine_genre(genre);
    average_genresongs_popularity = 50;
    if(!genre_songs.empty()){
        average_genresongs_popularity = 0;
        for(int i = 0; i < genre_songs.size(); i++){
            average_genresongs_popularity += genre_songs[i]->get_popularity();
        }
        average_genresongs_popularity = average_genresongs_popularity / genre_songs.size();
    }

    // randoming the factors that will influence the output popularity
    if(factor[2] != 0 && factor[3] != 0)
        average_popularity = (average_genresongs_popularity + average_groupsongs_popularity) / 2;
    else
        if(factor[2] == 0 && factor[3] == 0)
            average_popularity = 50;
        else
            if(factor[2] == 0 && factor[3] != 0)
                average_popularity = average_groupsongs_popularity;
            else
                average_popularity = average_genresongs_popularity;

    genre_respector = 0;
    if(factor[4] != 0) {
        if (!group_songs.empty()) {
            for (int i = 0; i < group_songs.size(); i++) {
                if (this->genre == group_songs[i]->get_genre())
                    genre_respector += 5;
                else
                    genre_respector -= 3;
            }
        }
    }
    average_popularity = average_popularity + genre_respector;
    if(factor[0] != 0)
        average_popularity = average_popularity + coeff_rand;

    if(average_popularity > 100)
        average_popularity = 100;
    if(average_popularity < 0)
        average_popularity = 0;
    if(factor[1] != 0)
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

void Song::set_date(int year, int month, int day)
{
    release.day = day;
    release.month = month;
    release.year = year;
}

void Song::set_date(Date in)
{
    release = in;
}

int Song::get_popularity() {
    return popularity;
}

string Song::get_popularity_text()
{
    return std::to_string(popularity);
}

string Song::get_name() {
    return name;
}

string Song::get_author_name() {
    return author_name;
}

Date Song::get_release_date()
{
    return release;
}

/**
 * This function displays on the screen the name and the popularity of the song
 */
void Song::display() {

    cout << "Name: " << this->name << ". Popularity: " << this->popularity << endl;
}

void Song::display_full() {

    cout << "Name: " << this->name << ". Popularity: " << this->popularity << endl;
    cout << "Author name: " << this->author_name << ". Genre: " << this->genre << endl;
    cout << "The release date: ";
    release.print();
}

/**
 * This function takes the array of the song as argument and sorts it by popularity
 *
 * @param in the array to sort
 * @return the sorted by popularity list of songs
 */
vector<Song*> sort_songs(vector<Song*> in, bool type){
    int current_p, insertion_p;               //creating two auxillary pointers
    current_p = insertion_p = 0;              //marking them on the head of the list

    while (current_p < in.size() || insertion_p < in.size()){ //if both pointer in the end - finish
        current_p = insertion_p + 1;
        while (current_p < in.size()){
            if(type == 0){
                if (in[current_p]->get_popularity() >= in[insertion_p]->get_popularity()) {
                    Song* temp = in[current_p];
                    in[current_p] = in[insertion_p];
                    in[insertion_p] = temp;
                }
            } else {
                if (in[current_p]->get_release_date() >= in[insertion_p]->get_release_date()) {
                    Song* temp = in[current_p];
                    in[current_p] = in[insertion_p];
                    in[insertion_p] = temp;
                }
            }
            current_p = current_p + 1;
        }
        insertion_p = insertion_p + 1;
    }

    return in;
}

/**
 * This function just prints the names of the songs and their popularity on the screen
 *
 * @param in the music to display
 */
void print_songs(vector<Song*> in){
    for(int i = 0; i < in.size(); i++){
        in[i]->display();
    }
}

/**
 * This function calculates the popularity for each song in the array in particular moment of the
 *      time and sorts it is descending order
 *
 * @param in the array to calculate popularity and sort to
 * @return the sorted by popularity array
 */
vector<Song*> rating_songs(vector<Song*> in){
    for(int i = 0; i < in.size(); i++){
        in[i]->calculate_popularity();
    }

    return sort_songs(in,0);
}

/**
 * This function sorts songs by date
 *
 * @param in the array to sort
 * @return the sorted array
 */
vector<Song*> date_songs(vector<Song*> in){
    return sort_songs(in,1);
}
