#ifndef ERROR1_H
#define ERROR1_H

#include <QDialog>
#include "widget.h"

namespace Ui {
class error1;
}

class error1 : public QDialog
{
    Q_OBJECT
    friend QWidget;

public:
    explicit error1(QWidget *parent = nullptr);
    ~error1();
    bool flag = false;

private slots:
    void on_existButton_clicked();

private:
    Ui::error1 *ui;

};

#endif // ERROR1_H
