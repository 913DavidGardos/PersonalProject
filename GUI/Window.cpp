//
// Created by david on 18.05.2021.
//

#include "Window.h"
#include "AdminMenu.h"
#include "ClientMenu.h"
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <iostream>
#include <GUI/Client/MyTableModel.h>

Window::Window(Service_ptc& se, MyTableModel& model,QWidget *parent) :
       _se{se}, _model(model) ,QWidget(parent)
{
    admin_button = new QPushButton("Admin", this);
    admin_button->setCheckable(true);

    client_button = new QPushButton("Client", this);
    client_button->setCheckable(true);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(admin_button, 0, 0);
    layout->addWidget(client_button, 1, 0);

    connect(admin_button, SIGNAL (clicked(bool)), this, SLOT (slot_admin_button_clicked(bool)));
    connect(client_button, SIGNAL (clicked(bool)), this, SLOT (slot_client_button_clicked(bool)));
}

void Window::slot_admin_button_clicked(bool checked)
{
    if (checked)
    {
        AdminMenu* admin_menu = new AdminMenu{_se};
        admin_menu->show();
    }
}

void Window::slot_client_button_clicked(bool checked)
{
    if (checked)
    {
        ClientMenu* client_menu = new ClientMenu{_se, _model};
        client_menu->show();
    }
}

Window::~Window() {

}
