//
// Created by david on 11.05.2021.
//

#include "CsvFile.h"
#include <fstream>

void CsvFile::append_to_basket_file(TrenchCoat &item) {
    std::ofstream f("/home/david/CLionProjects/A8-9/Persistency/basket.csv", std::ios::app);
    if (!f.is_open())
    {
        return;
    }

    f << std::endl;
    f << item;

    f.close();
}




