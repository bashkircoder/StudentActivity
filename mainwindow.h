#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <data.h>
#include "dialogwindow.h"
#include "deletewindow.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;

    DialogWindow *dialog;
    DeleteWindow *del;

    Data* data;

    QList<student> students;

private slots:
    void openDB();
    void findStudent();
    void findSubject();
    void exit();


    void on_pushButtonAdd_clicked();

    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
