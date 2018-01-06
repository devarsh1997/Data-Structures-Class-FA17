#include "disjointsets.h"
using std::vector;

#include <iostream>

/**
 * Joins the set containing a and the set containing b.
 *
 * Should use union-by-size. In case of a tie, proceed as if the set containing
 * a has larger size than the set containing b.
 */
void DisjointSets::unionBySize(int a, int b) {
  // TODO: implement this function

  a = find(a);
  b = find(b);
  if (a==b){
    return;
  }
  // std::cout << a << std::endl;
  // std::cout << b << '\n';
  int he = _data[a]+_data[b];
  if (_data[a] <= _data[b]){
    _data[b] = a;
    _data[a] = he;
  }else{
    _data[a] = b;
    _data[b] = he;
  }
}

/**
 * Finds the representative element of the set containing elem. Should compress
 * paths.
 */
int DisjointSets::find(int elem) {
  // TODO: modify this function to implement path compression
  int output;
  if (_data[elem] < 0) {
    output = elem;
  }else{
    output = find(_data[elem]);
    _data[elem] = output;
  }
  return output;
}


/*************************************
 * PROVIDED CODE - no need to modify *
 *************************************/
void DisjointSets::makeSets(int num) {
  for (; num > 0; num--) {
    _data.push_back(-1);
  }
}

int DisjointSets::simpleFind(int elem) const {
  if (_data[elem] < 0) {
    return elem;
  }
  return simpleFind(_data[elem]);
}
