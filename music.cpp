#include "music.h"
#include "ui_music.h"

Music::Music(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);

}

Music::~Music()
{
    delete ui;
}



void Music::songs_in(vector<Song *> in, std::string name)
{

    music = in;
    create_list();
    QString qtemp = QString::fromStdString(name);
    ui->type_of_music->setText(qtemp);

}

void Music::on_date_sort_clicked()
{
    update_list(1);
}

/**
 * This function creates the list taking by the foundation the music
 */
void Music::create_list(){
    ui->listWidget->clear();
    for(int i = 0; i < music.size(); i++){
        string temp = music[i]->get_name() + ".       " + music[i]->get_release_date().tostr() + " Popularity: " + music[i]->get_popularity_text();
        QString qtemp = QString::fromStdString(temp);
        ui->listWidget->addItem(qtemp);
    }
}

/**
 * This function will sort the list in the respectie order. 0 - date sort. 1 - popularity sort
 *
 * @param type the type to sort list with
 * @return the sorted list by respective type
 */
vector<Song *> Music::update_list(bool type)
{
    if(type == 0){
        music = rating_songs(music);
        create_list();
    } else{
        music = date_songs(music);
        create_list();
    }
}

void Music::on_popularity_sort_clicked()
{
        update_list(0);
}
