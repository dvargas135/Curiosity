#include "ubicar_elementos.hpp"
#include "../trees/quad/quadtree.hpp"
#include "../util/util.hpp"

void ubicar_elementos(System s) {
    QuadTree tree;
    std::queue<Element*> e_list = s.getElements();
    
    if (e_list.empty()) {
        printf("La información requerida no está almacenada en memoria.\n");
        return;
    }
    
    while (!e_list.empty()) {
        Point p = vectorToPoint(e_list.front()->getPosition());
        tree.insert(p);
        e_list.pop();
    }

    std::cout << "Pre-order: ";
    tree.preOrder();
    
    std::cout << std::endl << "In-order: ";
    tree.inOrder();
    
    std::cout << std::endl << "Post-order: ";
    tree.postOrder();

    std::cout << std::endl << "Level-order: ";
    tree.levelOrder();

    std::cout << std::endl;
}