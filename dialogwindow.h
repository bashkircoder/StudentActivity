#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QMainWindow>

namespace Ui {
class DialogWindow;
}

class DialogWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DialogWindow(QWidget *parent = nullptr);
    ~DialogWindow();

signals:
    void firstwindow();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonOk_clicked();

private:
    Ui::DialogWindow *ui;
};

#endif // DIALOGWINDOW_H
