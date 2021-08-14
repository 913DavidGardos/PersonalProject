//
// Created by david on 21.05.2021.
//

#ifndef A8_9_CLIENTSELECTSIZE_H
#define A8_9_CLIENTSELECTSIZE_H


#include <Business/Service_ptc.h>
#include <QWidget>
#include <QPushButton>

class ClientSelectSize : public QWidget {
Q_OBJECT
public:
    explicit ClientSelectSize(QString& file_type, Service_ptc& se, QWidget *parent = 0);

public:
private slots:
    void slot_next(bool);
    void slot_purchase(bool);


private:
    QPushButton* next;
    QPushButton* purchase;
    Service_ptc& _se;
    int position_counter = -1;
    QString size;
    QString& _file_type;
    QVector<TrenchCoat> vec;

    void show_item_to_purchase();

    void closeEvent(QCloseEvent *event);
};

#endif //A8_9_CLIENTSELECTSIZE_H
