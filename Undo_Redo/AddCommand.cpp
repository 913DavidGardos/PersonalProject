//
// Created by david on 25.05.2021.
//

#include <iostream>
#include <Persistency/TC_Database.h>
#include "AddCommand.h"


AddCommand::AddCommand(TC_Database& tc_db, TrenchCoat& tc)
: Command("Add"), _tc_db(tc_db), _tc(tc)
{
    tc_copy.push_back(tc);
}

void AddCommand::doCommand()
{
    std::cout<<"_tc id:"<<_tc.get_id()<<std::endl;
    _tc_db.add_tc(_tc);
}

void AddCommand::undoCommand()
{
    std::cout<<"tc_copy:"<<tc_copy.back().get_id()<<std::endl;
    _tc_db.undo_add(tc_copy.back());
    tc_copy_back = tc_copy.back();
    tc_copy.pop_back();
}

void AddCommand::redoCommand()
{
    tc_copy.push_back(tc_copy_back);
    _tc_db.redo_add();
}



