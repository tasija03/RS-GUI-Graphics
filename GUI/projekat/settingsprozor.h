#ifndef SETTINGSPROZOR_H
#define SETTINGSPROZOR_H

#include <QWidget>

namespace Ui {
class settingsProzor;
}

class settingsProzor : public QWidget
{
    Q_OBJECT

public:
    explicit settingsProzor(QWidget *parent = nullptr);
    ~settingsProzor();

private:
    Ui::settingsProzor *ui;
};

#endif // SETTINGSPROZOR_H
