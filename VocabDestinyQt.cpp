#include "FogOfLove.h"

#include "qbuttongroup.h"
#include "ui_mainwindow.h"

void MainWindow::on_player1Destiny(){
    int temp1 = 4;
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
    if(ui->radioButton_4->isChecked()){
        temp1 = 0;
    }else if(ui->radioButton_5->isChecked()){
        temp1 = 1;
    }else if(ui->radioButton_6->isChecked()){
        temp1 = 2;
    }

    resolveEffectsCQt(temp1, 1);
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
    ui->page_13_destiny->update();
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::resolveEffectsCQt(int choice, int player){
    //only touches the destiny page
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

void MainWindow::changeDestiny(){

    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_32);
    choiceGroup1->addButton(ui->radioButton_31);
    choiceGroup1->addButton(ui->radioButton_30);
    choiceGroup1->addButton(ui->radioButton_29);
    choiceGroup1->addButton(ui->radioButton_28);
    choiceGroup1->addButton(ui->radioButton_27);
    choiceGroup1->setExclusive(false);

    QButtonGroup* choiceGroup2 = new QButtonGroup;
    choiceGroup2->addButton(ui->radioButton_35);
    choiceGroup2->addButton(ui->radioButton_34);
    choiceGroup2->addButton(ui->radioButton_37);
    choiceGroup2->addButton(ui->radioButton_38);
    choiceGroup2->addButton(ui->radioButton_33);
    choiceGroup2->addButton(ui->radioButton_36);
    choiceGroup2->setExclusive(false);

    if(ui->label_73->text().toStdString()==session.x1.getName()){
        int index = 0;
        std::vector<int> hand;
        std::vector<int> hand1;
        for (int i = 0; i < session.d1.size(); i++) {
            if (session.d1.at(i).getIn()) {
                hand.push_back(i);
                index++;
            }else{
                hand1.push_back(i);
            }
        }
        if(ui->radioButton_32->isChecked()){
            ui->radioButton_32->setChecked(false);
            session.d1.at(hand.at(5)).changeIn();
        }else if(ui->radioButton_31->isChecked()){
            ui->radioButton_31->setChecked(false);
            session.d1.at(hand.at(4)).changeIn();
        }else if(ui->radioButton_30->isChecked()){
            ui->radioButton_30->setChecked(false);
            session.d1.at(hand.at(3)).changeIn();
        }else if(ui->radioButton_29->isChecked()){
            ui->radioButton_29->setChecked(false);
            session.d1.at(hand.at(2)).changeIn();
        }else if(ui->radioButton_28->isChecked()){
            ui->radioButton_28->setChecked(false);
            session.d1.at(hand.at(1)).changeIn();
        }else if(ui->radioButton_27->isChecked()){
            ui->radioButton_27->setChecked(false);
            session.d1.at(hand.at(0)).changeIn();
        }

        if(ui->radioButton_36->isChecked()){
            ui->radioButton_36->setChecked(false);
            session.d1.at(hand1.at(5)).changeIn();
        }else if(ui->radioButton_33->isChecked()){
            ui->radioButton_33->setChecked(false);
            session.d1.at(hand1.at(4)).changeIn();
        }else if(ui->radioButton_38->isChecked()){
            ui->radioButton_38->setChecked(false);
            session.d1.at(hand1.at(3)).changeIn();
        }else if(ui->radioButton_37->isChecked()){
            ui->radioButton_37->setChecked(false);
            session.d1.at(hand1.at(2)).changeIn();
        }else if(ui->radioButton_34->isChecked()){
            ui->radioButton_34->setChecked(false);
            session.d1.at(hand1.at(1)).changeIn();
        }else if(ui->radioButton_33->isChecked()){
            ui->radioButton_33->setChecked(false);
            session.d1.at(hand1.at(0)).changeIn();
        }


    }else if(ui->label_73->text().toStdString()==session.x2.getName()){
        int index = 0;
        std::vector<int> hand;
        std::vector<int> hand1;
        for (int i = 0; i < session.d2.size(); i++) {
            if (session.d2.at(i).getIn()) {
                hand.push_back(i);
                index++;
            }
        }
        if(ui->radioButton_32->isChecked()){
            ui->radioButton_32->setChecked(false);
            session.d2.at(hand.at(5)).changeIn();
        }else if(ui->radioButton_31->isChecked()){
            ui->radioButton_31->setChecked(false);
            session.d2.at(hand.at(4)).changeIn();
        }else if(ui->radioButton_30->isChecked()){
            ui->radioButton_30->setChecked(false);
            session.d2.at(hand.at(3)).changeIn();
        }else if(ui->radioButton_29->isChecked()){
            ui->radioButton_29->setChecked(false);
            session.d2.at(hand.at(2)).changeIn();
        }else if(ui->radioButton_28->isChecked()){
            ui->radioButton_28->setChecked(false);
            session.d2.at(hand.at(1)).changeIn();
        }else if(ui->radioButton_27->isChecked()){
            ui->radioButton_27->setChecked(false);
            session.d2.at(hand.at(0)).changeIn();
        }


        if(ui->radioButton_36->isChecked()){
            ui->radioButton_36->setChecked(false);
            session.d2.at(hand1.at(5)).changeIn();
        }else if(ui->radioButton_33->isChecked()){
            ui->radioButton_33->setChecked(false);
            session.d2.at(hand1.at(4)).changeIn();
        }else if(ui->radioButton_38->isChecked()){
            ui->radioButton_38->setChecked(false);
            session.d2.at(hand1.at(3)).changeIn();
        }else if(ui->radioButton_37->isChecked()){
            ui->radioButton_37->setChecked(false);
            session.d2.at(hand1.at(2)).changeIn();
        }else if(ui->radioButton_34->isChecked()){
            ui->radioButton_34->setChecked(false);
            session.d2.at(hand1.at(1)).changeIn();
        }else if(ui->radioButton_33->isChecked()){
            ui->radioButton_33->setChecked(false);
            session.d2.at(hand1.at(0)).changeIn();
        }



    }
    choiceGroup1->setExclusive(true);
    choiceGroup2->setExclusive(true);

}

void MainWindow::RI(int player, std::string destiny){
    setPageDestiny(player);

    ui->stackedWidget->setCurrentIndex(12);
    ui->pushButton_24->setEnabled(true);
    int found = 0;
    if (player %2== 1) {
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getName() == destiny && session.d1.at(i).getIn()) {
                    ui->label_75->setText(ui->label_75->text()+QString::fromStdString("\n"+session.x2.getName()+" should know that "+session.x1.getName() + " has " + destiny) + " in hand.\n");
                    found = 1;
                }
            }
            if(found==0){
                ui->label_75->setText(ui->label_75->text()+QString::fromStdString("\n"+session.x2.getName()+" should know that "+session.x1.getName() + " does not have " + destiny) + " in hand.\n");
            }

    }
        else {
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getName() == destiny && session.d2.at(i).getIn()) {
                    ui->label_75->setText(ui->label_75->text()+QString::fromStdString("\n"+session.x1.getName()+" should know that "+session.x2.getName() + " has " + destiny) + " in hand.\n");
                    found = 1;
                }
            }
            if(found==0){
                ui->label_75->setText(ui->label_75->text()+QString::fromStdString("\n"+session.x1.getName()+" should know that "+session.x2.getName() + " does not have " + destiny) + " in hand.\n");
            }
    }
    pages.erase(pages.begin());

    if(pages.size()==0){
        ui->pushButton_24->setText("Back to Board");
    }else if(pages.at(0)==12){
        ui->pushButton_24->setText("Next ("+QString::fromStdString(session.x2.getName())+")");
    }
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
}

