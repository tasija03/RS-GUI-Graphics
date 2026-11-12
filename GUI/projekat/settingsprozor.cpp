#include "settingsprozor.h"
#include "ui_settingsprozor.h"
#include "general.h"

settingsProzor::settingsProzor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsProzor)
{
    ui->setupUi(this);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &settingsProzor::otvoriDrugiProzor);

    QFrame *w = this->findChild<QFrame*>("frame");
    QGroupBox *gb1 = w->findChild<QGroupBox*>("groupBox");
    QGroupBox *gb2 = w->findChild<QGroupBox*>("groupBox_2");

    gb1->hide();
    gb2->hide();

}

settingsProzor::~settingsProzor()
{
    delete ui;
}

void settingsProzor::otvoriDrugiProzor(){

    general *prozor = new general();
    prozor->show();
    this->hide();
}
