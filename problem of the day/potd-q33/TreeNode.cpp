#include "TreeNode.h"
#include <iostream>
using namespace std;
TreeNode*& _find(TreeNode* &root, const int &key) {
  if (root == NULL){
    return root;
  }
  if (key == root->val_){
    return root;
  }
  if (key < root->val_){
    return _find(root->left_, key);
  }
  if (key > root->val_){
    return _find(root->right_, key);
  }
  return root; // this bull shit is just to get rid of a warning
} 

// TreeNode*& _findParent(TreeNode* &root, const int &key) {
//   if (_findParent(root->left_, key))
// } 



TreeNode* deleteNode(TreeNode* root, int key) {
  // your code here
  TreeNode*& ptr_tgtpt = _find(root, key);
  if (ptr_tgtpt->left_ == NULL && ptr_tgtpt->right_ == NULL){//leaf
    delete ptr_tgtpt; ptr_tgtpt = NULL;
    return root;
  }
  if (ptr_tgtpt->left_ == NULL){//one right child
    ptr_tgtpt = ptr_tgtpt->right_;
    return root;
  }
  if (ptr_tgtpt->right_ == NULL){//one left child
    ptr_tgtpt = ptr_tgtpt->left_;
    return root;
  }

  TreeNode* cun = ptr_tgtpt->right_;
  while (cun->left_ != NULL){
    cun = cun->left_;
  }
  ptr_tgtpt->val_ = cun->val_;
  ptr_tgtpt->right_ = deleteNode(ptr_tgtpt->right_, cun->val_);
  //     cout << "reach" << endl;
  //     inorderPrint(cun);

  // ptr_tgtpt = ptr_tgtpt->right_;

  // ptr_tgtpt->left_ = cun->left_;

  // ptr_tgtpt->right_ = cun;

  // cun->left_ = NULL;
  // cun->right_ = NULL;

  // // deleteNode(root, key);
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
