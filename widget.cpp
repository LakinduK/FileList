#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ButtonAdd_clicked()
{
    // create a new text obj and check text!= empty
    //  add the txt to the listwidget

    QString newText = ui->lineEdit->text();
    if( !newText.isEmpty() )
     ui->listWidget->addItem(newText);

}

void Widget::on_ButtonRemove_clicked()
{
    // loop through list items to delete selected items

    foreach (QListWidgetItem *item, ui->listWidget->selectedItems())
    delete item;
}

void Widget::on_ButtonClear_clicked()
{
    // clear the list
    ui->listWidget->clear();
}

void Widget::on_ButtonSave_clicked()
{
    // create text file obj, open the file and add permission to write
    // create stream, loop through items and write file, close stream

    QFile textFile("FileList.txt");
    textFile.open(QFile::WriteOnly);
    QTextStream fileStream(&textFile);
    for(int i =0; i < ui->listWidget->count(); i++ )
    {
        fileStream <<  i << " item "  << ui->listWidget->item(i)->text() << "\n";
    }
    textFile.close();
}


void Widget::on_ButtonLoad_clicked()
{
    // get the file obj, open the file and add permision to read
    // create stream, loop through file and retrieve data to the list widget
    QFile textFile("FileList.txt");
    textFile.open(QFile::ReadOnly);
    QTextStream fileStream(&textFile);
    int i=0;

    while (!textFile.atEnd()) {
        //ui->listWidget->addItem(fileStream.readLine());
        ui->listWidget-> addItem(fileStream.readLine());
        i++;
    }
    textFile.close();
}
