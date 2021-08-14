//
// Created by david on 18.05.2021.
//

#ifndef A8_9_WINDOW_H
#define A8_9_WINDOW_H


#include <QWidget>
#include <Business/Service_ptc.h>
#include <GUI/Client/MyTableModel.h>


class QPushButton;
class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(Service_ptc& se, MyTableModel& model, QWidget* parent = 0);
    ~Window();
private slots:
    void slot_admin_button_clicked(bool checked);
    void slot_client_button_clicked(bool checked);


private:
    QPushButton* client_button;
    QPushButton* admin_button;
    Service_ptc& _se;
    MyTableModel& _model;
//    BottomWindow& b_window;
//    TopMenu& t_menu;

    void clearLayout(QLayout *layout);
};

#endif //A8_9_WINDOW_H
