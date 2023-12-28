#include "dialogwindow.h"
#include "ui_dialogwindow.h"
#include "mainwindow.h"
#include "data.h"
#include "QMessageBox"

DialogWindow::DialogWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DialogWindow)
{
    ui->setupUi(this);
}

DialogWindow::~DialogWindow()
{
    delete ui;
}

void DialogWindow::on_pushButtonCancel_clicked()
{
    this->close();
    emit firstwindow();
}


void DialogWindow::on_pushButtonOk_clicked()
{

    if (ui->lineEditName->text().isEmpty() || ui->lineEditSubject->text().isEmpty() || ui->lineEditMarks->text().isEmpty()){

        QMessageBox::critical(this, "Ошибка", "Поля не могут быть пустыми", QMessageBox::Ok);

    } else {

        auto name = ui->lineEditName->text();
        auto subject = ui->lineEditSubject->text();
        auto marks = ui->lineEditMarks->text();

    auto db = new Data("D:\\Study\\2612Class\\students.db");
    db->AddStudent(name, subject, marks);

    QMessageBox::information(this, "Подтверждение", "Запись успешно сохранена", QMessageBox::Ok);

    ui->lineEditMarks->clear();
    ui->lineEditName->clear();
    ui->lineEditSubject->clear();
    this->close();
    emit firstwindow();

    }
}

