#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "data.h"

DeleteWindow::DeleteWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButtonCancel_clicked()
{
    this->close();
    emit firstwindow();
}


void DeleteWindow::on_pushButtonOk_clicked()
{
    if (ui->lineEdit->text().isEmpty()){

        QMessageBox::critical(this, "Ошибка", "Поля не могут быть пустыми", QMessageBox::Ok);

    } else {

        auto name = ui->lineEdit->text();

        auto db = new Data("D:\\Study\\2612Class\\students.db");
        db->DeleteStudent(name);

        QMessageBox::information(this, "Подтверждение", "Студент удален", QMessageBox::Ok);

        ui->lineEdit->clear();

        this->close();
        emit firstwindow();
}
}
