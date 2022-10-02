#include "FogOfLove.h"

#include "qbuttongroup.h"
#include "ui_mainwindow.h"

void MainWindow::drawFill(){
    while (session.hand1.size() < 5) {
        switch (session.chapters.at(chapter-1).getDraw().at(0))
        {
        case Sweet:
            session.hand1.push_back(session.sweetS.at(0));
            session.sweetS.erase(session.sweetS.begin());
            break;
        case Serious:
            session.hand1.push_back(session.seriousS.at(0));
            session.seriousS.erase(session.seriousS.begin());
            break;
        case Drama:
            session.hand1.push_back(session.dramaS.at(0));
            session.dramaS.erase(session.dramaS.begin());
            break;
        }
    }
    while (session.hand2.size() < 5) {
        switch (session.chapters.at(chapter-1).getDraw().at(0))
        {
        case Sweet:
            session.hand2.push_back(session.sweetS.at(0));
            session.sweetS.erase(session.sweetS.begin());
            break;
        case Serious:
            session.hand2.push_back(session.seriousS.at(0));
            session.seriousS.erase(session.seriousS.begin());
            break;
        case Drama:
            session.hand2.push_back(session.dramaS.at(0));
            session.dramaS.erase(session.dramaS.begin());
            break;
        }
    }
}

void MainWindow::CO(int player){
    pages.erase(pages.begin());

    if(player==1){
        ui->stackedWidget->setCurrentIndex(5);
        ui->label_25->setText("CHANGE OCCUPATION");
        std::vector<Occupation> occus1 = { session.occu.at(0), session.occu.at(1), session.occu.at(2) };
        ui->radioButton_10->setText(QString::fromStdString(occus1.at(0).printFull()));
        ui->radioButton_11->setText(QString::fromStdString(occus1.at(1).printFull()));
        ui->radioButton_12->setText(QString::fromStdString(occus1.at(2).printFull()));
        QButtonGroup* occuGroup1 = new QButtonGroup;
        occuGroup1->addButton(ui->radioButton_10);
        occuGroup1->addButton(ui->radioButton_11);
        occuGroup1->addButton(ui->radioButton_12);

        if(pages.size()==0){
            ui->pushButton_8->setText("Back to Board");
            connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(to_Board()));
        }else if(pages.at(0)==5){
            ui->pushButton_8->setText("Next ("+QString::fromStdString(session.x2.getName())+")");
            //change the slot
            connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(go_page()));
        }
    }else{
        ui->stackedWidget->setCurrentIndex(6);
        ui->label_28->setText("CHANGE OCCUPATION");
        std::vector<Occupation> occus2 = { session.occu.at(0), session.occu.at(1), session.occu.at(2) };
        ui->radioButton_13->setText(QString::fromStdString(occus2.at(0).printFull()));
        ui->radioButton_14->setText(QString::fromStdString(occus2.at(1).printFull()));
        ui->radioButton_15->setText(QString::fromStdString(occus2.at(2).printFull()));
        QButtonGroup* occuGroup2 = new QButtonGroup;
        occuGroup2->addButton(ui->radioButton_13);
        occuGroup2->addButton(ui->radioButton_14);
        occuGroup2->addButton(ui->radioButton_15);
        ui->pushButton_9->setText("Back to Board");
        connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(go_page()));

    }


}


void MainWindow::SWO() {
    Occupation temp = session.occu1;
    session = CancelEffect(session, 1, session.occu1.getDim(), session.occu1.getDim());
    session = CancelEffect(session, 2, session.occu2.getDim(), session.occu2.getNum());
    session.occu1 = session.occu2;
    session.occu2 = temp;
    session = ApplyEffect(session, 1, session.occu1.getDim(), session.occu1.getDim());
    session = ApplyEffect(session, 2, session.occu2.getDim(), session.occu2.getNum());
};
