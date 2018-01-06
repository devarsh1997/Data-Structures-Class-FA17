#include "Stack.h"
Stack::Stack(){
	this->head_ = new Node();
}

Stack::Stack(int value){
	this->head_ = new Node(value);
}
// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
	if (this->head_ == NULL){
		return 0;
	}
	int ct = 0;
	Node* cur = this->head_;
	while(cur->next != NULL){
		ct += 1;
		cur = cur->next;
	}
	return ct;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
	if (this->size() == 0){
		return true;
	}
	return false;
	// if (this->head_ == NULL){
	// 	return true;
	// }
 // 	return false;
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
	Node* node = new Node(value);
	node->next = this->head_;
	this->head_ = node;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
	int output = this->head_->data;
	Node* node = head_;
	this->head_ = this->head_->next;
	delete node; node = NULL;
  	return output;
}
