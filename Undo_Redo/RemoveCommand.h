//
// Created by david on 29.05.2021.
//

#ifndef A8_9_REMOVECOMMAND_H
#define A8_9_REMOVECOMMAND_H


#include "Command.h"

class RemoveCommand : public Command {
public:
    RemoveCommand(TC_Database &, TrenchCoat &);

public:
    void doCommand() override;
    void undoCommand() override;
    void redoCommand() override;

private:
    TC_Database &_tc_db;
    TrenchCoat &_tc;
    std::vector<TrenchCoat> tc_copy;
};

#endif //A8_9_REMOVECOMMAND_H
