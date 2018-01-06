#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node* head1 = NULL;
  cout << stringList(head1) << endl;

  // Test 2: A list with exactly one node
  Node* head2 = new Node();
  head2->data_ = 21;
  head2->next_ = NULL;
  cout << stringList(head2) << endl;
  // Test 3: A list with more than one node
  Node* head3 = new Node();
  Node* head4 = new Node();
  Node* head5 = new Node();
  head3->data_ = 31;
  head4->data_ = 32;
  head5->data_ = 33;
  head3->next_ = head4;
  head4->next_ = head5;
  head5->next_ = NULL;
  cout << stringList(head3) << endl;
  return 0;
}
