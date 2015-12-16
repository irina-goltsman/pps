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

    void on_pushButton_8_clicked(bool checked);

    void on_switchOnOff_clicked(bool checked);

    void on_floor_1_clicked();

    void on_floor_2_clicked();

    void on_floor_3_clicked();

    void on_floor_4_clicked();

    void on_floor_5_clicked();

    void on_floor_6_clicked();

    void on_floor_7_clicked();

private:
    Ui::MainWindow *ui; 
    QElevator elevator;
};

#endif // MAINWINDOW_H