void MainWindow::RK(int player){
    setPageDestiny(player);
    ui->label_76->setVisible(false);
    //ui->label_73->setText(QString::fromStdString(session.x1.getName()));
    if(player==1){
        ui->label_74->setText(QString::fromStdString(session.x1.getName()+", choose 1 DESTINY to reveal:"));
    }else if (player==2){
        ui->label_74->setText(QString::fromStdString(session.x2.getName()+", choose 1 DESTINY to reveal:"));
    }else if(player==3){
        ui->label_74->setText(QString::fromStdString(session.x1.getName()+", choose 1 DESTINY to reveal and then discard:"));
    }else{
        ui->label_74->setText(QString::fromStdString(session.x2.getName()+", choose 1 DESTINY to reveal and then discard:"));
    }
    ui->pushButton_24->setDisabled(true);

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



            QButtonGroup* choiceGroup1 = new QButtonGroup;
            switch(index){
                case 6:
                ui->radioButton_32->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_32);
                connect(ui->radioButton_32, SIGNAL(clicked()), this, SLOT(on_RK()));
            case 5:
                ui->radioButton_31->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_31);
                connect(ui->radioButton_31, SIGNAL(clicked()), this, SLOT(on_RK()));
            case 4:
                ui->radioButton_30->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_30);
                connect(ui->radioButton_30, SIGNAL(clicked()), this, SLOT(on_RK()));
            case 3:
                ui->radioButton_29->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_29);
                connect(ui->radioButton_29, SIGNAL(clicked()), this, SLOT(on_RK()));
            case 2:
                ui->radioButton_28->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_28);
                connect(ui->radioButton_28, SIGNAL(clicked()), this, SLOT(on_RK()));
            case 1:
                ui->radioButton_27->setVisible(true);
                choiceGroup1->addButton(ui->radioButton_27);
                connect(ui->radioButton_27, SIGNAL(clicked()), this, SLOT(on_RK()));
            }


        ui->stackedWidget->setCurrentIndex(12);
        pages.erase(pages.begin());

    if(pages.size()==0){
        ui->pushButton_24->setText("Back to Board");

    }else{
        ui->pushButton_24->setText("Next");
    }
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
}

