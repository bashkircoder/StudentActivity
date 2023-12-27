#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <data.h>
#include <QObject>
#include <QInputDialog>>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    foreach (auto item, students) {
        ui->textEdit->append("Full name: " + item.getStudentName() + ", subject: " + item.getStudentSubject() + ". Marks: " + item.getStudentMarks());
    }

}

void MainWindow::findStudent()
{

    ui->textEdit->clear();

    auto db = new Data("D:\\Study\\2612Class\\students.db");

    QString find = ui->lineEdit->text();

    auto students = db->FindByStudentName(find);

    foreach (auto item, students) {
        ui->textEdit->append(QString::number(item.getID()) + " " + item.getStudentName() + " " + item.getStudentSubject() + " " + item.getStudentMarks());
    }


}

void MainWindow::findSubject()
{

    ui->textEdit->clear();

    auto db = new Data("D:\\Study\\2612Class\\students.db");

    QString find = ui->lineEdit->text();

    auto students = db->FindBySubject(find);

    foreach (auto item, students) {
        ui->textEdit->append(QString::number(item.getID()) + " " + item.getStudentName() + " " + item.getStudentSubject() + " " + item.getStudentMarks());
    }


}

void MainWindow::exit()
{
    if (QMessageBox::question(this, "Выход", QString::fromUtf8("Вы уверены, что хотите выйти?")) == QMessageBox::Yes) {
        qApp->closeAllWindows();
    }
}



