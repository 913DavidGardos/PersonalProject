//
// Created by david on 31.03.2021.
//

#ifndef A45_CONSOLE_H
#define A45_CONSOLE_H


#include "../Business/Service_ptc.h"

class Console{
private:
    Service_ptc& _se;
public:
    Console(Service_ptc& se);

    void run();

    void Admin_mode();

    void Client_mode();

    void add_trench_coat_ui();

    void delete_trench_coat_ui();

    void update_trench_coat_ui();

    void see_all_trench_coats_ui();

    void see_trench_coat(const std::string&);

    void see_shopping_basket(const std::string&);

    void see_one_by_one_ui(const std::string &size, double total_sum, const std::string&);

    void purchase_ui(int total_sum, int last_position);

    void purchase_ui(double total_sum, int last_position, const std::string&);

    void undo();

    void redo();
};


#endif //A45_CONSOLE_H
