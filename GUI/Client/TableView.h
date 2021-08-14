//
// Created by david on 31.05.2021.
//

#ifndef A8_9_TABLEVIEW_H
#define A8_9_TABLEVIEW_H


#include <QTableView>
#include <Business/Service_ptc.h>
#include "MyTableModel.h"

class MyTableView : public QWidget{
    Q_OBJECT
public:
    explicit MyTableView(Service_ptc&, QWidget *parent = 0);


private:
    Service_ptc& _se;
};


#endif //A8_9_TABLEVIEW_H
