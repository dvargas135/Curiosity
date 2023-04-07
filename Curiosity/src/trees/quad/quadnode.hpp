#include "point.hpp"
class QuadNode {
    protected:
        Point data;
        QuadNode* superiorLeftChild;
        QuadNode* superiorRightChild;
        QuadNode* inferiorLeftChild;
        QuadNode* inferiorRightChild;
    public:
        QuadNode();
        QuadNode(Point val);
        ~QuadNode();
        Point getData();
        void setData(Point val);
        QuadNode* getSuperiorLeftChild();
        QuadNode* getSuperiorRightChild();
        QuadNode* getInferiorLeftChild();
        QuadNode* getInferiorRightChild();
        void setSuperiorLeftChild(QuadNode* sleft);
        void setSuperiorRightChild(QuadNode* sright);
        void setInferiorLeftChild(QuadNode* ileft);
        void setInferiorRightChild(QuadNode* iright);
        bool isLeaf();
};