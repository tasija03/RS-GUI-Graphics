#ifndef GENERAL_H
#define GENERAL_H

#include <QVBoxLayout>
#include <QWidget>
#include <QUrl>
#include <QDebug>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/Qt3DWindow>

#include <QCoreApplication>
#include <Qt3DExtras/QForwardRenderer>

#include <QWheelEvent>
#include <QVector3D>

namespace Ui {
class general;
}

class general : public QWidget
{
    Q_OBJECT

public:
    explicit general(QWidget *parent = nullptr);
    ~general();

private:
    Ui::general *ui;
    Qt3DRender::QCamera *camera;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // GENERAL_H
