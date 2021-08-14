//
// Created by david on 11.05.2021.
//
#include <fstream>
#include "HtmlFile.h"

void HtmlFile::append_to_basket_file(TrenchCoat &item)
{
    std::ofstream f("/home/david/CLionProjects/A8-9/Persistency/basket.html", std::ios::app);
    if (!f.is_open())
    {
        return;
    }

    f << std::endl;

    f << "<tr>";

        f << "<td>" << item.get_size() << "</td>";
        f << std::endl;
        f << "<td>" << item.get_color() << "</td>";
        f << std::endl;
        f << "<td>" << item.get_price() << "</td>";
        f << std::endl;
        f << "<td>" << item.get_quantity() << "</td>";
        f << std::endl;
        f << "<td>" << item.get_link() << "</td>";
        f << std::endl;

    f << "</tr>";
    f.close();
}

void HtmlFile::beginning_of_file() {
    std::ofstream f("/home/david/CLionProjects/A8-9/Persistency/basket.html", std::ios::app);
    if (!f.is_open())
    {
        return;
    }
    f << "<!DOCTYPE html> " << std::endl;
    f << "<html> " << std::endl;
    f << "<head> " << std::endl;
    f << "  <title>SHOPPING BASKET</title>" << std::endl;
    f << "</head> " << std::endl;
    f << "<body> " << std::endl;
    f << "<table border=\"1\"> " << std::endl;
}

void HtmlFile::ending_of_file()
{

    std::ofstream f("/home/david/CLionProjects/A8-9/Persistency/basket.html", std::ios::app);
    if (!f.is_open())
    {
        return;
    }
    f << std::endl;
    f << "</table>" << std::endl;
    f << "</body>" << std::endl;
    f << "</html>" << std::endl;
}

