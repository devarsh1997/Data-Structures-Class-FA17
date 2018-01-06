#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node** head, Node* insert) {
	if ((*head) == NULL){
		(*head) = insert;
		return;
	}
	if ((*head)->data_ < insert->data_){
		insertSorted(&((*head)->next_), insert);
	}else{
		insert->next_ = (*head);
		(*head) = insert;
		return;
	}
	if ((*head)->next_ == NULL){
		(*head)->next_ = insert;
		cout << "'reach'" << endl;
		return;
	}

	
  // your code here!
}
