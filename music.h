#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include<vector>
#include "Classes/Song.h"
#include <string.h>

using namespace  std;

namespace Ui {
class Music;
}

class Music : public QDialog
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

public slots:
    void songs_in(vector<Song*> in,string name);

private slots:
    void on_date_sort_clicked();

    void on_popularity_sort_clicked();

private:
    Ui::Music *ui;
    vector<Song*> music;

    /**
     * This function creates the list taking by the foundation the music
     */
    void create_list();

    /**
     * This function will sort the list in the respectie order. 0 - date sort. 1 - popularity sort
     *
     * @param type the type to sort list with
     * @return the sorted list by respective type
     */
    vector<Song*> update_list(bool type);
};

#endif // MUSIC_H
