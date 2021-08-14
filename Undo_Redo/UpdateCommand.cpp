//
// Created by david on 29.05.2021.
//

#include <Persistency/TC_Database.h>
#include "UpdateCommand.h"

UpdateCommand::UpdateCommand(TC_Database& tc_db, TrenchCoat& tc)
: Command("Update"), _tc_db(tc_db), _tc(tc)
{
    before_update_items.push_back(tc);
}

void UpdateCommand::doCommand()
{
    _tc_db.update_tc(_tc);
}

void UpdateCommand::undoCommand()
{
    _tc_db.undo_update_tc(before_update_items.back());
//    before_update_items.pop_back();
}

void UpdateCommand::redoCommand()
{
    _tc_db.redo_update_tc();
}
