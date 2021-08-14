//
// Created by david on 19.05.2021.
//

#ifndef A8_9_ADMINADD_H
#define A8_9_ADMINADD_H


#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include <Business/Service_ptc.h>

class AdminAdd : public QWidget{
    Q_OBJECT
public:
    explicit AdminAdd(Service_ptc& se, QWidget* parent = 0);
public:
    int getId() const;

    const QString &getSize() const;

    const QString &getColor() const;

    double getPrice() const;

    int getQuantity() const;

    const QString &getLink() const;


private slots:




private:
    int id;
    QString size;
    QString color;
    double price;
    int quantity;
    QString link;
    Service_ptc& _se;
};


#endif //A8_9_ADMINADD_H
