#include "Node.h"

using namespace std;

void mergeList(Node* first, Node* second) {
  // your code here!
	Node* n1 = first;
	Node* n2 = second;
	if (n1 == NULL && n2 == NULL){
		return;
	}
	if (n1 == NULL){
		first = second;
		return;
	}
	if (n2 == NULL){
		return;
	}
	while(n1->next_ != NULL && n2->next_ != NULL){
		Node* t = n2->next_;
		n2->next_ = n1->next_;
		n1->next_ = n2;
		n1 = n2->next_;
		n2 = t;
	}
	if (n1->next_ == NULL){
		n1->next_ = n2;
		return;
	}
	if (n2->next_ == NULL){
		n2->next_ = n1->next_;
		n1->next_ = n2;
		return;
	}

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

