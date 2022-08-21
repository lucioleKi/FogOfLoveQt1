#include "FogOfLove.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , session{}, ui(new Ui::MainWindow), scene({0, Sweet, 'B'})
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton2Clicked()));


}

void MainWindow::on_pushButton2Clicked(){
    setPage2();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_b4Enable2(){
    QButtonGroup* genderGroup1 = new QButtonGroup;
    genderGroup1->addButton(ui->radioButton);
    genderGroup1->addButton(ui->radioButton_2);
    genderGroup1->addButton(ui->radioButton_3);
    QButtonGroup* genderGroup2 = new QButtonGroup;
    genderGroup2->addButton(ui->radioButton_7);
    genderGroup2->addButton(ui->radioButton_8);
    genderGroup2->addButton(ui->radioButton_9);
    QButtonGroup* occuGroup1 = new QButtonGroup;
    occuGroup1->addButton(ui->radioButton_10);
    occuGroup1->addButton(ui->radioButton_11);
    occuGroup1->addButton(ui->radioButton_12);
    QButtonGroup* occuGroup2 = new QButtonGroup;
    occuGroup2->addButton(ui->radioButton_13);
    occuGroup2->addButton(ui->radioButton_14);
    occuGroup2->addButton(ui->radioButton_15);
    int traitCount1 = 0;
    int traitCount2 = 0;
    if(ui->checkBox->checkState()!=0){
        traitCount1++;
    }
    if(ui->checkBox_2->checkState()!=0){
        traitCount1++;
    }
    if(ui->checkBox_3->checkState()!=0){
        traitCount1++;
    }
    if(ui->checkBox_4->checkState()!=0){
        traitCount1++;
    }
    if(ui->checkBox_5->checkState()!=0){
        traitCount1++;
    }

    if(ui->checkBox_6->checkState()!=0){
        traitCount2++;
    }
    if(ui->checkBox_7->checkState()!=0){
        traitCount2++;
    }
    if(ui->checkBox_8->checkState()!=0){
        traitCount2++;
    }
    if(ui->checkBox_9->checkState()!=0){
        traitCount2++;
    }
    if(ui->checkBox_10->checkState()!=0){
        traitCount2++;
    }

    if(genderGroup1->checkedId()!=-1){
        emit page2Ready();
    }
    if(genderGroup2->checkedId()!=-1){
        emit page3Ready();
    }
    if(traitCount1==3){
        emit page4Ready();
    }else{
         ui->pushButton_6->setDisabled(true);
    }
    if(traitCount2==3){
        emit page5Ready();
    }else{
        ui->pushButton_7->setDisabled(true);
    }
    if(occuGroup1->checkedId()!=-1){
        emit page6Ready();
    }
    if(occuGroup2->checkedId()!=-1){
        emit page7Ready();
    }
}

void MainWindow::on_featureTurn(){

    int turn1 = 0;
    int turn2 = 0;
    if(ui->checkBox_11->checkState()!=0){
        turn1++;
    }
    if(ui->checkBox_12->checkState()!=0){
        turn1++;
    }
    if(ui->checkBox_13->checkState()!=0){
        turn1++;
    }
    if(ui->checkBox_14->checkState()!=0){
        turn1++;
    }
    if(ui->checkBox_15->checkState()!=0){
        turn1++;
    }

    if(ui->checkBox_16->checkState()!=0){
        turn2++;
    }
    if(ui->checkBox_17->checkState()!=0){
        turn2++;
    }
    if(ui->checkBox_18->checkState()!=0){
        turn2++;
    }
    if(ui->checkBox_19->checkState()!=0){
        turn2++;
    }
    if(ui->checkBox_20->checkState()!=0){
        turn2++;
    }
    if(turn1==3&&turn2==3){
        emit page8Ready();
    }else{
        ui->pushButton_10->setDisabled(true);
    }
    if(ui->lineEdit->text()!=""&&ui->lineEdit_2->text()!=""){
        emit page9Ready();
    }else{
        ui->pushButton_11->setDisabled(true);
    }
}

void MainWindow::on_chapterReady(){
    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_4);
    choiceGroup1->addButton(ui->radioButton_5);
    choiceGroup1->addButton(ui->radioButton_6);
    QButtonGroup* choiceGroup2 = new QButtonGroup;
    choiceGroup2->addButton(ui->radioButton_19);
    choiceGroup2->addButton(ui->radioButton_20);
    choiceGroup2->addButton(ui->radioButton_21);
    if(choiceGroup1->checkedId()!=-1){
        ui->pushButton_13->setEnabled(true);
    }
    if(choiceGroup2->checkedId()!=-1){
        ui->pushButton_15->setEnabled(true);
    }
}

