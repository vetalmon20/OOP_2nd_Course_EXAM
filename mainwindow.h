#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Classes/Song.h"
#include "music.h"
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>

#define GENRESNUM 5

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_genres_info_clicked();

    void on_all_music_clicked();

    void on_groups_music_clicked();

    void on_top3_clicked();

    void on_top3_toggled(bool checked);

    void on_top3_pressed();

    void on_top3_released();

    void react_toggle(bool checked);

signals:
    void songs_out(vector<Song*> out,string name);

private:
    Ui::MainWindow *ui;
    Music *mcw;

    void add_group(QString name);

    void add_preflist(int pref[GENRESNUM], QTreeWidgetItem *parent);

    void  add_preferences(string name, QTreeWidgetItem *parent);

    void  add_songs(string name, QTreeWidgetItem *parent);

    void add_songlist(vector<Song*> in, QTreeWidgetItem *parent);

    void fill_groups_all();

};
#endif // MAINWINDOW_H
