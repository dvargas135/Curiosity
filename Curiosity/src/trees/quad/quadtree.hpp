#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include "quadnode.hpp"
#include "../../classes/element.hpp"
#include <vector>

class QuadTree {
    protected:
        QuadNode* root;
    public:
        QuadTree();
        QuadTree(Point val);
        ~QuadTree();
        void deleteSubtree(QuadNode* node);
        Point rootData();
        QuadNode* getRoot();
        void setRoot(QuadNode* root_node);
        bool isEmpty();
        bool insert(Point& val);
        void preOrder(QuadNode* root);
        std::vector<Point> listaPreorder(QuadNode* root, double x1, double x2, double y1, double y2, std::vector<Point> puntos);
        void preOrder();
        void inOrder(QuadNode* root);
        void inOrder();
        void postOrder(QuadNode* root);
        void postOrder();
        void levelOrder();
};

#endif