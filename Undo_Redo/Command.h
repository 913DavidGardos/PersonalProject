//
// Created by david on 25.05.2021.
//

#ifndef A8_9_COMMAND_H
#define A8_9_COMMAND_H


#include <vector>
#include <string>

class Command {
public:
    Command(std::string);

    virtual void doCommand();
    virtual void undoCommand();
    virtual void redoCommand();
private:
    std::string name;
public:
    const std::string &getName() const;
};


#endif //A8_9_COMMAND_H
