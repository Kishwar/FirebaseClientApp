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
