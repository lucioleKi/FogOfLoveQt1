#include "FogOfLove.h"
#include "qbuttongroup.h"
#include "ui_mainwindow.h"

void MainWindow::go_page(){
    if(pages.size()==0){
        changeDestiny();
        if(turn==1){
            turn=2;
        }else{
            turn = 1;
        }
        counter++;
        to_Board();
    }else{
        changeDestiny();
        ui->stackedWidget->setCurrentIndex(pages.at(0));
    }
}

void MainWindow::bothPT(int temp1, int temp2){
    Choice c1 = scene.getChoices().at(temp1);
    Choice c2 = scene.getChoices().at(temp2);
    //special effects for PT
        int double3 = 0;
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DoubleThree") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DoubleThree") - session.carryOver.begin();
            session.carryOver.erase(session.carryOver.begin() + position);
            double3 = 1;
        }

        int doubleB = 0;
        if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACTPT") != session.carryOver.end()) {
            int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACTPT") - session.carryOver.begin();
            doubleB = 1;
        }


        for (int i = 0; i < c1.getDims().size(); i++) {
                if (c1.getNums().at(i) > 0) {
                    session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    if (doubleB != 0) {
                        session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    }
                    if (scene.getIndex() == 20 && scene.getDeck() == Sweet) {
                        session.per.change(2, c1.getDims().at(i) * 2, c1.getNums().at(i));
                    }
                    else if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {
                            session.per.change(1, c1.getDims().at(i) * 2, c1.getNums().at(i));
                        }
                    }
                }
                else {
                    session.per.change(1, c1.getDims().at(i) * 2 + 1, (c1.getNums().at(i)) * (-1));
                    if (doubleB != 0) {
                        session.per.change(1, c1.getDims().at(i) * 2 + 1, (c1.getNums().at(i)) * (-1));
                    }
                    if (scene.getIndex() == 20 && scene.getDeck() == Sweet) {
                        session.per.change(2, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                    }
                    else if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {
                            session.per.change(1, c1.getDims().at(i) * 2 + 1, c1.getNums().at(i) * (-1));
                        }
                    }
                }
            }


        for (int i = 0; i < c2.getDims().size(); i++) {
                if (c2.getNums().at(i) > 0) {
                    session.per.change(2, c2.getDims().at(i) * 2, c2.getNums().at(i));
                    if (doubleB != 0) {
                        session.per.change(2, c2.getDims().at(i) * 2, c2.getNums().at(i));
                    }
                    if (scene.getIndex() == 20 && scene.getDeck() == Sweet) {
                        session.per.change(1, c2.getDims().at(i) * 2, c2.getNums().at(i));
                    }
                    else if (double3 == 1) {
                        if (c2.getDims().at(i) == 3) {
                            session.per.change(2, c2.getDims().at(i) * 2, c2.getNums().at(i));
                        }
                    }
                }
                else {
                    session.per.change(2, c2.getDims().at(i) * 2 + 1, (c2.getNums().at(i)) * (-1));
                    if (doubleB != 0) {
                        session.per.change(2, c2.getDims().at(i) * 2 + 1, (c2.getNums().at(i)) * (-1));
                    }
                    if (scene.getIndex() == 20 && scene.getDeck() == Sweet) {
                        session.per.change(1, c2.getDims().at(i) * 2 + 1, c2.getNums().at(i) * (-1));
                    }
                    else if (double3 == 1) {
                        if (c1.getDims().at(i) == 3) {
                            session.per.change(2, c2.getDims().at(i) * 2 + 1, c2.getNums().at(i) * (-1));
                        }
                    }
                }
            }


}

