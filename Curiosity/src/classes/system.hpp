#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "../trees/quad/quadtree.hpp"
#include "../graph/Graph.hpp"

#include "command.hpp"
#include "element.hpp"
//#include "graph.hpp"
#include <queue>

class System {
    public:
        ~System();
        void addCommand(Command*);
        std::queue<Command*> getCommands() const;
        void clearCommands();
        
        void addElement(Element);
        std::vector<Element> getElements() const;
        void clearElements();

        QuadTree getTree() const;
        void setTree(QuadTree&);
        void setTreeRoot(QuadNode*);

        Graph* getGraph() const;
        void setGraph(Graph*);
    private:
        std::queue<Command*> cmd_list;
        std::vector<Element> elmt_list;
        QuadTree tree;
        Graph* graph;
};

#endif