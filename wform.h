#ifndef WFORM_H
#define WFORM_H

#include <QMainWindow>

namespace Ui {
class wform;
}

class wform : public QMainWindow
{
    Q_OBJECT

public:
    explicit wform(QWidget *parent = nullptr);
    ~wform();

private slots:
    void on_actionNew_triggered();

    void on_actionSearch_triggered();

    void on_actionUpdate_triggered();

private:
    Ui::wform *ui;
};

#endif // WFORM_H
