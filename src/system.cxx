#include "system.h"
#include <queue>

void System::addCommand(Command* c) {
    this->cmd_list.push(c);
}

std::queue<Command*> System::getCommands() const {
    return cmd_list;
}

void System::clearCommands() {
    this->cmd_list = {};
}

void System::addElement(Element* c) {
    this->elmt_list.push(c);
}

std::queue<Element*> System::getElements() const {
    return elmt_list;
}

void System::clearElements() {
    this->elmt_list = {};
}