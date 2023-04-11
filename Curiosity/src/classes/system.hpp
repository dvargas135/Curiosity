#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "../trees/quad/quadtree.hpp"

#include "command.hpp"
#include "element.hpp"
#include <queue>

class System {
    public:
        void addCommand(Command*);
        std::queue<Command*> getCommands() const;
        void clearCommands();
        
        void addElement(Element&);
        std::queue<Element> getElements() const;
        void clearElements();

        QuadTree getTree() const;
        void setTree(QuadTree&);
        void setTreeRoot(QuadNode*);
    private:
        std::queue<Command*> cmd_list;
        std::queue<Element> elmt_list;
        QuadTree tree;
};

#endif