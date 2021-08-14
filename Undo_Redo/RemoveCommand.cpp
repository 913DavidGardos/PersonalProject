//
// Created by david on 29.05.2021.
//

#include <Persistency/TC_Database.h>
#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(TC_Database& tc_db, TrenchCoat& tc)
: Command("Remove"), _tc_db(tc_db), _tc(tc)
{
    tc_copy.push_back(tc);
}

void RemoveCommand::doCommand()
{
    _tc_db.remove_tc(_tc.get_id());
}

void RemoveCommand::undoCommand()
{
    _tc_db.undo_remove_tc();
}

void RemoveCommand::redoCommand()
{
    _tc_db.redo_remove_tc(tc_copy.back());
    tc_copy.pop_back();
}
