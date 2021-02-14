//
// Class: wform (firebase -> firestore)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

#ifndef WFORM_H
#define WFORM_H

#include <QMainWindow>
#include <QMessageBox>
#include "dbfirestore.h"

namespace Ui {
class wform;
}

class wform : public QMainWindow, public dbfirestore
{
    Q_OBJECT

public:
    explicit wform(QWidget *parent = nullptr);
    ~wform();
    void nextid(std::string id);
    void result(std::string e);

private slots:
    void on_actionNew_triggered();
    void on_actionSearch_triggered();
    void on_actionUpdate_triggered();
    void on_actionClear_triggered();

private:
    Ui::wform *ui;
};

#endif // WFORM_H
