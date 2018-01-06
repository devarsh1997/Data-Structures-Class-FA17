#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
	if (head == NULL){
		return "Empty list";
	}
	int ct = 0;
	string out = "";
	while (head->next_ != NULL){
		out += "Node " + to_string(ct) + ": " + to_string(head->data_) + " -> ";
		head = head->next_;
		ct += 1;
	}
	out += "Node " + to_string(ct) + ": " + to_string(head->data_);
	return out;
}

		// Node 0: 100 -> Node 1: 200 -> Node 2: 300




		// string output = "Node " + to_string(ct) + ": " + to_string(head->data_) + " ->";
		// ct+= 1;
		// output += stringList(head->next_);
		// return output;


    // your code here!