void MainWindow::RR(int player){
    srand(time(0));
    setPageDestiny(player);
    ui->label_76->setVisible(false);
    if(player==1){

    }else{

    }
    ui->pushButton_24->setDisabled(false);

        int index = 0;
        std::vector<int> hand;
        if(player==1){
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
            int temp = rand()/RAND_MAX*index;
            ui->label_75->setText("The randomly revealed DESTINY is:\n"+QString::fromStdString(session.d1.at(hand.at(temp)).printFull()));
        }else{
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
            int temp = rand()/RAND_MAX*index;
            ui->label_75->setText("The randomly revealed DESTINY is:\n"+QString::fromStdString(session.d2.at(hand.at(temp)).printFull()));
        }
        ui->stackedWidget->setCurrentIndex(12);
        pages.erase(pages.begin());

    if(pages.size()==0){
        ui->pushButton_24->setText("Back to Board");    
    }else{
        ui->pushButton_24->setText("Next");
    }
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
}

void MainWindow::SI(int player, std::string destiny){
    setPageDestiny(player);
    int index = 0;
    ui->label_76->setVisible(false);
    ui->pushButton_24->setEnabled(false);
    int SO = 8;
    std::vector<int> hand;

    if (player == 1) {
        int temp = 0;
        if (destiny == "ANY") {
            ui->label_76->setText(QString::fromStdString(session.x1.getName() + ", choose one DESTINY to swap in:"));
            for (int i = 0; i < session.d1.size(); i++) {
                if (!session.d1.at(i).getIn()) {
                    hand.push_back(i);
                    index++;
                }
            }
            switch (index) {
            case 6:
                ui->radioButton_36->setVisible(true);
            case 5:
                ui->radioButton_33->setVisible(true);
            case 4:
                ui->radioButton_38->setVisible(true);
            case 3:
                ui->radioButton_37->setVisible(true);
            case 2:
                ui->radioButton_34->setVisible(true);
            case 1:
                ui->radioButton_35->setVisible(true);
            }
        }
        else if(destiny=="HEARTBREAKER/HONORABLE EXIT") {
            int available = 0;
            int temp1 = 8;
            int temp2 = 8;
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getName() == "HEARTBREAKER" && !session.d1.at(i).getIn()) {

                    available++;
                    temp1 = i;
                }
                if (session.d1.at(i).getName() == "HONORABLE EXIT" && !session.d1.at(i).getIn()) {

                    available++;
                    temp2 = i;
                }
            }
            if (available == 0) {
                ui->label_76->setText(QString::fromStdString(session.x1.getName() + ", HEARTBREAKER and HONORABLE EXIT are already in your hand. No need to swap.\n"));

            }
            else if(available==1){
                if (temp2 == 8) {
                    ui->label_76->setText("HEARTBREAKER will be swapped in.");
                    temp = temp1;
                    SO = temp1;
                }
                else {
                    ui->label_76->setText("HONORABLE EXIT will be swapped in.");
                    temp = temp2;
                    SO = temp2;
                }
            }
            else {
                ui->label_76->setText("Choose to swap in HEARTBREAKER or HONORABLE EXIT:");
                ui->radioButton_34->setVisible(true);
                ui->radioButton_35->setVisible(true);
                hand.push_back(temp1);
                hand.push_back(temp2);
                temp = hand.at(select(2));
                SO = temp;
            }

        }
        else {
            for (int i = 0; i < session.d1.size(); i++) {
                if (session.d1.at(i).getName() == destiny && !session.d1.at(i).getIn()) {
                    ui->label_76->setText(QString::fromStdString(session.d1.at(i).getName()+" will be swapped in."));
                    temp = i;
                    SO = i;
                    break;
                }
            }
            if (temp == 8) {
                ui->label_76->setText(QString::fromStdString(destiny + " is already in your hand. No need to swap."));

            }
        }
        hand.clear();
        index = 0;
        ui->label_74->setText(QString::fromStdString(session.x1.getName() + ", choose one DESTINY to swap out:"));
        for (int i = 0; i < session.d1.size(); i++) {
            if (session.d1.at(i).getIn()) {

                hand.push_back(i);
                index++;
            }
        }
        switch (index) {
        case 6:
            ui->radioButton_32->setVisible(true);
        case 5:
            ui->radioButton_31->setVisible(true);
        case 4:
            ui->radioButton_30->setVisible(true);
        case 3:
            ui->radioButton_29->setVisible(true);
        case 2:
            ui->radioButton_28->setVisible(true);
        case 1:
            ui->radioButton_27->setVisible(true);
        }

        //session.d1.at(SO).changeIn();


    }
    else {
        int temp = 8;
        if (destiny == "ANY") {

            for (int i = 0; i < session.d2.size(); i++) {
                if (!session.d2.at(i).getIn()) {

                    hand.push_back(i);
                    index++;
                }
            }
            switch (index) {
            case 6:
                ui->radioButton_36->setVisible(true);
            case 5:
                ui->radioButton_33->setVisible(true);
            case 4:
                ui->radioButton_38->setVisible(true);
            case 3:
                ui->radioButton_37->setVisible(true);
            case 2:
                ui->radioButton_34->setVisible(true);
            case 1:
                ui->radioButton_35->setVisible(true);
            }

        }
        else if (destiny == "HEARTBREAKER/HONORABLE EXIT") {
            int available = 0;
            int temp1 = 8;
            int temp2 = 8;
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getName() == "HEARTBREAKER" && !session.d2.at(i).getIn()) {

                    available++;
                    temp1 = i;
                }
                if (session.d2.at(i).getName() == "HONORABLE EXIT" && !session.d2.at(i).getIn()) {

                    available++;
                    temp2 = i;
                }
            }
            if (available == 0) {
               ui->label_76->setText(QString::fromStdString(session.x2.getName() + ", HEARTBREAKER and HONORABLE EXIT are already in your hand. No need to swap.\n"));
            }
            else if (available == 1) {
                if (temp2 == 8) {
                    ui->label_76->setText("HEARTBREAKER will be swapped in.");
                    temp = temp1;
                    SO = temp1;
                }
                else {
                    ui->label_76->setText("HONORABLE EXIT will be swapped in.");
                    temp = temp2;
                    SO = temp2;
                }
            }
            else {
                ui->label_76->setText("Choose to swap in HEARTBREAKER or HONORABLE EXIT:");
                ui->radioButton_34->setVisible(true);
                ui->radioButton_35->setVisible(true);
                hand.push_back(temp1);
                hand.push_back(temp2);
                temp = hand.at(select(2));
                SO = temp;
            }

        }
        else {
            for (int i = 0; i < session.d2.size(); i++) {
                if (session.d2.at(i).getName() == destiny && !session.d2.at(i).getIn()) {
                    ui->label_76->setText(QString::fromStdString(session.d2.at(i).getName()+" will be swapped in."));
                    temp = i;
                    SO = i;
                    break;
                }
            }
            if (temp == 8) {
                 ui->label_76->setText(QString::fromStdString(destiny + " is already in your hand. No need to swap."));

        }
        hand.clear();
        index = 0;
        ui->label_74->setText(QString::fromStdString(session.x1.getName() + ", choose one DESTINY to swap out:"));
        for (int i = 0; i < session.d2.size(); i++) {
            if (session.d2.at(i).getIn()) {

                hand.push_back(i);
                index++;
            }
        }
        switch (index) {
        case 6:
            ui->radioButton_32->setVisible(true);
        case 5:
            ui->radioButton_31->setVisible(true);
        case 4:
            ui->radioButton_30->setVisible(true);
        case 3:
            ui->radioButton_29->setVisible(true);
        case 2:
            ui->radioButton_28->setVisible(true);
        case 1:
            ui->radioButton_27->setVisible(true);
        }


        }
    }

    ui->pushButton_24->setText("Confirm");
    ui->stackedWidget->setCurrentIndex(12);
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
    pages.erase(pages.begin());


}

