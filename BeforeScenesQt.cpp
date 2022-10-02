#include "FogOfLove.h"
#include "qbuttongroup.h"
#include "ui_mainwindow.h"

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
    resetCharButtons();
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_page11(){

        setPageChapter1(chapter);
        ui->stackedWidget->setCurrentIndex(10);

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
    chapter = 1;
    counter = 0;
}

void MainWindow::resetCharButtons(){
    //reset gender buttons
    QButtonGroup* genderGroup1 = new QButtonGroup;
    genderGroup1->addButton(ui->radioButton);
    genderGroup1->addButton(ui->radioButton_2);
    genderGroup1->addButton(ui->radioButton_3);
    genderGroup1->setExclusive(false);
    if(ui->radioButton->isChecked()){
        ui->radioButton->setChecked(false);
    }else if(ui->radioButton_2->isChecked()){
        ui->radioButton_2->setChecked(false);
    }else if(ui->radioButton_3->isChecked()){
        ui->radioButton_3->setChecked(false);
    }
    genderGroup1->setExclusive(true);
    disconnect(ui->pushButton_4, SIGNAL(clicked()), 0, 0);

    QButtonGroup* genderGroup2 = new QButtonGroup;
    genderGroup2->addButton(ui->radioButton_7);
    genderGroup2->addButton(ui->radioButton_8);
    genderGroup2->addButton(ui->radioButton_9);
    genderGroup2->setExclusive(false);
    if(ui->radioButton_7->isChecked()){
        ui->radioButton_7->setChecked(false);
    }else if(ui->radioButton_8->isChecked()){
        ui->radioButton_8->setChecked(false);
    }else if(ui->radioButton_9->isChecked()){
        ui->radioButton_9->setChecked(false);
    }
    genderGroup2->setExclusive(true);
    disconnect(ui->pushButton_5, SIGNAL(clicked()), 0, 0);

    //reset trait buttons
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    disconnect(ui->pushButton_6, SIGNAL(clicked()), 0, 0);

    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    disconnect(ui->pushButton_6, SIGNAL(clicked()), 0, 0);

    //reset occu buttons
    QButtonGroup* occuGroup1 = new QButtonGroup;
    occuGroup1->addButton(ui->radioButton_10);
    occuGroup1->addButton(ui->radioButton_11);
    occuGroup1->addButton(ui->radioButton_12);
    occuGroup1->setExclusive(false);
    if(ui->radioButton_10->isChecked()){
        ui->radioButton_10->setChecked(false);
    }else if(ui->radioButton_11->isChecked()){
        ui->radioButton_11->setChecked(false);
    }else if(ui->radioButton_12->isChecked()){
        ui->radioButton_12->setChecked(false);
    }
    occuGroup1->setExclusive(true);
    disconnect(ui->pushButton_8, SIGNAL(clicked()), 0, 0);

    QButtonGroup* occuGroup2 = new QButtonGroup;
    occuGroup2->addButton(ui->radioButton_13);
    occuGroup2->addButton(ui->radioButton_14);
    occuGroup2->addButton(ui->radioButton_15);
    occuGroup2->setExclusive(false);
    if(ui->radioButton_13->isChecked()){
        ui->radioButton_13->setChecked(false);
    }else if(ui->radioButton_14->isChecked()){
        ui->radioButton_14->setChecked(false);
    }else if(ui->radioButton_15->isChecked()){
        ui->radioButton_15->setChecked(false);
    }
    occuGroup2->setExclusive(true);
    disconnect(ui->pushButton_9, SIGNAL(clicked()), 0, 0);

    //reset feature buttons
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_14->setChecked(false);
    ui->checkBox_15->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    disconnect(ui->pushButton_10, SIGNAL(clicked()), 0, 0);
    disconnect(ui->pushButton_11, SIGNAL(clicked()), 0, 0);

}
