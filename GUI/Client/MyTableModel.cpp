//
// Created by david on 31.05.2021.
//

#include <Business/Service_ptc.h>
#include <QTableWidget>
#include "MyTableModel.h"

MyTableModel::MyTableModel(Service_ptc& se, QObject *parent)
        : _se(se), QAbstractTableModel(parent)
{
}

int MyTableModel::rowCount(const QModelIndex & /*parent*/) const
{
    return _se.get_basket_size();//nr of elements in basket
}

int MyTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;
}

void MyTableModel::populateData(const QVector<TrenchCoat>& QTrench)
{
    for(auto i = 0; i < QTrench.size(); i++)
    {
        ql_id.push_back(QString::number(QTrench[i].get_id()));
        ql_size.push_back(QString::fromStdString(QTrench[i].get_size()));
        ql_color.push_back(QString::fromStdString(QTrench[i].get_color()));
        ql_price.push_back(QString::number(QTrench[i].get_price()));
        ql_quantity.push_back(QString::number(QTrench[i].get_quantity()));
        ql_link.push_back(QString::fromStdString(QTrench[i].get_link()));
    }
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    // this should populate the table with data i guess
    if(!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if (index.column() == 0)
        return ql_id[index.row()];
    else if (index.column() == 1)
        return ql_size[index.row()];
    else if (index.column() == 2)
        return ql_color[index.row()];
    else if (index.column() == 3)
        return ql_price[index.row()];
    else if (index.column() == 4)
        return ql_quantity[index.row()];
    else if (index.column() == 5)
        return ql_link[index.row()];


    return QVariant();
}


QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("ID");
            case 1:
                return QString("Size");
            case 2:
                return QString("Color");
            case 3:
                return QString("Price");
            case 4:
                return QString("Quantity");
            case 5:
                return QString("Link");
        }
    }
    return QVariant();
}