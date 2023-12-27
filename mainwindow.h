#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <data.h>

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

    Data* data;

    QList<student> students;

private slots:
    void openDB();
    void findStudent();
    void findSubject();
    void exit();


};
#endif // MAINWINDOW_H
