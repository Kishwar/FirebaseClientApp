#include "wfind.h"
#include "ui_wfind.h"

wfind::wfind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wfind)
{
    ui->setupUi(this);
}

wfind::~wfind()
{
    delete ui;
}
