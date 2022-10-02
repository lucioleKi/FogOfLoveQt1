#include "FogOfLove.h"
#include "ResolveEffects.h"
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

void MainWindow::go_prevScene(){

    if(turn==1){
        for(int i=1; i<session.hand1.size(); i++){
            if(ui->label_87->text()==QString::fromStdString(session.hand1.at(i).printFull())){
                ui->label_87->setText(QString::fromStdString(session.hand1.at(i-1).printFull()));
                if(i==1){
                    ui->toolButton->setDisabled(true);
                }

                break;
            }
        }
    }else{
        for(int i=1; i<session.hand2.size(); i++){
            if(ui->label_87->text()==QString::fromStdString(session.hand2.at(i).printFull())){
                ui->label_87->setText(QString::fromStdString(session.hand2.at(i-1).printFull()));
                if(i==1){
                    ui->toolButton->setDisabled(true);
                }

                break;
            }
        }
    }


    ui->toolButton_2->setEnabled(true);
}

void MainWindow::go_nextScene(){

    if(turn==1){
        for(int i=session.hand1.size()-2; i>-1; i--){
            if(ui->label_87->text()==QString::fromStdString(session.hand1.at(i).printFull())){
                ui->label_87->setText(QString::fromStdString(session.hand1.at(i+1).printFull()));
                if(i==session.hand1.size()-2){
                    ui->toolButton_2->setDisabled(true);
                }

                break;
            }
        }
    }else{
        for(int i=session.hand2.size()-2; i>-1; i--){
            if(ui->label_87->text()==QString::fromStdString(session.hand2.at(i).printFull())){
                ui->label_87->setText(QString::fromStdString(session.hand2.at(i+1).printFull()));
                if(i==session.hand2.size()-2){
                    ui->toolButton_2->setDisabled(true);
                }

                break;
            }
        }
    }

    ui->toolButton->setEnabled(true);
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

void MainWindow::on_sceneReady(){
    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_39);
    choiceGroup1->addButton(ui->radioButton_40);
    choiceGroup1->addButton(ui->radioButton_41);
    choiceGroup1->addButton(ui->radioButton_45);
    QButtonGroup* choiceGroup2 = new QButtonGroup;
    choiceGroup2->addButton(ui->radioButton_42);
    choiceGroup2->addButton(ui->radioButton_43);
    choiceGroup2->addButton(ui->radioButton_44);
    choiceGroup2->addButton(ui->radioButton_46);
    if(choiceGroup1->checkedId()!=-1){
        ui->pushButton_28->setEnabled(true);
    }
    if(choiceGroup2->checkedId()!=-1){
        ui->pushButton_29->setEnabled(true);
    }
}


void MainWindow::on_page12(){
    if(ui->pushButton_13->isEnabled()){
        ui->pushButton_13->setVisible(false);
        ui->radioButton_4->setVisible(false);
        ui->radioButton_5->setVisible(false);
        ui->radioButton_6->setVisible(false);
        ui->label_52->setText(QString::fromStdString(session.x1.getName()+" has chosen."));
    }
    if(ui->pushButton_15->isEnabled()){
        ui->pushButton_15->setVisible(false);
        ui->radioButton_19->setVisible(false);
        ui->radioButton_20->setVisible(false);
        ui->radioButton_21->setVisible(false);
        ui->label_56->setText(QString::fromStdString(session.x2.getName()+" has chosen."));
    }
    if(!ui->radioButton_4->isVisible()&&!ui->radioButton_19->isVisible()){
        disconnect(ui->pushButton_13, SIGNAL(clicked()), 0, 0);
        disconnect(ui->pushButton_15, SIGNAL(clicked()), 0, 0);
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
        }
        if(chapter!=1){

            on_player1Destiny();

        }else{
            to_Board();
        }

        to_Board();
    }
}



