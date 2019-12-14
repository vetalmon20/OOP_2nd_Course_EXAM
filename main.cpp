/**
 * 2nd Course K-29
 * Exam work. Variant 32
 * Task: definition the group class and the song class and methods/functions to work with them
 *
 *@author Vitaliy Datsiuk
 *@version 1 13/12/19
 */

#include <iostream>
#include <vector>
#include "Classes/Song.h"
#include "Classes/Group.h"
#include "Classes/Songlist.h"

using namespace std;

Songlist SONGS;
vector<Group*> GROUPS;

int main() {


Song* a = new Song("My Star", "SOAD", "rock");


cout << a->calculate_popularity() << endl;
cout << a->calculate_popularity() << endl;
cout << a->calculate_popularity() << endl;




}