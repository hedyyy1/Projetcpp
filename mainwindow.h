#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "livraisons.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    Livraisons L;

    void on_pb_supprimer_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
