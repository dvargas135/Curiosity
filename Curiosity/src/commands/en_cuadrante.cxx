#include "en_cuadrante.hpp"
#include <vector>
#include "../classes/element.hpp"
#include "../trees\quad/quadtree.hpp"
#include <iostream>
using namespace std;

vector<Element> en_cuadrante(double x1,double x2, double y1, double y2,QuadNode* root){
vector<Point> elementos;
QuadTree tree;
elementos=tree.listaPreorder(root,x1,x2,y1,y2,elementos);
}