void MainWindow::on_selectReady(){
    QButtonGroup* selectGroup1 = new QButtonGroup;
    selectGroup1->addButton(ui->radioButton_16);
    selectGroup1->addButton(ui->radioButton_17);
    selectGroup1->addButton(ui->radioButton_18);
    selectGroup1->addButton(ui->radioButton_22);
    selectGroup1->addButton(ui->radioButton_23);
    selectGroup1->addButton(ui->radioButton_24);
    selectGroup1->addButton(ui->radioButton_25);
    selectGroup1->addButton(ui->radioButton_26);
    if(selectGroup1->checkedId()!=-1){
        ui->pushButton_27->setEnabled(true);
    }
}

void MainWindow::on_b4Ready(){
    ui->pushButton_4->setEnabled(true);
}

void MainWindow::on_b5Ready(){
    ui->pushButton_5->setEnabled(true);
}

void MainWindow::on_b6Ready(){
    ui->pushButton_6->setEnabled(true);
}

void MainWindow::on_b7Ready(){
    ui->pushButton_7->setEnabled(true);
}

void MainWindow::on_b8Ready(){
    ui->pushButton_8->setEnabled(true);
}

void MainWindow::on_b9Ready(){
    ui->pushButton_9->setEnabled(true);
}

void MainWindow::on_b10Ready(){
    ui->pushButton_10->setEnabled(true);
}

void MainWindow::on_b11Ready(){
    ui->pushButton_11->setEnabled(true);
}

