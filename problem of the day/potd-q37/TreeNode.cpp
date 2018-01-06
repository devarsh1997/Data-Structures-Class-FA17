#include "TreeNode.h"


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
	int l = height(root->left_);
	int r = height(root->right_);
	if (l-r > 1 || r-l > 1){
		return false;
	}
  	return true;
}

bool isAVL(TreeNode* root) {
  // your code here
	if (root == NULL){
		return true;
	}
	if (isHeightBalanced(root)){
		return (isHeightBalanced(root->left_)&&isHeightBalanced(root->right_));
	}	
  	return false;
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
	if (root == NULL){
		return NULL;
	}
	if (!isAVL(root)){//left unbalance or right unballance or left-right > 1
		if (!isAVL(root->left_)){
			return findLastUnbalanced(root->left_);
		}else if (!isAVL(root->right_)) {
			return findLastUnbalanced(root->right_);
		}else{
			return root;
		}
	}
	return NULL;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

