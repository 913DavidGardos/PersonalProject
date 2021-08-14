//
// Created by david on 21.05.2021.
//

#include <QGridLayout>
#include <QInputDialog>
#include <Exceptions/MyWarning.h>
#include <QCloseEvent>
#include "ClientSelectSize.h"

ClientSelectSize::ClientSelectSize(QString& file_type, Service_ptc &se, QWidget *parent)
:_file_type{file_type}, _se{se}, QWidget(parent)
{
    while(true)
    {
        size = QInputDialog::getText(this,"Enter size of trench coat", "size");
        if(size == "S" || size == "M" || size == "L" || size == "XL" || size == "XXL" || size == "XXXL")
        {
            break;
        }
        else
        {
            MyWarning("Please use S/M/L format");
        }
    }

    next = new QPushButton("Next", this);
    next->setCheckable(true);

    purchase = new QPushButton("Purchase current item", this);
    purchase->setCheckable(true);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(next, 0, 0);
    layout->addWidget(purchase, 1, 0);



    connect(next, SIGNAL (clicked(bool)), this, SLOT (slot_next(bool)));
    connect(purchase, SIGNAL (clicked(bool)), this, SLOT (slot_purchase(bool)));
}

void ClientSelectSize::slot_next(bool checked)
{
    if(checked)
    {
        for(auto i : _se.get_qvec())
        {
            const std::string& item_size_ = i.get_size();
            QString item_size = QString::fromStdString(item_size_);
            if(item_size == this->size)
            {
                this->vec.append(i);
            }
        }
        this->show_item_to_purchase();
    }
}

void ClientSelectSize::slot_purchase(bool checked)
{
    if(checked)
    {
        QVector<TrenchCoat> compare_vec = _se.get_qvec();

        for(auto i = 0; i < compare_vec.size(); i++)
        {
            if(this->vec.at(this->position_counter) == compare_vec.at(i))
            {
                std::string file_type = _file_type.toStdString();
                _se.add_item_to_basket((i+1), file_type);
            }
        }
    }
}


void ClientSelectSize::show_item_to_purchase()
{
    this->position_counter++;

    std::string url = vec.at(this->position_counter).get_link();
    std::string op = std::string("xdg-open ").append(url);
    system(op.c_str());

    if(vec.size() == this->position_counter + 1)
        this->position_counter = 0;
}

void ClientSelectSize::closeEvent(QCloseEvent* event)
{
    if(_file_type == "HTML")
    {
        event->accept();
        this->_se.end_html_file();
    }
    else if(_file_type == "CSV")
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}