void MainWindow::SO(int player, std::string destiny){
    setPageDestiny(player);
    int index = 0;
    ui->label_76->setVisible(false);
    ui->pushButton_24->setEnabled(false);
    int SO = 8;
    std::vector<int> hand;
    int temp = 8;
    if(player==1){

        for (int i = 0; i < session.d1.size(); i++) {
            if (session.d1.at(i).getName() == destiny && session.d1.at(i).getIn()) {
                ui->label_75->setText(QString::fromStdString(session.d1.at(i).getName()+" will be swapped out."));
                session.d1.at(i).changeIn();
                temp = i;
                SO = i;
                break;
            }
        }
        if (temp == 8) {
            ui->label_75->setText(QString::fromStdString(destiny+" is not in your hand. No need to swap.\n"));

        }else{
             ui->label_76->setText(QString::fromStdString(session.x1.getName() + ", choose one DESTINY to swap in:\n"));
            for (int i = 0; i < session.d1.size(); i++) {
                if (!session.d1.at(i).getIn()) {

                    hand.push_back(i);
                    index++;
                }
            }
            switch (index) {
            case 6:
                ui->radioButton_36->setVisible(true);
            case 5:
                ui->radioButton_33->setVisible(true);
            case 4:
                ui->radioButton_38->setVisible(true);
            case 3:
                ui->radioButton_37->setVisible(true);
            case 2:
                ui->radioButton_34->setVisible(true);
            case 1:
                ui->radioButton_35->setVisible(true);
            }
        }


    }else{
        for (int i = 0; i < session.d2.size(); i++) {
            if (session.d2.at(i).getName() == destiny && session.d2.at(i).getIn()) {
                ui->label_75->setText(QString::fromStdString(session.d2.at(i).getName()+" will be swapped out."));
                session.d2.at(i).changeIn();
                temp = i;
                SO = i;
                break;
            }
        }
        if (temp == 8) {
            ui->label_75->setText(QString::fromStdString(destiny+" is not in your hand. No need to swap.\n"));

        }else{
             ui->label_76->setText(QString::fromStdString(session.x2.getName() + ", choose one DESTINY to swap in:\n"));
            for (int i = 0; i < session.d2.size(); i++) {
                if (!session.d2.at(i).getIn()) {

                    hand.push_back(i);
                    index++;
                }
            }
        }
        switch (index) {
        case 6:
            ui->radioButton_36->setVisible(true);
        case 5:
            ui->radioButton_33->setVisible(true);
        case 4:
            ui->radioButton_38->setVisible(true);
        case 3:
            ui->radioButton_37->setVisible(true);
        case 2:
            ui->radioButton_34->setVisible(true);
        case 1:
            ui->radioButton_35->setVisible(true);
        }
    }
    ui->pushButton_24->setText("Confirm");
    ui->stackedWidget->setCurrentIndex(12);
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
    pages.erase(pages.begin());

}


