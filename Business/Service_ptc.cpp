//
// Created by david on 31.03.2021.
//

#include "Service_ptc.h"
#include <iostream>
#include <ostream>
#include <Undo_Redo/AddCommand.h>
#include <Undo_Redo/RemoveCommand.h>
#include <Undo_Redo/UpdateCommand.h>
#include <memory>

Service_ptc::Service_ptc(TC_Database &tc_db, File &file, CommandManager& command_manager)
: _tc_db{tc_db}, _file{file}, _command_manager(command_manager)
{

}

void Service_ptc::add_trench_coat(int id, const std::string & size, const std::string & color,  double price, int quantity, const std::string &link)
{
    for(const auto& elem : _tc_db.get_tc_map())
    {
        if(elem.second.get_id() == id)
        {
            std::cout << "Id already exists, try another one" << std::endl;
            return;
        }
    }

    TrenchCoat t(id, size, color, price, quantity, link);
    std::unique_ptr<Command> cmd (new AddCommand(_tc_db, t));
    _command_manager.requestDoCommand(std::move(cmd));
}

void Service_ptc::delete_trench_coat(int id)
{
    auto elem = _tc_db.get_tc_map().find(id);
    TrenchCoat t = elem->second;
    std::unique_ptr<Command> rmv_cmd (new RemoveCommand(_tc_db, t));
    _command_manager.requestDoCommand(std::move(rmv_cmd));
}

void Service_ptc::see_all_trench_coats()
{
    _tc_db.print_contents_of_tc_db();
}

void Service_ptc::update_trench_coat(int id, const std::string & size, const std::string & color,  double price, int quantity, const std::string &link)
{
    bool id_exists = false;
    for(auto it = _tc_db.get_tc_map().begin(); it != _tc_db.get_tc_map().end(); it++)
    {
        if (it->first == id)
        {
            id_exists = true;
            break;
        }
    }
    if(!id_exists)
        return;

    TrenchCoat t(id, size, color, price, quantity, link);
    std::unique_ptr<Command> upd_cmd (new UpdateCommand(_tc_db, t));
    _command_manager.requestDoCommand(std::move(upd_cmd));
}

void Service_ptc::undo()
{
    _command_manager.requestUndoCommand();
//    for(auto i : _command_manager.doneCommands)
//        std::cout<< i->getName();
}

void Service_ptc::redo()
{
    _command_manager.requestRedoCommand();
}


int Service_ptc::return_position_of_item(const std::string &size, int current_position)
{
    int i = current_position;
    while(true)
    {
        if (_tc_db.get_tc_map().at(i).get_size() == size)
        {
            print_item_at_position(i);
            current_position = i;
            open_link_url_of_item(i);
            break;
        }
        i++;
        if(i >= _tc_db.get_tc_map().size())
            i = 1;
    }
    return current_position;
}

bool Service_ptc::add_item_to_basket(int i, const std::string &file_type)
{
    CsvFile _csv_file;
    HtmlFile _html_file;
//    File* f_ptr1 = & _csv_file;
//    File* f_ptr2 = &_html_file;

    TrenchCoat item{};
    item = _tc_db.get_tc_map().at(i);

    if(_tc_db.get_tc_map().at(i).get_quantity() > 0)
    {
        item.set_quantity(1);
        _tc_db.append_tc_to_shopping_basket(item);

        if(file_type == "CSV")
        {
            _csv_file.append_to_basket_file(item);
            this->_file.append_to_basket_file(item);
        }
        else if (file_type == "HTML")
        {
            if(this->once == 0)
            {
                _html_file.beginning_of_file();
                set_once(1);
            }
            _html_file.append_to_basket_file(item);
            this->_file.append_to_basket_file(item);
        }
        return true;
    }
    else
    {
        std::cout<<"No more items of this kind in Store for now"<<std::endl;
        return false;
    }
}

double Service_ptc::calculate_total_price_sh_basket()
{
    double total_sum = 0;
    for(TrenchCoat const& i : _tc_db.get_shopping_basket())
    {
        total_sum += i.get_price();
    }
    return total_sum;
}

void Service_ptc::print_shopping_basket() {

    for(TrenchCoat const& item : _tc_db.get_shopping_basket())
    {
        std::cout << "size: " << item.get_size() << " " << "id: " << item.get_id() << " "
                  << "color :" << item.get_color() << " "
                  << "price: " << item.get_price() << " "
                  << "quantity: " << item.get_quantity() << " "
                  << "link: " << item.get_link() << std::endl;
    }
    std::cout<<"Total price: "<<calculate_total_price_sh_basket()<<std::endl;
}

double Service_ptc::return_total_sum(int i)
{
    TrenchCoat item = _tc_db.get_tc_map().at(i);
    return item.get_price();
}


int Service_ptc::return_size_of_vector() const
{
    return _tc_db.get_tc_map().size();
}

void Service_ptc::open_libre_office_csv() {
    std::string file_path = "/home/david/CLionProjects/A8-9/Persistency/basket.csv";
    std::string op = std::string("xdg-open ").append(file_path);
    system(op.c_str());
}

void Service_ptc::set_once(int sth) {
    this->once = sth;
}

void Service_ptc::end_html_file() {
    //this->_html_file.ending_of_file();
}

void Service_ptc::open_browser_html() {
    std::string file_path = "/home/david/CLionProjects/A8-9/Persistency/basket.html";
    std::string op = std::string("xdg-open ").append(file_path);
    system(op.c_str());
}

QVector<TrenchCoat> Service_ptc::get_qvec()
{
    std::vector<TrenchCoat> temp{};
    auto tc_map = _tc_db.get_tc_map();
    temp.reserve(tc_map.size());

    for(const auto& elem : tc_map)
    {
        temp.push_back(elem.second);
    }

    const QVector<TrenchCoat> vec = QVector<TrenchCoat>(temp.begin(),temp.end());
    return vec;
}

void Service_ptc::print_item_at_position(int position)
{
    std::cout<<"size: "<<_tc_db.get_tc_map().at(position).get_size()
             <<"size: "<<_tc_db.get_tc_map().at(position).get_color()
             <<"size: "<<_tc_db.get_tc_map().at(position).get_price()
             <<"size: "<<_tc_db.get_tc_map().at(position).get_quantity()
             <<"size: "<<_tc_db.get_tc_map().at(position).get_link()<<std::endl;
}

void Service_ptc::open_link_url_of_item(int i)
{
    std::string url = _tc_db.get_tc_map().at(i).get_link();
    std::string op = std::string("xdg-open ").append(url);
    system(op.c_str());
}

void Service_ptc::free_mem_command_manager()
{
    _command_manager.free_mem();
}

int Service_ptc::get_basket_size() {
    return _tc_db.get_shopping_basket().size();
}

std::vector<TrenchCoat> Service_ptc::get_shopping_basket_copy() {
    std::vector<TrenchCoat> temp;
    std::copy(_tc_db.get_shopping_basket().begin(),
              _tc_db.get_shopping_basket().end(),
              std::back_inserter(temp));
    if(temp.empty())
        std::cout<<"SE temp is empty";

    return temp;
}



