#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "QtJoystickPad.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget, &QtJoystickPad::xChanged, this, [this](float x){
        qDebug() << "x: " << x << " y: " << ui->widget->y();
    });


    connect(ui->widget, &QtJoystickPad::yChanged, this, [this](float y){
        qDebug() << "x: " << ui->widget->x() << " y: " << y;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
