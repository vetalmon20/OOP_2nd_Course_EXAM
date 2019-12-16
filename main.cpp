#include "mainwindow.h"

#include <QApplication>

#include <vector>
#include "Classes/Song.h"
#include "Classes/Group.h"
#include "Classes/Songlist.h"
#include <QDebug>

using namespace std;

Songlist SONGS;
vector<Group*> GROUPS;

int main(int argc, char *argv[])
{
    Song* a1 = new Song("My Star", "SOAD", "rock");
    a1->set_date(2000,10,01);
    Song* b1 = new Song("Metro", "SOAD", "rock");
    b1->set_date(1999,9,9);
    Song* c1 = new Song("Believe", "Eminem", "pop");
    c1->set_date(2002,11,11);
    Song* d1 = new Song("Ma life", "Bob Marlye", "country");
    d1->set_date(2001,5,21);
    Song* e1 = new Song("Deep house", "Gayazanovs", "other");
    e1->set_date(2007,11,01);
    Song* f1 = new Song("360", "ALLJ", "pop");
    f1->set_date(2019,12,03);
    Song* g1 = new Song("Now You Gone", "Bon Jovi", "techno");
    g1->set_date(1950,1,07);
    Song* h1 = new Song("Mockingbird", "Eminem", "pop");
    h1->set_date(2000,2,16);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
