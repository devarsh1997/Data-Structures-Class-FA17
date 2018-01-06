// your code here
#include <iostream>
#include <string>
#include "q5.h"
#include "food.h"

using namespace std;

int main(){
	food* f =  new food();
	cout << "You have " << f->get_quantity() << " " << f->get_name() << endl;
	increase_quantity(f);
	cout << "You have " << f->get_quantity() << " " << f->get_name() << endl;
	return 0;
}