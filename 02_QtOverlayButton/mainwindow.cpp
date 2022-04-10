#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->tableWidget, &QtCustomTableWidget::clickedDetails, [=](){
       qDebug() << "Clicked Button from TableWidget" ;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
