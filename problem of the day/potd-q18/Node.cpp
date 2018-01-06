#include "Node.h"
#include <iostream>
using namespace std;

Node* findMin(Node* list_head){
	Node* cur = list_head;
	int val = cur->data_;
	if (cur->next_ == NULL){
		return cur;
	}
	Node* node_of_rest = findMin(cur->next_);
	int min_of_rest = node_of_rest->data_;
	if (min_of_rest < val){
		return node_of_rest;
	}else{
		return cur;
	}
}

// Node* findMax(Node* list_head){
// 	Node* cur = list_head;
// 	int val = cur->data_;
// 	if (cur->next_ == NULL){
// 		return cur;
// 	}
// 	Node* node_of_rest = findMax(cur->next_);
// 	int max_of_rest = node_of_rest->data_;
// 	if (max_of_rest > val){
// 		return node_of_rest;
// 	}else{
// 		return cur;
// 	}
// }

void print_List(Node *head) {
  if (head == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  Node *temp = head;
  int count = 0;
  while(temp != NULL) {
    cout << "Node " << count << ": " << temp ->data_ << endl;
    count++;
    temp = temp->next_;
  }
}


void sortList(Node** head) {
//   if (head == NULL || Node::getNumNodes() == 1 || *head == NULL ) {return;}

//   while (true) {
//     Node * start = *head;
//     Node * temp = start->next_;
//     Node * another = *head;
//     while (start->data_ <= temp->data_) {
//       start = temp;
//       temp = start->next_;
//       if (temp == NULL) {return;}
//     }
//     if (start == *head) {
//       start->next_ = temp->next_;
//       temp->next_ = start;
//       *head = temp;
//     }
//     else {
//       while (another->next_ != start) {
//         another = another->next_;
//       }
//       another->next_ = temp;
//       start->next_ = temp->next_;
//       temp->next_ = start;
//     }
//   }

// }

	print_List(*head);
	cout << "\n" << endl;
	Node* cur = *head;
	if (cur->next_ == NULL){
		return;
	}
	Node* small = findMin(cur);
	cout << small->data_ << endl;
	// Node* new_head;

	if (small != *head){
		Node* move = *head;
		while (move->next_ != small){
			move = move->next_;
		}
		move->next_ = small->next_;
		small->next_ = *head;
		head = &small;
	}
	// new_head = small->next_;

	sortList(&((*head)->next_));
	// small->next_ = findMin(new_head);
	return;
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

