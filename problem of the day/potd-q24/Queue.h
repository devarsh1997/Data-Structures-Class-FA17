#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>
#include <vector>
using namespace std;

class Queue {
    public:
    	Queue();
    	~Queue();
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
    private:
    	vector<int> q;
	// struct Node{
	// 	int data;
	// 	Node* next;
	// 	Node(){
	// 		this->data = 0;
	// 		this->next = NULL;
	// 	}
	// 	Node(int value){
	// 		this->data = value;
	// 		this->next = NULL;
	// 	}
	// };
	// Node* head_;
	// Node* tail_;
};

#endif
