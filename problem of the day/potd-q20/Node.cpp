#include "Node.h"
#include <iostream>

using namespace std;
//helper:
void addNode(Node* list_head, Node* add){
	// cout<<add->data_<<endl;
	if (list_head->data_ == add->data_){
		return;
	}
	if (list_head->next_ == NULL){
		if (list_head->data_ == add->data_){
			return;
		}else{
			cout<<"add new: "<<endl;
			cout<<add->data_<<endl;
			Node* addition = new Node;
			addition->data_ = add->data_;
			addition->next_ = NULL;
			list_head->next_ = addition;
			return;
		}
	}
	if (add->data_ != list_head->data_){
		addNode(list_head->next_, add);
	}else{
		return;
	}
}

Node *listUnion(Node *first, Node *second) {
  // your code here
	Node* output = new Node;

	if (first == NULL && second == NULL){
		return NULL;
	}
	if (first == NULL){
		output->data_ = second->data_;
		output->next_ = NULL;
		Node* to_add = second;
		while (to_add->next_!=NULL){
			addNode(output, to_add);
			to_add = to_add->next_;
		} 
		addNode(output, to_add);
		return output;
	}

	output->data_ = first->data_;
	output->next_ = NULL;
	



	Node* last_pointer = first;
	while(last_pointer->next_ != NULL){
		last_pointer = last_pointer->next_;
	}
	last_pointer->next_ = second;

	Node* to_add = first;
	while (to_add->next_!=NULL){
		addNode(output, to_add);
		to_add = to_add->next_;
	} 
	addNode(output, to_add);

	return output;
}






Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
