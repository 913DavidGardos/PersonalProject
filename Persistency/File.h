//
// Created by david on 11.05.2021.
//

#ifndef A45_FILE_H
#define A45_FILE_H


#include <map>
#include <vector>
#include "../Domain/TrenchCoat.h"
class File{
public:
    File(std::string );

public:
    const std::string& get_file_path();

public:
    void append_to_file(const TrenchCoat &t);
//    void delete_file_line(int id, TC_Database &re);
    void write_tc_map_to_file(const std::map<int, TrenchCoat>& );
    void update_in_file(int id, TrenchCoat &coat);
    virtual void append_to_basket_file(TrenchCoat &item);
    void read_tc_from_file(std::vector<TrenchCoat>&);

protected:
    std::string _file_path;
};


#endif //A45_FILE_H