void MainWindow::to_Board(){
    setBoard();
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::go_Destiny1(){
    disconnect(ui->pushButton_16, SIGNAL(clicked()), 0, 0);
    setPageDestiny(1);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::go_Destiny2(){
    disconnect(ui->pushButton_22, SIGNAL(clicked()), 0, 0);
    setPageDestiny(2);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::go_Traits1(){
    disconnect(ui->pushButton_17, SIGNAL(clicked()), 0, 0);
    setPageTraits(1);
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::go_Traits2(){
    disconnect(ui->pushButton_21, SIGNAL(clicked()), 0, 0);
    setPageTraits(2);
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::go_Secret1(){
    disconnect(ui->pushButton_19, SIGNAL(clicked()), 0, 0);
    setPageSecret(1);
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::go_Secret2(){
    disconnect(ui->pushButton_23, SIGNAL(clicked()), 0, 0);
    setPageSecret(2);
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::go_selectScene(){
    disconnect(ui->pushButton_14, SIGNAL(clicked()), 0, 0);
    setSceneSelect();
    ui->stackedWidget->setCurrentIndex(15);
}



void MainWindow::go_displayScene(){
    ui->label_92->setFixedHeight(21);
    ui->label_93->setFixedHeight(21);
    disconnect(ui->pushButton_27, SIGNAL(clicked()), 0, 0);
    disconnect(ui->pushButton_28, SIGNAL(clicked()), 0, 0);
    disconnect(ui->pushButton_29, SIGNAL(clicked()), 0, 0);

    if(turn==1){
        if(ui->radioButton_16->isChecked()){
            scene = session.hand1.at(0);
            session.hand1.erase(session.hand1.begin());
        }else if(ui->radioButton_17->isChecked()){
            scene = session.hand1.at(1);
            session.hand1.erase(session.hand1.begin()+1);
        }else if(ui->radioButton_18->isChecked()){
            scene = session.hand1.at(2);
            session.hand1.erase(session.hand1.begin()+2);
        }else if(ui->radioButton_22->isChecked()){
            scene = session.hand1.at(3);
            session.hand1.erase(session.hand1.begin()+3);
        }else if(ui->radioButton_23->isChecked()){
            scene = session.hand1.at(4);
            session.hand1.erase(session.hand1.begin()+4);
        }else if(ui->radioButton_24->isChecked()){
            scene = session.hand1.at(5);
            session.hand1.erase(session.hand1.begin()+5);
        }else if(ui->radioButton_25->isChecked()){
            scene = session.hand1.at(6);
            session.hand1.erase(session.hand1.begin()+6);
        }else if(ui->radioButton_26->isChecked()){
            scene = session.hand1.at(7);
            session.hand1.erase(session.hand1.begin()+7);
        }
    }else{
        if(ui->radioButton_16->isChecked()){
            scene = session.hand2.at(0);
            session.hand2.erase(session.hand2.begin());
        }else if(ui->radioButton_17->isChecked()){
            scene = session.hand2.at(1);
            session.hand2.erase(session.hand2.begin()+1);
        }else if(ui->radioButton_18->isChecked()){
            scene = session.hand2.at(2);
            session.hand2.erase(session.hand2.begin()+2);
        }else if(ui->radioButton_22->isChecked()){
            scene = session.hand2.at(3);
            session.hand2.erase(session.hand2.begin()+3);
        }else if(ui->radioButton_23->isChecked()){
            scene = session.hand2.at(4);
            session.hand2.erase(session.hand2.begin()+4);
        }else if(ui->radioButton_24->isChecked()){
            scene = session.hand2.at(5);
            session.hand2.erase(session.hand2.begin()+5);
        }else if(ui->radioButton_25->isChecked()){
            scene = session.hand2.at(6);
            session.hand2.erase(session.hand2.begin()+6);
        }else if(ui->radioButton_26->isChecked()){
            scene = session.hand2.at(7);
            session.hand2.erase(session.hand2.begin()+7);
        }
    }
    disconnect(ui->radioButton_16, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_17, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_18, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_22, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_23, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_24, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_25, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_26, SIGNAL(clicked()), 0, 0);
    setSceneDisplay();
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::go_discardRN(){
    drawFill();
    resetDisplayButton();
    go_selectScene();
}

void MainWindow::go_sceneB(){
    if(ui->pushButton_28->isEnabled()){
        ui->pushButton_28->setVisible(false);
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->label_92->setText(QString::fromStdString(session.x1.getName()+" has chosen."));
    }
    if(ui->pushButton_29->isEnabled()){
        ui->pushButton_29->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        ui->label_93->setText(QString::fromStdString(session.x2.getName()+" has chosen."));
    }
    if(!ui->radioButton_39->isVisible()&&!ui->radioButton_42->isVisible()){
        disconnect(ui->pushButton_28, SIGNAL(clicked()), 0, 0);
        disconnect(ui->pushButton_29, SIGNAL(clicked()), 0, 0);
        int temp1 = 5;
        int temp2 = 5;
        if(ui->radioButton_39->isChecked()){
            temp1 = 0;
            disconnect(ui->radioButton_39, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_40->isChecked()){
            temp1 = 1;
            disconnect(ui->radioButton_40, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_41->isChecked()){
            temp1 = 2;
            disconnect(ui->radioButton_41, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_45->isChecked()){
            temp1 = 3;
            disconnect(ui->radioButton_45, SIGNAL(clicked()), 0, 0);
        }

        if(ui->radioButton_42->isChecked()){
            temp2 = 0;
            disconnect(ui->radioButton_42, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_43->isChecked()){
            temp2 = 1;
            disconnect(ui->radioButton_43, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_44->isChecked()){
            temp2 = 2;
            disconnect(ui->radioButton_44, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_46->isChecked()){
            temp2 = 3;
            disconnect(ui->radioButton_46, SIGNAL(clicked()), 0, 0);
        }

        //resolve PT for choices
        bothPT(temp1, temp2);


        //resolve satisfaction
        int doubleImpact = 0;
        Choice c1 = scene.getChoices().at(temp1);
        Choice c2 = scene.getChoices().at(temp2);
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") - session.carryOver.begin();
            doubleImpact = std::stoi(session.carryOver.at(position+1));
        }
        if (doubleImpact == 0||turn==2) {
            if (c1.getCode().size() > 0) {
                pageSwitch(c1.getCode());


                resolveChoice(1, turn, c1.getCode());
            }else{


            }
        }
        if (doubleImpact == 0 || turn == 1) {
            if (c2.getCode().size() > 0) {
                pageSwitch(c2.getCode());


                resolveChoice(2, turn, c2.getCode());
            }else{

            }
        }
        if (doubleImpact == 1&&c2.getCode().size()>0) {
            pageSwitch(c2.getCode());


            resolveChoice(2, turn, c2.getCode());
        }else{

        }
        if (doubleImpact == 2 && c1.getCode().size() > 0) {
            pageSwitch(c1.getCode());


            resolveChoice(1, turn, c1.getCode());
        }else{

        }
        int position = matchChoice(scene, temp1, temp2, turn);
        if (position!= -1) {
            std::vector<std::string> effects = scene.getAddis().at(position).getCode();

            effects.erase(effects.begin());
            codePlayer cp = resolveCABCD(turn, scene, temp1, temp2, effects);
            int chooser = cp.chooser;
            pageSwitch(cp.code);

            resolveChoice(chooser, turn, cp.code);
        }


        counter++;
        if(turn==1){
            turn=2;
        }else if(turn==2){
            turn=1;
        }
        to_Board();
    }
}

void MainWindow::go_sceneP(){
    disconnect(ui->pushButton_28, SIGNAL(clicked()), 0, 0);
    disconnect(ui->pushButton_29, SIGNAL(clicked()), 0, 0);
    int temp = 5;
    int other = 0;
    if(turn==2){
        other = 1;
        if(ui->radioButton_39->isChecked()){
            temp = 0;
            disconnect(ui->radioButton_39, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_40->isChecked()){
            temp = 1;
            disconnect(ui->radioButton_40, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_41->isChecked()){
            temp = 2;
            disconnect(ui->radioButton_41, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_45->isChecked()){
            temp = 3;
            disconnect(ui->radioButton_45, SIGNAL(clicked()), 0, 0);
        }
    }else if(turn==1){
        other = 2;
        if(ui->radioButton_42->isChecked()){
            temp = 0;
            disconnect(ui->radioButton_42, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_43->isChecked()){
            temp = 1;
            disconnect(ui->radioButton_43, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_44->isChecked()){
            temp = 2;
            disconnect(ui->radioButton_44, SIGNAL(clicked()), 0, 0);
        }else if(ui->radioButton_46->isChecked()){
            temp = 3;
            disconnect(ui->radioButton_46, SIGNAL(clicked()), 0, 0);
        }
    }
    Choice c1 = scene.getChoices().at(temp);
    int double3 = 0;
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DoubleThree") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DoubleThree") - session.carryOver.begin();
            session.carryOver.erase(session.carryOver.begin() + position);
            double3 = 1;
        }
        int doubleImpact = 0;
        int doubleImpactB = 0;
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") - session.carryOver.begin();
            doubleImpact = std::stoi(session.carryOver.at(position + 1));
        }
        int doubleB = 0;
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACTPT") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACTPT") - session.carryOver.begin();
            doubleB = 1;
        }

        for (int i = 0; i < c1.getDims().size(); i++) {
            if (c1.getNums().at(i) > 0) {
                if (turn == 2) {
                    session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    if (doubleB != 0) {
                        session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    }
                    if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {

                            session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                        }
                    }

                }
                else {
                    session.per.change(2, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    if (doubleB != 0) {
                        session.per.change(2, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    }
                    if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {

                            session.per.change(2, c1.getDims().at(i) * 2, c1.getNums().at(i));
                        }
                    }

                }

            }
            else {
                if (turn == 2) {
                    session.per.change(1, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i)*(-1));
                    if (doubleB != 0) {
                        session.per.change(1, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                    }
                    if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {
                            session.per.change(1, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                        }
                    }


                }
                else {
                    session.per.change(2, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i)*(-1));
                    if (doubleB != 0) {
                        session.per.change(2, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                    }
                    if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {
                            session.per.change(2, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                        }
                    }

                }

            }
        }
        if (doubleImpact == 0) {
                resolveChoice(other, turn, c1.getCode());
        }
        else if (doubleImpact == other) {
                resolveChoice(other, turn, c1.getCode());
        }
        if(turn==1){
            turn=2;
        }else if(turn==2){
            turn=1;
        }
        counter++;
        to_Board();
}

void MainWindow::go_rSecret(){
    if(turn==1&&session.secret2.size()>0){
        scene = session.secret2.at(0);
        session.secret2.erase(session.secret2.begin());
        turn=2;
        counter++;
        setSecretDisplay();


    }else if(turn==2&&session.secret1.size()>0){
        scene = session.secret1.at(0);
        session.secret1.erase(session.secret1.begin());
        turn=1;
        counter++;
        setSecretDisplay();


    }else if(turn==1){
        turn=2;
        counter++;
        to_Board();
    }else if(turn==2){
        turn=1;
        counter++;
        to_Board();
    }
}

void MainWindow::go_resolution(){
    ui->label_76->setVisible(false);
    ui->label_77->setVisible(false);
    ui->radioButton_35->setVisible(false);
    ui->radioButton_34->setVisible(false);
    ui->radioButton_37->setVisible(false);
    ui->radioButton_38->setVisible(false);
    ui->radioButton_33->setVisible(false);
    ui->radioButton_36->setVisible(false);
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);

    ui->checkBox_21->setText(QString::fromStdString(session.x1.getName()));
    ui->checkBox_22->setText(QString::fromStdString(session.x2.getName()));
    ui->toolButton_3->setDisabled(true);
    ui->toolButton_4->setDisabled(true);
    ui->toolButton_5->setDisabled(true);
    ui->toolButton_6->setDisabled(true);
    ui->checkBox_21->setVisible(true);
    ui->checkBox_22->setVisible(true);
    connect(ui->checkBox_21, SIGNAL(clicked()), this, SLOT(go_finalD1()));
    connect(ui->checkBox_22, SIGNAL(clicked()), this, SLOT(go_finalD2()));
    connect(ui->toolButton_3, SIGNAL(clicked()), this, SLOT(go_displayD()));
    connect(ui->toolButton_5, SIGNAL(clicked()), this, SLOT(go_displayT()));
    connect(ui->toolButton_6, SIGNAL(clicked()), this, SLOT(go_displayFinal()));

    ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::go_finalD1(){
    resetDisplayButton();
    int index = 0;
    int temp = 8;
    std::vector<int> hand;
    ui->label_73->setText(QString::fromStdString(session.x1.getName()));
    ui->label_74->setText("Select a final DESTINY:");
    ui->label_75->setText("");
    for(int i=0; i<session.d1.size(); i++){
        if(session.d1.at(i).getIn()){
            ui->label_75->setText(ui->label_75->text()+QString::fromStdString(session.d1.at(i).printFull()+"\n"));
            //session.d1.at(i).changeIn();
            hand.push_back(i);
            index++;
        }
    }
    switch(index){
        case 6:
        ui->radioButton_32->setVisible(true);
        connect(ui->radioButton_32, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 5:
        ui->radioButton_31->setVisible(true);
        connect(ui->radioButton_31, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 4:
        ui->radioButton_30->setVisible(true);
        connect(ui->radioButton_30, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 3:
        ui->radioButton_29->setVisible(true);
        connect(ui->radioButton_29, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 2:
        ui->radioButton_28->setVisible(true);
        connect(ui->radioButton_28, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 1:
        ui->radioButton_27->setVisible(true);
        connect(ui->radioButton_27, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    }
    ui->pushButton_24->setText("Back");
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(return_resolution()));
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::go_finalD2(){
    resetDisplayButton();
    int index = 0;
    int temp = 8;
    std::vector<int> hand;
    ui->label_73->setText(QString::fromStdString(session.x2.getName()));
    ui->label_74->setText("Select a final DESTINY:");
    ui->label_75->setText("");
    for(int i=0; i<session.d2.size(); i++){
        if(session.d2.at(i).getIn()){
            ui->label_75->setText(ui->label_75->text()+QString::fromStdString(session.d2.at(i).printFull()+"\n"));
            //session.d2.at(i).changeIn();
            hand.push_back(i);
            index++;
        }
    }
    switch(index){
        case 6:
        ui->radioButton_32->setVisible(true);
        connect(ui->radioButton_32, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 5:
        ui->radioButton_31->setVisible(true);
        connect(ui->radioButton_31, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 4:
        ui->radioButton_30->setVisible(true);
        connect(ui->radioButton_30, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 3:
        ui->radioButton_29->setVisible(true);
        connect(ui->radioButton_29, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 2:
        ui->radioButton_28->setVisible(true);
        connect(ui->radioButton_28, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    case 1:
        ui->radioButton_27->setVisible(true);
        connect(ui->radioButton_27, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
    }
    ui->pushButton_24->setText("Back");
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(return_resolution()));
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::changeIn(int player, int d){
    int index = 0;
    std::vector<int> hand;
    if(player==1){
        for(int i=0; i<session.d1.size(); i++){
            if(session.d1.at(i).getIn()){
                session.d1.at(i).changeIn();
                hand.push_back(i);
                index++;
            }
        }
        session.d1.at(hand.at(d)).changeIn();
    }else{
        for(int i=0; i<session.d2.size(); i++){
            if(session.d2.at(i).getIn()){
                session.d2.at(i).changeIn();
                hand.push_back(i);
                index++;
            }
        }
        session.d2.at(hand.at(d)).changeIn();
    }

}

void MainWindow::return_resolution(){
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_32);
    choiceGroup1->addButton(ui->radioButton_31);
    choiceGroup1->addButton(ui->radioButton_30);
    choiceGroup1->addButton(ui->radioButton_29);
    choiceGroup1->addButton(ui->radioButton_28);
    choiceGroup1->addButton(ui->radioButton_27);
    choiceGroup1->setExclusive(false);
    int din = 0;

    if((ui->checkBox_22->isChecked()&&(!ui->checkBox_21->isVisible()))||ui->checkBox_22->isChecked()&&(!ui->checkBox_21->isChecked())){



        int index = 0;
        std::vector<int> hand;
        for(int i=0; i<session.d2.size(); i++){
            if(session.d2.at(i).getIn()){
                din++;
                hand.push_back(i);
                index++;
            }
        }
        if(din>1){
            if(ui->radioButton_32->isChecked()){
                ui->radioButton_32->setChecked(false);
                changeIn(2, 5);
                //session.d2.at(hand.at(5)).changeIn();
            }else if(ui->radioButton_31->isChecked()){
                ui->radioButton_31->setChecked(false);
                changeIn(2, 4);
                //session.d2.at(hand.at(4)).changeIn();
            }else if(ui->radioButton_30->isChecked()){
                ui->radioButton_30->setChecked(false);
                changeIn(2, 3);
                //session.d2.at(hand.at(3)).changeIn();
            }else if(ui->radioButton_29->isChecked()){
                ui->radioButton_29->setChecked(false);
                //session.d2.at(hand.at(2)).changeIn();
                changeIn(2, 2);
            }else if(ui->radioButton_28->isChecked()){
                changeIn(2, 1);
                ui->radioButton_28->setChecked(false);
                //session.d2.at(hand.at(1)).changeIn();
            }else if(ui->radioButton_27->isChecked()){
                ui->radioButton_27->setChecked(false);
                changeIn(2, 0);
                //session.d2.at(hand.at(0)).changeIn();
            }

        }
        ui->checkBox_22->setVisible(false);
        choiceGroup1->setExclusive(true);
    }
    if((ui->checkBox_21->isChecked()&&(!ui->checkBox_22->isVisible()))||(ui->checkBox_21->isChecked()&&(!ui->checkBox_22->isChecked()))){
        int index = 0;
        din = 0;
        std::vector<int> hand;
        for(int i=0; i<session.d1.size(); i++){
            if(session.d1.at(i).getIn()){
                din++;
                hand.push_back(i);
                index++;
            }
        }
        if(din>1){
            if(ui->radioButton_32->isChecked()){
                ui->radioButton_32->setChecked(false);
                changeIn(1, 5);
                //session.d1.at(hand.at(5)).changeIn();
            }else if(ui->radioButton_31->isChecked()){
                ui->radioButton_31->setChecked(false);
                changeIn(1, 4);
                //session.d1.at(hand.at(4)).changeIn();
            }else if(ui->radioButton_30->isChecked()){
                ui->radioButton_30->setChecked(false);
                changeIn(1, 3);
                //session.d1.at(hand.at(3)).changeIn();
            }else if(ui->radioButton_29->isChecked()){
                ui->radioButton_29->setChecked(false);
                changeIn(1, 2);
                //session.d1.at(hand.at(2)).changeIn();
            }else if(ui->radioButton_28->isChecked()){
                ui->radioButton_28->setChecked(false);
                changeIn(1, 1);
                //session.d1.at(hand.at(1)).changeIn();
            }else if(ui->radioButton_27->isChecked()){
                ui->radioButton_27->setChecked(false);
                changeIn(1, 0);
                //session.d1.at(hand.at(0)).changeIn();
            }

        }
        ui->checkBox_21->setVisible(false);
    }


    if(ui->checkBox_21->isChecked()&&ui->checkBox_22->isChecked()){
        ui->toolButton_3->setDisabled(false);
        ui->checkBox_21->setVisible(false);
        ui->checkBox_22->setVisible(false);
    }

    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::go_displayD(){
    ui->toolButton_3->setDisabled(true);
    disconnect(ui->toolButton_3, SIGNAL(clicked()), 0, 0);

    int destiny1 = 0;
    int destiny2 = 0;
    for (int i = 0; i < session.d1.size(); i++) {
        if (session.d1.at(i).getIn()) {
            destiny1 = i;
        }
        if(session.d2.at(i).getIn()){
            destiny2 = i;
        }
    }

    ui->label_214->setText(QString::fromStdString(session.x1.getName()+"\'s DESTINY: "+session.d1.at(findDestiny(session, 1)).getName()+"\n"+session.x2.getName()+"\'s DESTINY: "+session.d2.at(destiny2).getName()+"\n"));
    if(session.secret1.size()>0||session.secret2.size()>0){
        //ui->toolButton_4->setDisabled(false);

    }else{

    }
    ui->toolButton_5->setDisabled(false);
}

void MainWindow::go_displayT(){
    ui->toolButton_5->setDisabled(true);
    disconnect(ui->toolButton_5, SIGNAL(clicked()), 0, 0);

    ui->label_214->setText("");
        int number = 0;
        for (int i = 0; i < 3; i++) {
            PersonalityDim pd = session.traits1.at(i).getDim();
            int goal = session.traits1.at(i).getNum();
            if (session.traits1.at(i).getType() == Individual) {
                number = session.per.get1((int)pd) - session.per.get1(((int)pd) + 1);
            }
            else if (session.traits1.at(i).getType() == Shared) {
                number = session.per.getShared((int)pd) - session.per.getShared(((int)pd) + 1);
            }
            if (goal * (-1) < number && number < 0 || goal < number && number>0) {
                session.x1.setSatisfaction(3);
                ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x1.getName() + " achieved the TRAIT GOAL for " + session.traits1.at(i).getName() + ". \n"));
            }
            else {
                session.x1.setSatisfaction(-1);
                ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x1.getName() + " missed the TRAIT GOAL for " + session.traits1.at(i).getName() + ". \n"));
            }
        }
        for (int i = 0; i < 3; i++) {
            PersonalityDim pd = session.traits2.at(i).getDim();
            int goal = session.traits2.at(i).getNum();
            if (session.traits2.at(i).getType() == Individual) {
                number = session.per.get2((int)pd) - session.per.get2(((int)pd) + 1);
            }
            else if (session.traits2.at(i).getType() == Shared) {
                number = session.per.getShared((int)pd) - session.per.getShared(((int)pd) + 1);
            }
            if (goal * (-1) < number && number < 0 || goal < number && number>0) {
                session.x2.setSatisfaction(3);
                ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x2.getName() + " achieved the TRAIT GOAL for " + session.traits2.at(i).getName() + ". \n"));
            }
            else {
                session.x2.setSatisfaction(-1);
                ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x2.getName() + " missed the TRAIT GOAL for " + session.traits2.at(i).getName() + ". \n"));
            }
        }
    ui->toolButton_6->setDisabled(false);
}

void MainWindow::go_displayFinal(){
    ui->toolButton_6->setDisabled(true);
    disconnect(ui->toolButton_6, SIGNAL(clicked()), 0, 0);

    ui->label_214->setText("");

    if (fullfilDestiny(session, 1, findDestiny(session, 1), findDestiny(session,2))) {
        ui->label_214->setText(QString::fromStdString(session.x1.getName() + " has fulfilled the DESTINY: " + session.d1.at(findDestiny(session, 1)).getName() + ". Congrats!\n"));
    }
    else {
        ui->label_214->setText(QString::fromStdString(session.x1.getName() + " did not fulfill the DESTINY: " + session.d1.at(findDestiny(session, 1)).getName() + "\n"));
    }
    if (fullfilDestiny(session, 2, findDestiny(session, 1), findDestiny(session, 2))) {
        ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x2.getName() + " has fulfilled the DESTINY: " + session.d2.at(findDestiny(session, 2)).getName() + ". Congrats!\n"));
    }
    else {
        ui->label_214->setText(ui->label_214->text()+QString::fromStdString(session.x2.getName() + " did not fulfill the DESTINY: " + session.d2.at(findDestiny(session, 2)).getName() + "\n"));
    }
    ui->pushButton_56->setEnabled(true);
}

void MainWindow::setPageChapter1(int c){
    ui->pushButton_13->setDisabled(true);
    ui->pushButton_13->setVisible(true);
    ui->pushButton_15->setDisabled(true);
    ui->pushButton_15->setVisible(true);
    ui->radioButton_4->setVisible(true);
    ui->radioButton_5->setVisible(true);
    ui->radioButton_6->setVisible(true);
    ui->radioButton_19->setVisible(true);
    ui->radioButton_20->setVisible(true);
    ui->radioButton_21->setVisible(true);
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
    drawFill();
    resetDisplayButton();
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
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
    //next turn button, can go to next chapter
    if(counter==session.chapters.at(chapter-1).getLength()&&chapter==session.chapters.size()){
        ui->pushButton_14->setText("Next Turn (Resolution)");
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(go_resolution()));
    }else if(counter==session.chapters.at(chapter-1).getLength()){
        chapter++;
        ui->pushButton_14->setText("Next Turn (Chapter "+QString::fromStdString(std::to_string(chapter))+")");
        counter = 0;
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(on_page11()));
    }else if(turn==1){
        ui->pushButton_14->setText("Next Turn ("+QString::fromStdString(session.x1.getName())+")");
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(go_selectScene()));
    }else{
        ui->pushButton_14->setText("Next Turn ("+QString::fromStdString(session.x2.getName())+")");
        connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(go_selectScene()));
    }

}

void MainWindow::setPageDestiny(int c){
    ui->pushButton_24->setEnabled(true);
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(to_Board()));
    ui->label_75->setText("");
    ui->label_77->setText("");
    ui->radioButton_27->setVisible(false);
    ui->radioButton_28->setVisible(false);
    ui->radioButton_29->setVisible(false);
    ui->radioButton_30->setVisible(false);
    ui->radioButton_31->setVisible(false);
    ui->radioButton_32->setVisible(false);

    ui->radioButton_35->setVisible(false);
    ui->radioButton_34->setVisible(false);
    ui->radioButton_37->setVisible(false);
    ui->radioButton_38->setVisible(false);
    ui->radioButton_33->setVisible(false);
    ui->radioButton_36->setVisible(false);

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
    }else if(c==1){
        for(int i=0; i<session.secret1.size(); i++){
            ui->label_82->setText(ui->label_82->text()+QString::fromStdString(session.secret1.at(i).printFull()+"\n"));
        }
    }else if(c==2){
        for(int i=0; i<session.secret2.size(); i++){
            ui->label_82->setText(ui->label_82->text()+QString::fromStdString(session.secret2.at(i).printFull()+"\n"));
        }
    }
}

void MainWindow::setSceneSelect(){
    ui->radioButton_16->setVisible(false);
    ui->radioButton_17->setVisible(false);
    ui->radioButton_18->setVisible(false);
    ui->radioButton_22->setVisible(false);
    ui->radioButton_23->setVisible(false);
    ui->radioButton_24->setVisible(false);
    ui->radioButton_25->setVisible(false);
    ui->radioButton_26->setVisible(false);
    ui->pushButton_27->setDisabled(true);
    ui->label_87->clear();
    ui->toolButton->setDisabled(true);
    ui->toolButton_2->setEnabled(true);

    if(turn==1){
        ui->label_84->setText(QString::fromStdString(session.x1.getName()));
        ui->label_87->setText(QString::fromStdString(session.hand1.at(0).printFull()));
    }else{
        ui->label_84->setText(QString::fromStdString(session.x2.getName()));
        ui->label_87->setText(QString::fromStdString(session.hand2.at(0).printFull()));
    }

    switch(session.hand1.size()){
        case 8:
        ui->radioButton_26->setVisible(true);
        connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 7:
        ui->radioButton_25->setVisible(true);
        connect(ui->radioButton_25, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 6:
        ui->radioButton_24->setVisible(true);
        connect(ui->radioButton_24, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 5:
        ui->radioButton_23->setVisible(true);
        connect(ui->radioButton_23, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 4:
        ui->radioButton_22->setVisible(true);
        connect(ui->radioButton_22, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 3:
        ui->radioButton_18->setVisible(true);
        connect(ui->radioButton_18, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 2:
        ui->radioButton_17->setVisible(true);
        connect(ui->radioButton_17, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    case 1:
        ui->radioButton_16->setVisible(true);
        connect(ui->radioButton_16, SIGNAL(clicked()), this, SLOT(on_selectReady()));
    }
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(go_prevScene()));
    connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(go_nextScene()));
    connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(go_displayScene()));
}

void MainWindow::setSecretDisplay(){
    ui->label_86->clear();
    ui->label_118->clear();
    ui->radioButton_39->setVisible(true);
    ui->radioButton_40->setVisible(true);
    ui->radioButton_41->setVisible(true);
    ui->radioButton_45->setVisible(true);
    ui->radioButton_42->setVisible(true);
    ui->radioButton_43->setVisible(true);
    ui->radioButton_44->setVisible(true);
    ui->radioButton_46->setVisible(true);
    ui->pushButton_28->setVisible(true);
    ui->pushButton_29->setVisible(true);
    ui->label_92->setVisible(true);
    ui->label_93->setVisible(true);

    //additional effects
    ui->label_120->setVisible(true);
    ui->line_33->setVisible(true);
    ui->line_34->setVisible(true);

    ui->label_117->setText(QString::fromStdString(scene.getTitle()));
    ui->label_116->setText(QString::fromStdString(scene.getLine()));
    ui->label_92->setText(QString::fromStdString(session.x1.getName()));
    ui->label_93->setText(QString::fromStdString(session.x2.getName()));

    std::vector<std::string> alphabet = {"A", "B", "C", "D"};

    ui->label_115->setText("SECRET");
    if(scene.getExplain()!="N"){
        ui->label_86->setText(QString::fromStdString(scene.getExplain()+scene.getAddis().at(0).getFull()));
    }
    if(scene.getWho()=='T'){
        ui->label_86->setText(ui->label_86->text()+QString::fromStdString("If revealed:\n"+scene.getAddis().at(1).getFull()));
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        resolveChoice(turn, turn, scene.getAddis().at(1).getCode());
        if(turn==1){
            ui->pushButton_28->setVisible(false);
            ui->pushButton_29->setDisabled(false);
            turn=2;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_28->setDisabled(false);
            ui->pushButton_29->setVisible(false);
            turn=1;
            counter++;
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }
    }else if(scene.getWho()=='C'){
        ui->pushButton_28->setDisabled(true);
        ui->pushButton_29->setDisabled(true);
        ui->label_86->setText(ui->label_86->text()+QString::fromStdString("\nIf revealed, PARTNER CHOOSES:\n"));
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
        }
        if(turn==1){
            ui->label_92->setVisible(false);
            ui->label_93->setText(QString::fromStdString(session.x2.getName()));
            ui->pushButton_28->setVisible(false);
            ui->pushButton_29->setText("Submit");
            ui->radioButton_39->setVisible(false);
            ui->radioButton_40->setVisible(false);
            ui->radioButton_41->setVisible(false);
            ui->radioButton_45->setVisible(false);
            switch (scene.getChoices().size()){
                case 2:
                ui->radioButton_44->setVisible(false);
            case 3:
                ui->radioButton_46->setVisible(false);
            }
            connect(ui->radioButton_42, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_43, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_44, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_46, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_sceneP()));
        }else{
            ui->label_93->setVisible(false);
            ui->label_92->setText(QString::fromStdString(session.x1.getName()));
            ui->pushButton_29->setVisible(false);
            ui->pushButton_28->setText("Submit");

            ui->radioButton_42->setVisible(false);
            ui->radioButton_43->setVisible(false);
            ui->radioButton_44->setVisible(false);
            ui->radioButton_46->setVisible(false);
            switch (scene.getChoices().size()){
                case 2:
                ui->radioButton_41->setVisible(false);
            case 3:
                ui->radioButton_45->setVisible(false);

            }
            connect(ui->radioButton_39, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_40, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_41, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_45, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_sceneP()));
        }



    }

    ui->page_17_playScene->update();
    //ui->stackedWidget->setCurrentIndex(16);

}

void MainWindow::setSceneDisplay(){
    //disconnect buttons from selectScene
    disconnect(ui->radioButton_16, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_17, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_18, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_22, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_23, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_24, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_25, SIGNAL(clicked()), 0, 0);
    disconnect(ui->radioButton_26, SIGNAL(clicked()), 0, 0);
    disconnect(ui->toolButton, SIGNAL(clicked()), 0, 0);
    disconnect(ui->toolButton_2, SIGNAL(clicked()), 0, 0);

    //clear choice and add
    ui->label_86->clear();
    ui->label_118->clear();
    ui->radioButton_39->setVisible(true);
    ui->radioButton_40->setVisible(true);
    ui->radioButton_41->setVisible(true);
    ui->radioButton_45->setVisible(true);
    ui->radioButton_42->setVisible(true);
    ui->radioButton_43->setVisible(true);
    ui->radioButton_44->setVisible(true);
    ui->radioButton_46->setVisible(true);
    ui->pushButton_28->setVisible(true);
    ui->pushButton_28->setDisabled(true);
    ui->pushButton_29->setVisible(true);
    ui->pushButton_29->setDisabled(true);
    ui->label_92->setVisible(true);
    ui->label_93->setVisible(true);

    //additional effects
    ui->label_120->setVisible(true);
    ui->line_33->setVisible(true);
    ui->line_34->setVisible(true);

    ui->label_117->setText(QString::fromStdString(scene.getTitle()));
    ui->label_116->setText(QString::fromStdString(scene.getLine()));
    ui->label_92->setText(QString::fromStdString(session.x1.getName()));
    ui->label_93->setText(QString::fromStdString(session.x2.getName()));

    std::vector<std::string> alphabet = {"A", "B", "C", "D"};
    if(scene.getWho()=='R'){
        ui->label_115->setText("REACTION");
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
        }
        ui->label_120->setText("MINOR SCENE");
        ui->label_118->setText("Does not count towards CHAPTER LENGTH.\nYou may discard this SCENE face up at the beginning of your turn and draw a new one.");
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        if(turn==1){
            ui->label_92->setFixedHeight(61);
            ui->label_92->setText(QString::fromStdString(session.x1.getName())+", discard the reaction as a minor scene.");
            ui->pushButton_28->setDisabled(false);
            ui->pushButton_28->setText("OK");
            ui->pushButton_29->setDisabled(true);
            ui->pushButton_29->setVisible(false);
            ui->label_93->setVisible(false);
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_discardRN()));
        }else if(turn==2){
            ui->label_93->setFixedHeight(61);
            ui->label_93->setText(QString::fromStdString(session.x2.getName())+", discard the reaction as a minor scene.");
            ui->pushButton_28->setDisabled(true);
            ui->pushButton_29->setDisabled(false);
            ui->pushButton_29->setText("OK");
            ui->pushButton_28->setVisible(false);
            ui->label_92->setVisible(false);
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_discardRN()));
        }
    }else if(scene.getWho()=='N'){
        ui->label_115->setText("REACTION");
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
        }
        ui->label_120->setText("MINOR SCENE");
        ui->label_118->setText("Does not count towards CHAPTER LENGTH.\nYou may discard this SCENE face up at the beginning of your turn and draw a new one.");
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        if(turn==1){
            ui->label_92->setFixedHeight(61);
            ui->label_92->setText(QString::fromStdString(session.x1.getName())+", discard this reaction as a minor scene.");
            ui->pushButton_28->setDisabled(false);
            ui->pushButton_29->setDisabled(true);
            ui->pushButton_29->setVisible(false);
            ui->label_93->setVisible(false);
            ui->pushButton_28->setText("OK");
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_discardRN()));
        }else if(turn==2){
            ui->label_93->setFixedHeight(61);
            ui->label_93->setText(QString::fromStdString(session.x1.getName())+", discard this reaction as a minor scene.");
            ui->pushButton_28->setDisabled(true);
            ui->pushButton_29->setDisabled(false);
            ui->pushButton_28->setVisible(false);
            ui->label_92->setVisible(false);
            ui->pushButton_29->setText("OK");
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_discardRN()));
        }
    }

    if(scene.getWho()=='B'){
        ui->pushButton_28->setDisabled(true);
        ui->pushButton_29->setDisabled(true);
        ui->pushButton_28->setText("Submit");
        ui->pushButton_29->setText("Submit");
        ui->label_115->setText("BOTH CHOOSE");
        if(scene.getExplain()!="N"){
            ui->label_86->setText(QString::fromStdString(scene.getExplain()+"\n"));
        }
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(alphabet.at(i)+" = "+scene.getChoices().at(i).printFull()));
        }
        ui->label_120->setText("ADDITIONAL EFFECTS");
        for(int i=0; i<scene.getAddis().size(); i++){
            ui->label_118->setText(ui->label_118->text()+QString::fromStdString(scene.getAddis().at(i).getFull()+"\n"));
        }
        ui->label_92->setText(QString::fromStdString(session.x1.getName()));
        ui->label_93->setText(QString::fromStdString(session.x2.getName()));
        switch (scene.getChoices().size()){
            case 2:
            ui->radioButton_41->setVisible(false);
            ui->radioButton_44->setVisible(false);
        case 3:
            ui->radioButton_45->setVisible(false);
            ui->radioButton_46->setVisible(false);
        }
        //choices
        connect(ui->radioButton_39, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_40, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_41, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_45, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_42, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_43, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_44, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
        connect(ui->radioButton_46, SIGNAL(clicked()), this, SLOT(on_sceneReady()));

        //submit
        connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_sceneB()));
        connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_sceneB()));

    }else if(scene.getWho()=='P'){


        ui->label_115->setText("PARTNER CHOOSES");

        if(scene.getExplain()!="N"){
            ui->label_86->setText(QString::fromStdString(scene.getExplain()+"\n"));
        }
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(alphabet.at(i)+" = "+scene.getChoices().at(i).printFull()));
        }
        //additional effects invisible
        ui->label_120->setVisible(false);
        ui->line_33->setVisible(false);
        ui->line_34->setVisible(false);



        if(turn==1){
            ui->label_92->setVisible(false);
            ui->label_93->setText(QString::fromStdString(session.x2.getName()));
            ui->pushButton_28->setVisible(false);
            ui->pushButton_29->setText("Submit");
            ui->pushButton_29->setDisabled(true);
            ui->radioButton_39->setVisible(false);
            ui->radioButton_40->setVisible(false);
            ui->radioButton_41->setVisible(false);
            ui->radioButton_45->setVisible(false);
            switch (scene.getChoices().size()){
                case 2:
                ui->radioButton_44->setVisible(false);
            case 3:
                ui->radioButton_46->setVisible(false);
            }
            connect(ui->radioButton_42, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_43, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_44, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_46, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_sceneP()));
        }else{
            ui->label_92->setText(QString::fromStdString(session.x1.getName()));
            ui->label_93->setVisible(false);
            ui->pushButton_28->setDisabled(true);
            ui->pushButton_28->setText("Submit");
            ui->pushButton_29->setVisible(false);
            ui->radioButton_42->setVisible(false);
            ui->radioButton_43->setVisible(false);
            ui->radioButton_44->setVisible(false);
            ui->radioButton_46->setVisible(false);
            switch (scene.getChoices().size()){
                case 2:
                ui->radioButton_41->setVisible(false);
            case 3:
                ui->radioButton_45->setVisible(false);
            }
            connect(ui->radioButton_39, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_40, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_41, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->radioButton_45, SIGNAL(clicked()), this, SLOT(on_sceneReady()));
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_sceneP()));

        }
    }else if(scene.getWho()=='S'){
        ui->label_115->setText("SITUATION");
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
        }
        setSituation();


    }else if(scene.getWho()=='E'){
        ui->label_115->setText("SPECIAL EFFECT");
        for(int i=0; i<scene.getChoices().size(); i++){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
        }
        ui->label_120->setVisible(false);
        ui->line_33->setVisible(false);
        ui->line_34->setVisible(false);
        //invisible option buttons for both players
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        if(turn==2){
            ui->pushButton_28->setVisible(false);

            session.secret2.push_back(scene);

            ui->pushButton_29->setText("OK");
            ui->pushButton_29->setDisabled(false);
            ui->label_92->setVisible(false);
            ui->label_93->setText(QString::fromStdString(session.x2.getName()));
            turn=1;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_29->setVisible(false);
            session.secret1.push_back(scene);
            ui->pushButton_28->setText("OK");
            ui->pushButton_28->setDisabled(false);
            ui->label_93->setVisible(false);
            ui->label_92->setText(QString::fromStdString(session.x1.getName()));
            turn=2;
            counter++;
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }
    }else if(scene.getWho()=='T'||scene.getWho()=='C'){
        ui->label_115->setText("SECRET");
        if(scene.getExplain()!="N"){
            ui->label_86->setText(QString::fromStdString(scene.getExplain()+scene.getAddis().at(0).getFull()));
        }
        if(scene.getWho()=='T'){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString("If revealed:\n"+scene.getAddis().at(1).getFull()));
        }else if(scene.getWho()=='C'){
            ui->label_86->setText(ui->label_86->text()+QString::fromStdString("\nIf revealed, PARTNER CHOOSES:\n"));
            for(int i=0; i<scene.getChoices().size(); i++){
                ui->label_86->setText(ui->label_86->text()+QString::fromStdString(scene.getChoices().at(i).printFull()));
            }

        }
        ui->label_120->setVisible(false);
        ui->line_33->setVisible(false);
        ui->line_34->setVisible(false);
        //invisible option buttons for both players
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        if(turn==2){
            ui->pushButton_28->setVisible(false);

            session.secret2.push_back(scene);

            ui->pushButton_29->setText("OK");
            ui->pushButton_29->setDisabled(false);
            ui->label_92->setVisible(false);
            ui->label_93->setText(QString::fromStdString(session.x2.getName()));
            turn=1;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_29->setVisible(false);
            session.secret1.push_back(scene);
            ui->pushButton_28->setText("OK");
            ui->pushButton_28->setDisabled(false);
            ui->label_93->setVisible(false);
            ui->label_92->setText(QString::fromStdString(session.x1.getName()));
            turn=2;
            counter++;
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }



    }else if(scene.getWho()=='V'){
        //can discard or reveal
        ui->label_115->setText("REVEAL SECRET");
        ui->label_86->setText("Reveal one of your PARTNER'S SECRETS in play. All consequences of the SECRET are resolved immediately.");
        ui->label_120->setText("MINOR SCENE");
        ui->label_118->setText("Does not count towards CHAPTER LENGTH.\nYou may discard this SCENE face up at the beginning of your turn and draw a new one.");
        ui->pushButton_28->setText("Reveal");
        ui->pushButton_29->setText("Discard");
        ui->pushButton_29->setEnabled(true);
        //choices invisible
        ui->radioButton_39->setVisible(false);
        ui->radioButton_40->setVisible(false);
        ui->radioButton_41->setVisible(false);
        ui->radioButton_45->setVisible(false);
        ui->radioButton_42->setVisible(false);
        ui->radioButton_43->setVisible(false);
        ui->radioButton_44->setVisible(false);
        ui->radioButton_46->setVisible(false);
        //todo: reveal secret connect button_28
        if(turn==1){
            ui->label_93->setVisible(false);

        }else{
            ui->label_92->setVisible(false);
        }
        connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(go_rSecret()));
        connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(go_discardRN()));
    }


}

