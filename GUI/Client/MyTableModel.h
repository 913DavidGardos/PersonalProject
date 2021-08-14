//
// Created by david on 31.05.2021.
//

#ifndef A8_9_MYTABLEMODEL_H
#define A8_9_MYTABLEMODEL_H
#include <QAbstractTableModel>

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTableModel(Service_ptc& se, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    void populateData(const QVector<TrenchCoat> &QTrench);

private:
    QList<QString> ql_id;
    QList<QString> ql_size;
    QList<QString> ql_color;
    QList<QString> ql_price;
    QList<QString> ql_quantity;
    QList<QString> ql_link;

    Service_ptc& _se;

};


#endif //A8_9_MYTABLEMODEL_H
