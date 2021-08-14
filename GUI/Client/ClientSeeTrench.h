//
// Created by david on 19.05.2021.
//

#ifndef A8_9_CLIENTSEETRENCH_H
#define A8_9_CLIENTSEETRENCH_H


#include <Business/Service_ptc.h>
#include <QWidget>

class ClientSeeTrench : public QWidget {
Q_OBJECT
public:
    explicit ClientSeeTrench(QString& file_type, Service_ptc& se, QWidget *parent = 0);

public:
private slots:
    void slot_see_all_prods_button_clicked(bool checked);

    void slot_select_size_button_clicked(bool checked);
private:
    QPushButton* see_all_prods;
    QPushButton* select_size;
    Service_ptc& _se;
    QString& _file_type;

};
#endif //A8_9_CLIENTSEETRENCH_H
