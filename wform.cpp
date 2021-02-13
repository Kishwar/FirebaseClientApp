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

void wform::on_actionNew_triggered()
{

}

void wform::on_actionSearch_triggered()
{

}

void wform::on_actionUpdate_triggered()
{

}
