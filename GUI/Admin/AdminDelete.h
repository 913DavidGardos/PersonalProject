//
// Created by david on 19.05.2021.
//

#ifndef A8_9_ADMINDELETE_H
#define A8_9_ADMINDELETE_H


#include <QWidget>
#include <Business/Service_ptc.h>

class AdminDelete : public QWidget {
Q_OBJECT
public:
    explicit AdminDelete(Service_ptc& se, QWidget *parent = 0);

public:

private:
    int id;
    Service_ptc& _se;
public:
    int getId() const;
};

#endif //A8_9_ADMINDELETE_H
