#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BeforeScenes.h"
#include "StartChar.h"

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

private:
    Ui::MainWindow *ui;
    QString s;

    Character x1;
    Character x2;
    std::vector<Trait> traits;
    std::vector<Trait> traits1;
    std::vector<Trait> traits2;
    std::vector<Occupation> occu;
    Occupation occu1;
    Occupation occu2;
    std::vector<Feature> features;
    std::vector<Feature> fea1;
    std::vector<Feature> fea2;
    PersonalityToken per;
    Synopsis plot;
    std::vector<Destiny> d1;
    std::vector<Destiny> d2;
    std::vector<Chapter> chapters;
    std::vector<Scene> sweetS;
    std::vector<Scene> seriousS;
    std::vector<Scene> dramaS;
    std::vector<Scene> hand1;
    std::vector<Scene> hand2;
    std::vector<std::string> carryOver;
    std::vector<Scene> secret1;
    std::vector<Scene> secret2;



private slots:
    //start button
    void on_pushButton2Clicked();
    //check if next can be clicked in name, trait, occupation
    void on_b4Enable2();
    void on_page2Ready();
    void on_page3();
    void on_page3Ready();
    void on_page4();
    void on_page4Ready();
    void on_page5();
    void on_page5Ready();
    void on_page6();
    void on_page6Ready();
    void on_page7();
    void on_page7Ready();
    void on_page8();
    //check feature in turns
    void on_featureTurn();
    void on_page8Ready();
    void on_page9();
    void on_page9Ready();
    void on_page10();
};



#endif // MAINWINDOW_H
