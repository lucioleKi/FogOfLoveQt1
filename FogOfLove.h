#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StartChar.h"
#include "RunGameHelper.h"
#include "Session.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setPage2();
    void setPage3();
    void setPageChapter1(int c);
    void setBoard();
    //page 12
    void setPageDestiny(int c);
    void setPageTraits(int c);
    void setPageSecret(int c);
    void setSceneSelect(int c);
    void resolveEffectsCQt(int choice, int player);

    ~MainWindow();
signals:
    void page2Ready();
    void page3Ready();
    void page4Ready();
    void page5Ready();
    void page6Ready();
    void page7Ready();
    void page8Ready();
    void page9Ready();
    void chapterReady();
    //void pageDestiny();
private:
    Ui::MainWindow *ui;
    QString s;
    Session session;
    int turn;
    int chapter;
    Scene scene;



private slots:
    //start button
    void on_pushButton2Clicked();
    //check if next can be clicked in name, trait, occupation
    void on_b4Enable2();
    void on_b4Ready();
    void on_b5Ready();
    void on_b6Ready();
    void on_b7Ready();
    void on_b8Ready();
    void on_b9Ready();
    void on_b10Ready();
    void on_b11Ready();
    void on_b24Ready();
    void on_page3();
    void on_page4();
    void on_page5();
    void on_page6();
    void on_page7();
    void on_page8();
    //check feature in turns
    void on_featureTurn();
    void on_page9();
    void on_page10();

    void on_page11();
    void on_chapterReady();
    void on_page12();
    //board buttons
    void to_Board();
    void go_Destiny1();
    void go_Destiny2();
    void go_Traits1();
    void go_Traits2();
    void go_Secret1();
    void go_Secret2();
    void go_selectScene1();
    void go_selectScene2();
    void go_displayScene();
    void on_selectReady();
    void on_player1Destiny();
    void on_player2Destiny();
    void changeDestiny();
    void cEffectEnd();
};



#endif // MAINWINDOW_H
