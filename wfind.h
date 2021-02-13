#ifndef WFIND_H
#define WFIND_H

#include <QWidget>

namespace Ui {
class wfind;
}

class wfind : public QWidget
{
    Q_OBJECT

public:
    explicit wfind(QWidget *parent = nullptr);
    ~wfind();

private:
    Ui::wfind *ui;
};

#endif // WFIND_H
