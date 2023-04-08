#include "ubicar_elementos.hpp"
#include "../trees/quad/quadtree.hpp"

void ubicar_elementos() {
    QuadTree tree;
    Point p1 = {5.3, 5.5};
    Point p2 = {3.63, 7.3};
    Point p3 = {8.1, 1.98};
    Point p4 = {1.3, 3.11};
    Point p5 = {7.0, 9.3};
    Point p6 = {2.2, 2.16};
    Point p7 = {9.3, 4.10};
    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);
    tree.insert(p5);
    tree.insert(p6);
    tree.insert(p7);

    std::cout << "Pre-order traversal: ";
    tree.preOrder();
    
    std::cout << std::endl << "In-order traversal: ";
    tree.inOrder();
    
    std::cout << std::endl << "Post-order traversal: ";
    tree.postOrder();

    std::cout << std::endl << "Level-order traversal: ";
    tree.levelOrder();

    std::cout << std::endl;
}