//
// Created by david on 19.05.2021.
//

#include "AdminAdd.h"

AdminAdd::AdminAdd(Service_ptc& se, QWidget *parent) :_se{se}, QWidget(parent)
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

    _se.add_trench_coat(id, size_, color_, price,quantity, link_);
}

int AdminAdd::getId() const {
    return id;
}

const QString &AdminAdd::getSize() const {
    return size;
}

const QString &AdminAdd::getColor() const {
    return color;
}

double AdminAdd::getPrice() const {
    return price;
}

int AdminAdd::getQuantity() const {
    return quantity;
}

const QString &AdminAdd::getLink() const {
    return link;
}
