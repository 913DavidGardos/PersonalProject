//
// Created by david on 31.05.2021.
//

#include <Domain/TrenchCoat.h>
#include <QLayoutItem>
#include <QGridLayout>
#include "TableView.h"



MyTableView::MyTableView(Service_ptc &se, QWidget *parent)
: _se(se), QWidget(parent)
{
    this->setFixedSize(625,700);

    std::vector<TrenchCoat> temp = _se.get_shopping_basket_copy();
    if(_se.get_shopping_basket_copy().empty())
    {
        std::cout<<"get-s-b is empty"<<std::endl;
    }
    else
        std::cout<<"get-s-b is not empty"<<std::endl;

    if(temp.empty())
    {
        std::cout<<"temp is empty"<<std::endl;
    }
    else
        std::cout<<"Temp is not empty"<<std::endl;

    const QVector<TrenchCoat> basket = QVector<TrenchCoat>(temp.begin(),temp.end());
    //create model
    auto* my_model = new MyTableModel(_se, reinterpret_cast<QObject *>(this));


    //populate model
    my_model->populateData(basket);
//    my_model->data();

    //create tbview
    auto* tableView = new QTableView(reinterpret_cast<QWidget *>(this));
    //connect tbview to model
    tableView->setModel(my_model);
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(tableView);

    my_model->headerData(0, Qt::Horizontal, Qt::DisplayRole);
    tableView->show();
}