void MainWindow::destinyEffectEnd(){
    changeDestiny();
    disconnect(ui->pushButton_24, SIGNAL(clicked()), 0, 0);
    resetChapterButtons();
    to_Board();
}


//destiny->back to board button
void MainWindow::on_b24Ready(){
    ui->pushButton_24->setEnabled(true);
}

void MainWindow::on_RK(){
    std::vector<Destiny> temp;
    std::vector<int> hand;
    if(ui->label_73->text()==QString::fromStdString(session.x1.getName())){
        temp = session.d1;
        ui->label_77->setText(QString::fromStdString(session.x2.getName()+" should know that "+session.x1.getName() + " has "));

        for (int i = 0; i < session.d1.size(); i++) {
            if (session.d1.at(i).getIn()) {
                hand.push_back(i);

            }
        }
    }else{
        temp = session.d2;
         ui->label_77->setText(QString::fromStdString(session.x1.getName()+" should know that "+session.x2.getName() + " has "));
        for (int i = 0; i < session.d2.size(); i++) {
            if (session.d2.at(i).getIn()) {
                hand.push_back(i);

            }
        }
    }
    if(ui->radioButton_32->isChecked()){
        ui->radioButton_32->setAutoExclusive(false);
        ui->radioButton_32->setChecked(false);
        ui->radioButton_32->setAutoExclusive(true);
         ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(5).getName() + " ."));
    }else if(ui->radioButton_31->isChecked()){
        ui->radioButton_31->setAutoExclusive(false);
        ui->radioButton_31->setChecked(false);
        ui->radioButton_31->setAutoExclusive(true);
        ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(4).getName() + " in hand."));
    }else if(ui->radioButton_30->isChecked()){
        ui->radioButton_30->setAutoExclusive(false);
        ui->radioButton_30->setChecked(false);
        ui->radioButton_30->setAutoExclusive(true);
        ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(3).getName() + " in hand."));
    }else if(ui->radioButton_29->isChecked()){
        ui->radioButton_29->setAutoExclusive(false);
        ui->radioButton_29->setChecked(false);
        ui->radioButton_29->setAutoExclusive(true);
        ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(2).getName() + " in hand."));
    }else if(ui->radioButton_28->isChecked()){
        ui->radioButton_28->setAutoExclusive(false);
        ui->radioButton_28->setChecked(false);
        ui->radioButton_28->setAutoExclusive(true);
        ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(1).getName() + " in hand."));
    }else if(ui->radioButton_27->isChecked()){
        ui->radioButton_27->setAutoExclusive(false);
        ui->radioButton_27->setChecked(false);
        ui->radioButton_27->setAutoExclusive(true);
        ui->label_77->setText(ui->label_77->text()+QString::fromStdString(temp.at(0).getName() + " in hand."));
    }

    ui->pushButton_24->setEnabled(true);
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(go_page()));
}

