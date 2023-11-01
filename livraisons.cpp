#include "livraisons.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Livraisons::Livraisons()
{
NUMLIV=0; ADRESSELIV=" "; STATUTLIV=" "; DATELIV=" ";
}
Livraisons::Livraisons(int NUMLIV,QString ADRESSELIV,QString STATUTLIV,QString DATELIV)
{this->NUMLIV=NUMLIV; this->STATUTLIV=STATUTLIV; this->ADRESSELIV=ADRESSELIV; this->DATELIV=DATELIV; }
int Livraisons::getNUMLIV(){return NUMLIV;}
QString Livraisons::getADRESSELIV(){return ADRESSELIV;}
QString Livraisons::getSTATUTLIV(){return STATUTLIV;}
QString Livraisons::getDATELIV(){return DATELIV;}
void Livraisons::setNUMLIV(int NUMLIV){this->NUMLIV=NUMLIV;}
void Livraisons::setADRESSELIV(QString ADRESSELIV){this->ADRESSELIV=ADRESSELIV;}
void Livraisons::setSTATUTLIV(QString STATUTLIV){this->STATUTLIV=STATUTLIV;}
void Livraisons::setDATELIV(QString DATELIV){this->DATELIV=DATELIV;}
bool Livraisons::ajouter()
{
    QSqlQuery query;
    QString num_string= QString::number(NUMLIV);
          query.prepare("INSERT INTO LIVRAISONS (NUMLIV ,ADRESSELIV, STATUTLIV, DATELIV) "
                        "VALUES (:NUMLIV, :ADRESSELIV, :STATUTLIV, :DATELIV)");
          query.bindValue(":NUMLIV", num_string);
          query.bindValue(":ADRESSELIV", ADRESSELIV);
          query.bindValue(":DATELIV", DATELIV);
          query.bindValue(":STATUTLIV", STATUTLIV);



return  query.exec();
}
bool Livraisons::supprimer(int NUMLIV)
{
    QSqlQuery query;
    QString num_string= QString::number(NUMLIV);
          query.prepare("Delete from LIVRAISONS where NUMLIV= :NUMLIV");
          query.bindValue(":NUMLIV", NUMLIV);

return  query.exec();
}
QSqlQueryModel* Livraisons::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT*,FROM LIVRAISONS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMLIV"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATELIV"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUTLIV"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSELIV"));

    return model;
}
