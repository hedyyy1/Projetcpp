#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "livraisons.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QtDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numliv->setValidator(new QIntValidator(0, 999999, this));
    ui->tablivraisons->setModel(L.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{

   int NUMLIV=ui->numliv->text().toInt();
   QString ADRESSELIV=ui->adresseliv->text();
   QString STATUTLIV=ui->statutliv->text();
   QString DATELIV=ui->dateliv->text();
   Livraisons L(NUMLIV,ADRESSELIV,STATUTLIV,DATELIV);
   bool test=L.ajouter();
   if (test){



       QMessageBox::information(nullptr, QObject::tr("ok"),
                   QObject::tr("ajout avec success.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tablivraisons->setModel(L.afficher());

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                   QObject::tr(" ajout non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}





void MainWindow::on_pb_supprimer_clicked()
{
   Livraisons L1;
   L1.setNUMLIV(ui->numsupp->text().toInt());
   bool test=L1.supprimer(L1.getNUMLIV());
   QMessageBox msgBox;
   if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("Supprimer client"),
                                    QObject::tr("produit supprimé.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tablivraisons->setModel(L1.afficher());
       }

}

