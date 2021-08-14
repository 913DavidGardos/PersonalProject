//
// Created by david on 31.03.2021.
//

#ifndef A45_SERVICE_PTC_H
#define A45_SERVICE_PTC_H
#include<iostream>
#include<string>
#include <QVector>
#include <Undo_Redo/Command.h>
#include <Undo_Redo/CommandManager.h>


#include "../Persistency/TC_Database.h"
#include "../Persistency/File.h"
#include "../Persistency/CsvFile.h"
#include "../Persistency/HtmlFile.h"

class Service_ptc {

public:
    Service_ptc(TC_Database& tc_db, File& file, CommandManager& command_manager);

    void undo();

    void redo();

    void free_mem_command_manager();

    int get_basket_size();

    std::vector<TrenchCoat> get_shopping_basket_copy();

public:
    void add_trench_coat(int, const std::string&, const std::string&,  double,  int, const std::string&);
    void delete_trench_coat(int);
    void update_trench_coat(int, const std::string&, const std::string&,  double,  int, const std::string&);
    void see_all_trench_coats();
    void print_item_at_position(int);


    void set_once(int);

    bool add_item_to_basket(int i, const std::string&);

    void print_shopping_basket();

    double return_total_sum(int i);

    double calculate_total_price_sh_basket();

    int return_position_of_item(const std::string &size, int last_position);

    int return_size_of_vector() const;

    void open_libre_office_csv();

    void end_html_file();

    void open_browser_html();


    QVector<TrenchCoat> get_qvec();

private:
    TC_Database& _tc_db;
    File& _file;
    CommandManager& _command_manager;
//    CsvFile& _csv_file;
//    HtmlFile& _html_file;
//    Command& _command;

private:
    int once = 0;


    void open_link_url_of_item(int i);
};


#endif //A45_SERVICE_PTC_H
