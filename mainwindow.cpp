#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_smoke_clicked(bool checked)
{
    elevator.HandleSmokeEvent(checked);
}

void MainWindow::on_switchOnOff_clicked(bool checked)
{
    elevator.HandleSwitchOnOff(checked);
}

void MainWindow::on_floor_1_clicked()
{
    elevator.HandleAddFloorTask(1);
}

void MainWindow::on_floor_2_clicked()
{
    elevator.HandleAddFloorTask(2);
}

void MainWindow::on_floor_3_clicked()
{
    elevator.HandleAddFloorTask(3);
}

void MainWindow::on_floor_4_clicked()
{
    elevator.HandleAddFloorTask(4);
}

void MainWindow::on_floor_5_clicked()
{
    elevator.HandleAddFloorTask(5);
}

void MainWindow::on_floor_6_clicked()
{
    elevator.HandleAddFloorTask(6);
}

void MainWindow::on_floor_7_clicked()
{
    elevator.HandleAddFloorTask(7);
}
