#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&elevator, SIGNAL (NewFloorReached(int)),
            this, SLOT (updateFloor(int)));
    connect(&elevator, SIGNAL (TaskListChanged(QVector<int>)),
            this, SLOT(updateTaskList(QVector<int>)));
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

void MainWindow::updateFloor(int cur_floor)
{
    ui->textBrowser->setText(QString("current floor = ") + QString::number(cur_floor));
}

void MainWindow::updateTaskList(QVector<int> task_list)
{
    QString tasks;
    for (int task : task_list) {
        tasks += QString::number(task) + QString("\n");
    }
    ui->textBrowser_2->setText(tasks);
}