void MainWindow::setSituation(){
    ui->radioButton_39->setVisible(false);
    ui->radioButton_40->setVisible(false);
    ui->radioButton_41->setVisible(false);
    ui->radioButton_45->setVisible(false);
    ui->radioButton_42->setVisible(false);
    ui->radioButton_43->setVisible(false);
    ui->radioButton_44->setVisible(false);
    ui->radioButton_46->setVisible(false);
    ui->label_92->setText(QString::fromStdString(session.x1.getName()));
    ui->label_93->setText(QString::fromStdString(session.x2.getName()));
    if(scene.getIndex()==34){
        //remote cabin, RR

        ui->label_120->setText("DESTINY");
        int index = 0;
        std::vector<int> hand;
        if(turn==2){
            ui->pushButton_29->setText("Next");
            ui->pushButton_29->setEnabled(true);
            ui->pushButton_28->setVisible(false);
            ui->label_92->setVisible(false);
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
            int temp = rand()/RAND_MAX*index;
            ui->label_118->setText("The randomly revealed DESTINY of "+QString::fromStdString(session.x1.getName())+" is:\n"+QString::fromStdString(session.d1.at(hand.at(temp)).printFull()));
            turn=1;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_29->setVisible(false);
             ui->pushButton_28->setEnabled(true);
            ui->pushButton_28->setText("Next");
            ui->label_93->setVisible(false);
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
            int temp = rand()/RAND_MAX*index;
            ui->label_118->setText("The randomly revealed DESTINY is:\n"+QString::fromStdString(session.x2.getName())+""+QString::fromStdString(session.d2.at(hand.at(temp)).printFull()));
            turn=2;
            counter++;
            ui->pushButton_28->setVisible(true);
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }

    }else if(scene.getIndex()==19){
        ui->label_120->setVisible(false);
        ui->line_33->setVisible(false);
        ui->line_34->setVisible(false);
        //change trait
        if(turn==1){
            ui->pushButton_28->setText("Next");
             ui->pushButton_28->setEnabled(true);
            ui->pushButton_29->setVisible(false);
            ui->label_93->setVisible(false);
            turn=2;
            counter++;
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_29->setText("Next");
             ui->pushButton_29->setEnabled(true);
            ui->pushButton_28->setVisible(false);
            ui->label_93->setVisible(false);
            turn=1;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }
    }else{
        //trade
        ui->label_120->setVisible(false);
        ui->line_33->setVisible(false);
        ui->line_34->setVisible(false);
        if(turn==1){
            ui->pushButton_28->setText("Next");
             ui->pushButton_28->setEnabled(true);
            ui->pushButton_29->setVisible(false);
            ui->label_93->setVisible(false);
            turn=2;
            counter++;
            connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else{
            ui->pushButton_29->setText("Next");
             ui->pushButton_29->setEnabled(true);
            ui->pushButton_28->setVisible(false);
            ui->label_92->setVisible(false);
            turn=1;
            counter++;
            connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(to_Board()));
        }
    }
}

