//
// Created by david on 19.05.2021.
//

#include <QPushButton>
#include <QGridLayout>
#include <GUI/Admin/AdminSee.h>
#include "ClientSelectSize.h"
#include "ClientSeeTrench.h"

ClientSeeTrench::ClientSeeTrench(QString& file_type, Service_ptc& se, QWidget *parent) :_file_type{file_type}, _se{se}, QWidget(parent)
{
    see_all_prods = new QPushButton("See all Products", this);
    see_all_prods->setCheckable(true);

    select_size = new QPushButton("Select Size", this);
    select_size->setCheckable(true);


    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(see_all_prods, 0, 0);
    layout->addWidget(select_size, 1, 0);


    connect(see_all_prods, SIGNAL (clicked(bool)), this, SLOT (slot_see_all_prods_button_clicked(bool)));
    connect(select_size, SIGNAL (clicked(bool)), this, SLOT (slot_select_size_button_clicked(bool)));
}

void ClientSeeTrench::slot_see_all_prods_button_clicked(bool checked)
{
    if(checked)
    {
        AdminSee* admin_see = new AdminSee{_se};
        admin_see->show();
    }
}

void ClientSeeTrench::slot_select_size_button_clicked(bool checked)
{
    if(checked)
    {
        ClientSelectSize* admin_select_size = new ClientSelectSize{_file_type,_se};
        admin_select_size->show();
    }
}