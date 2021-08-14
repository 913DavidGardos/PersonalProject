//
// Created by david on 25.05.2021.
//

#include <iostream>
#include "Command.h"


Command::Command(std::string name)
{

}

void Command::doCommand()
{
    std::cout<<"done command"  << name << " from Command class";
}

void Command::undoCommand()
{
    std::cout << "undone command " << name << " from Command class";
}

const std::string &Command::getName() const {
    return name;
}

void Command::redoCommand() {
    std::cout << "redone command " << name << " from Command class";
}
