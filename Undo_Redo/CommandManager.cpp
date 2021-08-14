//
// Created by david on 27.05.2021.
//

#include <iostream>
#include "CommandManager.h"

void CommandManager::requestDoCommand(std::unique_ptr<Command> c)
{
    c->doCommand();
    doneCommands.push_back(std::move(c));
    undoneCommands.clear();
}

void CommandManager::requestUndoCommand()
{
    if (doneCommands.empty())
        return;
    std::unique_ptr<Command> temp;
    temp = std::move(doneCommands.at(doneCommands.size() - 1));
    undoneCommands.push_back(std::move(temp));
    undoneCommands.back()->undoCommand();
    doneCommands.pop_back();
}

void CommandManager:: requestRedoCommand()
{
    if (undoneCommands.empty())
        return;
    std::unique_ptr<Command> temp;
    temp = std::move(undoneCommands.at(undoneCommands.size() - 1));
    doneCommands.push_back(std::move(temp));
    doneCommands.back()->redoCommand();
    undoneCommands.pop_back();
}

void CommandManager::free_mem()
{
//    if(!doneCommands.empty() && !undoneCommands.empty())
//    {
//        for (auto item : doneCommands)
//            delete item;
//        for (auto item : undoneCommands)
//            delete item;
//    }
}
