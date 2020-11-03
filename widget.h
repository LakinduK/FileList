#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_ButtonAdd_clicked();

    void on_ButtonRemove_clicked();

    void on_ButtonClear_clicked();

    void on_ButtonSave_clicked();

    void on_ButtonLoad_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
