#include "system.hpp"

void System::addCommand(Command* c) {
    this->cmd_list.push(c);
}

std::queue<Command*> System::getCommands() const {
    return cmd_list;
}

void System::clearCommands() {
    this->cmd_list = {};
}

void System::addElement(Element e) {
    this->elmt_list.push_back(e);
}

std::vector<Element> System::getElements() const {
    return elmt_list;
}

void System::clearElements() {
    // for (auto e : elmt_list) {
    //     delete e;
    // }
    this->elmt_list = {};
}

QuadTree System::getTree() const {
    return tree;
}

void System::setTree(QuadTree& tree) {
    this->tree = tree;
}

void System::setTreeRoot(QuadNode* treeroot) {
    this->tree.setRoot(treeroot);
}

Graph System::getGraph() const {
    return graph;
}

void System::setGraph(Graph& graph) {
    this->graph = graph;
}