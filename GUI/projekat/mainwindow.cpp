#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsprozor.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::otvoriDrugiProzor);

}

MainWindow::~MainWindow()
{
}

void MainWindow::otvoriDrugiProzor(){
    settingsProzor *prozor = new settingsProzor();
    prozor->show();
    this->close();
}
