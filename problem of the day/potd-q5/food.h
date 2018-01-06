// Your code here
#ifndef FOOD_H
#define FOOD_H

#include <string>
using namespace std;

class food{
private:
	string name_;
	int quantity_;
public:
	food();
	string get_name();
	void set_name(string name);
	int get_quantity();
	void set_quantity(int quant);
};

#endif