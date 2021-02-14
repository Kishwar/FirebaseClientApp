#ifndef WFORM_H
#define WFORM_H

#include <QMainWindow>
//
// Class: wform (firebase -> firestore)
//
// Auther: Kishwar Kumar
// Date:   13.02.2021
//
//

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

private slots:
    void on_actionNew_triggered();
    void on_actionSearch_triggered();
    void on_actionUpdate_triggered();

private:
    Ui::wform *ui;
};

#endif // WFORM_H