void MainWindow::resetDisplayButton(){
    QButtonGroup* selectGroup1 = new QButtonGroup;
    selectGroup1->addButton(ui->radioButton_16);
    selectGroup1->addButton(ui->radioButton_17);
    selectGroup1->addButton(ui->radioButton_18);
    selectGroup1->addButton(ui->radioButton_22);
    selectGroup1->addButton(ui->radioButton_23);
    selectGroup1->addButton(ui->radioButton_24);
    selectGroup1->addButton(ui->radioButton_25);
    selectGroup1->addButton(ui->radioButton_26);
    selectGroup1->setExclusive(false);
    if(ui->radioButton_16->isChecked()){
        ui->radioButton_16->setChecked(false);
    }else if(ui->radioButton_17->isChecked()){
        ui->radioButton_17->setChecked(false);
    }else if(ui->radioButton_18->isChecked()){
        ui->radioButton_18->setChecked(false);
    }else if(ui->radioButton_22->isChecked()){
        ui->radioButton_22->setChecked(false);
    }else if(ui->radioButton_23->isChecked()){
        ui->radioButton_23->setChecked(false);
    }else if(ui->radioButton_24->isChecked()){
        ui->radioButton_24->setChecked(false);
    }else if(ui->radioButton_25->isChecked()){
        ui->radioButton_25->setChecked(false);
    }else if(ui->radioButton_26->isChecked()){
        ui->radioButton_26->setChecked(false);
    }
    selectGroup1->setExclusive(true);

    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_39);
    choiceGroup1->addButton(ui->radioButton_40);
    choiceGroup1->addButton(ui->radioButton_41);
    choiceGroup1->addButton(ui->radioButton_45);
    choiceGroup1->setExclusive(false);
    if(ui->radioButton_39->isChecked()){
        ui->radioButton_39->setChecked(false);
    }else if(ui->radioButton_40->isChecked()){
        ui->radioButton_40->setChecked(false);
    }else if(ui->radioButton_41->isChecked()){
        ui->radioButton_41->setChecked(false);
    }else if(ui->radioButton_45->isChecked()){
        ui->radioButton_45->setChecked(false);
    }
    choiceGroup1->setExclusive(true);
    QButtonGroup* choiceGroup2 = new QButtonGroup;
    choiceGroup2->addButton(ui->radioButton_42);
    choiceGroup2->addButton(ui->radioButton_43);
    choiceGroup2->addButton(ui->radioButton_44);
    choiceGroup2->addButton(ui->radioButton_46);
    choiceGroup2->setExclusive(false);
    if(ui->radioButton_42->isChecked()){
        ui->radioButton_42->setChecked(false);
    }else if(ui->radioButton_43->isChecked()){
        ui->radioButton_43->setChecked(false);
    }else if(ui->radioButton_44->isChecked()){
        ui->radioButton_44->setChecked(false);
    }else if(ui->radioButton_46->isChecked()){
        ui->radioButton_46->setChecked(false);
    }
    choiceGroup2->setExclusive(true);

    QButtonGroup* choiceChapter1 = new QButtonGroup;
    choiceChapter1->addButton(ui->radioButton_4);
    choiceChapter1->addButton(ui->radioButton_5);
    choiceChapter1->addButton(ui->radioButton_6);
    choiceChapter1->setExclusive(false);
    if(ui->radioButton_4->isChecked()){
        ui->radioButton_4->setChecked(false);
    }else if(ui->radioButton_5->isChecked()){
        ui->radioButton_5->setChecked(false);
    }else if(ui->radioButton_6->isChecked()){
        ui->radioButton_6->setChecked(false);
    }
    choiceChapter1->setExclusive(true);

    QButtonGroup* choiceChapter2 = new QButtonGroup;
    choiceChapter2->addButton(ui->radioButton_19);
    choiceChapter2->addButton(ui->radioButton_20);
    choiceChapter2->addButton(ui->radioButton_21);
    choiceChapter2->setExclusive(false);
    if(ui->radioButton_19->isChecked()){
        ui->radioButton_19->setChecked(false);
    }else if(ui->radioButton_20->isChecked()){
        ui->radioButton_20->setChecked(false);
    }else if(ui->radioButton_21->isChecked()){
        ui->radioButton_21->setChecked(false);
    }
    choiceChapter2->setExclusive(true);

    QButtonGroup* destinyGroup1 = new QButtonGroup;
    destinyGroup1->addButton(ui->radioButton_27);
    destinyGroup1->addButton(ui->radioButton_28);
    destinyGroup1->addButton(ui->radioButton_29);
    destinyGroup1->addButton(ui->radioButton_30);
    destinyGroup1->addButton(ui->radioButton_31);
    destinyGroup1->addButton(ui->radioButton_32);
    destinyGroup1->setExclusive(false);
    if(ui->radioButton_27->isChecked()){
        ui->radioButton_27->setChecked(false);
    }else if(ui->radioButton_28->isChecked()){
        ui->radioButton_28->setChecked(false);
    }else if(ui->radioButton_29->isChecked()){
        ui->radioButton_29->setChecked(false);
    }else if(ui->radioButton_30->isChecked()){
        ui->radioButton_30->setChecked(false);
    }else if(ui->radioButton_31->isChecked()){
        ui->radioButton_31->setChecked(false);
    }else if(ui->radioButton_32->isChecked()){
        ui->radioButton_32->setChecked(false);
    }
    destinyGroup1->setExclusive(true);

    QButtonGroup* destinyGroup2 = new QButtonGroup;
    destinyGroup2->addButton(ui->radioButton_35);
    destinyGroup2->addButton(ui->radioButton_34);
    destinyGroup2->addButton(ui->radioButton_37);
    destinyGroup2->addButton(ui->radioButton_38);
    destinyGroup2->addButton(ui->radioButton_33);
    destinyGroup2->addButton(ui->radioButton_36);
    destinyGroup2->setExclusive(false);
    if(ui->radioButton_35->isChecked()){
        ui->radioButton_35->setChecked(false);
    }else if(ui->radioButton_34->isChecked()){
        ui->radioButton_34->setChecked(false);
    }else if(ui->radioButton_37->isChecked()){
        ui->radioButton_37->setChecked(false);
    }else if(ui->radioButton_38->isChecked()){
        ui->radioButton_38->setChecked(false);
    }else if(ui->radioButton_33->isChecked()){
        ui->radioButton_33->setChecked(false);
    }else if(ui->radioButton_36->isChecked()){
        ui->radioButton_36->setChecked(false);
    }
    destinyGroup2->setExclusive(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

