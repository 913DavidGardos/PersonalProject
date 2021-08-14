//
// Created by david on 19.05.2021.
//

#ifndef A8_9_ADMINUPDATE_H
#define A8_9_ADMINUPDATE_H



#include <QWidget>
#include <Business/Service_ptc.h>

class AdminUpdate : public QWidget {
Q_OBJECT
public:
    explicit AdminUpdate(Service_ptc& se, QWidget *parent = 0);

public:

public:
    int getId() const;



public:
    const QString &getSize() const;

    const QString &getColor() const;

    double getPrice() const;

    int getQuantity() const;

    const QString &getLink() const;

private:
    int id;
    QString size;
    QString color;
    double price;
    int quantity;
    QString link;
    Service_ptc& _se;
};


#endif //A8_9_ADMINUPDATE_H
