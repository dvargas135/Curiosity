#include "quadnode.hpp"

class QuadTree {
    protected:
        QuadNode* raiz;
    public:
        QuadTree();
        QuadTree(Point val);
        ~QuadTree();
        Point rootData();
        QuadNode* getRoot();
        void setRoot(QuadNode* rootNode);
        bool isEmpty();
        bool insert(Point val);
        void preOrder();
        void inOrder();
        void posOrder();
        void levelOrder();
};