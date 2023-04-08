#include "ubicar_elementos.hpp"
#include "../trees/quad/quadtree.hpp"

void ubicar_elementos() {
    QuadTree tree;
    Point p1 = {5, 5};
    Point p2 = {3, 7};
    Point p3 = {8, 1};
    Point p4 = {1, 3};
    Point p5 = {7, 9};
    Point p6 = {2, 2};
    Point p7 = {9, 4};
    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);
    tree.insert(p5);
    tree.insert(p6);
    tree.insert(p7);
    
    std::cout << "Pre-order traversal: ";
    tree.preOrder();
    
    std::cout << "In-order traversal: ";
    tree.inOrder();
    
    std::cout << "Post-order traversal: ";
    tree.postOrder();

    std::cout << "Level-order traversal: ";
    tree.levelOrder();
}