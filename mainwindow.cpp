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
    // TODO: отправить сигнал на Elevator
}

void MainWindow::on_weight_clicked(bool checked)
{
    // TODO: отправить сигнал на Elevator
}
