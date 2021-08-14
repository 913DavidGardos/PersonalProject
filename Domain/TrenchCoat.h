//
// Created by david on 05.04.2021.
//

#ifndef A45_TRENCHCOAT_H
#define A45_TRENCHCOAT_H
#include<iostream>

class TrenchCoat{
private:
    int _id{};
public:
    void setId(int id);

    void setSize(const std::string &size);

    void setColor(const std::string &color);

    void setPrice(double price);

    void setQuantity(int quantity);

    void setLink(const std::string &link);

public:
    TrenchCoat()=default;
    TrenchCoat(int, const std::string&, const std::string&, double, int , const std::string&);
    TrenchCoat ( const TrenchCoat & );
public:
    TrenchCoat& operator=(const TrenchCoat &);
    bool operator==(const TrenchCoat &) const;
    friend std::ostream& operator<<(std::ostream&, const TrenchCoat&);
    friend std::istream& operator>>(std::istream&, TrenchCoat&);
    friend std::istream& operator>>(std::istream&, TrenchCoat&);
    ~TrenchCoat()= default;
public:
    int get_id() const;
    const std::string& get_size() const;

    const std::string& get_color() const;

    double get_price() const;

    int get_quantity() const;

    const std::string& get_link() const;

    void set_id(int );

    void set_size(const std::string&);
    void set_color(const std::string&);
    void set_price(double);
    void set_quantity(int);
    void set_link(const std::string&);
    void increase_quantity_by_one();

private:
    std::string _size;
    std::string _color;
    double _price{};
    int _quantity{};
    std::string _link;
};




#endif //A45_TRENCHCOAT_H
