//
// Class: wform (firebase -> firestore)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#include "wform.h"
#include "ui_wform.h"

wform::wform(QWidget *parent) : QMainWindow(parent), ui(new Ui::wform)
{
    ui->setupUi(this);
}

wform::~wform()
{
    delete ui;
}

void wform::nextid(std::string id) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    ui->tid->setText(QString::fromStdString(id));
}

void wform::on_actionNew_triggered() {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    getnextid_async();
}

void wform::result(std::string e) {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    ui->statusbar->showMessage(e.c_str());
    on_actionClear_triggered();
}

void wform::on_actionSearch_triggered() {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;
}

void wform::on_actionUpdate_triggered() {
    std::cout << "LOG: " << __FILE_NAME__ << " | " << __LINE__ << " | " << __FUNCTION__ << std::endl;

    std::map<std::string, std::vector<std::string>> data;
    std::vector<std::string> vdata;

    vdata.push_back(ui->tfullname->text().toStdString());
    data["full_name"] = vdata;
    vdata.clear();

    vdata.push_back(ui->tdate->text().toStdString());
    data["dob"] = vdata;
    vdata.clear();

    storedata(ui->tid->text().toStdString(), data);
}

void wform::on_actionClear_triggered()
{
    ui->tid->setText("");
    ui->tfullname->setText("");
}
