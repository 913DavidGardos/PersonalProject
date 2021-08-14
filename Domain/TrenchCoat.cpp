//
// Created by david on 05.04.2021.
//

#include <vector>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "TrenchCoat.h"

TrenchCoat::TrenchCoat(int id, const std::string &size, const std::string &color, double price, int quantity, const std::string &link)
:_id{id},_size{size},_color{color},_price{price},_quantity{quantity},_link{link}
{

}

TrenchCoat::TrenchCoat(const TrenchCoat &) = default;

int TrenchCoat::get_id() const {
    return this->_id;
}

const std::string& TrenchCoat::get_size() const {
    return this->_size;
}

const std::string& TrenchCoat::get_color() const {
    return this->_color;
}

double TrenchCoat::get_price() const {
    return this->_price;
}

int TrenchCoat::get_quantity() const {
    return this->_quantity;
}

const std::string& TrenchCoat::get_link() const {
    return this->_link;
}





void TrenchCoat::set_id(int id) {
    this->_id = id;
}

void TrenchCoat::set_size(const std::string& size) {
    this->_size = size;
}

void TrenchCoat::set_color(const std::string& color) {
    this->_color = color;
}

void TrenchCoat::set_price(double price) {
    this->_price = price;
}

void TrenchCoat::set_quantity(int quantity) {
    this-> _quantity = quantity;
}

void TrenchCoat::set_link(const std::string& link) {
    this->_link = link;
}

void TrenchCoat::increase_quantity_by_one() {
    this->_quantity++;
}



//operators
TrenchCoat& TrenchCoat::operator=(const TrenchCoat &t) {
    this->_id = t._id;
    this->_link = t._link;
    this->_quantity = t._quantity;
    this->_color = t._color;
    this->_price = t._price;
    this->_size = t._size;
    return *this;
}

bool TrenchCoat::operator==(const TrenchCoat &t) const {
    return this->_id == t._id;
}

std::ostream &operator<<(std::ostream& os, const TrenchCoat& t)
{
    if(&os == &std::cout)
    {
        os<<t._id<<" "<<t._size<<" "<<t._color<<" "<<t._price<<" "<<t._quantity<<" "<<t._link<<" "<<std::endl;
    }
    else
    {
        os<<t._id<<","<<t._size<<","<<t._color<<","<<t._price<<","<<t._quantity<<","<<t._link;
    }
    return os;
}

std::vector<std::string> tokenize(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}
// checkers :))
bool check_number(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

bool check_size(const std::string& str) {
    for (int i = 0; i < str.length(); i++)
        if (str != "S" && str != "M" && str != "L" && str != "XL"
            && str != "XXL" && str != "XXXL")
        {
            return false;
        }

    return true;
}
bool check_color(const std::string& color)
{
    for (int i = 0; i < color.length(); i++)
        if(color != "red"&& color != "orange"&&color != "yellow"&&color != "green"&&color != "blue"&&
           color != "purple"&&color != "pink"&& color != "brown"&&color != "grey"&&color != "black"&&
           color != "white")
            return false;
    return true;
}
bool check_price(const std::string& s)
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}
// end of checkers :)))
std::istream &operator>>(std::istream & is, TrenchCoat & t) {
    if(&is == &std::cin)
    {
        is>>t._id>>t._size>>t._color>>t._price>>t._quantity>>t._link;
    }
    else
    {
        std::string line;
        getline(is, line);

        std::vector<std::string> tokens = tokenize(line, ',');
        if (tokens.size() != 6)
            return is;

        // here probably should change to exceptions :)) but that should be for tomorrow
        bool is_int = check_number(tokens[0]);
        if(is_int)
        {
            std::cout<<tokens[0]<<std::endl;
            int tmp = stoi(tokens[0]);
            t.set_id(tmp);
        }
        else
        {
            std::cout<<"is not int"<<std::endl;
        }

        bool is_size = check_size(tokens[1]);
        if(is_size)
        {
            t._size = tokens[1];
        }
        else
        {
            std::cout<<"Size must be (S/M/L/...)\n";
        }

        bool is_color = check_color(tokens[2]);
        if(is_color)
        {
            t._color = tokens[2];
        }
        else
        {
            std::cout<<"color must be red/blue/...\n";
        }

        bool is_price = check_price(tokens[3]);
        if(is_price)
        {
            t._price = stod(tokens[3]);
        }
        else
        {
            std::cout<<"must be double\n";
        }
        bool is_quantity = check_number(tokens[4]);
        if(is_quantity)
        {
            t._quantity = stoi(tokens[4]);
        }
        else
        {
            std::cout<<"must be int\n";
        }

        t._link = tokens[5];

        return is;
    }
    return is;
}

void TrenchCoat::setId(int id) {
    _id = id;
}

void TrenchCoat::setSize(const std::string &size) {
    _size = size;
}

void TrenchCoat::setColor(const std::string &color) {
    _color = color;
}

void TrenchCoat::setPrice(double price) {
    _price = price;
}

void TrenchCoat::setQuantity(int quantity) {
    _quantity = quantity;
}

void TrenchCoat::setLink(const std::string &link) {
    _link = link;
}




