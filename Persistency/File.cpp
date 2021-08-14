//
// Created by david on 11.05.2021.
//

#include "File.h"
#include <ostream>
#include <fstream>
#include <utility>


void File::append_to_file(const TrenchCoat &t)
{
    std::ofstream f(_file_path, std::ios::app);	// will append data
    if (!f.is_open())
    {
        return;
    }
    f << std::endl;
    f << t;

    f.close();
}

//void File::delete_file_line(int id, TC_Database &tc_db)
//{
//    std::ifstream file("/home/david/CLionProjects/A8-9/Persistency/1.txt");
//    std::ofstream temp("/home/david/CLionProjects/A8-9/Persistency/temp.txt");
//    TrenchCoat t{};
//    if (!file.is_open())
//    {
//        std::cout<<"file didn t open"<<std::endl;
//        return;
//    }
//    if(!temp.is_open())
//    {
//        std::cout<<"temp didn t open"<<std::endl;
//        return;
//    }
//    for(int i = 0; i < tc_db.vec.size(); i++)
//    {
//        temp << tc_db.vec.at(i);
//        if(i == tc_db.vec.size()-1)
//            break;
//        if(tc_db.vec.at(i).get_id() != id)
//            temp << std::endl;
//
//
//    }
//    file.close();
//    temp.close();
//    remove("/home/david/CLionProjects/A8-9/Persistency/1.txt");
//    rename("/home/david/CLionProjects/A8-9/Persistency/temp.txt", "/home/david/CLionProjects/A8-9/Persistency/1.txt");
//}


void File::update_in_file(int id, TrenchCoat& coat)
{
    std::ifstream file("/home/david/CLionProjects/A8-9/Persistency/1.txt");
    std::ofstream temp("/home/david/CLionProjects/A8-9/Persistency/temp.txt");
    TrenchCoat t{};
    if (!file.is_open())
    {
        std::cout<<"file didn t open"<<std::endl;
        return;
    }
    if(!temp.is_open())
    {
        std::cout<<"temp didn t open"<<std::endl;
        return;
    }
    while (file >> t)
    {
        if(t.get_id() != id)
        {
            temp << t << std::endl;
        }
        else
        {
            temp << coat << std::endl;
        }
    }
    file.close();
    temp.close();
    remove("/home/david/CLionProjects/A8-9/Persistency/1.txt");
    rename("/home/david/CLionProjects/A8-9/Persistency/temp.txt", "/home/david/CLionProjects/A8-9/Persistency/1.txt");
}

void File::append_to_basket_file(TrenchCoat& item)
{
    std::ofstream f("/home/david/CLionProjects/A8-9/Persistency/basket.txt", std::ios::app);
    if (!f.is_open())
    {
        return;
    }

    f << std::endl;
    f << item;

    f.close();
}

File::File(std::string  file_path)
: _file_path(std::move(file_path))
{

}

void File::read_tc_from_file(std::vector<TrenchCoat> & vec)
{
    std::ifstream file(_file_path);
    if (!file.is_open())
        return;
    TrenchCoat t;

    while (file >> t)
    {
        vec.emplace_back(t);
    }
    file.close();
}

void File::write_tc_map_to_file(const std::map<int, TrenchCoat>& tc_map)
{
    std::ofstream file(_file_path, std::ofstream::trunc);
    if(!file.is_open())
        return;

    for(auto tc : tc_map)
    {
        file << tc.second << std::endl;
    }
    file.close();
}

const std::string &File::get_file_path() {
    return _file_path;
}

