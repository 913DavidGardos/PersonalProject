//
// Created by david on 19.05.2021.
//

#include <QInputDialog>
#include <QGridLayout>
#include <GUI/Client/ClientSeeTrench.h>
#include <QMessageBox>
#include <Exceptions/MyWarning.h>
#include <GUI/Client/MyTableModel.h>
#include <QTableView>
#include <GUI/Client/TableView.h>
#include <QTableWidget>
#include "ClientMenu.h"

ClientMenu::ClientMenu(Service_ptc& se,MyTableModel& model, QWidget *parent) : _se{se}, _model(model), QWidget(parent)
{
    while(true)
    {
        file_type = QInputDialog::getText(this,"Enter the file type you want to use: HTML/CSV","HTML/CSV:");
        if(file_type == "HTML" || file_type == "CSV")
        {
            break;
        }
        else
        {
            MyWarning("Please enter HTML or CSV");
        }
    }

    see_t = new QPushButton("See Trench coat", this);
    see_t->setCheckable(true);

    see_shopping_b = new QPushButton("See Shopping Basket", this);
    see_shopping_b->setCheckable(true);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(see_t, 0, 0);
    layout->addWidget(see_shopping_b, 1, 0);

    connect(see_t, SIGNAL (clicked(bool)), this, SLOT (slot_see_t_button_clicked(bool)));
    connect(see_shopping_b, SIGNAL (clicked(bool)), this, SLOT (slot_see_shopping_b_button_clicked(bool)));
}

void ClientMenu::slot_see_t_button_clicked(bool checked)
{
    if(checked)
    {
        ClientSeeTrench* c_see_trench = new ClientSeeTrench{file_type, _se};
        c_see_trench->show();
    }
}

void ClientMenu::slot_see_shopping_b_button_clicked(bool checked)
{
    if(file_type == "CSV")
    {
        this->_se.open_libre_office_csv();
    }
    else if(file_type == "HTML")
    {
        this->_se.open_browser_html();
    }

    //get data to store
    MyTableView* view= new MyTableView(_se);
    view->show();
}