#include "./tests/catch.hpp"
#include "./tests/tests_helper.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "./cs225/PNG.h"
#include "./cs225/HSLAPixel.h"

#include "list.h"

using namespace cs225;

using namespace std;
int main() {
	List<int> list1;
	int size1 = 540000;
  	for (int i = 0; i < size1; i++) { 
  		list1.insertFront(size1-i); 
  	}
  	// list1.print(cout);

  	List<int> list2;
	int size2 = 540000;
  	for (int i = 0; i < size2; i++) { 
  		list2.insertFront(3*(size2-i)); 
  	}

  	// list2.print(cout);
  	list1.mergeWith(list2);
  	// list1.print(cout);
  	// out
  	// cout<<"can create origin!"<<endl;
  	// list.waterfall();
  	// list.print(cout);



	// PNG in;        
	// in.readFromFile("tests/alma copy.png");

	// List<HSLAPixel> list = imageToList(in);
	// // list.print(cout);
	// cout << list.size() << endl;
	// // list.print(cout);
	// list.reverse();

	
  return 0;
}
