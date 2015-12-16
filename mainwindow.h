#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Elevator.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_smoke_clicked(bool checked);


    void on_weight_clicked(bool checked);

private:
    Ui::MainWindow *ui; 
    QElevator elevator;
};

#endif // MAINWINDOW_H
