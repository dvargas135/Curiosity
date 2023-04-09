#ifndef _ubicar_h
#define _ubicar_h
#include <vector>
#include "../classes/element.hpp"
#include "../trees\quad/quadnode.hpp"
#include <iostream>
using namespace std;

vector<Element> en_cuandrante(double x1,double x2, double y1, double y2,QuadNode* root);

#endif