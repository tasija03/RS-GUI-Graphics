#include "settingsprozor.h"
#include "ui_settingsprozor.h"

settingsProzor::settingsProzor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsProzor)
{
    ui->setupUi(this);
}

settingsProzor::~settingsProzor()
{
    delete ui;
}
