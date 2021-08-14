//
// Created by david on 31.03.2021.
//
#include <iostream>
#include <fstream>
#include "TC_Database.h"

int TC_Database::get_tc_number()
{
    return vec.size();
}

TC_Database::TC_Database(const std::string &file_path)
: _file_path(file_path), _file(file_path)
{
    add_from_file();
}

//void TC_Database::add_from_file(const std::string &file_path)
//{
//    std::ifstream file(file_path);
//
//    if (!file.is_open())
//        return;
//    TrenchCoat t;
//
//    while (file >> t)
//    {
//        this->vec.emplace_back(t);
//    }
//    file.close();
//}

void TC_Database::add_tc(TrenchCoat &t)
{
//    int id = get_next_id();
//    t.set_id(id);

    tc_map.insert(std::pair<int, TrenchCoat>(t.get_id(), t));
    _file.write_tc_map_to_file(tc_map);
}

void TC_Database::undo_add(const TrenchCoat& tc)
{
    std::cout<<"INTRA"<<std::endl;
    if(tc_map.empty())
        return;

    for(auto elem : tc_map)
    {
        if(tc == elem.second)
        {
            tc_vector_erased_items_add_command.push_back(tc);

            tc_map.erase(elem.first);

            _file.write_tc_map_to_file(tc_map);
            std::cout<<"INTRA"<<std::endl;
            break;
        }
    }
}


void TC_Database::redo_add()
{
    if(tc_vector_erased_items_add_command.empty())
        return;

    auto elem = tc_vector_erased_items_add_command.back();

    tc_map.insert(std::pair<int, TrenchCoat>(elem.get_id(),elem));
    _file.write_tc_map_to_file(tc_map);
    tc_vector_erased_items_add_command.pop_back();
}

void TC_Database::remove_tc(int id)
{
//    for(auto item : tc_map)
//        std::cout<<item.first<<" "<<item.second<<std::endl;

//      here is the code if the id is generated not provided by the user
//    if(tc_map.find(id) == tc_map.end())
//    {
//        std::cout<<"id isn t present in the map :)"<<std::endl;
//        return;
//    }
//    tc_map.erase(id);
    if(tc_map.find(id) == tc_map.end())
    {
        std::cout<<"id isn t present in the map :)"<<"the id is:"<< id <<std::endl;
        return;
    }
    for(auto it = tc_map.begin(); it != tc_map.end(); ++it)
    {
        if (it->second.get_id() == id)
        {
            tc_vector_erased_items_remove_command.push_back(it->second);
            tc_map.erase(it->first);
            break;
        }
    }
    _file.write_tc_map_to_file(tc_map);
}

void TC_Database::undo_remove_tc()
{
    if(tc_vector_erased_items_remove_command.empty())
        return;
    auto elem = tc_vector_erased_items_remove_command.back();
    tc_vector_erased_items_remove_command.pop_back();
    tc_map.insert(std::pair<int, TrenchCoat>(elem.get_id(), elem));
    _file.write_tc_map_to_file(tc_map);
}

void TC_Database::redo_remove_tc(const TrenchCoat &coat)
{
    if(tc_map.empty())
        return;

    for(auto elem : tc_map)
    {
        if(elem.second == coat)
        {
            tc_vector_erased_items_remove_command.push_back(elem.second);
            tc_map.erase(elem.first);
            _file.write_tc_map_to_file(tc_map);

            break;
        }
    }
}

void TC_Database::update_tc(TrenchCoat& t)
{
    //      here is the code if the id is generated not provided by the user
//    if(tc_map.find(t.get_id()) == tc_map.end())
//    {
//        std::cout<<"id not present in the map :)"<<std::endl;
//        return;
//    }
    auto old_elem = tc_map.find(t.get_id());
//    std::cout<<old_elem->second<<std::endl;
    tc_vector_previous_to_update.push_back(old_elem->second);

    tc_map.erase(old_elem->first);
    _file.write_tc_map_to_file(tc_map);

    tc_map.insert(std::pair<int, TrenchCoat>(t.get_id(), t));
//    std::cout<<t<<std::endl;
    _file.write_tc_map_to_file(tc_map);
}

