//
// Class: wlogin (firebase -> Authentication)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#include "wlogin.h"
#include "ui_wlogin.h"

wlogin::wlogin(QWidget *parent): QMainWindow(parent), ui(new Ui::wlogin) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    ui->setupUi(this);
    setFixedSize(width(), height());
}

wlogin::~wlogin() {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    delete ui;
}


void wlogin::on_actionAbout_triggered()
{
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    QMessageBox::information(this, "About", "This program is created by team Music Therapy.\n"
                                            "\nThis demo App shows how we can use Google's "
                                            "firebase Authentication and Firestore to store "
                                            "and collect data.");
}

#include "dbfirestore.h"

void wlogin::on_pushButton_clicked()
{
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

#if 1 //temp turn off login
    auth = new authenticate();
    std::string error;

    if(auth->sign_in_sync(ui->temail->text().toStdString(),
                          ui->tpassword->text().toStdString(),
                          error) == 0) {
        ui->statusbar->showMessage("Sign in successful.");
        wform *oform = new wform();
        oform->show();
        this->hide();
    } else {
        ui->statusbar->showMessage(error.c_str());
    }
#else
    wform *oform = new wform();
    oform->show();
    this->hide();
#endif
}
