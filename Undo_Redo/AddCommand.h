//
// Created by david on 25.05.2021.
//

#ifndef A8_9_ADDCOMMAND_H
#define A8_9_ADDCOMMAND_H

#include "Command.h"

class AddCommand : public Command{
public:
    AddCommand(TC_Database&, TrenchCoat&);

public:
    void doCommand() override;
    void undoCommand() override;
    void redoCommand() override;

private:
    TC_Database& _tc_db;
    TrenchCoat& _tc;
    TrenchCoat tc_copy_back;
    std::vector<TrenchCoat> tc_copy;
};


#endif //A8_9_ADDCOMMAND_H
