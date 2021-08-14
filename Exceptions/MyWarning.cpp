//
// Created by david on 20.05.2021.
//

#include <QMessageBox>
#include "MyWarning.h"


MyWarning::MyWarning(const QString & str) {
    QMessageBox msgWarning;
    msgWarning.setText("WARNING!\n"+ str);
    msgWarning.setIcon(QMessageBox::Warning);
    msgWarning.setWindowTitle("Caution");
    msgWarning.exec();
}
