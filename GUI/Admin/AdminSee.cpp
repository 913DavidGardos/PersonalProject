//
// Created by david on 19.05.2021.
//

#include <QTableWidget>
#include <QVBoxLayout>
#include <QFileDialog>
#include <fstream>
#include <QTextStream>
#include <QStandardItemModel>
#include "AdminSee.h"
#include "Persistency/TC_Database.h"

AdminSee::AdminSee(Service_ptc& se, QWidget *parent) :_se{se}, QWidget(parent)
{
    int size_ = _se.get_qvec().size();
    auto table = new QTableWidget(size_,6,this);
    table->setMinimumSize(630,400);
    QStringList str_l = QStringList{"ID", "Size", "Color", "Price", "Quantity","Link"};
    table->setHorizontalHeaderLabels(str_l);

    for(auto i = 0; i < _se.get_qvec().size(); i++)
    {
        QString str1 = QString::number(_se.get_qvec()[i].get_id());
        QString str2 = QString::fromStdString(_se.get_qvec()[i].get_size());
        QString str3 = QString::fromStdString(_se.get_qvec()[i].get_color());
        QString str4 = QString::number(_se.get_qvec()[i].get_price());
        QString str5 = QString::number(_se.get_qvec()[i].get_quantity());
        QString str6 = QString::fromStdString(_se.get_qvec()[i].get_link());

        auto* item1 = new QTableWidgetItem(str1);
        table->setItem(i, 0, item1);


        auto* item2 = new QTableWidgetItem(str2);
        table->setItem(i, 1, item2);


        auto* item3 = new QTableWidgetItem(str3);
        table->setItem(i, 2, item3);


        auto* item4 = new QTableWidgetItem(str4);
        table->setItem(i, 3, item4);


        auto* item5 = new QTableWidgetItem(str5);
        table->setItem(i, 4, item5);


        auto* item6 = new QTableWidgetItem(str6);
        table->setItem(i, 5, item6);
    }
    table->show();
}


int AdminSee::getId() const {
    return id;
}

const QString &AdminSee::getSize() const {
    return size;
}

const QString &AdminSee::getColor() const {
    return color;
}

double AdminSee::getPrice() const {
    return price;
}

int AdminSee::getQuantity() const {
    return quantity;
}

const QString &AdminSee::getLink() const {
    return link;
}

