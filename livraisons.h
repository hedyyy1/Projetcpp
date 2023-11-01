#ifndef LIVRAISONS_H
#define LIVRAISONS_H
#include <QString>
#include<QSqlQueryModel>


class Livraisons
{
public:
    Livraisons();
    Livraisons(int,QString,QString,QString);
    int getNUMLIV();
    QString getADRESSELIV();
    QString getSTATUTLIV();
    QString getDATELIV();
    void setNUMLIV(int);
    void setADRESSELIV(QString);
    void setSTATUTLIV(QString);
    void setDATELIV(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);


private:
    int NUMLIV;
    QString ADRESSELIV;
    QString STATUTLIV;
    QString DATELIV;
};

#endif // LIVRAISONS_H
