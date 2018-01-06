#include "TreeNode.h"
#include <iostream>
#include <cmath>

// Part 1 code

void rotateRight(TreeNode *& root) {

    TreeNode *nuRoot = root->left_;
    root->left_ = nuRoot->right_;
    nuRoot->right_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->right_);
    return;
}


void rotateLeft(TreeNode *& root) {

    TreeNode *nuRoot = root->right_;
    root->right_ = nuRoot->left_;
    nuRoot->left_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->left_);
    return;
}

void rotateLeftRight(TreeNode* &root) {
    rotateLeft(root->left_);
    rotateRight(root);
}


void rotateRightLeft(TreeNode* &root) {
    rotateRight(root->right_);
    rotateLeft(root);
}

// Your Code

void insert(TreeNode* &root, int val) {
    // Your code here
    if (root == NULL){
      root = new TreeNode(val);
      updateHeight(root);
      return;
    }
    if (val < root->val_){//insert left
      if (root->left_ == NULL){
        root->left_ = new TreeNode(val);
      }else{
        insert(root->left_, val);
      }
    }
    if (val > root->val_) {//insert right
      if (root->right_ == NULL){
        root->right_ = new TreeNode(val);
      }else{
        insert(root->right_, val);
      }
    }
    rebalance(root);
    updateHeight(root);
    return;
}

void rebalance(TreeNode* &root) {
    // The following line is to silence compiler warnings.  Delete it.
    if (root == NULL){
      return;
    }
    int leftH = heightOrNeg1(root->left_);
    int rightH = heightOrNeg1(root->right_);
    if ((rightH-leftH)>1){//right long
      // if (root->right_->right_ == NULL){
      //   rotateRightLeft(root->right_);
      // }else{
        rotateLeft(root->right_);
      //}
      //rebalance(root->right_);
      return;
    }else if ((leftH-rightH)>1){//left long
      // if (root->left_->left_ == NULL){
      //   rotateLeftRight(root->left_);
      // }else{
        rotateRight(root->left_);
      //}
      //rebalance(root->left_);
      return;
    }else{
      return;
    }
}

// Helper functions

int heightOrNeg1(TreeNode *root) {
    if (root==NULL)
        return -1;
    else
        return root->height_;
}

void updateHeight(TreeNode * node) {
    node->height_ = 1 + std::max(heightOrNeg1(node->right_), heightOrNeg1(node->left_));
}

using namespace std;

void show(TreeNode *t1) {
    if (t1==NULL) {
        cout << "x";
        return;
    }

    if (t1->left_ == NULL && t1->right_==NULL) {
        cout << t1->val_;
        return;
    }

    cout << "(" << t1-> val_ << " ";
    show(t1->left_);
    cout << " ";
    show(t1->right_);
    cout << ")";
}

void deleteTree(TreeNode* root)
{
    if (root == NULL) return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}
