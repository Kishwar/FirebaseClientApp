#include "wform.h"
#include "ui_wform.h"

wform::wform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wform)
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

void wform::on_actionSearch_triggered()
{

}

void wform::on_actionUpdate_triggered()
{

}
