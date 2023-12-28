#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <data.h>
#include <QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialog = new DialogWindow();
    del = new DeleteWindow();

    connect(dialog, &DialogWindow::firstwindow, this, &MainWindow::show);
    connect(del, &DeleteWindow::firstwindow, this, &MainWindow::show);

    connect(ui->actionLoadDB, SIGNAL(triggered()), this, SLOT(openDB()));
    connect(ui->actionFindStudent, SIGNAL(triggered()), this, SLOT(findStudent()));
    connect(ui->actionFindSubject, SIGNAL(triggered()), this, SLOT(findSubject()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));

    connect(ui->pushButtonDB, SIGNAL(clicked()), this, SLOT(openDB()));
    connect(ui->pushButtonFindStud, SIGNAL(clicked()), this, SLOT(findStudent()));
    connect(ui->pushButtonFindSubject, SIGNAL(clicked()), this, SLOT(findSubject()));
    connect(ui->pushButtonExit, SIGNAL(clicked()), this, SLOT(exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDB()
{

    ui->textEdit->clear();

    auto db = new Data("D:\\Study\\2612Class\\students.db");

    auto students = db->GetALL();

    ui->textEdit->append("Student name: \t\t Subject: \t Marks:");

    foreach (auto item, students) {
        ui->textEdit->append(item.getStudentName() + " \t\t " + item.getStudentSubject() + " \t " + item.getStudentMarks());
    }

}

void MainWindow::findStudent()
{

    ui->textEdit->clear();

    auto db = new Data("D:\\Study\\2612Class\\students.db");

    QString find = ui->lineEditStud->text();

    auto students = db->FindByStudentName(find);

    ui->textEdit->append("Student name: \t Subject: \t Marks:");

    foreach (auto item, students) {
        ui->textEdit->append(item.getStudentName() + " \t " + item.getStudentSubject() + " \t " + item.getStudentMarks());
    }

    ui->lineEditStud->clear();


}

void MainWindow::findSubject()
{

    ui->textEdit->clear();

    auto db = new Data("D:\\Study\\2612Class\\students.db");

    QString find = ui->lineEditSubject->text();

    auto students = db->FindBySubject(find);

    ui->textEdit->append("Student name: \t Subject: \t Marks:");

    foreach (auto item, students) {
        ui->textEdit->append(item.getStudentName() + " \t " + item.getStudentSubject() + " \t " + item.getStudentMarks());
    }

    ui->lineEditSubject->clear();

}
void MainWindow::exit()
{
    if (QMessageBox::question(this, "Выход", QString::fromUtf8("Вы уверены, что хотите выйти?")) == QMessageBox::Yes) {
        qApp->closeAllWindows();
    }
}




void MainWindow::on_pushButtonAdd_clicked()
{

    dialog->show();
    this->close();

}




void MainWindow::on_pushButton_clicked()
{

    del->show();
    this->close();

}

