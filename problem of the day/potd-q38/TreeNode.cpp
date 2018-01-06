#include "TreeNode.h"
#include <algorithm>

int getheight(TreeNode * root) {
  int height = 0;
  if (root == NULL) {return 0;}
  height++;
  if (getheight(root->right_) > getheight(root->left_)) {
    height = height + getheight(root->right_);
  }
  else {
    height = height + getheight(root->left_);
  }
  return height;
}

int getb(TreeNode * root) {
  int b = getheight(root->right_) - getheight(root->left_);
  return b;
}

void rightRotate(TreeNode* root) {
    TreeNode* x = root;
    TreeNode* y = root->left_;
    if (x->parent_ != NULL) {
      x->parent_->left_ = y;
    }
    y->parent_ = x->parent_;
    x->left_ = y->right_;
    if (y->right_ != NULL) {
      y->right_->parent_ = x;
    }
    y->right_ = x;
    x->parent_ = y;
}


    // Your code here


void leftRotate(TreeNode* root) {
    TreeNode* x = root;
    TreeNode* y = root->right_;
    if (x->parent_ != NULL) {
      x->parent_->right_ = y;
    }
    y->parent_ = x->parent_;
    x->right_ = y->left_;
    if (y->left_ != NULL) {
      y->left_->parent_ = x;
    }
    y->left_ = x;
    x->parent_ = y;
    // your code her
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