void TC_Database::undo_update_tc(const TrenchCoat& coat)
{
//    tc_vector_previous_to_update.push_back(coat);
//
//    tc_map.erase(coat.get_id());
//    _file.write_tc_map_to_file(tc_map);
//
//    auto old_elem = tc_vector_previous_to_update.end()[-2];//second to last element
//    tc_map.insert(std::pair<int, TrenchCoat>(old_elem.get_id(), old_elem));
//    _file.write_tc_map_to_file(tc_map);
//
//    for(auto it = tc_vector_previous_to_update.begin(); it != tc_vector_previous_to_update.end(); it++)
//    {
//        if(*it == old_elem)
//            tc_vector_previous_to_update.erase(it);
//    }
    auto old_elem = tc_vector_previous_to_update.back();
        std::cout<<"old elem: "<<old_elem<<std::endl;

    tc_vector_previous_to_update.pop_back();
    for(auto elem : tc_map)
    {
        if(old_elem.get_id()==elem.first)
        {
            auto temp = tc_map.at(elem.first);
                std::cout<<"elem in tcmap: "<<tc_map.at(elem.first)<<std::endl;

            tc_map[elem.first] = old_elem;
            std::cout<<"elem in tcmap: "<<tc_map.at(elem.first)<<std::endl;

            old_elem = temp;
        }
    }
    redo_update_tc_vector_previous.push_back(old_elem);
    _file.write_tc_map_to_file(tc_map);
//
//    tc_vector_previous_to_update.push_back(coat);
//    for(auto it = tc_map.begin(); it != tc_map.end(); it++)
//    {
//        if(it->second == old_elem)
//        {
//            tc_vector_previous_to_update.push_back(coat);
//            tc_map.erase(it->first);
//            break;
//        }
//    }
//
//    tc_map.insert(std::pair<int, TrenchCoat>(coat.get_id(), old_elem));
//    _file.write_tc_map_to_file(tc_map);
}

void TC_Database::redo_update_tc()
{
    auto old_elem = redo_update_tc_vector_previous.back();
    std::cout<<"old elem: "<<old_elem<<std::endl;

    redo_update_tc_vector_previous.pop_back();
    for(auto elem : tc_map)
    {
        if(old_elem.get_id()==elem.first)
        {
            auto temp = tc_map.at(elem.first);
            std::cout<<"elem in tcmap: "<<tc_map.at(elem.first)<<std::endl;

            tc_map[elem.first] = old_elem;
            std::cout<<"elem in tcmap: "<<tc_map.at(elem.first)<<std::endl;

            old_elem = temp;
        }
    }
    tc_vector_previous_to_update.push_back(old_elem);
    _file.write_tc_map_to_file(tc_map);
}



int TC_Database::get_next_id()
{
    if(tc_map.empty())
        return 0;

    int temp = tc_map.size();
    while(tc_map.find(temp) != tc_map.end())
    {
        temp++;
    }
    return temp;
}

void TC_Database::add_from_file()
{
    std::vector<TrenchCoat> v;
    _file.read_tc_from_file(v);
    for(auto tc : v)
        tc_map.insert(std::pair<int, TrenchCoat>(tc.get_id(),tc));
}

void TC_Database::print_contents_of_tc_db()
{
    for(auto tc : tc_map)
        std::cout<< tc.first<< " " << tc.second << std::endl;

}

void TC_Database::append_tc_to_shopping_basket(TrenchCoat& coat)
{
    basket.push_back(coat);
}

const std::map<int, TrenchCoat> &TC_Database::get_tc_map()
{
    return tc_map;
}

const std::vector<TrenchCoat>& TC_Database::get_shopping_basket()
{
    return basket;
}

