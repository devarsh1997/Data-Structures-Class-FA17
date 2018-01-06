#include "Node.h"
#include <iostream>
using namespace std;

bool exist(Node* head, Node* check){
	if(head->next_ == NULL){
		if (head->data_ == check->data_){
			return true;
		}else{
			return false;
		}
	}
	if(head->data_ == check->data_){
		return true;
	}else{
		return (exist(head->next_,check));
	}
}

Node *listIntersection(Node *first, Node *second) {
  // your code here
	if (first==NULL || second==NULL){
		return NULL;
	}
	Node* intersection = new Node;
	intersection->next_ = NULL;
	Node* cur = intersection;
	if(first!=NULL && second!=NULL){
		Node* n1 = first;
		if(first->next_==NULL && second->next_==NULL){
			if(exist(second,first)){
				intersection->data_ = first->data_;
				return intersection;
			}else{
				return NULL;
			}

		}
		while(n1->next_ != NULL){
			if (exist(second, n1) && !exist(intersection, n1)){
				Node* add = new Node;
				add->data_ = n1->data_;
				add->next_ = NULL;
				cur->next_ = add;
				cur = add;
				add = NULL;
			}
			n1 = n1->next_;
		}
		if (exist(second, n1)){
			Node* add = new Node;
			add->data_ = n1->data_;
			add->next_ = NULL;
			cur->next_ = add;
		}
	}
	return intersection->next_;
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