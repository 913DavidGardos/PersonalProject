//
// Created by david on 19.05.2021.
//

#ifndef A8_9_CLIENTMENU_H
#define A8_9_CLIENTMENU_H


#include <QWidget>
#include <QPushButton>
#include <Business/Service_ptc.h>

class ClientMenu : public QWidget {
Q_OBJECT
public:
    explicit ClientMenu(Service_ptc& se,MyTableModel& model, QWidget *parent = 0);

private slots:
    void slot_see_shopping_b_button_clicked(bool checked);
    void slot_see_t_button_clicked(bool checked);

private:
    QString file_type;
    QPushButton* see_t;
    QPushButton *see_shopping_b;
    Service_ptc& _se;
    MyTableModel& _model;
};
#endif //A8_9_CLIENTMENU_H
