#include <vector>
#include "BTreeNode.h"

// struct BTreeNode {
//     bool is_leaf_=true;
//     std::vector<int> elements_;
//     std::vector<BTreeNode*> children_;
//     BTreeNode() {}
//     BTreeNode (std::vector<int> v) {
//       this->elements_ = v;
//     }
// };

BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
	if (root == NULL){
		return NULL;
	}
    for (int i=0; i<int(root->elements_.size()); i++){
    	if (root->elements_[i] == key){
    		return root;
    	}
    }
    for (int i=0; i<int(root->children_.size()); i++){
    	if (find(root->children_[i], key) != NULL){
    		return find(root->children_[i], key);
    	}
    }

  	return NULL;
}


    // for (vector<int>::iterator it=root->elements_.begin(); it!=root->elements_.end(); ++it){
    // 	if (*it == key){
    // 		return root;
    // 	}
    // }
    // for (vector<int>::iterator it=root->children_.begin(); it!=root->elements_.end(); ++it){
    // 	return find(*it, key);
    // }