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
    Song* c1 = new Song("Coin", "Dark men", "techno");
    c1->set_date(2001,10,01);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
