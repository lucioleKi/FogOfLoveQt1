#include "FogOfLove.h"
#include "qbuttongroup.h"
#include "ui_mainwindow.h"


void MainWindow::on_player1Destiny(){
    int temp1 = 4;
    if(ui->radioButton_4->isChecked()){
        temp1 = 0;
    }else if(ui->radioButton_5->isChecked()){
        temp1 = 1;
    }else if(ui->radioButton_6->isChecked()){
        temp1 = 2;
    }

    resolveEffectsCQt(temp1, 1);

    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_player2Destiny(){
    changeDestiny();
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
    int temp2 = 4;
    if(ui->radioButton_19->isChecked()){
        temp2 = 0;
    }else if(ui->radioButton_20->isChecked()){
        temp2 = 1;
    }else if(ui->radioButton_21->isChecked()){
        temp2 = 2;
    }
    resolveEffectsCQt(temp2, 2);
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::cEffectEnd(){
    changeDestiny();
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
    to_Board();
}

void MainWindow::changeDestiny(){

    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_32);
    choiceGroup1->addButton(ui->radioButton_31);
    choiceGroup1->addButton(ui->radioButton_30);
    choiceGroup1->addButton(ui->radioButton_29);
    choiceGroup1->addButton(ui->radioButton_28);
    choiceGroup1->addButton(ui->radioButton_27);
    if(ui->label_73->text().toStdString()==session.x1.getName()){
        int index = 0;
        std::vector<int> hand;
        for (int i = 0; i < session.d1.size(); i++) {
            if (session.d1.at(i).getIn()) {
                hand.push_back(i);
                index++;
            }
        }
        if(ui->radioButton_32->isChecked()){
            ui->radioButton_32->setAutoExclusive(false);
            ui->radioButton_32->setChecked(false);
            ui->radioButton_32->setAutoExclusive(true);
            session.d1.at(hand.at(5)).changeIn();
        }else if(ui->radioButton_31->isChecked()){
            ui->radioButton_31->setAutoExclusive(false);
            ui->radioButton_31->setChecked(false);
            ui->radioButton_31->setAutoExclusive(true);
            session.d1.at(hand.at(4)).changeIn();
        }else if(ui->radioButton_30->isChecked()){
            ui->radioButton_30->setAutoExclusive(false);
            ui->radioButton_30->setChecked(false);
            ui->radioButton_30->setAutoExclusive(true);
            session.d1.at(hand.at(3)).changeIn();
        }else if(ui->radioButton_29->isChecked()){
            ui->radioButton_29->setAutoExclusive(false);
            ui->radioButton_29->setChecked(false);
            ui->radioButton_29->setAutoExclusive(true);
            session.d1.at(hand.at(2)).changeIn();
        }else if(ui->radioButton_28->isChecked()){
            ui->radioButton_28->setAutoExclusive(false);
            ui->radioButton_28->setChecked(false);
            ui->radioButton_28->setAutoExclusive(true);
            session.d1.at(hand.at(1)).changeIn();
        }else if(ui->radioButton_27->isChecked()){
            ui->radioButton_27->setAutoExclusive(false);
            ui->radioButton_27->setChecked(false);
            ui->radioButton_27->setAutoExclusive(true);
            session.d1.at(hand.at(0)).changeIn();
        }
    }else if(ui->label_73->text().toStdString()==session.x2.getName()){
        int index = 0;
        std::vector<int> hand;
        for (int i = 0; i < session.d2.size(); i++) {
            if (session.d2.at(i).getIn()) {
                hand.push_back(i);
                index++;
            }
        }
        if(ui->radioButton_32->isChecked()){
            ui->radioButton_32->setAutoExclusive(false);
            ui->radioButton_32->setChecked(false);
            ui->radioButton_32->setAutoExclusive(true);
            session.d2.at(hand.at(5)).changeIn();
        }else if(ui->radioButton_31->isChecked()){
            ui->radioButton_31->setAutoExclusive(false);
            ui->radioButton_31->setChecked(false);
            ui->radioButton_31->setAutoExclusive(true);
            session.d2.at(hand.at(4)).changeIn();
        }else if(ui->radioButton_30->isChecked()){
            ui->radioButton_30->setAutoExclusive(false);
            ui->radioButton_30->setChecked(false);
            ui->radioButton_30->setAutoExclusive(true);
            session.d2.at(hand.at(3)).changeIn();
        }else if(ui->radioButton_29->isChecked()){
            ui->radioButton_29->setAutoExclusive(false);
            ui->radioButton_29->setChecked(false);
            ui->radioButton_29->setAutoExclusive(true);
            session.d2.at(hand.at(2)).changeIn();
        }else if(ui->radioButton_28->isChecked()){
            ui->radioButton_28->setAutoExclusive(false);
            ui->radioButton_28->setChecked(false);
            ui->radioButton_28->setAutoExclusive(true);
            session.d2.at(hand.at(1)).changeIn();
        }else if(ui->radioButton_27->isChecked()){
            ui->radioButton_27->setAutoExclusive(false);
            ui->radioButton_27->setChecked(false);
            ui->radioButton_27->setAutoExclusive(true);
            session.d2.at(hand.at(0)).changeIn();
        }
    }

}

void MainWindow::on_b24Ready(){
    ui->pushButton_24->setEnabled(true);
}

void MainWindow::resolveEffectsCQt(int choice, int player){
    //goal is to enable the next button, either go to player 2 or to the board
    setPageDestiny(player);
    ui->pushButton_24->setDisabled(true);
    Choice c1 = session.chapters.at(chapter-1).getChoices().at(choice);
    if(c1.getCode().size() ==3 ) {
        int index = 0;
        std::vector<int> hand;
        if(player==1){
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
        }else{
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
        }

        if (hand.size() == 2) {
            ui->label_75->setText(ui->label_75->text()+"\nYou only have 2 DESTINIES in hand. You cannot discard a DESTINY now.");
            ui->pushButton_24->setEnabled(true);
            return;
        }

        else {
            ui->label_75->setText(ui->label_75->text()+"\nSelect a DESTINY to discard:\n");
            QButtonGroup* choiceGroup1 = new QButtonGroup;
            switch(index){
                case 6:
                ui->radioButton_32->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_32);
                connect(ui->radioButton_32, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 5:
                ui->radioButton_31->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_31);
                connect(ui->radioButton_31, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 4:
                ui->radioButton_30->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_30);
                connect(ui->radioButton_30, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 3:
                ui->radioButton_29->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_29);
                connect(ui->radioButton_29, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 2:
                ui->radioButton_28->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_28);
                connect(ui->radioButton_28, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 1:
                ui->radioButton_27->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_27);
                connect(ui->radioButton_27, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            }


        }
        ui->stackedWidget->setCurrentIndex(12);


    }
    else if (c1.getCode().size() == 7) {
        int index = 0;
        std::vector<int> hand;
        if(player==1){
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getIn()&& session.d1.at(i).getName() != c1.getCode().at(6)) {
                    hand.push_back(i);
                    index++;
                }
            }
        }else{
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getIn()&& session.d2.at(i).getName() != c1.getCode().at(6)) {
                    hand.push_back(i);
                    index++;
                }
            }
        }
        if (hand.size() == 2) {
            ui->label_75->setText(ui->label_75->text()+"\nYou only have 2 DESTINIES in hand. You cannot discard a DESTINY now.");
            ui->pushButton_24->setEnabled(true);
            return;
        }
        else {
            ui->label_75->setText(ui->label_75->text()+"\nSelect a DESTINY to discard:\n");
            QButtonGroup* choiceGroup1 = new QButtonGroup;
            switch(index){
                case 6:
                ui->radioButton_32->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_32);
                connect(ui->radioButton_32, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 5:
                ui->radioButton_31->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_31);
                connect(ui->radioButton_31, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 4:
                ui->radioButton_30->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_30);
                connect(ui->radioButton_30, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 3:
                ui->radioButton_29->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_29);
                connect(ui->radioButton_29, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 2:
                ui->radioButton_28->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_28);
                connect(ui->radioButton_28, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            case 1:
                ui->radioButton_27->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_27);
                connect(ui->radioButton_27, SIGNAL(clicked()), this, SLOT(on_b24Ready()));
            }
        }

    }

    if(player==1){
        ui->pushButton_24->setText(QString::fromStdString("Next ("+session.x2.getName()+")"));
        connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(on_player2Destiny()));
    }else{
        ui->pushButton_24->setText(QString::fromStdString("To the Board"));
        connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(cEffectEnd()));
    }

}