void TC_Database::append_tc_to_erased_items(TrenchCoat &coat)
{
    tc_vector_erased_items_add_command.push_back(coat);
}

const TrenchCoat& TC_Database::get_tc_vector_erase_top_element()
{
    if(!tc_vector_erased_items_add_command.empty())
    {
        return tc_vector_erased_items_add_command.back();
    }
}


const TrenchCoat &TC_Database::get_tc_map_previous_to_update_top_element()
{
    if(!tc_vector_previous_to_update.empty())
    {
        auto temp = tc_vector_previous_to_update.size() - 1;
        return tc_vector_previous_to_update.at(temp);
    }
}

void TC_Database::remove_tc_vector_erased_top_element()
{
    if(!tc_vector_erased_items_add_command.empty())
        tc_vector_erased_items_add_command.pop_back();
}











//    TrenchCoat t1(1,"S","red",34,1,"http://www.newsshare.in/wp-content/uploads/2016/09/Trench-Coat-6.jpg");
//    TrenchCoat t2(2,"M","brown",4,20,"https://media1.popsugar-assets.com/files/thumbor/rPXi86rwn-7hNNQxpx0bbJIKN9U/fit-in/1024x1024/filters:format_auto-!!-:strip_icc-!!-/2019/09/18/593/n/2589280/d6988d496d187a41_app005prod_6_/i/Other-Stories-Belted-Trench-Coat.jpeg");
//    TrenchCoat t3(3,"S","red",32,31,"https://cdnd.lystit.com/photos/2013/11/05/burberry-dark-teal-midlength-slim-fit-wool-cashmere-trench-coat-product-1-14709274-528981409.jpeg");
//    TrenchCoat t4(4,"XL","grey",14,56,"https://duckduckgo.com/?q=photos+of+trench+coats&t=brave&iax=images&ia=images&iai=https%3A%2F%2Fcdnb.lystit.com%2Fphotos%2F4548-2014%2F03%2F13%2Fburberry-brown-long-cotton-bonded-virgin-wool-mohair-trench-coat-product-1-18403279-2-538602497-normal.jpeg");
//    TrenchCoat t5(5,"S","red",58,63,"https://cdna.lystit.com/photos/2013/12/03/burberry-parade-red-long-gem-collar-satin-trench-coat-product-1-15766705-036021481.jpeg");
//    TrenchCoat t6(6,"XXL","blue",90,106,"https://cdna.lystit.com/photos/2e99-2014/01/12/burberry-green-double-cotton-military-trench-coat-product-1-16688807-1-542220550-normal.jpeg");
//    TrenchCoat t7(7,"M","red",31,70,"https://cdna.lystit.com/photos/2012/03/30/burberry-jet-black-long-cotton-gabardine-hooded-trench-coat-product-1-3139045-819569369.jpeg");
//    TrenchCoat t8(8,"L","black",64,89,"https://cdna.lystit.com/photos/2013/07/30/ndeg-21-ivory-flared-hem-trench-coat-product-1-12235532-058854430.jpeg");
//    TrenchCoat t9(9,"XXXL","white",18, 17,"https://cdna.lystit.com/photos/burberry/e7e2da9c/burberry-DARK-CAMEL-Cashmere-Trench-Coat.jpeg");
//    TrenchCoat t10(10,"M","red",24, 28,"https://cdna.lystit.com/photos/2013/04/05/burberry-brit-taupe-britton-doublebreasted-trenchcoat-product-1-7647594-776935097.jpeg");
//    this->vec.emplace_back(t1);
//    this->vec.emplace_back(t2);
//    this->vec.emplace_back(t3);
//    this->vec.emplace_back(t4);
//    this->vec.emplace_back(t5);
//    this->vec.emplace_back(t6);
//    this->vec.emplace_back(t7);
//    this->vec.emplace_back(t8);
//    this->vec.emplace_back(t9);
//    this->vec.emplace_back(t10);
