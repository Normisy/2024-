#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <string>
#include <error1.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    friend void encodeFunc(Widget &my, std::string input, std::string output, std::string cstr);
    friend void decodeFunc(Widget &my, std::string input, std::string output, std::string cstr);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_radioMode_clicked(bool checked);


private:
    Ui::Widget *ui;
    bool modeType = false;
    void changeMode();
    int errorType = 0;
};
#endif // WIDGET_H
