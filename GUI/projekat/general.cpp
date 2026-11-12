#include "general.h"
#include "ui_general.h"

general::general(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::general)
{
    ui->setupUi(this);
    // 1. Kreiranje Qt 3D prozora
       Qt3DExtras::Qt3DWindow *view =
           new Qt3DExtras::Qt3DWindow();
        //postavljanje boje pozadine
       view->defaultFrameGraph()->setClearColor(QColor(50, 50, 50));

       // 2. Kreiranje QWidget kontejnera
       QWidget *container =
           QWidget::createWindowContainer(view, this);

       // 3. Layout običnog widgeta
       QVBoxLayout *layout = new QVBoxLayout(this);
       layout->addWidget(container);

       // 4. Kreiranje korena 3D scene
       Qt3DCore::QEntity *rootEntity =
           new Qt3DCore::QEntity();

       // 5. Kreiranje entiteta modela
       Qt3DCore::QEntity *modelEntity =
           new Qt3DCore::QEntity(rootEntity);

       Qt3DCore::QEntity *modelEntity2 =
           new Qt3DCore::QEntity(rootEntity);

       // 6. Učitavanje OBJ modela
       Qt3DRender::QSceneLoader *loader =
           new Qt3DRender::QSceneLoader(modelEntity);

       Qt3DRender::QSceneLoader *loader2 =
           new Qt3DRender::QSceneLoader(modelEntity2);

       Qt3DCore::QTransform *transform = new Qt3DCore::QTransform();
       transform->setTranslation(QVector3D(0.0f, 0.5f, 0.0f));
       transform->setScale(0.1f);

       loader->setSource(
           QUrl::fromLocalFile(
               "/home/anastasija/Desktop/rs projekat/tablaMonopol.obj"
           )
       );

       loader2->setSource(
                   QUrl::fromLocalFile(
                       "/home/anastasija/Desktop/rs projekat/figurica.obj"));

       modelEntity->addComponent(loader);
       modelEntity2->addComponent(loader2);
       modelEntity2->addComponent(transform);


       // 7. Podešavanje kamere
       camera = view->camera();
       //dodajem event filter
       view->installEventFilter(this);

       camera->lens()->setPerspectiveProjection(
           45.0f, 1.0f, 0.1f, 1000.0f
       );

       camera->setPosition(QVector3D(0, 5, 15));
       camera->setViewCenter(QVector3D(0, 0, 0));
       camera->setUpVector(QVector3D(0, 1, 0));


       // 8. Povezivanje scene sa 3D prozorom
       view->setRootEntity(rootEntity);

       // 9. Prikaz prozora
       resize(900, 600);
}

general::~general()
{
    delete ui;
}


//zumiranje na skrol misa
bool general::eventFilter(QObject *obj, QEvent *event){
    if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheel =
                static_cast<QWheelEvent*>(event);

            QVector3D direction =
                camera->position() - camera->viewCenter();

            float distance = direction.length();

            distance -= wheel->angleDelta().y() * 0.01f;

            distance = qBound(2.0f, distance, 100.0f);

            direction.normalize();

            camera->setPosition(
                camera->viewCenter() + direction * distance
            );

            return true;
        }

        return QWidget::eventFilter(obj, event);
}
