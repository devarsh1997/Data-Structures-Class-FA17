#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <iostream>
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"
using namespace std;
/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  int i_x = start.x;
  int i_y = start.y;
  int w = png.width();
  int h = png.height();
  tool.push_front(start);
  while (!tool.empty()){
    Point temp = this->pop();
    int x = temp.x;
    int y = temp.y;
    if (std::find(seq.begin(),seq.end(),temp) == seq.end()){
      seq.push_back(temp);
      if (x+1 < w){
        if (calculate(*(png.getPixel(x+1, y)), *(png.getPixel(i_x, i_y))) < tolerance) {
          add(Point(x+1, y));
        }
      }
      if (y+1 < h){
        if (calculate(*(png.getPixel(x, y+1)), *(png.getPixel(i_x, i_y))) < tolerance) {
          add(Point(x, y+1));
        }
      }
      if (x-1 >= 0){
        if (calculate(*(png.getPixel(x-1, y)), *(png.getPixel(i_x, i_y))) < tolerance) {
          add(Point(x-1, y));
        }
      }
      if (y-1 >= 0){
        if (calculate(*(png.getPixel(x, y-1)), *(png.getPixel(i_x, i_y))) < tolerance) {
          add(Point(x, y - 1));
        }
      }
    }
  }
}
/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
 /** @todo [Part 1] */
  return ImageTraversal::Iterator(this->seq.begin());

}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
    return ImageTraversal::Iterator(this->seq.end());
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  this->tool.push_front(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point out = this->tool.front();
  this->tool.pop_front();
  return out;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  Point out = this->tool.front();
  return out;
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return this->tool.empty();
}