void MainWindow::resolveChoice(int chooser, int player, std::vector<std::string> code){
    codeT = code;

    int doubleimpact = 0;
    int doubleImpactB = 0;
    if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") != session.carryOver.end()) {
        int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") - session.carryOver.begin();
        doubleimpact = std::stoi(session.carryOver.at(position+1));
    }
    if (std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") != session.carryOver.end()) {
        int position = std::find(session.carryOver.begin(), session.carryOver.end(), "DOUBLEIMPACT") - session.carryOver.begin();
        doubleImpactB = 1;
    }
    int index = 0;

    if(codeT.size()>1&&codeT.at(0)=="B"){
        if (codeT.at(1).find_first_of("0123456789") != std::string::npos) {
            if (doubleimpact == 1) {
                session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                session.x2.setSatisfaction(std::stoi(codeT.at(1))*(-1));
            }
            else if(doubleimpact == 2){
                session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                session.x1.setSatisfaction(std::stoi(codeT.at(1)) * (-1));
            }
            if (doubleImpactB == 1) {
                session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                session.x2.setSatisfaction(std::stoi(codeT.at(1)));
            }
            session.x1.setSatisfaction(std::stoi(codeT.at(1)));
            session.x2.setSatisfaction(std::stoi(codeT.at(1)));
            codeT.erase(codeT.begin() + 1);

        }
        if(codeT.size()>1){
            if (std::find(codeT.begin(), codeT.end(), "SWO") != codeT.end()) {
                int position = std::find(codeT.begin(), codeT.end(), "SWO") - codeT.begin();
                SWO();
                codeT.erase(codeT.begin() + position);
            }

        }

        if(codeT.size()>1&&codeT.at(1)!="PA"&&pages.size()>0){

            if(pages.at(0)==12){
                if (std::find(codeT.begin(), codeT.end(), "RI") != codeT.end()) {
                    //destiny
                    int position = std::find(codeT.begin(), codeT.end(), "RI") - codeT.begin();
                    RI(1, codeT.at(position + 1));
                    codeT.erase(codeT.begin() + position, codeT.begin() + position + 2);
                }
                if (std::find(codeT.begin(), codeT.end(), "RK") != codeT.end()) {
                    //destiny
                    int position = std::find(codeT.begin(), codeT.end(), "RK") - codeT.begin();
                    RK(1);
                    codeT.erase(codeT.begin() + position);

                }
                if (std::find(codeT.begin(), codeT.end(), "RR") != codeT.end()) {
                    int position = std::find(codeT.begin(), codeT.end(), "RR") - codeT.begin();
                    RR(1);
                    codeT.erase(codeT.begin() + position);
                }
                if (std::find(codeT.begin(), codeT.end(), "SI") != codeT.end()) {
                    int position = std::find(codeT.begin(), codeT.end(), "SI") - codeT.begin();
                    SI(1, codeT.at(position+1));
                    codeT.erase(codeT.begin() + position, codeT.begin() + position + 2);
                }
                if (std::find(codeT.begin(), codeT.end(), "DD") != codeT.end()) {
                    int position = std::find(codeT.begin(), codeT.end(), "DD") - codeT.begin();

                    codeT.erase(codeT.begin() + position, codeT.begin() + position + 2);
                }
            }else if(pages.at(0)==5){
                int position = std::find(codeT.begin(), codeT.end(), "CO") - code.begin();

                codeT.erase(codeT.begin() + position);
            }else if(pages.at(0)==3){

            }else if(pages.at(0)==4){

            }else if(pages.at(0)==22){

            }else if(pages.at(0)==14){

            }
        }
    }else if(codeT.size()>1&&std::find(codeT.begin(), codeT.end(), "OT") != codeT.end()) {
        std::vector<std::string> OT;
        int other = std::find(codeT.begin(), codeT.end(), "OT") - codeT.begin();
        if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {

            if (chooser == 2) {
                session.x1.setSatisfaction(std::stoi(codeT.at(other + 1)));
                if (doubleImpactB == 1) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(other+1)));
                }
            }
            else {
                if (doubleImpactB == 1) {
                    session.x2.setSatisfaction(std::stoi(codeT.at(other+1)));
                }
                session.x2.setSatisfaction(std::stoi(codeT.at(other + 1)));
            }
            if (doubleimpact!=0) {
                if (doubleimpact == chooser) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(other + 1)));
                }
                else {
                    session.x2.setSatisfaction(std::stoi(codeT.at(other + 1))*(-1));
                }
            }
            codeT.erase(codeT.begin() + other + 1);
        }


        while (other + 1 + index < codeT.size()) {
            OT.push_back(codeT.at(other + 1 + index));
            index++;
        }

        while (OT.size() > 0&&pages.size()>0) {
            if (std::find(OT.begin(), OT.end(), "DR") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "DR") - OT.begin();
                session = drawScene(session, chooser, "OT", OT.at(position+1));
                OT.erase(OT.begin() + position, OT.begin() + position + 2);
            }
            if (std::find(OT.begin(), OT.end(), "SI") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "SI") - OT.begin();

                OT.erase(OT.begin() + position, OT.begin() + position + 2);
            }
            if (std::find(OT.begin(), OT.end(), "SO") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "SO") - OT.begin();

                OT.erase(OT.begin() + position, OT.begin() + position + 2);
            }
            if (std::find(OT.begin(), OT.end(), "DD") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "DD") - OT.begin();

                OT.erase(OT.begin() + position, OT.begin() + position + 2);
            }
            if (std::find(OT.begin(), OT.end(), "RE") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "RE") - OT.begin();

                OT.erase(OT.begin() + position, OT.begin() + position + 2);
            }
            if (std::find(OT.begin(), OT.end(), "DoubleThree") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "DoubleThree")-OT.begin();
                OT.erase(OT.begin() + position);
            }
            if (std::find(OT.begin(), OT.end(), "RSS") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "RSS") - OT.begin();
                OT.erase(OT.begin() + position);
            }
            if (std::find(OT.begin(), OT.end(), "CO") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "CO") - OT.begin();

                OT.erase(OT.begin() + position);
            }
            if (std::find(OT.begin(), OT.end(), "CRT") != OT.end()) {
                int position = std::find(OT.begin(), OT.end(), "CRT") - OT.begin();
                if (turn == 1) {

                }
                else {

                }

                OT.erase(OT.begin() + position);
            }
        }
        codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
    }else if (codeT.size()>0&&std::find(codeT.begin(), codeT.end(), "CH") != codeT.end()) {
        std::vector<std::string> CH;

        //chooser action
        if (codeT.at(1).find_first_of("0123456789") != std::string::npos) {
            if (chooser == 1) {
                session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                if (doubleImpactB == 1) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            else {
                session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                if (doubleImpactB == 1) {
                    session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            if (doubleimpact != 0) {
                if (doubleimpact == chooser) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(1))*(-1));
                }
                else {
                    session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            codeT.erase(codeT.begin() + 1);
        }


        while (CH.size() > 0&&pages.size()>0) {
            if (std::find(CH.begin(), CH.end(), "DR") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "DR") - CH.begin();
                session = drawScene(session, chooser, "CH", CH.at(position+1));
                CH.erase(CH.begin() + position, CH.begin() + position + 2);

            }
            if (std::find(CH.begin(), CH.end(), "RD") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "RD") - CH.begin();
                RK(chooser);
                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "RR") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "RR") - CH.begin();

                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "SI") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "SI") - CH.begin();

                if (position != 0 && CH.at(position - 1) == "MAY") {

                    CH.erase(CH.begin() + position - 1, CH.begin() + position + 2);
                }
                else {

                    CH.erase(CH.begin() + position, CH.begin() + position + 2);
                }

            }
            if (std::find(CH.begin(), CH.end(), "SO") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "SO") - CH.begin();

                CH.erase(CH.begin() + position, CH.begin() + position + 2);
            }
            if (std::find(CH.begin(), CH.end(), "DD") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "DD") - CH.begin();

                CH.erase(CH.begin() + position, CH.begin() + position + 2);
            }
            if (std::find(CH.begin(), CH.end(), "RE") != CH.end()) {

                int position = std::find(CH.begin(), CH.end(), "RE") - CH.begin();

                CH.erase(CH.begin() + position, CH.begin() + position + 2);
            }
            if (std::find(CH.begin(), CH.end(), "DS") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "DS") - CH.begin();

                CH.erase(CH.begin() + position, CH.begin() + position + 2);
            }
            if (std::find(CH.begin(), CH.end(), "DOUBLEIMPACT") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "DOUBLEIMPACT") - CH.begin();
                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "STELL") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "STELL") - CH.begin();

                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "CTT") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "CTT") - CH.begin();
                if(turn==1){

                }else{

                }
                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "CRT") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "CRT") - CH.begin();
                if(turn==1){

                }else{

                }
                CH.erase(CH.begin() + position);
            }
            if (std::find(CH.begin(), CH.end(), "RS") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "RS") - CH.begin();
                CH.erase(CH.begin() + position);
            }

            if (std::find(CH.begin(), CH.end(), "RSALL") != CH.end()) {
                int position = std::find(CH.begin(), CH.end(), "RSALL") - CH.begin();
                CH.erase(CH.begin() + position);
            }

        }

        codeT.erase(codeT.begin(), codeT.begin() + index + 1);
    }else if (codeT.size()>0&&std::find(codeT.begin(), codeT.end(), "PA") != codeT.end()) {
        std::vector<std::string> PA;
        int other = std::find(codeT.begin(), codeT.end(), "PA") - codeT.begin();
        if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {
            if (player == 1) {
                session.x2.setSatisfaction(std::stoi(codeT.at(other + 1)));
                if (doubleImpactB == 1) {
                    session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            else {
                session.x1.setSatisfaction(std::stoi(codeT.at(other + 1)));
                if (doubleImpactB == 1) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            if (doubleimpact != 0) {
                if (doubleimpact == player) {
                    session.x2.setSatisfaction(std::stoi(codeT.at(other + 1)));
                }
                else {
                    session.x1.setSatisfaction(std::stoi(codeT.at(other + 1))*(-1) );
                }
            }
            codeT.erase(codeT.begin() + other + 1);


        }
        while (PA.size() > 0&&pages.size()>0) {
            if (std::find(PA.begin(), PA.end(), "DD") != PA.end()) {
                int position = std::find(PA.begin(), PA.end(), "DD") - PA.begin();

                PA.erase(PA.begin() + position, PA.begin() + position + 2);
            }
            if (std::find(PA.begin(), PA.end(), "RE") != PA.end()) {
                int position = std::find(PA.begin(), PA.end(), "RE") - PA.begin();

                PA.erase(PA.begin() + position, PA.begin() + position + 2);
            }
            if (std::find(PA.begin(), PA.end(), "RR") != PA.end()) {
                int position = std::find(PA.begin(), PA.end(), "RR") - PA.begin();

                PA.erase(PA.begin() + position);
            }
            if (std::find(PA.begin(), PA.end(), "DRC") != PA.end()) {
                int position = std::find(PA.begin(), PA.end(), "DRC") - PA.begin();

                PA.erase(PA.begin() + position);
            }
            if (std::find(PA.begin(), PA.end(), "DECIDEFIRST") != PA.end()) {
                int position = std::find(PA.begin(), PA.end(), "DECIDEFIRST") - PA.begin();
                PA.erase(PA.begin() + position);
            }
        }

        codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
    }else if (codeT.size()>0&&std::find(codeT.begin(), codeT.end(), "PL") != codeT.end()) {
        std::vector<std::string> PL;
        int other = std::find(codeT.begin(), codeT.end(), "PL") - codeT.begin();
        //chooser action
        if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {
            if (player == 1) {
                session.x1.setSatisfaction(std::stoi(codeT.at(other + 1)));
                if (doubleImpactB == 1) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            else {
                session.x2.setSatisfaction(std::stoi(codeT.at(other + 1)));
                if (doubleImpactB == 1) {
                    session.x2.setSatisfaction(std::stoi(codeT.at(1)));
                }
            }
            if (doubleimpact != 0) {
                if (doubleimpact == chooser) {
                    session.x1.setSatisfaction(std::stoi(codeT.at(other + 1))*(-1));
                }
                else {
                    session.x2.setSatisfaction(std::stoi(codeT.at(other + 1)));
                }
            }
            codeT.erase(codeT.begin() + 1);

        }
        while (PL.size() > 0&&pages.size()>0) {
            if (std::find(PL.begin(), PL.end(), "DR") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "DR") - PL.begin();
                session = drawScene(session, player, "CH", PL.at(position+1));
                PL.erase(PL.begin() + position, PL.begin() + position + 2);

            }
            if (std::find(PL.begin(), PL.end(), "DD") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "DD") - PL.begin();

                PL.erase(PL.begin() + position, PL.begin() + position + 2);
            }
            if (std::find(PL.begin(), PL.end(), "RE") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "RE") - PL.begin();

                PL.erase(PL.begin() + position, PL.begin() + position + 2);
            }
            if (std::find(PL.begin(), PL.end(), "CO") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "CO") - PL.begin();

                PL.erase(PL.begin() + position);
            }
            if (std::find(PL.begin(), PL.end(), "DRC") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "DRC") - PL.begin();

                PL.erase(PL.begin() + position);
            }
            if (std::find(PL.begin(), PL.end(), "CTT") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "CTT") - PL.begin();
                if(turn==1){

                }else{

                }
                PL.erase(PL.begin() + position);
            }
            if (std::find(PL.begin(), PL.end(), "DS") != PL.end()) {
                int position = std::find(PL.begin(), PL.end(), "DS") - PL.begin();

                PL.erase(PL.begin() + position, PL.begin() + position + 2);
            }
        }

        codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
    }
    /*
    if(codeT.size()==1){
        counter++;
        if(turn==1){
            turn=2;
        }else{
            turn=1;
        }
        to_Board();
    }*/
}
void MainWindow::pageSwitch(std::vector<std::string> code){
    codeT = code;
    int index = 0;
        if (codeT.size() > 0 && codeT.at(0) == "B") {
            std::vector<std::string> B;
            if (codeT.at(1).find_first_of("0123456789") != std::string::npos) {
                codeT.erase(codeT.begin() + 1);
            }

            while (1 + index < codeT.size()&&codeT.at(index+1)!="PA") {
                B.push_back(codeT.at(1 + index));
                index++;
            }
            while (B.size() > 0) {
                if (std::find(B.begin(), B.end(), "RI") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "RI") - B.begin();

                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position, B.begin() + position + 2);
                }
                if (std::find(B.begin(), B.end(), "RK") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "RK") - B.begin();
                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "RR") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "RR") - B.begin();
                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "SI") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "SI") - B.begin();
                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position, B.begin() + position + 2);
                }
                if (std::find(B.begin(), B.end(), "DD") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "DD") - B.begin();
                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position, B.begin() + position + 2);
                }
                if (std::find(B.begin(), B.end(), "RE") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "RE") - B.begin();
                    pages.push_back(12);
                    pages.push_back(12);
                    B.erase(B.begin() + position, B.begin() + position + 2);
                }
                if (std::find(B.begin(), B.end(), "CO") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "CO") - B.begin();
                    pages.push_back(5);
                    pages.push_back(5);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "SWO") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "SWO") - B.begin();
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "TRADE") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "TRADE") - B.begin();
                    pages.push_back(22);
                    pages.push_back(22);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "STELLL") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "STELLL") - B.begin();
                    pages.push_back(14);
                    pages.push_back(14);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "CTT") != B.end()) {
                    int position = std::find(B.begin(), B.end(), "CTT") - B.begin();
                    pages.push_back(3);
                    pages.push_back(4);
                    B.erase(B.begin() + position);
                }
                if (std::find(B.begin(), B.end(), "DOUBLEIMPACTB") != B.end()||std::find(B.begin(), B.end(), "DOUBLEIMPACTPT") != B.end()||std::find(B.begin(), B.end(), "BEHALF") != B.end()||std::find(B.begin(), B.end(), "BEHALFCHO")!=B.end()) {
                    int position = std::find(B.begin(), B.end(), "DOUBLEIMPACTB") - B.begin();
                    B.erase(B.begin() + position);
                }

            }

            codeT.erase(codeT.begin(), codeT.begin() + index + 1);
        }

        index = 0;
        if (codeT.size() > 0 && std::find(codeT.begin(), codeT.end(), "OT") != codeT.end()) {
            std::vector<std::string> OT;
            int other = std::find(codeT.begin(), codeT.end(), "OT") - codeT.begin();
            if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {
                codeT.erase(codeT.begin() + other + 1);
            }

            while (other + 1 + index < codeT.size()) {
                OT.push_back(codeT.at(other + 1 + index));
                index++;
            }

            while (OT.size() > 0) {
                if (std::find(OT.begin(), OT.end(), "DR") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "DR") - OT.begin();
                    OT.erase(OT.begin() + position, OT.begin() + position + 2);
                }
                if (std::find(OT.begin(), OT.end(), "SI") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "SI") - OT.begin();
                    pages.push_back(12);
                    OT.erase(OT.begin() + position, OT.begin() + position + 2);
                }
                if (std::find(OT.begin(), OT.end(), "SO") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "SO") - OT.begin();
                    pages.push_back(12);
                    OT.erase(OT.begin() + position, OT.begin() + position + 2);
                }
                if (std::find(OT.begin(), OT.end(), "DD") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "DD") - OT.begin();
                    pages.push_back(12);
                    OT.erase(OT.begin() + position, OT.begin() + position + 2);
                }
                if (std::find(OT.begin(), OT.end(), "RE") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "RE") - OT.begin();
                    pages.push_back(12);
                    OT.erase(OT.begin() + position, OT.begin() + position + 2);
                }
                if (std::find(OT.begin(), OT.end(), "DoubleThree") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "DoubleThree")-OT.begin();
                    OT.erase(OT.begin() + position);
                }
                if (std::find(OT.begin(), OT.end(), "RSS") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "RSS") - OT.begin();
                    OT.erase(OT.begin() + position);
                }
                if (std::find(OT.begin(), OT.end(), "CO") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "CO") - OT.begin();
                    pages.push_back(5);
                    OT.erase(OT.begin() + position);
                }
                if (std::find(OT.begin(), OT.end(), "CRT") != OT.end()) {
                    int position = std::find(OT.begin(), OT.end(), "CRT") - OT.begin();
                    if (turn == 1) {
                        pages.push_back(4);
                    }
                    else {
                        pages.push_back(3);
                    }

                    OT.erase(OT.begin() + position);
                }
            }

            codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
        }
        index = 0;
        if (codeT.size() > 0 && std::find(codeT.begin(), codeT.end(), "CH") != codeT.end()) {
            std::vector<std::string> CH;

            //chooser action
            if (codeT.at(1).find_first_of("0123456789") != std::string::npos) {

                codeT.erase(codeT.begin() + 1);
            }

            while (1 + index < codeT.size()) {
                CH.push_back(codeT.at(1 + index));
                index++;

            }
            while (CH.size() > 0) {
                if (std::find(CH.begin(), CH.end(), "DR") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "DR") - CH.begin();
                    CH.erase(CH.begin() + position, CH.begin() + position + 2);

                }
                if (std::find(CH.begin(), CH.end(), "RD") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "RD") - CH.begin();
                    pages.push_back(12);
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "RR") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "RR") - CH.begin();
                    pages.push_back(12);
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "SI") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "SI") - CH.begin();
                    pages.push_back(12);
                    if (position != 0 && CH.at(position - 1) == "MAY") {

                        CH.erase(CH.begin() + position - 1, CH.begin() + position + 2);
                    }
                    else {

                        CH.erase(CH.begin() + position, CH.begin() + position + 2);
                    }

                }
                if (std::find(CH.begin(), CH.end(), "SO") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "SO") - CH.begin();
                    pages.push_back(12);
                    CH.erase(CH.begin() + position, CH.begin() + position + 2);
                }
                if (std::find(CH.begin(), CH.end(), "DD") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "DD") - CH.begin();
                    pages.push_back(12);
                    CH.erase(CH.begin() + position, CH.begin() + position + 2);
                }
                if (std::find(CH.begin(), CH.end(), "RE") != CH.end()) {

                    int position = std::find(CH.begin(), CH.end(), "RE") - CH.begin();
                    pages.push_back(12);
                    CH.erase(CH.begin() + position, CH.begin() + position + 2);
                }
                if (std::find(CH.begin(), CH.end(), "DS") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "DS") - CH.begin();
                    pages.push_back(22);
                    CH.erase(CH.begin() + position, CH.begin() + position + 2);
                }
                if (std::find(CH.begin(), CH.end(), "DOUBLEIMPACT") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "DOUBLEIMPACT") - CH.begin();
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "STELL") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "STELL") - CH.begin();
                    pages.push_back(14);
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "CTT") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "CTT") - CH.begin();
                    if(turn==1){
                        pages.push_back(3);
                    }else{
                        pages.push_back(4);
                    }
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "CRT") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "CRT") - CH.begin();
                    if(turn==1){
                        pages.push_back(3);
                    }else{
                        pages.push_back(4);
                    }
                    CH.erase(CH.begin() + position);
                }
                if (std::find(CH.begin(), CH.end(), "RS") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "RS") - CH.begin();
                    CH.erase(CH.begin() + position);
                }

                if (std::find(CH.begin(), CH.end(), "RSALL") != CH.end()) {
                    int position = std::find(CH.begin(), CH.end(), "RSALL") - CH.begin();
                    CH.erase(CH.begin() + position);
                }

            }

            codeT.erase(codeT.begin(), codeT.begin() + index + 1);
        }
        index = 0;
        if (codeT.size() > 0 && std::find(codeT.begin(), codeT.end(), "PA") != codeT.end()) {
            std::vector<std::string> PA;
            int other = std::find(codeT.begin(), codeT.end(), "PA") - codeT.begin();
            if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {
                codeT.erase(codeT.begin() + other + 1);
            }

            while (other + 1 + index < codeT.size()&&codeT.at(other+1+index)!="PL") {
                PA.push_back(codeT.at(other + 1 + index));
                index++;
            }
            while (PA.size() > 0) {
                if (std::find(PA.begin(), PA.end(), "DD") != PA.end()) {
                    int position = std::find(PA.begin(), PA.end(), "DD") - PA.begin();
                    pages.push_back(12);
                    PA.erase(PA.begin() + position, PA.begin() + position + 2);
                }
                if (std::find(PA.begin(), PA.end(), "RE") != PA.end()) {
                    int position = std::find(PA.begin(), PA.end(), "RE") - PA.begin();
                    pages.push_back(12);
                    PA.erase(PA.begin() + position, PA.begin() + position + 2);
                }
                if (std::find(PA.begin(), PA.end(), "RR") != PA.end()) {
                    int position = std::find(PA.begin(), PA.end(), "RR") - PA.begin();
                    pages.push_back(12);
                    PA.erase(PA.begin() + position);
                }
                if (std::find(PA.begin(), PA.end(), "DRC") != PA.end()) {
                    int position = std::find(PA.begin(), PA.end(), "DRC") - PA.begin();
                    pages.push_back(22);
                    PA.erase(PA.begin() + position);
                }
                if (std::find(PA.begin(), PA.end(), "DECIDEFIRST") != PA.end()) {
                    int position = std::find(PA.begin(), PA.end(), "DECIDEFIRST") - PA.begin();
                    PA.erase(PA.begin() + position);
                }
            }

            codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
        }

        index = 0;
        if (codeT.size() > 0 && std::find(codeT.begin(), codeT.end(), "PL") != codeT.end()) {
            std::vector<std::string> PL;
            int other = std::find(codeT.begin(), codeT.end(), "PL") - codeT.begin();
            //chooser action
            if (codeT.at(other + 1).find_first_of("0123456789") != std::string::npos) {
                codeT.erase(codeT.begin() + 1);
            }

            while (other + 1 + index < codeT.size() && codeT.at(index) != ""&&codeT.at(other + 1 + index) != "PL") {
                PL.push_back(codeT.at(1 + index));
                index++;
            }
            while (PL.size() > 0) {
                if (std::find(PL.begin(), PL.end(), "DR") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "DR") - PL.begin();
                    PL.erase(PL.begin() + position, PL.begin() + position + 2);

                }
                if (std::find(PL.begin(), PL.end(), "DD") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "DD") - PL.begin();
                   pages.push_back(12);
                    PL.erase(PL.begin() + position, PL.begin() + position + 2);
                }
                if (std::find(PL.begin(), PL.end(), "RE") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "RE") - PL.begin();
                    pages.push_back(12);
                    PL.erase(PL.begin() + position, PL.begin() + position + 2);
                }
                if (std::find(PL.begin(), PL.end(), "CO") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "CO") - PL.begin();
                    pages.push_back(5);
                    PL.erase(PL.begin() + position);
                }
                if (std::find(PL.begin(), PL.end(), "DRC") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "DRC") - PL.begin();
                    pages.push_back(22);
                    PL.erase(PL.begin() + position);
                }
                if (std::find(PL.begin(), PL.end(), "CTT") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "CTT") - PL.begin();
                    if(turn==1){
                        pages.push_back(3);
                    }else{
                        pages.push_back(4);
                    }
                    PL.erase(PL.begin() + position);
                }
                if (std::find(PL.begin(), PL.end(), "DS") != PL.end()) {
                    int position = std::find(PL.begin(), PL.end(), "DS") - PL.begin();
                    pages.push_back(22);
                    PL.erase(PL.begin() + position, PL.begin() + position + 2);
                }
            }

            codeT.erase(codeT.begin() + other, codeT.begin() + other + index + 1);
        }
}