void MainWindow::on_page3(){
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_page4(){
   ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_page5(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_page6(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_page7(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_page8(){
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_page9(){
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_page10(){
    setPage3();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_page11(){

        setPageChapter1(chapter);
        ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_page12(){
    if(ui->pushButton_13->isEnabled()){
        ui->pushButton_13->setDisabled(true);
        ui->radioButton_4->setVisible(false);
        ui->radioButton_5->setVisible(false);
        ui->radioButton_6->setVisible(false);
        ui->label_52->setText(QString::fromStdString(session.x1.getName()+" has chosen."));
    }
    if(ui->pushButton_15->isEnabled()){
        ui->pushButton_15->setDisabled(true);
        ui->radioButton_19->setVisible(false);
        ui->radioButton_20->setVisible(false);
        ui->radioButton_21->setVisible(false);
        ui->label_56->setText(QString::fromStdString(session.x2.getName()+" has chosen."));
    }
    if(!ui->radioButton_4->isVisible()&&!ui->radioButton_19->isVisible()){
        int temp1 = 4;
        int temp2 = 4;
        if(ui->radioButton_4->isChecked()){
            temp1 = 0;
        }else if(ui->radioButton_5->isChecked()){
            temp1 = 1;
        }else if(ui->radioButton_6->isChecked()){
            temp1 = 2;
        }
        if(ui->radioButton_19->isChecked()){
            temp2 = 0;
        }else if(ui->radioButton_20->isChecked()){
            temp2 = 1;
        }else if(ui->radioButton_21->isChecked()){
            temp2 = 2;
        }
        int additionalMatch = -1;
        std::vector<std::string> matches = match2(temp1, temp2, 1);
        for (int i = 0; i < session.chapters.at(chapter-1).getAddis().size(); i++) {
            std::string c = session.chapters.at(chapter-1).getAddis().at(i).getCode().at(0);
            if (std::find(matches.begin(), matches.end(), c) != matches.end()) {
                additionalMatch = i;
            }
        }
        if (additionalMatch != -1) {
            std::vector<std::string> effects = session.chapters.at(chapter-1).getAddis().at(additionalMatch).getCode();
            session.x1.setSatisfaction(std::stoi(effects.at(2)));
            session.x2.setSatisfaction(std::stoi(effects.at(2)));
        };
        if(chapter!=1){
            on_player1Destiny();
        }else{
            to_Board();
        }

        //to_Board();
    }
}



void MainWindow::to_Board(){
    setBoard();
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::go_Destiny1(){
    setPageDestiny(1);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::go_Destiny2(){
    setPageDestiny(2);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::go_Traits1(){
    setPageTraits(1);
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::go_Traits2(){
    setPageTraits(2);
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::go_Secret1(){
    setPageSecret(1);
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::go_Secret2(){
    setPageSecret(2);
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::go_selectScene1(){
    setSceneSelect(1);
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::go_selectScene2(){
    setSceneSelect(2);
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::go_displayScene(){
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::setPage2(){
    //disable all buttons in character creation
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_13->setDisabled(true);
    ui->pushButton_15->setDisabled(true);

    //select gender
    QButtonGroup* genderGroup1 = new QButtonGroup;
    genderGroup1->addButton(ui->radioButton);
    genderGroup1->addButton(ui->radioButton_2);
    genderGroup1->addButton(ui->radioButton_3);
    QButtonGroup* genderGroup2 = new QButtonGroup;
    genderGroup2->addButton(ui->radioButton_7);
    genderGroup2->addButton(ui->radioButton_8);
    genderGroup2->addButton(ui->radioButton_9);

    //draw traits
    session.traits = importTraits("trait.txt");
    std::vector<Trait> trait1 = {session.traits.at(0), session.traits.at(1), session.traits.at(2), session.traits.at(3), session.traits.at(4)};
    std::vector<Trait> trait2 = {session.traits.at(5), session.traits.at(6), session.traits.at(7), session.traits.at(8), session.traits.at(9)};
    ui->label_4->setText(QString::fromStdString(trait1.at(0).printFull()));
    ui->label_5->setText(QString::fromStdString(trait1.at(1).printFull()));
    ui->label_12->setText(QString::fromStdString(trait1.at(2).printFull()));
    ui->label_13->setText(QString::fromStdString(trait1.at(3).printFull()));
    ui->label_14->setText(QString::fromStdString(trait1.at(4).printFull()));
    ui->label_18->setText(QString::fromStdString(trait2.at(0).printFull()));
    ui->label_19->setText(QString::fromStdString(trait2.at(1).printFull()));
    ui->label_20->setText(QString::fromStdString(trait2.at(2).printFull()));
    ui->label_21->setText(QString::fromStdString(trait2.at(3).printFull()));
    ui->label_22->setText(QString::fromStdString(trait2.at(4).printFull()));

    //draw occupations
    session.occu = importOccus("occupation.txt");
    std::vector<Occupation> occus1 = { session.occu.at(0), session.occu.at(1), session.occu.at(2) };
    std::vector<Occupation> occus2 = { session.occu.at(3), session.occu.at(4), session.occu.at(5) };
    ui->radioButton_10->setText(QString::fromStdString(occus1.at(0).printFull()));
    ui->radioButton_11->setText(QString::fromStdString(occus1.at(1).printFull()));
    ui->radioButton_12->setText(QString::fromStdString(occus1.at(2).printFull()));
    ui->radioButton_13->setText(QString::fromStdString(occus2.at(0).printFull()));
    ui->radioButton_14->setText(QString::fromStdString(occus2.at(1).printFull()));
    ui->radioButton_15->setText(QString::fromStdString(occus2.at(2).printFull()));
    QButtonGroup* occuGroup1 = new QButtonGroup;
    occuGroup1->addButton(ui->radioButton_10);
    occuGroup1->addButton(ui->radioButton_11);
    occuGroup1->addButton(ui->radioButton_12);
    QButtonGroup* occuGroup2 = new QButtonGroup;
    occuGroup2->addButton(ui->radioButton_13);
    occuGroup2->addButton(ui->radioButton_14);
    occuGroup2->addButton(ui->radioButton_15);

    //draw traits
    session.features = importFeatures("feature.txt");
    std::vector<Feature> features1 = { session.features.at(0), session.features.at(1), session.features.at(2), session.features.at(3), session.features.at(4) };
    std::vector<Feature> features2 = { session.features.at(5), session.features.at(6), session.features.at(7), session.features.at(8), session.features.at(9) };
    ui->checkBox_11->setText(QString::fromStdString(features1.at(0).printFull()));
    ui->checkBox_12->setText(QString::fromStdString(features1.at(1).printFull()));
    ui->checkBox_13->setText(QString::fromStdString(features1.at(2).printFull()));
    ui->checkBox_14->setText(QString::fromStdString(features1.at(3).printFull()));
    ui->checkBox_15->setText(QString::fromStdString(features1.at(4).printFull()));
    ui->checkBox_16->setText(QString::fromStdString(features2.at(0).printFull()));
    ui->checkBox_17->setText(QString::fromStdString(features2.at(1).printFull()));
    ui->checkBox_18->setText(QString::fromStdString(features2.at(2).printFull()));
    ui->checkBox_19->setText(QString::fromStdString(features2.at(3).printFull()));
    ui->checkBox_20->setText(QString::fromStdString(features2.at(4).printFull()));

    //occupation and gender buttons
    for(int i=-2; i>-5; i--){
        connect(occuGroup1->button(i), SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
        connect(genderGroup1->button(i), SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
        connect(occuGroup2->button(i), SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
        connect(genderGroup2->button(i), SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    }
    //trait1 buttons
    connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_3, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_4, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_5, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    //trait2 buttons
    connect(ui->checkBox_6, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_7, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_8, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_9, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));
    connect(ui->checkBox_10, SIGNAL(clicked()), this, SLOT(on_b4Enable2()));

    //feature1 buttons
    connect(ui->checkBox_11, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_12, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_13, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_14, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_15, SIGNAL(clicked()), this, SLOT(on_featureTurn()));

    //feature2 buttons
    connect(ui->checkBox_16, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_17, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_18, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_19, SIGNAL(clicked()), this, SLOT(on_featureTurn()));
    connect(ui->checkBox_20, SIGNAL(clicked()), this, SLOT(on_featureTurn()));

    //name lineEdits
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_featureTurn()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(on_featureTurn()));

    //all 'next' buttons
    connect(this, SIGNAL(page2Ready()), this, SLOT(on_b4Ready()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_page3()));
    connect(this, SIGNAL(page3Ready()), this, SLOT(on_b5Ready()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_page4()));
    connect(this, SIGNAL(page4Ready()), this, SLOT(on_b6Ready()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_page5()));
    connect(this, SIGNAL(page5Ready()), this, SLOT(on_b7Ready()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_page6()));
    connect(this, SIGNAL(page6Ready()), this, SLOT(on_b8Ready()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_page7()));
    connect(this, SIGNAL(page7Ready()), this, SLOT(on_b9Ready()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_page8()));
    connect(this, SIGNAL(page8Ready()), this, SLOT(on_b10Ready()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(on_page9()));
    connect(this, SIGNAL(page9Ready()), this, SLOT(on_b11Ready()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_page10()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_page11()));

}

void MainWindow::setPage3(){
    if(ui->radioButton->isChecked()){
        session.x1.setGender(Female);
    }else if(ui->radioButton_2->isChecked()){
        session.x1.setGender(Male);
    }else if(ui->radioButton_3->isChecked()){
        session.x1.setGender(Other);
    }
    if(ui->radioButton_7->isChecked()){
        session.x2.setGender(Female);
    }else if(ui->radioButton_8->isChecked()){
        session.x2.setGender(Male);
    }else if(ui->radioButton_9->isChecked()){
        session.x2.setGender(Other);
    }
    session.x1.setName(ui->lineEdit->text().toStdString());
    session.x2.setName(ui->lineEdit_2->text().toStdString());

    if(ui->radioButton_10->isChecked()){
        session.occu1 = session.occu.at(0);
        session.occu.push_back(session.occu.at(1));
        session.occu.push_back(session.occu.at(2));
    }else if(ui->radioButton_11->isChecked()){
        session.occu1 = session.occu.at(1);
        session.occu.push_back(session.occu.at(0));
        session.occu.push_back(session.occu.at(2));
    }else if(ui->radioButton_12->isChecked()){
        session.occu1 = session.occu.at(2);
        session.occu.push_back(session.occu.at(0));
        session.occu.push_back(session.occu.at(1));
    }
    session.per.changeOccu(1, session.occu1);
    session.occu.erase(session.occu.begin(), session.occu.begin()+3);
    if(ui->radioButton_13->isChecked()){
        session.occu2 = session.occu.at(0);
        session.occu.push_back(session.occu.at(1));
        session.occu.push_back(session.occu.at(2));
    }else if(ui->radioButton_14->isChecked()){
        session.occu2 = session.occu.at(1);
        session.occu.push_back(session.occu.at(0));
        session.occu.push_back(session.occu.at(2));
    }else if(ui->radioButton_15->isChecked()){
        session.occu2 = session.occu.at(2);
        session.occu.push_back(session.occu.at(0));
        session.occu.push_back(session.occu.at(1));
    }
    session.per.changeOccu(2, session.occu2);
    session.occu.erase(session.occu.begin(), session.occu.begin()+3);

    //traits
    if(ui->checkBox_5->isChecked()){
        session.traits1.push_back(session.traits.at(4));
    }
    if(ui->checkBox_4->isChecked()){
        session.traits1.push_back(session.traits.at(3));
    }
    if(ui->checkBox_3->isChecked()){
        session.traits1.push_back(session.traits.at(2));
    }
    if(ui->checkBox_2->isChecked()){
        session.traits1.push_back(session.traits.at(1));
    }
    if(ui->checkBox->isChecked()){
        session.traits1.push_back(session.traits.at(0));
    }
    session.traits.push_back(session.traits.at(0));
    session.traits.push_back(session.traits.at(1));
    session.traits.erase(session.traits.begin(), session.traits.begin()+5);
    if(ui->checkBox_10->isChecked()){
        session.traits2.push_back(session.traits.at(4));
    }
    if(ui->checkBox_9->isChecked()){
        session.traits2.push_back(session.traits.at(3));
    }
    if(ui->checkBox_8->isChecked()){
        session.traits2.push_back(session.traits.at(2));
    }
    if(ui->checkBox_7->isChecked()){
        session.traits2.push_back(session.traits.at(1));
    }
    if(ui->checkBox_6->isChecked()){
        session.traits2.push_back(session.traits.at(0));
    }
    session.traits.push_back(session.traits.at(0));
    session.traits.push_back(session.traits.at(1));
    session.traits.erase(session.traits.begin(), session.traits.begin()+5);

    //feature
    if(ui->checkBox_15->isChecked()){
        session.fea1.push_back(session.features.at(4));
    }
    if(ui->checkBox_14->isChecked()){
        session.fea1.push_back(session.features.at(3));
    }
    if(ui->checkBox_13->isChecked()){
        session.fea1.push_back(session.features.at(2));
    }
    if(ui->checkBox_12->isChecked()){
        session.fea1.push_back(session.features.at(1));
    }
    if(ui->checkBox_11->isChecked()){
        session.fea1.push_back(session.features.at(0));
    }
    session.features.push_back(session.features.at(0));
    session.features.push_back(session.features.at(1));
    session.features.erase(session.features.begin(), session.features.begin()+5);
    if(ui->checkBox_20->isChecked()){
        session.fea2.push_back(session.features.at(4));
    }
    if(ui->checkBox_19->isChecked()){
        session.fea2.push_back(session.features.at(3));
    }
    if(ui->checkBox_18->isChecked()){
        session.fea2.push_back(session.features.at(2));
    }
    if(ui->checkBox_17->isChecked()){
        session.fea2.push_back(session.features.at(1));
    }
    if(ui->checkBox_16->isChecked()){
        session.fea2.push_back(session.features.at(0));
    }
    session.features.push_back(session.features.at(0));
    session.features.push_back(session.features.at(1));
    session.features.erase(session.features.begin(), session.features.begin()+5);
    session.per.changeFeature(1, session.fea1.at(0));
    session.per.changeFeature(1, session.fea1.at(1));
    session.per.changeFeature(1, session.fea1.at(2));
    session.per.changeFeature(2, session.fea2.at(0));
    session.per.changeFeature(2, session.fea2.at(1));
    session.per.changeFeature(2, session.fea2.at(2));
    session.plot = selectSynopsis();
    session.d1 = session.plot.getDestinies();
    session.d2 = session.plot.getDestinies();
    session.chapters = importChapters("chapters.txt", "chapterEffect.txt");
    session.sweetS = importScenes("scenesSweet.txt", "sceneEffectSweet.txt");
    session.seriousS = importScenes("scenesSerious.txt", "sceneEffectSerious.txt");
    session.dramaS = importScenes("scenesDrama.txt", "sceneEffectDrama.txt");
    session = drawStarting(session);
    turn = 1;
    chapter = 2;
}

void MainWindow::setPageChapter1(int c){
    ui->label_101->setText(QString::fromStdString(session.chapters.at(c-1).getTitle()));
    ui->label_100->setText(QString::fromStdString(session.chapters.at(c-1).getLine()));
    ui->label_106->setText(QString::fromStdString("A = "+session.chapters.at(c-1).getChoices().at(0).printFull()+"B = " + session.chapters.at(c-1).getChoices().at(1).printFull()+"C = "+session.chapters.at(c-1).getChoices().at(2).printFull()));
    ui->label_50->setText(QString::fromStdString("Length: "+std::to_string(session.chapters.at(c-1).getLength())+" cards"));

    if(c==1){
        ui->label_102->setText(QString::fromStdString(session.chapters.at(c-1).getAddis().at(0).getFull()+"\nYou are fully in sync about what to do."));

        ui->label_103->setText(QString::fromStdString(session.chapters.at(c-1).getAddis().at(1).getFull()+"\nYou agree to do a bit of both your suggestions."));

    }else if(c==2){
        ui->label_107->setText(QString::fromStdString("CHAPTER TWO"));
        ui->label_102->setText(QString::fromStdString(session.chapters.at(c-1).getAddis().at(0).getFull()));
        ui->label_103->clear();
        ui->label_51->setText(QString::fromStdString("Draw cards from: Serious"));

    }else if(c==3){
        ui->label_107->setText(QString::fromStdString("CHAPTER THREE"));
        ui->label_102->setText(QString::fromStdString(session.chapters.at(c-1).getAddis().at(0).getFull()));
        ui->label_103->setText(QString::fromStdString(session.chapters.at(c-1).getAddis().at(1).getFull()));
        ui->label_51->setText(QString::fromStdString("Draw cards from: Drama"));
    }
    ui->label_52->setText(QString::fromStdString(session.x1.getName()));
    ui->label_56->setText(QString::fromStdString(session.x2.getName()));

    //player 1 choice
    connect(ui->radioButton_4, SIGNAL(clicked()), this, SLOT(on_chapterReady()));
    connect(ui->radioButton_5, SIGNAL(clicked()), this, SLOT(on_chapterReady()));
    connect(ui->radioButton_6, SIGNAL(clicked()), this, SLOT(on_chapterReady()));
    //player 2 choice
    connect(ui->radioButton_19, SIGNAL(clicked()), this, SLOT(on_chapterReady()));
    connect(ui->radioButton_20, SIGNAL(clicked()), this, SLOT(on_chapterReady()));
    connect(ui->radioButton_21, SIGNAL(clicked()), this, SLOT(on_chapterReady()));

    //two submit buttons for chapter choices
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_page12()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(on_page12()));
}

void MainWindow::setBoard(){
    ui->pushButton_24->setEnabled(true);
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(to_Board()));
    //character profiles
    ui->label_55->setText(QString::fromStdString(session.x1.getName()));
    ui->label_57->setText(QString::fromStdString(session.x2.getName()));
    ui->label_59->setText(QString::fromStdString(session.x1.getName()));
    ui->label_60->setText(QString::fromStdString(session.x2.getName()));
    if(session.x1.getGender()==Female){
        ui->label_53->setText(QString::fromStdString("Gender: Female\n"));
    }else if(session.x1.getGender()==Male){
        ui->label_53->setText(QString::fromStdString("Gender: Male\n"));
    }else if(session.x1.getGender()==Other){
        ui->label_53->setText(QString::fromStdString("Gender: Other\n"));
    }
    if(session.x2.getGender()==Female){
        ui->label_54->setText(QString::fromStdString("Gender: Female\n"));
    }else if(session.x2.getGender()==Male){
        ui->label_54->setText(QString::fromStdString("Gender: Male\n"));
    }else if(session.x2.getGender()==Other){
        ui->label_54->setText(QString::fromStdString("Gender: Other\n"));
    }
    ui->label_53->setText(ui->label_53->text()+QString::fromStdString("Occupation: "+session.occu1.getName()+"\nFeatures: "+session.fea1.at(0).getName()+", "+session.fea1.at(1).getName()+",\n "+session.fea1.at(2).getName()+"\n"));
    ui->label_54->setText(ui->label_54->text()+QString::fromStdString("Occupation: "+session.occu2.getName()+"\nFeatures: "+session.fea2.at(0).getName()+", "+session.fea2.at(1).getName()+",\n "+session.fea2.at(2).getName()+"\n"));
    ui->label_53->setText(ui->label_53->text()+QString::fromStdString("Satisfaction: "+std::to_string(session.x1.getSatisfaction())));
    ui->label_54->setText(ui->label_54->text()+QString::fromStdString("Satisfaction: "+std::to_string(session.x2.getSatisfaction())));
    //personality tokens
    ui->label_61->setText(QString::fromStdString("+"+std::to_string(session.per.get1(0))+"+"+std::to_string(session.per.get2(0))));
    ui->label_62->setText(QString::fromStdString("-"+std::to_string(session.per.get1(1))+"-"+std::to_string(session.per.get2(1))));
    ui->label_63->setText(QString::fromStdString("+"+std::to_string(session.per.get1(2))+"+"+std::to_string(session.per.get2(2))));
    ui->label_64->setText(QString::fromStdString("-"+std::to_string(session.per.get1(3))+"-"+std::to_string(session.per.get2(3))));
    ui->label_65->setText(QString::fromStdString("+"+std::to_string(session.per.get1(4))+"+"+std::to_string(session.per.get2(4))));
    ui->label_66->setText(QString::fromStdString("-"+std::to_string(session.per.get1(5))+"-"+std::to_string(session.per.get2(5))));
    ui->label_67->setText(QString::fromStdString("+"+std::to_string(session.per.get1(6))+"+"+std::to_string(session.per.get2(6))));
    ui->label_68->setText(QString::fromStdString("-"+std::to_string(session.per.get1(7))+"-"+std::to_string(session.per.get2(7))));
    ui->label_69->setText(QString::fromStdString("+"+std::to_string(session.per.get1(8))+"+"+std::to_string(session.per.get2(8))));
    ui->label_70->setText(QString::fromStdString("-"+std::to_string(session.per.get1(9))+"-"+std::to_string(session.per.get2(9))));
    ui->label_71->setText(QString::fromStdString("+"+std::to_string(session.per.get1(10))+"+"+std::to_string(session.per.get2(10))));
    ui->label_72->setText(QString::fromStdString("-"+std::to_string(session.per.get1(11))+"-"+std::to_string(session.per.get2(11))));
    //destiny buttons
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(go_Destiny1()));
    connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(go_Destiny2()));
    //traits buttons
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(go_Traits1()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(go_Traits2()));
    //secret buttons
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(go_Secret1()));
    connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT(go_Secret2()));
    //next turn button
    if(turn==1){
        ui->pushButton_14->setText("Next Turn (Player 1)");
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(go_selectScene1()));
    }else{
        ui->pushButton_14->setText("Next Turn (Player 2)");
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(go_selectScene2()));
    }

}

void MainWindow::setPageDestiny(int c){
    ui->label_75->setText("");
    ui->label_77->setText("");
    ui->radioButton_27->setVisible(false);
    ui->radioButton_28->setVisible(false);
    ui->radioButton_29->setVisible(false);
    ui->radioButton_30->setVisible(false);
    ui->radioButton_31->setVisible(false);
    ui->radioButton_32->setVisible(false);
    if(c==1){
        ui->label_73->setText(QString::fromStdString(session.x1.getName()));
        for(int i=0; i<session.d1.size(); i++){
            if(session.d1.at(i).getIn()){
                ui->label_75->setText(ui->label_75->text()+QString::fromStdString(session.d1.at(i).printFull()+"\n"));
            }else{
                ui->label_77->setText(ui->label_77->text()+QString::fromStdString(session.d1.at(i).printFull()+"\n"));
            }
        }
    }else{
        ui->label_73->setText(QString::fromStdString(session.x2.getName()));
        for(int i=0; i<session.d2.size(); i++){
            if(session.d2.at(i).getIn()){
                ui->label_75->setText(ui->label_75->text()+QString::fromStdString(session.d2.at(i).printFull()+"\n"));
            }else{
                ui->label_77->setText(ui->label_77->text()+QString::fromStdString(session.d2.at(i).printFull()+"\n"));
            }
        }
    }

};

void MainWindow::setPageTraits(int c){
    ui->label_80->setText("");
    if(c==1){
        ui->label_78->setText(QString::fromStdString(session.x1.getName()));
        for(int i=0; i<3; i++){
            ui->label_80->setText(ui->label_80->text()+QString::fromStdString(session.traits1.at(i).printFull()+"\n"));
        }
    }else{
        ui->label_78->setText(QString::fromStdString(session.x2.getName()));
        for(int i=0; i<3; i++){
            ui->label_80->setText(ui->label_80->text()+QString::fromStdString(session.traits2.at(i).printFull()+"\n"));
        }
    }
    connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT(to_Board()));
}

void MainWindow::setPageSecret(int c){
    connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(to_Board()));
     ui->label_82->setText("");
     if(c==1){
         ui->label_83->setText(QString::fromStdString(session.x1.getName()));
     }else{
         ui->label_83->setText(QString::fromStdString(session.x2.getName()));
     }
    if(c==1&&session.secret1.size()==0||c==2&&session.secret2.size()==0){
        ui->label_81->setText("You have no unrevealed SECRET.");
        return;
    }
    if(c==1){
        for(int i=0; i<session.secret1.size(); i++){
            ui->label_82->setText(ui->label_82->text()+QString::fromStdString(session.secret1.at(i).printFull()+"\n"));
        }
    }else{
        for(int i=0; i<session.secret1.size(); i++){
            ui->label_82->setText(ui->label_82->text()+QString::fromStdString(session.secret2.at(i).printFull()+"\n"));
        }
    }
}

void MainWindow::setSceneSelect(int c){
    ui->pushButton_27->setDisabled(true);
    if(c==1){
        ui->label_84->setText(QString::fromStdString(session.x1.getName()));
        for(int i=0; i<session.hand1.size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(session.hand1.at(i).printFull()+"\n"));
        }
    }else{
        ui->label_84->setText(QString::fromStdString(session.x2.getName()));
        for(int i=0; i<session.hand2.size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(session.hand2.at(i).printFull()+"\n"));
        }
    }
    connect(ui->radioButton_16, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_17, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_18, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_22, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_23, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_24, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_25, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->radioButton_26, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(go_displayScene()));
}



MainWindow::~MainWindow()
{
    delete ui;
}

