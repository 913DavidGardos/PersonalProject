//
// Created by david on 18.05.2021.
//

#include <QGridLayout>
#include <iostream>
#include <GUI/Admin/AdminSee.h>
#include <QShortcut>
#include "AdminMenu.h"
#include "GUI/Admin/AdminAdd.h"
#include "GUI/Admin/AdminDelete.h"
#include "GUI/Admin/AdminUpdate.h"


AdminMenu::AdminMenu(Service_ptc& se, QWidget* parent): _se{se}, QWidget(parent)
{
    add = new QPushButton("Add a trench coat", this);
    add->setCheckable(true);

    del = new QPushButton("Delete a trench coat", this);
    del->setCheckable(true);

    update = new QPushButton("Update a trench coat", this);
    update->setCheckable(true);

    see_all = new QPushButton("See all trench coats", this);
    see_all->setCheckable(true);

    back = new QPushButton("Back", this);
    back->setCheckable(true);

    undo = new QPushButton("Undo", this);
    undo->setCheckable(true);

    redo = new QPushButton("Redo", this);
    redo->setCheckable(true);

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(add, 0, 0);
    layout->addWidget(del, 1, 0);
    layout->addWidget(update, 2, 0);
    layout->addWidget(see_all, 3, 0);
    layout->addWidget(back, 4, 0);
    layout->addWidget(undo, 5, 0);
    layout->addWidget(redo, 6, 0);

    connect(add, SIGNAL (clicked(bool)), this, SLOT (slot_add_button_clicked(bool)));
    connect(del, SIGNAL (clicked(bool)), this, SLOT (slot_del_button_clicked(bool)));
    connect(update, SIGNAL (clicked(bool)), this, SLOT (slot_update_button_clicked(bool)));
    connect(see_all, SIGNAL (clicked(bool)), this, SLOT (slot_see_all_button_clicked(bool)));
    connect(back, SIGNAL (clicked(bool)), this, SLOT (slot_back_button_clicked(bool)));
    connect(undo, SIGNAL (clicked(bool)), this, SLOT (slot_undo_button_clicked(bool)));
    connect(redo, SIGNAL (clicked(bool)), this, SLOT (slot_redo_button_clicked(bool)));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(slot_undo_shortcut()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this, SLOT(slot_redo_shortcut()));
}

void AdminMenu::slot_back_button_clicked(bool checked)
{
    if(checked)
    {
        delete this;
    }
}

void AdminMenu::slot_add_button_clicked(bool checked)
{
    if(checked)
    {
        AdminAdd* admin_add = new AdminAdd{_se};
        admin_add->show();
        delete admin_add;
    }
}

void AdminMenu::slot_del_button_clicked(bool checked)
{
    if(checked)
    {
        AdminDelete* admin_delete = new AdminDelete{_se};
        admin_delete->show();
        delete admin_delete;
    }
}

void AdminMenu::slot_update_button_clicked(bool checked)
{
    if(checked)
    {
        AdminUpdate* admin_update = new AdminUpdate{_se};
        admin_update->show();
        delete admin_update;
    }
}

void AdminMenu::slot_see_all_button_clicked(bool checked)
{
    if(checked)
    {
        AdminSee* admin_see = new AdminSee{_se};
        admin_see->show();

    }
}

void AdminMenu::slot_undo_button_clicked(bool checked)
{
    if(checked)
    {
        _se.undo();
    }
}

void AdminMenu::slot_redo_button_clicked(bool checked)
{
    if(checked)
    {
        _se.redo();
    }
}

void AdminMenu::slot_undo_shortcut()
{
    _se.undo();
}

void AdminMenu::slot_redo_shortcut()
{
    _se.redo();
}


