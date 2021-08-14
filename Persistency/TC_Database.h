//
// Created by david on 31.03.2021.
//

#ifndef A45_REPO_PTC_H
#define A45_REPO_PTC_H
#include<vector>

#include <map>
#include "../Domain/TrenchCoat.h"
#include "File.h"

class TC_Database {
public:
    TC_Database() = default;
    TC_Database(const std::string& file_path);
    //good to know:





public:
    int get_tc_number();
    const std::map<int, TrenchCoat>& get_tc_map();
    const std::vector<TrenchCoat>& get_shopping_basket();
    const TrenchCoat& get_tc_vector_erase_top_element();
    const TrenchCoat& get_tc_map_previous_to_update_top_element();

public:
    void add_tc(TrenchCoat& t);
    void undo_add(const TrenchCoat&);
    void redo_add();

    void remove_tc(int id);
    void undo_remove_tc();
    void redo_remove_tc(const TrenchCoat &coat);

    void update_tc(TrenchCoat& );
    void undo_update_tc(const TrenchCoat&);
    void redo_update_tc();


    void print_contents_of_tc_db();
    void append_tc_to_shopping_basket(TrenchCoat&);
    void append_tc_to_erased_items(TrenchCoat &coat);
    void append_tc_to_items_previous_to_update(TrenchCoat& coat);
    void remove_tc_map_previous_to_update_top_element();
    void remove_tc_vector_erased_top_element();

private:
    File _file;
    std::string _file_path;
    std::vector<TrenchCoat> vec = {};
    std::map<int, TrenchCoat> tc_map;
    std::vector<TrenchCoat> basket = {};

    std::vector<TrenchCoat> tc_vector_previous_to_update;
    std::vector<TrenchCoat> tc_vector_erased_items_add_command;
    std::vector<TrenchCoat> tc_vector_erased_items_remove_command;
    std::vector<TrenchCoat> redo_update_tc_vector_previous;

private:
    int get_next_id();
    void add_from_file();
};


#endif //A45_REPO_PTC_H
