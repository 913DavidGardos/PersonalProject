//
// Created by david on 19.05.2021.
//

#include <QInputDialog>
#include "AdminUpdate.h"

AdminUpdate::AdminUpdate(Service_ptc& se, QWidget *parent)
: _se{se}, QWidget(parent)
{
    id = QInputDialog::getInt(this,"Add trench coat id","id");
    size = QInputDialog::getText(this,"Add size of trench coat", "size");
    color = QInputDialog::getText(this,"Add color of trench coat", "color");
    price = QInputDialog::getDouble(this,"Add price of trench coat", "price");
    quantity = QInputDialog::getInt(this,"Add quantity of trench coat", "quantity");
    link = QInputDialog::getText(this,"Add link of trench coat", "link");

    std::string link_ = link.toStdString();
    std::string color_ = color.toStdString();
    std::string size_ = size.toStdString();

    _se.update_trench_coat(id, size_, color_, price,quantity, link_);
}

int AdminUpdate::getId() const {
    return 0;
}

const QString &AdminUpdate::getSize() const {
    return size;
}

const QString &AdminUpdate::getColor() const {
    return color;
}

double AdminUpdate::getPrice() const {
    return price;
}

int AdminUpdate::getQuantity() const {
    return quantity;
}

const QString &AdminUpdate::getLink() const {
    return link;
}
