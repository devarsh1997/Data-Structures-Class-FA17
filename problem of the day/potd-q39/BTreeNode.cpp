#include <vector>
#include "BTreeNode.h"
#include <iostream>

using namespace std;




std::vector<int> traverse(BTreeNode* root) {
  std::vector<int> v;
  if (root->is_leaf_) {
    cout << 13 << endl;
    for (unsigned i = 0; i < root->elements_.size(); i++) {
      v.push_back(root->elements_[i]);
    }
    return v;
  }
  for (unsigned i = 0; i < root->elements_.size(); i++) {

    if (root->elements_[i] == root->elements_.back()) {
      cout << 22 << endl;
      vector<int> ele1 =  traverse(root->children_[i]);
      for (unsigned i = 0; i < ele1.size(); i++) {
        v.push_back(ele1[i]);
      }
      v.push_back(root->elements_[i]);
      vector<int> ele2 = traverse(root->children_[i+1]);
      for (unsigned i = 0; i < ele2.size(); i++) {
        v.push_back(ele2[i]);
      }
    }
    else {
    vector <int> ele3 = traverse(root->children_[i]);
    for (unsigned i = 0; i < ele3.size(); i++) {
      v.push_back(ele3[i]);
    }
    v.push_back(root->elements_[i]);
    }

  }

  return v;
}
