//
// Created by david on 29.05.2021.
//

#ifndef A8_9_UPDATECOMMAND_H
#define A8_9_UPDATECOMMAND_H


#include "Command.h"

class UpdateCommand : public Command {
public:
    UpdateCommand(TC_Database &, TrenchCoat &);

public:
    void doCommand() override;
    void undoCommand() override;
    void redoCommand() override;

private:
    TC_Database &_tc_db;
    TrenchCoat &_tc;
    std::vector<TrenchCoat> before_update_items;
};

#endif //A8_9_UPDATECOMMAND_H
