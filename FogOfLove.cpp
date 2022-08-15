#include "FogOfLove.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), x1(1), x2(2), occu1({"test", Discipline, 0}),occu2({"test", Discipline, 0})
    , plot{selectSynopsis()}
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

    int turn1=0;
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

void MainWindow::on_page2Ready(){
    ui->pushButton_4->setEnabled(true);
}

void MainWindow::on_page3Ready(){
    ui->pushButton_5->setEnabled(true);
}

void MainWindow::on_page4Ready(){
    ui->pushButton_6->setEnabled(true);
}

void MainWindow::on_page5Ready(){
    ui->pushButton_7->setEnabled(true);
}

void MainWindow::on_page6Ready(){
    ui->pushButton_8->setEnabled(true);
}

void MainWindow::on_page7Ready(){
    ui->pushButton_9->setEnabled(true);
}

void MainWindow::on_page8Ready(){
    ui->pushButton_10->setEnabled(true);
}

void MainWindow::on_page9Ready(){
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

void MainWindow::setPage2(){

    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);



    QButtonGroup* genderGroup1 = new QButtonGroup;
    genderGroup1->addButton(ui->radioButton);
    genderGroup1->addButton(ui->radioButton_2);
    genderGroup1->addButton(ui->radioButton_3);
    QButtonGroup* genderGroup2 = new QButtonGroup;
    genderGroup2->addButton(ui->radioButton_7);
    genderGroup2->addButton(ui->radioButton_8);
    genderGroup2->addButton(ui->radioButton_9);

    traits = importTraits("trait.txt");

    std::vector<Trait> trait1 = {traits.at(0), traits.at(1), traits.at(2), traits.at(3), traits.at(4)};
    std::vector<Trait> trait2 = {traits.at(5), traits.at(6), traits.at(7), traits.at(8), traits.at(9)};


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
    std::vector<Trait> chosen1, chosen2;

    occu = importOccus("occupation.txt");
    std::vector<Occupation> occus1 = { occu.at(0), occu.at(1), occu.at(2) };
    std::vector<Occupation> occus2 = { occu.at(3), occu.at(4), occu.at(5) };

    QRadioButton *o1 = ui->radioButton_10;
    o1->setText(QString::fromStdString(occus1.at(0).printFull()));
    QRadioButton *o2 = ui->radioButton_11;
    o2->setText(QString::fromStdString(occus1.at(1).printFull()));
    QRadioButton *o3 = ui->radioButton_12;
    o3->setText(QString::fromStdString(occus1.at(2).printFull()));
    QRadioButton *o4 = ui->radioButton_13;
    o4->setText(QString::fromStdString(occus2.at(0).printFull()));
    QRadioButton *o5 = ui->radioButton_14;
    o5->setText(QString::fromStdString(occus2.at(1).printFull()));
    QRadioButton *o6 = ui->radioButton_15;
    o6->setText(QString::fromStdString(occus2.at(2).printFull()));

    QButtonGroup* occuGroup1 = new QButtonGroup;
    occuGroup1->addButton(ui->radioButton_10);
    occuGroup1->addButton(ui->radioButton_11);
    occuGroup1->addButton(ui->radioButton_12);
    QButtonGroup* occuGroup2 = new QButtonGroup;
    occuGroup2->addButton(ui->radioButton_13);
    occuGroup2->addButton(ui->radioButton_14);
    occuGroup2->addButton(ui->radioButton_15);

    features = importFeatures("feature.txt");
    std::vector<Feature> features1 = { features.at(0), features.at(1), features.at(2), features.at(3), features.at(4) };
    std::vector<Feature> features2 = { features.at(5), features.at(6), features.at(7), features.at(8), features.at(9) };
    QCheckBox *f1 = ui->checkBox_11;
    f1->setText(QString::fromStdString(features1.at(0).printFull()));
    QCheckBox *f2 = ui->checkBox_12;
    f2->setText(QString::fromStdString(features1.at(1).printFull()));
    QCheckBox *f3 = ui->checkBox_13;
    f3->setText(QString::fromStdString(features1.at(2).printFull()));
    QCheckBox *f4 = ui->checkBox_14;
    f4->setText(QString::fromStdString(features1.at(3).printFull()));
    QCheckBox *f5 = ui->checkBox_15;
    f5->setText(QString::fromStdString(features1.at(4).printFull()));
    QCheckBox *f6 = ui->checkBox_16;
    f6->setText(QString::fromStdString(features2.at(0).printFull()));
    QCheckBox *f7 = ui->checkBox_17;
    f7->setText(QString::fromStdString(features2.at(1).printFull()));
    QCheckBox *f8 = ui->checkBox_18;
    f8->setText(QString::fromStdString(features2.at(2).printFull()));
    QCheckBox *f9 = ui->checkBox_19;
    f9->setText(QString::fromStdString(features2.at(3).printFull()));
    QCheckBox *f10 = ui->checkBox_20;
    f10->setText(QString::fromStdString(features2.at(4).printFull()));

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

    connect(this, SIGNAL(page2Ready()), this, SLOT(on_page2Ready()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_page3()));
    connect(this, SIGNAL(page3Ready()), this, SLOT(on_page3Ready()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_page4()));
    connect(this, SIGNAL(page4Ready()), this, SLOT(on_page4Ready()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_page5()));
    connect(this, SIGNAL(page5Ready()), this, SLOT(on_page5Ready()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_page6()));
    connect(this, SIGNAL(page6Ready()), this, SLOT(on_page6Ready()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_page7()));
    connect(this, SIGNAL(page7Ready()), this, SLOT(on_page7Ready()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_page8()));
    connect(this, SIGNAL(page8Ready()), this, SLOT(on_page8Ready()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(on_page9()));
    connect(this, SIGNAL(page9Ready()), this, SLOT(on_page9Ready()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_page10()));

}

void MainWindow::setPage3(){
    if(ui->radioButton->isChecked()){
        x1.setGender(Female);
    }else if(ui->radioButton_2->isChecked()){
        x1.setGender(Male);
    }else if(ui->radioButton_3->isChecked()){
        x1.setGender(Other);
    }
    if(ui->radioButton_7->isChecked()){
        x2.setGender(Female);
    }else if(ui->radioButton_8->isChecked()){
        x2.setGender(Male);
    }else if(ui->radioButton_9->isChecked()){
        x2.setGender(Other);
    }
    x1.setName(ui->lineEdit->text().toStdString());
    x2.setName(ui->lineEdit_2->text().toStdString());

    if(ui->radioButton_10->isChecked()){
        occu1 = occu.at(0);
        occu.push_back(occu.at(1));
        occu.push_back(occu.at(2));
    }else if(ui->radioButton_11->isChecked()){
        occu1 = occu.at(1);
        occu.push_back(occu.at(0));
        occu.push_back(occu.at(2));
    }else if(ui->radioButton_12->isChecked()){
        occu1 = occu.at(2);
        occu.push_back(occu.at(0));
        occu.push_back(occu.at(1));
    }
    per.changeOccu(1, occu1);
    occu.erase(occu.begin(), occu.begin()+3);
    if(ui->radioButton_13->isChecked()){
        occu2 = occu.at(0);
        occu.push_back(occu.at(1));
        occu.push_back(occu.at(2));
    }else if(ui->radioButton_14->isChecked()){
        occu2 = occu.at(1);
        occu.push_back(occu.at(0));
        occu.push_back(occu.at(2));
    }else if(ui->radioButton_15->isChecked()){
        occu2 = occu.at(2);
        occu.push_back(occu.at(0));
        occu.push_back(occu.at(1));
    }
    per.changeOccu(2, occu2);
    occu.erase(occu.begin(), occu.begin()+3);

    //traits
    if(ui->checkBox_5->isChecked()){
        traits1.push_back(traits.at(4));
    }
    if(ui->checkBox_4->isChecked()){
        traits1.push_back(traits.at(3));
    }
    if(ui->checkBox_3->isChecked()){
        traits1.push_back(traits.at(2));
    }
    if(ui->checkBox_2->isChecked()){
        traits1.push_back(traits.at(1));
    }
    if(ui->checkBox->isChecked()){
        traits1.push_back(traits.at(0));
    }
    traits.push_back(traits.at(0));
    traits.push_back(traits.at(1));
    traits.erase(traits.begin(), traits.begin()+5);
    if(ui->checkBox_10->isChecked()){
        traits2.push_back(traits.at(4));
    }
    if(ui->checkBox_9->isChecked()){
        traits2.push_back(traits.at(3));
    }
    if(ui->checkBox_8->isChecked()){
        traits2.push_back(traits.at(2));
    }
    if(ui->checkBox_7->isChecked()){
        traits2.push_back(traits.at(1));
    }
    if(ui->checkBox_6->isChecked()){
        traits2.push_back(traits.at(0));
    }
    traits.push_back(traits.at(0));
    traits.push_back(traits.at(1));
    traits.erase(traits.begin(), traits.begin()+5);

    //feature
    if(ui->checkBox_15->isChecked()){
        fea1.push_back(features.at(4));
    }
    if(ui->checkBox_14->isChecked()){
        fea1.push_back(features.at(3));
    }
    if(ui->checkBox_13->isChecked()){
        fea1.push_back(features.at(2));
    }
    if(ui->checkBox_12->isChecked()){
        fea1.push_back(features.at(1));
    }
    if(ui->checkBox_11->isChecked()){
        fea1.push_back(features.at(0));
    }
    features.push_back(features.at(0));
    features.push_back(features.at(1));
    features.erase(features.begin(), features.begin()+5);
    if(ui->checkBox_20->isChecked()){
        fea2.push_back(features.at(4));
    }
    if(ui->checkBox_19->isChecked()){
        fea2.push_back(features.at(3));
    }
    if(ui->checkBox_18->isChecked()){
        fea2.push_back(features.at(2));
    }
    if(ui->checkBox_17->isChecked()){
        fea2.push_back(features.at(1));
    }
    if(ui->checkBox_16->isChecked()){
        fea2.push_back(features.at(0));
    }
    features.push_back(features.at(0));
    features.push_back(features.at(1));
    features.erase(features.begin(), features.begin()+5);
    per.changeFeature(1, fea1.at(0));
    per.changeFeature(1, fea1.at(1));
    per.changeFeature(1, fea1.at(2));
    per.changeFeature(2, fea2.at(0));
    per.changeFeature(2, fea2.at(1));
    per.changeFeature(2, fea2.at(2));

    d1 = plot.getDestinies();
    d2 = plot.getDestinies();
    chapters = importChapters("chapters.txt", "chapterEffect.txt");
    sweetS = importScenes("scenesSweet.txt", "sceneEffectSweet.txt");
    seriousS = importScenes("scenesSerious.txt", "sceneEffectSerious.txt");
    dramaS = importScenes("scenesDrama.txt", "sceneEffectDrama.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

