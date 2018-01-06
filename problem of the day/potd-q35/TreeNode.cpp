#include "TreeNode.h"
#include <iostream>
using namespace std;
    // int val_;
    // TreeNode *left_;
    // TreeNode *right_;
    // TreeNode(int x) {
    //   left_ = NULL;
    //   right_ = NULL;
    //   val_ = x;

int height(TreeNode* root){
	if (root == NULL){
		return -1;
	}
	if (root->left_ == NULL && root->right_ == NULL){
		return 0;
	}
	if (root->left_ == NULL){
		return 1+height(root->right_);
	}
	if (root->right_ == NULL){
		return 1+height(root->left_);
	}
	int l = height(root->left_);
	int r = height(root->right_);
	if (l>r){
		return 1+l;
	}else{
		return 1+r;
	}
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
	if (root == NULL){
		return true;
	}
	// cout << height(root->left_) <<endl;
	// cout << height(root->right_) << endl;

	int l = height(root->left_);
	int r = height(root->right_);
	if (l-r > 1 || r-l > 1){
		return false;
	}
  	return true;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

