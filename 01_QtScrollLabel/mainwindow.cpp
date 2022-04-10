#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rightToLeft->setDirection(QtScrollLabel::RightToLeft);
    ui->leftToRight->setDirection(QtScrollLabel::LeftToRight);
    ui->leftToRight->setInterval(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

