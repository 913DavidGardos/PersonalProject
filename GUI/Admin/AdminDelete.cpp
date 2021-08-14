//
// Created by david on 19.05.2021.
//

#include <QInputDialog>
#include "AdminDelete.h"

AdminDelete::AdminDelete(Service_ptc& se, QWidget *parent) :_se{se}, QWidget(parent)
{
    id = QInputDialog::getInt(this,"Enter id of trench coat you want to delete","id");

    _se.delete_trench_coat(id);
}

int AdminDelete::getId() const {
    return id;
}
