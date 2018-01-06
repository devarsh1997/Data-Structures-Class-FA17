#include "TreeNode.h"

// Your function here

TreeNode *makeFullLeft(int n) {

  int ct = 0;
  TreeNode* out = new TreeNode(ct, NULL, NULL);
  if (n == 1){
    return out;
  }
  ct += 2;
  out->left_ = new TreeNode(ct, NULL, NULL);
  out->right_ = new TreeNode(ct+1, NULL, NULL);
  TreeNode* cur = out;
  while(cur->right_->data_ != n){
    cur = cur->left_;
    ct += 2;
    cur->left_ = new TreeNode(ct, NULL, NULL);
    cur->right_ = new TreeNode(ct+1, NULL, NULL);
  }
  return out;
}

// Methods and functions we provide following.
// You should not need to edit this code.

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right) :
    data_(data), left_(left), right_(right) {}

TreeNode::~TreeNode() {
    if (left_ != NULL)
        delete left_;
    if (right_ != NULL)
        delete right_;
}

bool equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == NULL)
        return n2 == NULL;

    if (n2==NULL)
        return false;

    return (n1->getData() == n2->getData() &&
            equal(n1->getLeft(),n2->getLeft()) &&
            equal(n1->getRight(),n2->getRight()));
}

int TreeNode::getData() const {
    return data_;
}

TreeNode *TreeNode::getLeft() const {
    return left_;
}

TreeNode *TreeNode::getRight() const {
    return right_;
}
