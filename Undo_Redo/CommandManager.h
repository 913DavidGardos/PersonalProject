//
// Created by david on 27.05.2021.
//

#ifndef A8_9_COMMANDMANAGER_H
#define A8_9_COMMANDMANAGER_H
#include <memory>

#include "Command.h"

class CommandManager{
public:
    void requestDoCommand(std::unique_ptr<Command> c);
    void requestUndoCommand();
    void requestRedoCommand();

public:

    std::vector<std::unique_ptr<Command>> doneCommands;
    std::vector<std::unique_ptr<Command>> undoneCommands;

    void free_mem();
};


#endif //A8_9_COMMANDMANAGER_H