void MainWindow::resetChapterButtons(){
    disconnect(ui->pushButton_13, SIGNAL(clicked()), 0, 0);
    disconnect(ui->pushButton_15, SIGNAL(clicked()), 0, 0);

    QButtonGroup* choiceGroup1 = new QButtonGroup;
    choiceGroup1->addButton(ui->radioButton_4);
    choiceGroup1->addButton(ui->radioButton_5);
    choiceGroup1->addButton(ui->radioButton_6);
    choiceGroup1->setExclusive(false);

    QButtonGroup* choiceGroup2 = new QButtonGroup;
    choiceGroup2->addButton(ui->radioButton_19);
    choiceGroup2->addButton(ui->radioButton_20);
    choiceGroup2->addButton(ui->radioButton_21);
    choiceGroup2->setExclusive(false);

    if(ui->radioButton_4->isChecked()){
        ui->radioButton_4->setChecked(false);
    }else if(ui->radioButton_5->isChecked()){
        ui->radioButton_5->setChecked(false);
    }else if(ui->radioButton_6->isChecked()){
        ui->radioButton_6->setChecked(false);
    }

    if(ui->radioButton_19->isChecked()){
        ui->radioButton_19->setChecked(false);
    }else if(ui->radioButton_20->isChecked()){
        ui->radioButton_20->setChecked(false);
    }else if(ui->radioButton_21->isChecked()){
        ui->radioButton_21->setChecked(false);
    }
    choiceGroup1->setExclusive(true);
    choiceGroup2->setExclusive(true);
}
