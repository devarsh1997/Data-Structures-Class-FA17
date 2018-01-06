#include "Queue.h"
#include <vector>
using namespace std;

Queue::Queue() {

}

Queue::~Queue(){
	q.clear();
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
	return q.size();
	// if (this->head_ == NULL){
	// 	return 0;
	// }
	// int ct = 0;
	// Node* cur = this->head_;
	// while(cur->next != NULL){
	// 	ct += 1;
	// 	cur = cur->next;
	// }
	// return ct;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
	return q.empty();
	// if (this->size() == 0){
	// 	return true;
	// }
	// return false;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
	q.insert(q.begin(),value);
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
	int out = q.back();
	q.pop_back();
  	return out;
}
