#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
	if (this->left_ == NULL && this->right_ == NULL){
		return 0;
	}
	if (this->left_ == NULL){
		return 1+this->right_->getHeight();
	}
	if (this->right_ == NULL){
		return 1+this->left_->getHeight();
	}
	int left = this->left_->getHeight();
	int right = this->right_->getHeight();
	if (left > right){
		return 1+left;
	}else{
		return 1+right;
	}

}
