#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "command.hpp"
#include "element.hpp"
#include <queue>

class System {
    public:
        void addCommand(Command*);
        std::queue<Command*> getCommands() const;
        void clearCommands();
        
        void addElement(Element*);
        std::queue<Element*> getElements() const;
        void clearElements();
    private:
        std::queue<Command*> cmd_list;
        std::queue<Element*> elmt_list;
};

#endif