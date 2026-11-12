#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFrame>

// Forward deklaracija Qt UI klase
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui; // Pokazivač preko kojeg pristupate elementima iz .ui fajla

private slots:
    void otvoriDrugiProzor();
};

#endif // MAINWINDOW_H
