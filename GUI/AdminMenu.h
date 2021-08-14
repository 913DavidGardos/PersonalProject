//
// Created by david on 18.05.2021.
//

#ifndef A8_9_ADMINMENU_H
#define A8_9_ADMINMENU_H


#include <QWidget>
#include <QPushButton>
#include "Window.h"

class AdminMenu : public QWidget{
Q_OBJECT
public:
    explicit AdminMenu(Service_ptc& se, QWidget* parent = 0);
private:
    QPushButton* add;
    QPushButton* del;
    QPushButton* update;
    QPushButton* see_all;
    QPushButton* back;
    QPushButton* undo;
    QPushButton* redo;

    Service_ptc& _se;

    private slots:
    void slot_back_button_clicked(bool checked);

    void slot_add_button_clicked(bool checked);

    void slot_del_button_clicked(bool checked);

    void slot_update_button_clicked(bool checked);

    void slot_see_all_button_clicked(bool checked);

    void slot_undo_button_clicked(bool checked);

    void slot_redo_button_clicked(bool checked);

    void slot_undo_shortcut();

    void slot_redo_shortcut();
};


#endif //A8_9_ADMINMENU_H
