#include <iostream>
#include "circle.h"

using namespace std;

void pass_by_value(circle inputValue){
	cout<<"In pass_by_value, the memory address of c is: "<<(&inputValue)<<endl;
}

// pass_by_pointer:
void pass_by_pointer(circle* inputPtr){
	cout<<"In pass_by_pointer, the memory address of c is: "<<(inputPtr)<<endl;	
}
// pass_by_ref:
void pass_by_ref(circle &inputRef){
	cout<<"In pass_by_ref, the memory address of c is: "<<(&inputRef)<<endl;
}
// Include the following line in pass_by_value:
//   cout<<"In pass_by_value, the memory address of c is: "<<(&c)<<endl;

// Include the following line in pass_by_pointer:
//   cout<<"In pass_by_pointer, the memory address of c is: "<<(c)<<endl;

// Include the following line in pass_by_ref:
//   cout<<"In pass_by_ref, the memory address of c is: "<<(&c)<<endl;

