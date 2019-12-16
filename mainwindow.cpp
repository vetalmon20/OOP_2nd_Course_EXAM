#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/Songlist.h"
#include "Classes/Group.h"
#include <string>
#include <QMessageBox>

extern Songlist SONGS;
extern vector<Group*> GROUPS;

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->genres_list->addItem("pop");
    ui->genres_list->addItem("rock");
    ui->genres_list->addItem("techno");
    ui->genres_list->addItem("country");
    ui->genres_list->addItem("other");

    fill_groups_all();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_genres_info_clicked()
{
    if(ui->genres_list->currentRow() == -1)
        return;
    else{
        mcw = new Music(this);
        connect(this, &MainWindow::songs_out, mcw, &Music::songs_in);
        QListWidgetItem *temp = new QListWidgetItem();
        temp = ui->genres_list->currentItem();
        QString temp_qstring = temp->text();
        string temp_string = temp_qstring.toStdString();
        string music = " music";
        vector<Song*> out = SONGS.determine_genre(temp_string);
        temp_string = temp_string + music;
        songs_out(out, temp_string);
        mcw->show();

    }

}

void MainWindow::on_all_music_clicked()
{
    mcw = new Music(this);
    connect(this, &MainWindow::songs_out, mcw, &Music::songs_in);
    vector<Song*> out = SONGS.allsongs;
    string temp_string = "all music";
    songs_out(out, temp_string);
    mcw->show();
}

void MainWindow::add_group(QString name)
{
    QTreeWidgetItem *temp = new QTreeWidgetItem(ui->treeWidget);
    temp->setText(0, name) ;
    ui->treeWidget->addTopLevelItem(temp);
    add_preferences(name.toStdString(), temp);
    add_songs(name.toStdString(), temp);
}

void MainWindow:: add_preferences(string name,  QTreeWidgetItem *parent)
{
    QTreeWidgetItem *temp = new QTreeWidgetItem(parent);//
    QString pref_text = "Preferences";
    temp->setText(0, pref_text) ;
    parent->addChild(temp);
    add_preflist(GROUPS[find_group(name)]->get_pref(), temp);
}

void MainWindow::add_preflist(int pref[GENRESNUM], QTreeWidgetItem *parent)
{
    QString qtemp;
    QTreeWidgetItem *temp1 = new QTreeWidgetItem(parent);//
    qtemp = "pop: ";
    temp1->setText(0, qtemp + QString::number(pref[0])) ;
    parent->addChild(temp1);
    qtemp.clear();

    QTreeWidgetItem *temp2 = new QTreeWidgetItem(parent);//
    qtemp = "rock: ";
    temp2->setText(0, qtemp + QString::number(pref[1])) ;
    parent->addChild(temp2);
    qtemp.clear();

    QTreeWidgetItem *temp3 = new QTreeWidgetItem(parent);//
    qtemp = "techno: ";
    temp3->setText(0, qtemp + QString::number(pref[2])) ;
    parent->addChild(temp3);
    qtemp.clear();

    QTreeWidgetItem *temp4 = new QTreeWidgetItem(parent);//
    qtemp = "country: ";
    temp4->setText(0, qtemp + QString::number(pref[3])) ;
    parent->addChild(temp4);
    qtemp.clear();

    QTreeWidgetItem *temp5 = new QTreeWidgetItem(parent);//
    qtemp = "other: ";
    temp5->setText(0, qtemp + QString::number(pref[4])) ;
    parent->addChild(temp5);

}


void MainWindow::add_songs(string name, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *temp = new QTreeWidgetItem(parent);//
    QString songs_text = "Songs";
    temp->setText(0, songs_text) ;
    parent->addChild(temp);
    add_songlist(GROUPS[find_group(name)]->get_songs(), temp);
}

void MainWindow::add_songlist(vector<Song *> in, QTreeWidgetItem *parent)
{
    for(int i = 0 ; i < in.size(); i++){
         QTreeWidgetItem *temp = new QTreeWidgetItem(parent);//
         temp->setText(0, QString::fromStdString(in[i]->get_name())) ;
         parent->addChild(temp);
    }
}

void MainWindow::fill_groups_all()
{
    for(int i = 0 ; i < GROUPS.size(); i++){
        QString temp = QString::fromStdString(GROUPS[i]->get_name());
        add_group(temp);
    }
}

void MainWindow::on_top3_clicked()
{


}

void MainWindow::on_top3_toggled(bool checked)
{
    ui->treeWidget->clear();
    if(checked == 1){
        vector<Song*> top = rating_songs(SONGS.allsongs);
        if(top.size() <= 3)
            fill_groups_all();
        else{
            vector<Song*> top3;
            Song* stemp = new Song();
            int counter = 0;
            int j = 0;
            bool present = 0;
            QString temp;
            while(counter < 3 && j < top.size()){
                temp = QString::fromStdString(top[j]->get_author_name());
                for(int i = 0; i < top3.size(); i++){
                    if(top3[i]->get_author_name() == top[j]->get_author_name())
                        present = 1;
                }
                if(present == 0){
                    top3.push_back(top[j]);
                    counter++;
                } else {
                    present = 0;
                }
                temp.clear();
                j++;
            }
            for(int i = 0; i < top3.size(); i++){
                temp = QString::fromStdString(top[i]->get_author_name());
                add_group(temp);
                temp.clear();
            }
        }
    } else {
        fill_groups_all();
    }
}

void MainWindow::on_top3_pressed()
{

}

void MainWindow::on_top3_released()
{

}

void MainWindow::react_toggle(bool checked)
{

}


void MainWindow::on_groups_music_clicked()
{
  QTreeWidgetItem *temp = new QTreeWidgetItem();
  temp = ui->treeWidget->currentItem();
  QString qtemp = temp->text(0);
  string stemp = qtemp.toStdString();
  if(find_group(stemp) == -1){
      QMessageBox::information(this,tr("Miss click"), tr("You should choose the group to view the music of the group"));
  } else{
      mcw = new Music(this);
      connect(this, &MainWindow::songs_out, mcw, &Music::songs_in);
      vector<Song*> out = GROUPS[find_group(stemp)]->get_songs();
      string temp_string = stemp +"'s music";
      songs_out(out, temp_string);
      mcw->show();
  }

}

