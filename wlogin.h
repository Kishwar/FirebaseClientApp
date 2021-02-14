//
// Class: wlogin (firebase -> Authentication)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#ifndef WLOGIN_H
#define WLOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "wform.h"
#include "authenticate.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class wlogin; }
QT_END_NAMESPACE

class wlogin : public QMainWindow
{
    Q_OBJECT

public:
    wlogin(QWidget *parent = nullptr);
    ~wlogin();

private slots:
    void on_actionAbout_triggered();
    void on_pushButton_clicked();

private:
    Ui::wlogin *ui;
    authenticate *auth = NULL;
};

#endif // WLOGIN_H
